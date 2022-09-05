#version 330 core
// Volume rendering vertex shader

layout (location = 0) in vec2 coordinate;

void main()
{
    gl_Position = vec4(coordinate, 0.0F, 1.0F);
}
