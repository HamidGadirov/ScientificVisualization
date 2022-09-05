#version 330 core
// Height plot scale vertex shader

layout (location = 0) in vec2 vertCoordinates_in;
layout (location = 1) in float height;
layout (location = 2) in float value_in;
layout (location = 3) in vec3 vertNormals_in;

// height value
out float value;
// depicts the brightness of the color
out float shading;
// magnitude of the gradient
out float heightChange;

uniform float rangeMin;
uniform float rangeMax;
uniform float transferK;

uniform mat4 projectionTransform;
uniform mat4 viewTransform;
uniform mat3 normalTransform;

uniform vec4 material;
uniform vec3 lightPosition;

void main()
{
    gl_Position = viewTransform * projectionTransform * vec4(vertCoordinates_in, height, 1.0F);

    // Placeholder values
    value = rangeMin + rangeMax;
    shading = transferK + material.x + lightPosition.x;
    heightChange = normalTransform[0][0];
}
