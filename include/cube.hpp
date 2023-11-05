#ifndef VOXELCRAFT_CUBE_HPP
#define VOXELCRAFT_CUBE_HPP

#include <array>

#include "material.hpp"
#include "transform.hpp"

constexpr float CUBE_SIZE = 0.2f;

constexpr std::array<uint32_t, 36> CUBE_INDICES = {
	0, 1, 2, 2, 3, 1, // front face
	1, 5, 3, 3, 7, 5, // right face
	5, 4, 7, 7, 6, 4, // back face
	4, 0, 6, 6, 2, 0, // left face
	4, 0, 1, 1, 4, 5, // top face
	2, 3, 6, 6, 7, 3  // bottom face
};

constexpr std::array<float, 24> CUBE_VERTICES = {
	// front face
	-CUBE_SIZE, CUBE_SIZE, 0.0f,
	CUBE_SIZE, CUBE_SIZE, 0.0f,
	-CUBE_SIZE, -CUBE_SIZE, 0.0f,
	CUBE_SIZE, -CUBE_SIZE, 0.0f,

	-CUBE_SIZE, CUBE_SIZE, -CUBE_SIZE * 2,
	CUBE_SIZE, CUBE_SIZE, -CUBE_SIZE * 2,
	-CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE * 2,
	CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE * 2
};

class Cube {
public:
	Material material;
	Transform transform;

	Cube(const Material& material, const Transform& transform) : 
		material(material), 
		transform(transform) {}
	Cube(const Cube&) = default;
	Cube(Cube&&) = default;
	virtual ~Cube() = default;

	Cube& operator=(const Cube& cube) {
		material = cube.material;
		transform = cube.transform;
		return *this;
	}
};

#endif