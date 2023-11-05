#ifndef VOXELCRAFT_CAMERA_HPP
#define VOXELCRAFT_CAMERA_HPP

#include <glm/glm.hpp>

#include "transform.hpp"

class Camera {
public:
	Camera() {};
	Camera(
		float aspect, 
		float fov, 
		float near,
		float far,
		const glm::vec3& front, 
		const glm::vec3& right, 
		const glm::vec3& up,
		const Transform& transform) :
		aspect(aspect),
		fov(glm::radians(fov)),
		near(near),
		far(far),
		front(glm::normalize(front)),
		right(glm::normalize(right)),
		up(glm::normalize(up)),
		transform(transform) {}
	Camera(const Camera&) = default;
	Camera(Camera&&) = default;
	virtual ~Camera() = default;

	Camera& operator=(const Camera& camera) {
		aspect = camera.aspect;
		fov = camera.fov;
		near = camera.near;
		far = camera.far;
		front = camera.front;
		right = camera.right;
		up = camera.up;
		transform = camera.transform;
		return *this;
	}

	float aspect;
	float fov;
	float near;
	float far;
	glm::vec3 front;
	glm::vec3 right;
	glm::vec3 up;
	Transform transform;
};

#endif