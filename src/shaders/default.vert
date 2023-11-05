#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

out vec3 vertexColor;
out vec3 vertexNormal;
out vec3 FragPos;

out float ambientLightIntensity;
out vec3 directionalLightDirection;
out float directionalLightIntensity;

uniform float aLightIntensity;
uniform vec3 dLightDirection;
uniform float dLightIntensity;

uniform vec3 color;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(position, 1.0);
    FragPos = vec3(model * vec4(position, 1.0));
    vertexColor = color;
    vertexNormal = normal;
    ambientLightIntensity = aLightIntensity;
    directionalLightIntensity = dLightIntensity;
    directionalLightDirection = dLightDirection;
}