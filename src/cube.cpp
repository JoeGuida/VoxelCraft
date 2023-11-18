#include "cube.hpp"

std::array<uint32_t, 36> Cube::getIndices() const {
	return {
		 0,  1,  2,  2,  3,  1, // front face
		 4,  5,  6,  6,  7,  5, // right face
		 8,  9, 10, 10, 11,  9, // back face
		12, 13, 14, 14, 15, 13, // left face
		16, 17, 18, 18, 19, 17, // top face
		20, 21, 22, 22, 23, 21, // bottom face
	};
}

std::array<float, 192> Cube::getVertices() const {
	return {
		// positions                                              // normals		  // texCoords
		-CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f,  0.0f,  0.0f,  1.0f, (texCoords[0] % ATLAS_SIZE) * TEXTURE_SIZE,                1.0f - (texCoords[0] / ATLAS_SIZE) * TEXTURE_SIZE,
		 CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f,  0.0f,  0.0f,  1.0f, (texCoords[0] % ATLAS_SIZE) * TEXTURE_SIZE + TEXTURE_SIZE, 1.0f - (texCoords[0] / ATLAS_SIZE) * TEXTURE_SIZE,
		-CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f,  0.0f,  0.0f,  1.0f, (texCoords[0] % ATLAS_SIZE) * TEXTURE_SIZE,                1.0f - TEXTURE_SIZE - (texCoords[0] / ATLAS_SIZE) * TEXTURE_SIZE,
		 CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f,  0.0f,  0.0f,  1.0f, (texCoords[0] % ATLAS_SIZE) * TEXTURE_SIZE + TEXTURE_SIZE, 1.0f - TEXTURE_SIZE - (texCoords[0] / ATLAS_SIZE) * TEXTURE_SIZE,

		 CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f,  1.0f,  0.0f,  0.0f, (texCoords[0] % ATLAS_SIZE) * TEXTURE_SIZE,                1.0f - (texCoords[0] / ATLAS_SIZE) * TEXTURE_SIZE,
		 CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f,  1.0f,  0.0f,  0.0f, (texCoords[0] % ATLAS_SIZE) * TEXTURE_SIZE + TEXTURE_SIZE, 1.0f - (texCoords[0] / ATLAS_SIZE) * TEXTURE_SIZE,
		 CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f,  1.0f,  0.0f,  0.0f, (texCoords[0] % ATLAS_SIZE) * TEXTURE_SIZE,                1.0f - TEXTURE_SIZE - (texCoords[0] / ATLAS_SIZE) * TEXTURE_SIZE,
		 CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f,  1.0f,  0.0f,  0.0f, (texCoords[0] % ATLAS_SIZE) * TEXTURE_SIZE + TEXTURE_SIZE, 1.0f - TEXTURE_SIZE - (texCoords[0] / ATLAS_SIZE) * TEXTURE_SIZE,

		 CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f,  0.0f,  0.0f, -1.0f, (texCoords[0] % ATLAS_SIZE) * TEXTURE_SIZE,                1.0f - (texCoords[0] / ATLAS_SIZE) * TEXTURE_SIZE,
		-CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f,  0.0f,  0.0f, -1.0f, (texCoords[0] % ATLAS_SIZE) * TEXTURE_SIZE + TEXTURE_SIZE, 1.0f - (texCoords[0] / ATLAS_SIZE) * TEXTURE_SIZE,
		 CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f,  0.0f,  0.0f, -1.0f, (texCoords[0] % ATLAS_SIZE) * TEXTURE_SIZE,                1.0f - TEXTURE_SIZE - (texCoords[0] / ATLAS_SIZE) * TEXTURE_SIZE,
		-CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f,  0.0f,  0.0f, -1.0f, (texCoords[0] % ATLAS_SIZE) * TEXTURE_SIZE + TEXTURE_SIZE, 1.0f - TEXTURE_SIZE - (texCoords[0] / ATLAS_SIZE) * TEXTURE_SIZE,

		-CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f, -1.0f,  0.0f,  0.0f, (texCoords[0] % ATLAS_SIZE) * TEXTURE_SIZE,                1.0f - (texCoords[0] / ATLAS_SIZE) * TEXTURE_SIZE,
		-CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f, -1.0f,  0.0f,  0.0f, (texCoords[0] % ATLAS_SIZE) * TEXTURE_SIZE + TEXTURE_SIZE, 1.0f - (texCoords[0] / ATLAS_SIZE) * TEXTURE_SIZE,
		-CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f, -1.0f,  0.0f,  0.0f, (texCoords[0] % ATLAS_SIZE) * TEXTURE_SIZE,                1.0f - TEXTURE_SIZE - (texCoords[0] / ATLAS_SIZE) * TEXTURE_SIZE,
		-CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f, -1.0f,  0.0f,  0.0f, (texCoords[0] % ATLAS_SIZE) * TEXTURE_SIZE + TEXTURE_SIZE, 1.0f - TEXTURE_SIZE - (texCoords[0] / ATLAS_SIZE) * TEXTURE_SIZE,

		 CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f,  0.0f,  1.0f,  0.0f, (texCoords[1] % ATLAS_SIZE) * TEXTURE_SIZE,                1.0f - (texCoords[1] / ATLAS_SIZE) * TEXTURE_SIZE,
		-CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f,  0.0f,  1.0f,  0.0f, (texCoords[1] % ATLAS_SIZE) * TEXTURE_SIZE + TEXTURE_SIZE, 1.0f - (texCoords[1] / ATLAS_SIZE) * TEXTURE_SIZE,
		 CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f,  0.0f,  1.0f,  0.0f, (texCoords[1] % ATLAS_SIZE) * TEXTURE_SIZE,                1.0f - TEXTURE_SIZE - (texCoords[1] / ATLAS_SIZE) * TEXTURE_SIZE,
		-CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f,  0.0f,  1.0f,  0.0f, (texCoords[1] % ATLAS_SIZE) * TEXTURE_SIZE + TEXTURE_SIZE, 1.0f - TEXTURE_SIZE - (texCoords[1] / ATLAS_SIZE) * TEXTURE_SIZE,

		-CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f,  0.0f, -1.0f,  0.0f, (texCoords[2] % ATLAS_SIZE) * TEXTURE_SIZE,                1.0f - (texCoords[2] / ATLAS_SIZE) * TEXTURE_SIZE,
		 CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f,  0.0f, -1.0f,  0.0f, (texCoords[2] % ATLAS_SIZE) * TEXTURE_SIZE + TEXTURE_SIZE, 1.0f - (texCoords[2] / ATLAS_SIZE) * TEXTURE_SIZE,
		-CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f,  0.0f, -1.0f,  0.0f, (texCoords[2] % ATLAS_SIZE) * TEXTURE_SIZE,                1.0f - TEXTURE_SIZE - (texCoords[2] / ATLAS_SIZE) * TEXTURE_SIZE,
		 CUBE_SIZE / 2.0f, -CUBE_SIZE / 2.0f,  CUBE_SIZE / 2.0f,  0.0f, -1.0f,  0.0f, (texCoords[2] % ATLAS_SIZE) * TEXTURE_SIZE + TEXTURE_SIZE, 1.0f - TEXTURE_SIZE - (texCoords[2] / ATLAS_SIZE) * TEXTURE_SIZE,
	};
}

std::array<Triangle, 6> Cube::getTriangles() const {
	std::array<uint32_t, 36> indices = getIndices();
	std::array<float, 192> vertices = getVertices();
	std::array<Triangle, 12> triangles;
	glm::mat4 model = transform.model();
	std::array<int, 6> triangleIndices = { 0, 2, 4, 6, 8, 11 };

	// compute all triangles
	int j = 0;
	for (int i = 0; i < indices.size() - 2; i += 3) {
		int ia = indices[i] * 8;
		int ib = indices[i + 1] * 8;
		int ic = indices[i + 2] * 8;

		glm::vec4 a =  glm::vec4(vertices[ia + 0], vertices[ia + 1], vertices[ia + 2], 1.0f);
		glm::vec4 b =  glm::vec4(vertices[ib + 0], vertices[ib + 1], vertices[ib + 2], 1.0f);
		glm::vec4 c =  glm::vec4(vertices[ic + 0], vertices[ic + 1], vertices[ic + 2], 1.0f);
		glm::vec3 normal(vertices[ia + 3], vertices[ia + 4], vertices[ia + 5]);

		triangles[j] = Triangle(a, b, c, normal);
		j++;
	}

	// since only triangle [0, 2, 4, 6, 8, 11] are used for raycasting
	// only return those triangles
	return {
		triangles[0],
		triangles[2],
		triangles[4],
		triangles[6],
		triangles[8],
		triangles[11]
	};
}
