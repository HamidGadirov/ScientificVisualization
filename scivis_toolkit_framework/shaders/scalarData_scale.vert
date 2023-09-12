#version 330 core
// scalarData_scale vertex shader

layout (location = 0) in vec4 vertCoordinates_in;
layout (location = 1) in float value_in;

out float value;

uniform float rangeMin;
uniform float rangeMax;
uniform float transferK;

void main()
{
    gl_Position = vertCoordinates_in;

    // Map values from [rangeMin, rangeMax] to [0, 1].
    value = rangeMin + rangeMax; // Remove this placeholder computation

    // Apply transfer function.
    value = pow(value, transferK);
}
