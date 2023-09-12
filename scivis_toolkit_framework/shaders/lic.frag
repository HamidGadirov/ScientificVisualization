#version 330 core
// lic fragment shader

uniform sampler2D noiseTexture;
uniform sampler2D velocityField;

uniform int streamlineLength; // i.e. L. One way (e.g., only forwards)
uniform float stepSize;

in vec2 texCoordinates;

out vec4 color;

void main()
{
    // Placeholder computations to prevent warnings
    float magnitude = length(texture(velocityField, texCoordinates).xy);
    float noiseValue = texture(noiseTexture, texCoordinates).r;
    float nonsenseValue = magnitude * noiseValue * stepSize * streamlineLength;

    color = vec4(nonsenseValue, nonsenseValue, nonsenseValue, 1.0F);
}
