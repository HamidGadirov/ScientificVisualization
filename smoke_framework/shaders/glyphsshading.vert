#version 330 core
// glyphsshading vertex shader

layout (location = 0) in vec3 vertCoordinates_in;
layout (location = 1) in float value_in;
layout (location = 2) in mat4 modelTransform;

uniform mat4 projectionTransform;

out vec3 vertPosition;
out float value;

void main()
{
    vertPosition = vec3(modelTransform * vec4(vertCoordinates_in, 1.0F));
    gl_Position = projectionTransform * vec4(vertPosition, 1.0F);

    value = value_in;
}
