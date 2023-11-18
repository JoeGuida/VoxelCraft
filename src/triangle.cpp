#include "triangle.hpp"

std::array<float, 24> Triangle::getVertices() const {
	return {
		a.x, a.y, a.z, normal.x, normal.y, normal.z, 0.0f, 0.0f,
		b.x, b.y, b.z, normal.x, normal.y, normal.z, 0.0f, 0.0f,
		c.x, c.y, c.z, normal.x, normal.y, normal.z, 0.0f, 0.0f
	};
}

Triangle operator*(const Triangle& triangle, const glm::mat4& mat) {
	glm::vec3 a = mat * glm::vec4(triangle.getA(), 1.0);
	glm::vec3 b = mat * glm::vec4(triangle.getB(), 1.0);
	glm::vec3 c = mat * glm::vec4(triangle.getC(), 1.0);
	return Triangle(a, b, c, triangle.getNormal());
}
