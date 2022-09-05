#version 330 core
// Colormap fragment shader

in float value;

uniform vec3 colorMapColors[3];

out vec4 color;

void main()
{
    // As a place holder, always choose the color with index 0.
    vec3 colorFromColorMap = colorMapColors[0] * value; // Remove this placeholder value

    color = vec4(colorFromColorMap, 1.0F);
}
