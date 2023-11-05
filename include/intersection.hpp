#ifndef VOXELCRAFT_INTERSECTION_HPP
#define VOXELCRAFT_INTERSECTION_HPP

#include "cube.hpp"
#include "ray.hpp"

class Intersection {
public:
	static bool rayCubeIntersection(const Ray& ray, const Cube& cube) {
		return false;
	}
};

#endif