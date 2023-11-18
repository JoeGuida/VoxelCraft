#ifndef VOXELCRAFT_CHUNKGENERATOR_HPP
#define VOXELCRAFT_CHUNKGENERATOR_HPP

#include <glm/vec3.hpp>

#include <vector>

#include "cube.hpp"
#include "intersection.hpp"
#include "ray.hpp"

constexpr glm::uvec3 CHUNK_SIZE(16, 16, 16);

class ChunkGenerator {
public:
	ChunkGenerator(int seed) : seed(seed) {}
	ChunkGenerator(const ChunkGenerator&) = default;
	ChunkGenerator(ChunkGenerator&&) = default;
	virtual ~ChunkGenerator() = default;

	std::vector<std::vector<Cube>> generateChunks(float drawDistance, const glm::vec3& position);
	std::vector<Cube> getVisible(const std::vector<Cube>& chunk);

private:
	int seed;
};

#endif
