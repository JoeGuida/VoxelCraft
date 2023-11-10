#include "chunkgenerator.hpp"

std::vector<std::vector<Cube>> ChunkGenerator::generateChunks(float drawDistance, const glm::vec3& position) {
	int n = static_cast<int>(drawDistance / (CHUNK_SIZE.x * CUBE_SIZE));
	int numChunks = static_cast<int>(pow((n * 2) - 1, 2));
	int numCubes = CHUNK_SIZE.x * CHUNK_SIZE.y * CHUNK_SIZE.z;
	std::vector<std::vector<Cube>> chunks;

	// reserve and assign chunks
	Cube cube(
		Material(glm::vec3(0.5f)),
		Transform(glm::vec3(0.0f)),
		std::array<uint32_t, 3> { 1, 0, 2}
	);
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
					glm::vec3 pos(CUBE_SIZE * x, CUBE_SIZE * y, CUBE_SIZE * z);
					chunks[i][x + (z * CHUNK_SIZE.z) + y * (CHUNK_SIZE.x * CHUNK_SIZE.y)].transform.position = pos;
				}
			}
		}

	}

	return chunks;
}

std::vector<Cube> ChunkGenerator::getVisible(const std::vector<Cube>& chunk) {
	std::vector<Cube> visibleCubes;
	float distance = 0.01f;

	for(int i = 0; i < chunk.size(); i++) {
		std::array<Ray, 1> rays = {
			Ray(glm::vec3(chunk[i].transform.position), glm::vec3(1.0f, 0.0f, 0.0f), distance),
			Ray(glm::vec3(chunk[i].transform.position), glm::vec3(-1.0f, 0.0f, 0.0f), distance),
			Ray(glm::vec3(chunk[i].transform.position), glm::vec3(0.0f, 1.0f, 0.0f), distance),
			Ray(glm::vec3(chunk[i].transform.position), glm::vec3(1.0f, -1.0f, 0.0f), distance),
			Ray(glm::vec3(chunk[i].transform.position), glm::vec3(0.0f, 0.0f, 1.0f), distance),
			Ray(glm::vec3(chunk[i].transform.position), glm::vec3(0.0f, 0.0f, -1.0f), distance),
		};

		bool visible = false;
		for (const Ray& ray : rays) {
			for (const Triangle& triangle : chunk[i].getTriangles()) {
				if (Intersection::raycastTriangle(ray, triangle) == -1) {
					visible = true;
				}
			}
		}

		if (visible) {
			visibleCubes.push_back(chunk[i]);
		}
	}

	return visibleCubes;
}