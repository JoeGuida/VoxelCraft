#include "chunkgenerator.hpp"

std::vector<std::vector<Cube>> ChunkGenerator::generateChunks(float drawDistance, const glm::vec3& position) {
	int n = static_cast<int>(drawDistance / (CHUNK_SIZE.x * CUBE_SIZE));
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

		for (unsigned int y = 0; y < CHUNK_SIZE.y; y++) {
			for (unsigned int z = 0; z < CHUNK_SIZE.z; z++) {
				for (unsigned int x = 0; x < CHUNK_SIZE.x; x++) {
					glm::vec3 pos(CUBE_SIZE * 2 * x, CUBE_SIZE * 2 * y, CUBE_SIZE * 2 * z);
					chunks[i][x + (z * CHUNK_SIZE.z) + y * (CHUNK_SIZE.x * CHUNK_SIZE.y)].transform.position = pos;
				}
			}
		}

	}

	return chunks;
}

std::vector<Cube> ChunkGenerator::getVisible(const std::vector<Cube>& chunk) {
	std::vector<Cube> visibleCubes;

	for (const Cube& cube : chunk) {
		Ray rays[6] = {
			Ray(glm::vec3(cube.transform.position), cube.transform.position + glm::vec3(1.0f, 0.0f, 0.0f), 0.5f),
			Ray(glm::vec3(cube.transform.position), cube.transform.position + glm::vec3(-1.0f, 0.0f, 0.0f), 0.5f),
			Ray(glm::vec3(cube.transform.position), cube.transform.position + glm::vec3(0.0f, 1.0f, 0.0f), 0.5f),
			Ray(glm::vec3(cube.transform.position), cube.transform.position + glm::vec3(1.0f, -1.0f, 0.0f), 0.5f),
			Ray(glm::vec3(cube.transform.position), cube.transform.position + glm::vec3(0.0f, 0.0f, 1.0f), 0.5f),
			Ray(glm::vec3(cube.transform.position), cube.transform.position + glm::vec3(0.0f, 0.0f, -1.0f), 0.5f),
		};

		bool visible = false;
		for (const Ray& ray : rays) {
			if (!Intersection::rayCubeIntersection(ray, cube)) {
				visible = true;
			}
		}

		if (visible) {
			visibleCubes.push_back(cube);
		}
	}

	return visibleCubes;
}