#ifndef VOXELCRAFT_TRIANGLE_HPP
#define VOXELCRAFT_TRIANGLE_HPP

#include <glm/geometric.hpp>
#include <glm/vec3.hpp>

#include <array>

#include "material.hpp"
#include "transform.hpp"

class Triangle {
public:
	Triangle() : a(glm::vec3(0.0f)), b(glm::vec3(0.0f)), c(glm::vec3(0.0f)), normal(glm::vec3(0.0f)) {}
	Triangle(const glm::vec3& a, const glm::vec3& b, const glm::vec3& c, const glm::vec3& normal) : 
		a(a), 
		b(b), 
		c(c),
		normal(glm::normalize(normal)) {}
	Triangle(const Triangle&) = default;
	Triangle(Triangle&&) = default;
	virtual ~Triangle() = default;

	Triangle& operator=(const Triangle& triangle) {
		a = triangle.a;
		b = triangle.b;
		c = triangle.c;
		normal = triangle.normal;
		return *this;
	}

	glm::vec3 getA() const { return a; }
	glm::vec3 getB() const { return b; }
	glm::vec3 getC() const { return c; }
	std::array<float, 24> getVertices() const;

private:
	glm::vec3 a;
	glm::vec3 b;
	glm::vec3 c;
	glm::vec3 normal;
};
#endif