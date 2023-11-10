#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include <stb_image.h>

#include <iostream>
#include <random>
#include <vector>

#include "chunkgenerator.hpp"
#include "camera.hpp"
#include "cube.hpp"
#include "line.hpp"
#include "renderer.hpp"
#include "shader.hpp"
#include "triangle.hpp"

void framebufferSizeCallback(GLFWwindow* window, int width, int height);
GLFWwindow* initialize();
void processInput(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouseCallback(GLFWwindow* window, double xpos, double ypos);

// Screen settings
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
constexpr double ASPECT_RATIO = double(SCREEN_WIDTH) / double(SCREEN_HEIGHT);
bool wireframe = false;

// Time
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// Mouse look
bool firstMouse = true;
float centerX = SCREEN_WIDTH / 2.0f;
float centerY = SCREEN_HEIGHT / 2.0f;
float lastX = centerX;
float lastY = centerY;

// Camera
float drawDistance = 5.0f;
Camera camera;

int main() {
    // --------------------------------------------------------------------------------------------
    // Setup GLFW, GLAD, Renderer, initialize window
    // --------------------------------------------------------------------------------------------
    GLFWwindow* window = initialize();
    Renderer::initialize();

    // --------------------------------------------------------------------------------------------
    // Shader Setup
    // --------------------------------------------------------------------------------------------
    std::shared_ptr<Shader> shader = ShaderFactory::create("default");
    std::shared_ptr<Shader> lineShader = ShaderFactory::create("line");

    // --------------------------------------------------------------------------------------------
    // Camera Setup
    // --------------------------------------------------------------------------------------------
    glm::vec3 pos(0.0f, 0.0f, 1.0f);
    glm::vec3 front(0.0f, 0.0f, -1.0f);
    glm::vec3 right(1.0f, 0.0f, 0.0f);
    glm::vec3 up(0.0f, 1.0f, 0.0f);
    camera = Camera(
        ASPECT_RATIO, 
        90.0f, 
        0.1f, 
        100.0f, 
        front, 
        right, 
        up, 
        Transform(pos, Rotation(0.0f, -90.0f, 0.0f)));

    // --------------------------------------------------------------------------------------------
    // Object Setup
    // --------------------------------------------------------------------------------------------
    std::default_random_engine generator;
    std::uniform_int_distribution<long> distribution(LONG_MIN, LONG_MAX);
    long seed = distribution(generator);
    ChunkGenerator chunkGenerator(seed);
    std::vector<std::vector<Cube>> chunks = chunkGenerator.generateChunks(drawDistance, camera.transform.position);
    
    std::array<Triangle, 12> triangles = chunks[0][1].getTriangles();
    
    std::array<Ray, 6> rays = {
        Ray(glm::vec3(chunks[0][0].transform.position), glm::vec3(0.0f, 0.0f, 1.0f), CUBE_SIZE),
        Ray(glm::vec3(chunks[0][0].transform.position), glm::vec3(1.0f, 0.0f, 0.0f), CUBE_SIZE),
        Ray(glm::vec3(chunks[0][0].transform.position), glm::vec3(0.0f, 0.0f, -1.0f), CUBE_SIZE),
        Ray(glm::vec3(chunks[0][0].transform.position), glm::vec3(-1.0f, 0.0f, 0.0f), CUBE_SIZE),
        Ray(glm::vec3(chunks[0][0].transform.position), glm::vec3(0.0f, 1.0f, 0.0f), CUBE_SIZE),
        Ray(glm::vec3(chunks[0][0].transform.position), glm::vec3(0.0f, -1.0f, 0.0f), CUBE_SIZE),
    };

    std::array<Line, 6> lines{
        Line(rays[0].origin, rays[0].origin + rays[0].direction * rays[0].distance),
        Line(rays[1].origin, rays[1].origin + rays[1].direction * rays[1].distance),
        Line(rays[2].origin, rays[2].origin + rays[2].direction * rays[2].distance),
        Line(rays[3].origin, rays[3].origin + rays[3].direction * rays[3].distance),
        Line(rays[4].origin, rays[4].origin + rays[4].direction * rays[4].distance),
        Line(rays[5].origin, rays[5].origin + rays[5].direction * rays[5].distance)
    };

    // --------------------------------------------------------------------------------------------
    // Texture Setup
    // --------------------------------------------------------------------------------------------
    int width, height, numChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(
        (FileSystem::getPath("/src/textures/") + "main_atlas.png").c_str(), 
        &width, 
        &height, 
        &numChannels, 
        0);

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        stbi_image_free(data);
    }
    else {
        std::cout << "Failed to load texture" << std::endl;
    }

    // --------------------------------------------------------------------------------------------
    // Render Loop
    // --------------------------------------------------------------------------------------------
    glm::mat4 projection = glm::perspective(camera.fov, camera.aspect, camera.near, camera.far);
    shader->set("projection", projection);
    lineShader->set("projection", projection);
    while (!glfwWindowShouldClose(window)) {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // clear window
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // set camera view matrix, as camera moves
        glm::mat4 view = glm::lookAt(camera.transform.position, camera.transform.position + camera.front, camera.up);
        shader->set("view", view);
        lineShader->set("view", view);

        // Render initial cube and rays casted around it
        // render each triangle hit on next cube
        Renderer::draw(chunks[0][0], shader);
        for (int i = 0; i < rays.size(); i++) {
            for (int j = 0; j < triangles.size(); j++) {
                if (Intersection::raycastTriangle(rays[i], triangles[j]) != -1) {
                    float t = Intersection::raycastTriangle(rays[i], triangles[j]);
                    Renderer::draw(triangles[j], chunks[0][1].transform, shader);
                }
            }
        }

        for (const Line& line : lines) {
            Renderer::draw(line, glm::vec3(0.0f, 1.0f, 0.0f), lineShader);
        }

        // swap buffers and poll for input events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

GLFWwindow* initialize() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create GLFW window and set callbacks
    GLFWwindow* window = glfwCreateWindow(
        SCREEN_WIDTH, 
        SCREEN_HEIGHT, 
        "VoxelCraft", 
        nullptr, 
        nullptr);
    if (!window) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwSetKeyCallback(window, processInput);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, mouseCallback);
    glfwSetCursorPos(window, centerX, centerY);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    return window;
}

void processInput(GLFWwindow* window, int key, int scancode, int action, int mods) {
    float cameraSpeed = 10.0f * deltaTime;

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
    if (key == GLFW_KEY_LEFT_SHIFT && action == GLFW_PRESS) {
        if (!wireframe) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            wireframe = true;
        }
        else {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            wireframe = false;
        }

    }

    // camera input
    if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        camera.transform.position += cameraSpeed * camera.front;
    }
    if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        camera.transform.position -= cameraSpeed * camera.front;
    }
    if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        camera.transform.position -= cameraSpeed * glm::normalize(glm::cross(camera.front, camera.up));
    }
    if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        camera.transform.position += cameraSpeed * glm::normalize(glm::cross(camera.front, camera.up));
    }
}

void mouseCallback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = centerX;
        lastY = centerY;
        firstMouse = false;
    }

    // get offset from last mouse position
    float xoffset = xpos - centerX;
    float yoffset = centerY - ypos;

    // multiply offset by mouse sensitivity
    const float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    // clamp pitch to [-89.0f, 89.0f] 
    Rotation rotation(camera.transform.rotation);

    rotation.yaw += xoffset;
    rotation.pitch += yoffset;

    if (rotation.pitch > 89.0f)
        rotation.pitch = 89.0f;
    if (rotation.pitch < -89.0f)
        rotation.pitch = -89.0f;

    // update camera vectors
    camera.front = glm::normalize(glm::vec3(rotation));
}