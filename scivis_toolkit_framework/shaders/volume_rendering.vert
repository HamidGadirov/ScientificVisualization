#version 330 core
// volume_rendering vertex shader

layout (location = 0) in vec4 coordinate_in;
layout (location = 1) in vec2 uv_in;

out vec2 uv;

void main()
{
    gl_Position = coordinate_in;
    uv = uv_in;
}
