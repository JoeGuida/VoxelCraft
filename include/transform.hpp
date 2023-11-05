#ifndef VOXELCRAFT_TRANSFORM_HPP
#define VOXELCRAFT_TRANSFORM_HPP

#include <glm/vec3.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <iostream>

class Rotation {
public:
	Rotation(float pitch, float yaw, float roll) : pitch(pitch), yaw(yaw), roll(roll) {}
	Rotation(const Rotation&) = default;
	Rotation(Rotation&&) = default;
	virtual ~Rotation() = default;

	Rotation& operator=(const Rotation& rotation) {
		pitch = rotation.pitch;
		yaw = rotation.yaw;
		roll = rotation.roll;
		return *this;
	}

	operator glm::vec3() const { 
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

		x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
		y = sin(glm::radians(pitch));
		z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));

		return glm::vec3(x, y, z);
	}

	float pitch;
	float yaw;
	float roll;
};

class Transform {
public:
	Transform() : position(glm::vec3(0.0f)), rotation(Rotation(0.0f, 0.0f, 0.0f)), scale(glm::vec3(1.0f)) {}
	Transform(const glm::vec3& position, const Rotation& rotation, const glm::vec3& scale) :
		position(position),
		rotation(rotation),
		scale(scale) {}
	Transform(const glm::vec3& position, const Rotation& rotation) :
		position(position),
		rotation(rotation),
		scale(glm::vec3(1.0f)) {}
	Transform(const glm::vec3& position) :
		position(position),
		rotation(Rotation(0.0f, 0.0f, 0.0f)),
		scale(glm::vec3(1.0f)) {}
	Transform(const Transform&) = default;
	Transform(Transform&&) = default;
	virtual ~Transform() = default;

	Transform& operator=(const Transform& transform) {
		position = transform.position;
		rotation = transform.rotation;
		scale = transform.scale;
		return *this;
	}

	glm::vec3 position;
	Rotation rotation;
	glm::vec3 scale;
};

#endif