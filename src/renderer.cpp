#include "renderer.hpp"

uint32_t Renderer::VAO;
uint32_t Renderer::VBO;
uint32_t Renderer::EBO;

void Renderer::draw(const Cube& cube, const std::shared_ptr<Shader>& shader) {
    std::array<float, 192> vertices = cube.getVertices();
    std::array<uint32_t, 36> indices = cube.getIndices();

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint32_t), indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0); // positions
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float))); // normals
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float))); // texCoords
    glEnableVertexAttribArray(2);

    // Apply matrix transformation and set shader uniforms
    glm::mat4 model = glm::mat4(1.0f);
    glm::vec3 rotation = glm::vec3(cube.transform.rotation);
    model = glm::translate(model, cube.transform.position);
    if (fabsf(cube.transform.rotation.pitch) > 0.0f)
        model = glm::rotate(model, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    if (fabsf(cube.transform.rotation.yaw) > 0.0f)
        model = glm::rotate(model, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    if (fabsf(cube.transform.rotation.roll) > 0.0f)
        model = glm::rotate(model, rotation.z, glm::vec3(0.0f, 0.0f, -1.0f));
    model = glm::scale(model, cube.transform.scale);
    shader->set("model", model);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void Renderer::draw(const Line& line, const glm::vec3& color, const std::shared_ptr<Shader>& shader) {
    glm::vec3 start = line.getStart();
    glm::vec3 end = line.getEnd();
    std::array<float, 6> vertices = {
        start.x, start.y, start.z,
        end.x, end.y, end.z
    };

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); // positions
    glEnableVertexAttribArray(0);

    // Apply matrix transformation and set shader uniforms
    glm::mat4 model = glm::mat4(1.0f);
    shader->set("model", model);
    shader->set("color", color);

    glDrawArrays(GL_LINES, 0, 2);
}

void Renderer::draw(const Triangle& triangle, const Transform& transform, const std::shared_ptr<Shader>& shader) {
    std::array<float, 24> vertices = triangle.getVertices();

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0); // positions
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float))); // normals
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float))); // texCoords
    glEnableVertexAttribArray(2);

    // Apply matrix transformation and set shader uniforms
    glm::mat4 model = glm::mat4(1.0f);
    glm::vec3 rotation = glm::vec3(transform.rotation);
    model = glm::translate(model, transform.position);
    if (fabsf(transform.rotation.pitch) > 0.0f)
        model = glm::rotate(model, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    if (fabsf(transform.rotation.yaw) > 0.0f)
        model = glm::rotate(model, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    if (fabsf(transform.rotation.roll) > 0.0f)
        model = glm::rotate(model, rotation.z, glm::vec3(0.0f, 0.0f, -1.0f));
    model = glm::scale(model, transform.scale);
    shader->set("model", model);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}
