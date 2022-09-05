#version 330 core
// isolines vertex shader

layout (location = 0) in vec2 vertCoordinates_in;
layout (location = 1) in float height;

uniform mat4 projectionTransform;

void main()
{
    gl_Position = projectionTransform * vec4(vertCoordinates_in, height, 1.0F);
}
