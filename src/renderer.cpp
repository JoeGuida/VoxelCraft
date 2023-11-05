#include "renderer.hpp"

uint32_t Renderer::VAO;
uint32_t Renderer::VBO;
uint32_t Renderer::EBO;

void Renderer::draw(const Cube& cube, const std::shared_ptr<Shader>& shader) {
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, CUBE_VERTICES.size() * sizeof(float), CUBE_VERTICES.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, CUBE_INDICES.size() * sizeof(uint32_t), CUBE_INDICES.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); // position attribute
    glEnableVertexAttribArray(0);

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
    shader->set("color", cube.material.getColor());

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void Renderer::draw(const Square& square, const std::shared_ptr<Shader>& shader) {
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, SQUARE_VERTICES.size() * sizeof(float), SQUARE_VERTICES.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, SQUARE_INDICES.size() * sizeof(uint32_t), SQUARE_INDICES.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); // position attribute
    glEnableVertexAttribArray(0);

    // Apply matrix transformation and set shader uniforms
    glm::mat4 model = glm::mat4(1.0f);
    glm::vec3 rotation = glm::normalize(glm::vec3(square.transform.rotation));
    model = glm::translate(model, square.transform.position);

    if(fabsf(square.transform.rotation.pitch) > 0.0f)
        model = glm::rotate(model, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    if (fabsf(square.transform.rotation.yaw) > 0.0f)
        model = glm::rotate(model, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    if (fabsf(square.transform.rotation.roll) > 0.0f)
        model = glm::rotate(model, rotation.z, glm::vec3(0.0f, 0.0f, -1.0f));
    model = glm::scale(model, square.transform.scale);
    shader->set("model", model);
    shader->set("color", square.material.getColor());

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}