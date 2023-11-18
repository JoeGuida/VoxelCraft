#ifndef VOXELCRAFT_SQUARE_HPP
#define VOXELCRAFT_SQUARE_HPP

#include <array>

#include "material.hpp"
#include "transform.hpp"

constexpr float SQUARE_SIZE = 0.2f;

constexpr std::array<uint32_t, 6> SQUARE_INDICES = {
	0, 1, 2, 2, 3, 1
};

constexpr std::array<float, 12> SQUARE_VERTICES = {
	-SQUARE_SIZE, SQUARE_SIZE, 0.0f,
	SQUARE_SIZE, SQUARE_SIZE, 0.0f,
	-SQUARE_SIZE, -SQUARE_SIZE, 0.0f,
	SQUARE_SIZE, -SQUARE_SIZE, 0.0f,
};

class Square {
public:
	Material material;
	Transform transform;

	Square(const Material& material, const Transform& transform) :
		material(material),
		transform(transform) {}
	Square(const Square&) = default;
	Square(Square&&) = default;
	virtual ~Square() = default;
};

#endif
