#ifndef VOXELCRAFT_RENDERER_HPP
#define VOXELCRAFT_RENDERER_HPP

#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include <memory>

#include "cube.hpp"
#include "line.hpp"
#include "shader.hpp"
#include "square.hpp"
#include "triangle.hpp"

class Renderer {
public:
	static void initialize() {
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
	}

	static void draw(const Cube& cube, const std::shared_ptr<Shader>& shader);
	static void draw(const Line& line, const glm::vec3& color, const std::shared_ptr<Shader>& shader);
	static void draw(const Triangle& triangle, const Transform& transform, const std::shared_ptr<Shader>& shader);

private:
	static uint32_t VAO;
	static uint32_t VBO;
	static uint32_t EBO;
};

#endif