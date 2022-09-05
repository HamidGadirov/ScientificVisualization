#version 330 core
// Scalar data scale vertex shader

layout (location = 0) in vec2 vertCoordinates_in;
layout (location = 1) in float value_in;

out float value;

uniform float rangeMin;
uniform float rangeMax;
uniform float transferK;

uniform mat4 projectionTransform;

void main()
{
    gl_Position = projectionTransform * vec4(vertCoordinates_in, 0.0F, 1.0F);

    // Map values from [rangeMin, rangeMax] to [0, 1].
    value = rangeMin + rangeMax; // Remove this placeholder computation

    // Apply transfer function.
    value = pow(value, transferK);
}
