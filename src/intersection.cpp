#include "intersection.hpp"

glm::vec3 Intersection::barycentric(const glm::vec3& point, const Triangle& triangle) {
	glm::vec3 ap = point - triangle.getA();
	glm::vec3 bp = point - triangle.getB();
	glm::vec3 cp = point - triangle.getC();

	glm::vec3 ab = triangle.getB() - triangle.getA();
	glm::vec3 ac = triangle.getC() - triangle.getA();
	glm::vec3 bc = triangle.getC() - triangle.getB();
	glm::vec3 cb = triangle.getB() - triangle.getC();
	glm::vec3 ca = triangle.getA() - triangle.getC();

	glm::vec3 v = ab - glm::proj(ab, cb);
	float a = 1.0f - (glm::dot(v, ap) / dot(v, ab));

	v = bc - proj(bc, ac);
	float b = 1.0f - (glm::dot(v, bp) / dot(v, bc));
	
	v = ca - proj(ca, ab);
	float c = 1.0f - (glm::dot(v, cp) / dot(v, ca));

	return glm::vec3(a, b, c);
}

float Intersection::raycastPlane(const Ray& ray, const Plane& plane) {
	float nd = glm::dot(ray.direction, plane.getNormal());
	float pn = glm::dot(ray.origin, plane.getNormal());

	if (nd >= 0.0f) {
		return -1;
	}

	float t = (plane.getDistance() - pn) / nd;
	if (t >= 0.0f) {
		return t;
	}

	return -1;
}

float Intersection::raycastTriangle(const Ray& ray, const Triangle& triangle) {
	Plane plane = planeFromTriangle(triangle);
	float t = raycastPlane(ray, plane);
	if (t < 0.0f) {
		return t;
	}
	glm::vec3 result = ray.origin + ray.direction * t;

	glm::vec3 bary = barycentric(result, triangle);
	if (bary.x >= 0.0f && bary.x <= 1.0f &&
		bary.y >= 0.0f && bary.y <= 1.0f &&
		bary.z >= 0.0f && bary.z <= 1.0f) {
		return t;
	}

	return -1;
}
