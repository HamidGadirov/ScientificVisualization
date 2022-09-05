#version 330 core
// Lic vertex shader

layout (location = 0) in vec2 vertCoordinates_in;
layout (location = 1) in vec2 texCoordinates_in;

uniform mat4 projectionTransform;

out vec2 texCoordinates;

void main()
{
    gl_Position = projectionTransform * vec4(vertCoordinates_in, 0.0F, 1.0F);
    texCoordinates = texCoordinates_in;
}
