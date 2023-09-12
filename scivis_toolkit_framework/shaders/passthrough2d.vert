#version 330 core
// passthrough2d vertex shader

layout (location = 0) in vec4 vertCoordinates_in;
layout (location = 1) in float value_in;

out float value;

void main()
{
    gl_Position = vertCoordinates_in;
    value = value_in;
}
