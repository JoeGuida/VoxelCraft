#ifndef VOXELCRAFT_MATERIAL_HPP
#define VOXELCRAFT_MATERIAL_HPP

#include <glm/vec3.hpp>

class Material {
public:
	Material(const glm::vec3& color) : color(color) {}
	Material(const Material&) = default;
	Material(Material&&) = default;
	virtual ~Material() = default;

	Material& operator=(const Material& other) {
		color = other.color;
		return *this;
	}

	glm::vec3 getColor() const { return color; }
	void setColor(const glm::vec3& newColor) { color = newColor; }

private:
	glm::vec3 color;
};

#endif