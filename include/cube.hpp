#ifndef VOXELCRAFT_CUBE_HPP
#define VOXELCRAFT_CUBE_HPP

#include <array>

#include "material.hpp"
#include "transform.hpp"
#include "triangle.hpp"

constexpr float CUBE_SIZE = 0.4f;
constexpr int ATLAS_SIZE = 8;
constexpr float TEXTURE_SIZE = (1.0f / ATLAS_SIZE);

class Cube {
public:
	Cube(const Material& material, const Transform& transform, const std::array<uint32_t, 3>& texCoords) : 
		material(material), 
		transform(transform),
		texCoords(texCoords) {}
	Cube(const Cube&) = default;
	Cube(Cube&&) = default;
	virtual ~Cube() = default;

	Cube& operator=(const Cube& cube) {
		material = cube.material;
		transform = cube.transform;
		return *this;
	}

	std::array<uint32_t, 36> getIndices() const;
	std::array<float, 192> getVertices() const;
	std::array<Triangle, 12> getTriangles() const;

	Material material;
	Transform transform;

private:
	std::array<uint32_t, 3> texCoords;
};

#endif