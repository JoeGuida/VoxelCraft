#ifndef VOXELCRAFT_LINE_HPP
#define VOXELCRAFT_LINE_HPP

#include <glm/vec3.hpp>

class Line {
public:
	Line(const glm::vec3& start, const glm::vec3& end) : start(start), end(end) {}
	Line(const Line&) = default;
	Line(Line&&) = default;
	virtual ~Line() = default;

	glm::vec3 getStart() const { return start; }
	glm::vec3 getEnd() const { return end; }

private:
	glm::vec3 start;
	glm::vec3 end;
};

#endif