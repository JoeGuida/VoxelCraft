#include "triangle.hpp"

std::array<float, 24> Triangle::getVertices() const {
	return {
		a.x, a.y, a.z, normal.x, normal.y, normal.z, 0.0f, 0.0f,
		b.x, b.y, b.z, normal.x, normal.y, normal.z, 0.0f, 0.0f,
		c.x, c.y, c.z, normal.x, normal.y, normal.z, 0.0f, 0.0f
	};
}