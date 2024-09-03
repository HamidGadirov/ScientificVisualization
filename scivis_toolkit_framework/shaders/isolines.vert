#version 330 core
// isolines vertex shader

layout (location = 0) in vec4 vertCoordinates_in;
layout (location = 1) in float value_in;

uniform float rho;

out VS_OUT
{
    float value;
    int greaterThanRho;
} vs_out;

void main()
{
    gl_Position = vertCoordinates_in;
    vs_out.value = value_in;
    vs_out.greaterThanRho = int(value_in > rho);
}
