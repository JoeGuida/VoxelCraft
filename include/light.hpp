#ifndef VOXELCRAFT_LIGHT_HPP
#define VOXELCRAFT_LIGHT_HPP

#include <glm/vec3.hpp>

class AmbientLight {
public:
	AmbientLight(float intensity) : intensity(intensity) {}
	AmbientLight(const AmbientLight&) = default;
	AmbientLight(AmbientLight&&) = default;
	virtual ~AmbientLight() = default;

	float getIntensity() const { return intensity; }

private:
	float intensity;
};

class DirectionalLight {
public:
	DirectionalLight(float intensity, const glm::vec3& direction) : intensity(intensity), direction(glm::normalize(direction)) {}
	DirectionalLight(const DirectionalLight&) = default;
	DirectionalLight(DirectionalLight&&) = default;
	virtual ~DirectionalLight() = default;

	float getIntensity() const { return intensity; }
	glm::vec3 getDirection() const { return direction; }

private:
	float intensity;
	glm::vec3 direction;
};

#endif
