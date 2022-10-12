#version 330 core
// glyphsshading fragment shader

in vec3 vertPosition;
in float value;

uniform sampler1D textureSampler;

out vec4 color;

const vec3 vertNormal = vec3(0.0F, 0.0F, 1.0F); // Up
const vec3 viewPosition = vec3(300.0F, 300.0F, 200.0F);
const vec3 lightPosition = vec3(300.0F, 300.0F, 200.0F);
const vec4 materialCoefficients = vec4(0.5F, 0.5F, 0.8F, 1.0F);

void main()
{
    vec3 materialColor = texture(textureSampler, value).rgb;
    color = vec4(materialColor, 1.0F);
}
