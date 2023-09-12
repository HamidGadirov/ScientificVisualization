#version 330 core
// glyph vertex shader

layout (location = 0) in vec4 vertCoordinates_in;
layout (location = 1) in float value_in;
layout (location = 2) in mat4 modelTransform;

out vec3 vertPosition;
out float value;

void main()
{
    vertPosition = vec3(modelTransform * vertCoordinates_in);
    gl_Position = vec4(vertPosition, 1.0F);

    value = value_in;
}
