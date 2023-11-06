#ifndef VOXELCRAFT_CUBE_HPP
#define VOXELCRAFT_CUBE_HPP

#include <array>

#include "material.hpp"
#include "transform.hpp"

constexpr float CUBE_SIZE = 0.2f;
constexpr float TEXTURE_OFFSET = (1.0f / 8.0f);

constexpr std::array<uint32_t, 36> CUBE_INDICES = {
	 0,  1,  2,  2,  3,  1, // front face
	 4,  5,  6,  6,  7,  5, // right face
	 8,  9, 10, 10, 11,  9, // back face
	12, 13, 14, 14, 15, 13, // left face
	16, 17, 18, 18, 19, 17, // top face
	20, 21, 22, 22, 23, 21, // bottom face
};

constexpr std::array<float, 192> CUBE_VERTICES = {
	// positions						// normals		  // texCoords
	// front face
	-CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, 0.0f, 0.0f, 1.0f, TEXTURE_OFFSET, 1.0f,
	CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, 0.0f, 0.0f, 1.0f, TEXTURE_OFFSET * 2, 1.0f,
	-CUBE_SIZE, -CUBE_SIZE, CUBE_SIZE, 0.0f, 0.0f, 1.0f, TEXTURE_OFFSET, 1.0f - TEXTURE_OFFSET,
	CUBE_SIZE, -CUBE_SIZE, CUBE_SIZE, 0.0f, 0.0f, 1.0f, TEXTURE_OFFSET * 2, 1.0f - TEXTURE_OFFSET,
	// right face
	CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, 1.0f, 0.0f, 0.0f, TEXTURE_OFFSET, 1.0f,
	CUBE_SIZE, CUBE_SIZE, -CUBE_SIZE, 1.0f, 0.0f, 0.0f, TEXTURE_OFFSET * 2, 1.0f,
	CUBE_SIZE, -CUBE_SIZE, CUBE_SIZE, 1.0f, 0.0f, 0.0f, TEXTURE_OFFSET, 1.0f - TEXTURE_OFFSET,
	CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE, 1.0f, 0.0f, 0.0f, TEXTURE_OFFSET * 2, 1.0f - TEXTURE_OFFSET,
	// back face
	CUBE_SIZE, CUBE_SIZE, -CUBE_SIZE, 0.0f, 0.0f, -1.0f, TEXTURE_OFFSET, 1.0f,
	-CUBE_SIZE, CUBE_SIZE, -CUBE_SIZE, 0.0f, 0.0f, -1.0f, TEXTURE_OFFSET * 2, 1.0f,
	CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE, 0.0f, 0.0f, -1.0f, TEXTURE_OFFSET, 1.0f - TEXTURE_OFFSET,
	-CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE, 0.0f, 0.0f, -1.0f, TEXTURE_OFFSET * 2, 1.0f - TEXTURE_OFFSET,
	// left face
	-CUBE_SIZE, CUBE_SIZE, -CUBE_SIZE, -1.0f, 0.0f, 0.0f, TEXTURE_OFFSET, 1.0f,
	-CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, -1.0f, 0.0f, 0.0f, TEXTURE_OFFSET * 2, 1.0f,
	-CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE, -1.0f, 0.0f, 0.0f, TEXTURE_OFFSET, 1.0f - TEXTURE_OFFSET,
	-CUBE_SIZE, -CUBE_SIZE, CUBE_SIZE, -1.0f, 0.0f, 0.0f, TEXTURE_OFFSET * 2, 1.0f - TEXTURE_OFFSET,
	// top face
	 CUBE_SIZE, CUBE_SIZE,  CUBE_SIZE, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
	-CUBE_SIZE, CUBE_SIZE,  CUBE_SIZE, 0.0f, 1.0f, 0.0f, TEXTURE_OFFSET, 1.0f,
	 CUBE_SIZE, CUBE_SIZE, -CUBE_SIZE, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f - TEXTURE_OFFSET,
	-CUBE_SIZE, CUBE_SIZE, -CUBE_SIZE, 0.0f, 1.0f, 0.0f, TEXTURE_OFFSET, 1.0f - TEXTURE_OFFSET,
	// bottom face
	-CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE, 0.0f, -1.0f, 0.0f, TEXTURE_OFFSET * 2, 1.0f,
	CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE, 0.0f, -1.0f, 0.0f, TEXTURE_OFFSET * 3, 1.0f,
	-CUBE_SIZE, -CUBE_SIZE, CUBE_SIZE, 0.0f, -1.0f, 0.0f, TEXTURE_OFFSET * 2, 1.0f - TEXTURE_OFFSET,
	CUBE_SIZE, -CUBE_SIZE, CUBE_SIZE, 0.0f, -1.0f, 0.0f, TEXTURE_OFFSET * 3, 1.0f - TEXTURE_OFFSET
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