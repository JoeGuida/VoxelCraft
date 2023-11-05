#version 330 core

in vec3 vertexColor;
in vec3 vertexNormal;
in vec3 FragPos;

in float ambientLightIntensity;
in vec3 directionalLightDirection;
in float directionalLightIntensity;

out vec4 FragColor;

void main() {
    vec3 normal = normalize(vertexNormal);
    vec3 lightDirection = normalize(directionalLightDirection - FragPos);

    float ambient = ambientLightIntensity;
    float diff = max(dot(normal, lightDirection), 0.0) * directionalLightIntensity;
    vec3 diffuse = diff * vec3(1.0, 1.0, 1.0);

    FragColor = vec4((ambient + diffuse) * vertexColor, 1.0);
}