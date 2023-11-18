#ifndef VOXELCRAFT_RAY_HPP
#define VOXELCRAFT_RAY_HPP

#include <glm/vec3.hpp>

class Ray {
public:
	Ray(const glm::vec3& origin, const glm::vec3& direction) :
		origin(origin),
		direction(direction) {}

	glm::vec3 origin;
	glm::vec3 direction;
};

#endif
