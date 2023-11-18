#version 330 core

in vec3 vertexNormal;
in vec2 vertexTexCoord;
in vec3 FragPos;

out vec4 FragColor;

uniform sampler2D tex;

void main() {
    FragColor = texture(tex, vertexTexCoord);
}
