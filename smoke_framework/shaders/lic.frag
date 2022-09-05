#version 330 core
// Lic fragment shader

in vec2 texCoordinates;

uniform sampler2D textureSampler;

out vec4 color;

void main()
{
    float texColor = texture(textureSampler, texCoordinates).r; // / 256.0F;
    color = vec4(texColor, texColor, texColor, 1.0F);
}
