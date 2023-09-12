#version 330 core
// lic vertex shader

layout (location = 0) in vec4 vertCoordinates_in;
layout (location = 1) in vec2 texCoordinates_in;

out vec2 texCoordinates;

void main()
{
    gl_Position = vertCoordinates_in;
    texCoordinates = texCoordinates_in;
}
