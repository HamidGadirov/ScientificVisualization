#version 330 core
// passthrough2d vertex shader

layout (location = 0) in vec2 vertCoordinates_in;
layout (location = 1) in float value_in;

out float value;

void main()
{
    gl_Position = vec4(vertCoordinates_in, 0.0F, 1.0F);
    value = value_in;
}
