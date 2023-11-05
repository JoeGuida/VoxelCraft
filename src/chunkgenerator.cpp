#include "chunkgenerator.hpp"

std::vector<std::vector<Cube>> ChunkGenerator::generateChunks(float drawDistance, const glm::vec3& position) {
	int n = drawDistance / (CHUNK_SIZE.x * CUBE_SIZE);
	int numChunks = static_cast<int>(pow((n * 2) - 1, 2));
	int numCubes = CHUNK_SIZE.x * CHUNK_SIZE.y * CHUNK_SIZE.z;
	std::vector<std::vector<Cube>> chunks;

	// reserve and assign chunks
	Cube cube(Material(glm::vec3(0.5f)), Transform(glm::vec3(0.0f)));
	std::vector<Cube> cubes;

	cubes.reserve(numCubes);
	cubes.assign(numCubes, cube);
	chunks.reserve(numChunks);
	chunks.assign(numChunks, cubes);

	// generate cubes in each chunk
	for (int i = 0; i < numChunks; i++) {


		for (int y = 0; y < CHUNK_SIZE.y; y++) {
			for (int z = 0; z < CHUNK_SIZE.z; z++) {
				for (int x = 0; x < CHUNK_SIZE.x; x++) {
					glm::vec3 pos(CUBE_SIZE * 2 * x, CUBE_SIZE * 2 * y, CUBE_SIZE * 2 * z);
					chunks[i][x + (z * CHUNK_SIZE.z) + y * (CHUNK_SIZE.x * CHUNK_SIZE.y)].transform.position = pos;
				}
			}
		}


	}

	return chunks;
}