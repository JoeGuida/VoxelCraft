#ifndef VOXELCRAFT_PLANE_HPP
#define VOXELCRAFT_PLANE_HPP

#include <glm/geometric.hpp>
#include <glm/vec3.hpp>

#include "triangle.hpp"

class Plane {
public:
	Plane(const glm::vec3& normal, float distance) : normal(normal), distance(distance) {}
	Plane(const Plane&) = default;
	Plane(Plane&&) = default;
	virtual ~Plane() = default;

	glm::vec3 getNormal() const { return normal; }
	float getDistance() const { return distance; }

private:
	glm::vec3 normal;
	float distance;
};

Plane planeFromTriangle(const Triangle& triangle);

#endif
