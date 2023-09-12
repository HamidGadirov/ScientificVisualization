#version 330 core
// scalarData_clamp vertex shader

layout (location = 0) in vec4 vertCoordinates_in;
layout (location = 1) in float value_in;

out float value;

uniform float clampMin;
uniform float clampMax;
uniform float transferK;

void main()
{
    gl_Position = vertCoordinates_in;

    // Clamp values.
    value = clamp(value_in, clampMin, clampMax);

    // Map the range [clampMin, clampMax] to [0, 1].
    value = clampMin + clampMax; // Remove this placeholder computation

    // Apply transfer function.
    value = pow(value, transferK);
}
