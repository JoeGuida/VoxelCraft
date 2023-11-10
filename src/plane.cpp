#include "plane.hpp"

Plane planeFromTriangle(const Triangle& triangle) {
	glm::vec3 normal = glm::normalize(glm::cross(triangle.getB() - triangle.getA(), triangle.getC() - triangle.getA()));
	float distance = glm::dot(normal, triangle.getA());
	return Plane(normal, distance);
}