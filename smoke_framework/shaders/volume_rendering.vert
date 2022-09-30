#version 330 core
// Volume rendering vertex shader

layout (location = 0) in vec2 coordinate_in;
layout (location = 1) in vec2 uv_in;

out vec2 uv;

void main()
{
    gl_Position = vec4(coordinate_in, 0.0F, 1.0F);
    uv = uv_in;
}
