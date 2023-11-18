#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

out vec3 vertexNormal;
out vec2 vertexTexCoord;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(position, 1.0);
    vertexNormal = normal;
    vertexTexCoord = texCoord;
    FragPos = vec3(model * vec4(position, 1.0));
}
