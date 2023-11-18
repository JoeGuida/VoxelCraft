#ifndef VOXELCRAFT_INTERSECTION_HPP
#define VOXELCRAFT_INTERSECTION_HPP

#include <glm/vec3.hpp>
#include <glm/gtx/projection.hpp>

#include "cube.hpp"
#include "plane.hpp"
#include "ray.hpp"
#include "triangle.hpp"

class Intersection {
public:
	static glm::vec3 barycentric(const glm::vec3& point, const Triangle& triangle);
	static float raycastPlane(const Ray& ray, const Plane& plane);
	static float raycastTriangle(const Ray& ray, const Triangle& triangle, float maxDistance);
};

#endif
