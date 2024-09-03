#version 330 core
// scalarData_customcolormap fragment shader

in float value;

uniform vec3 colorMapColors[3];

out vec4 color;

void main()
{
    // As a placeholder, always choose the color with index 0.
    vec3 colorFromColorMap = colorMapColors[0] * value; // Remove this placeholder value

    color = vec4(colorFromColorMap, 1.0F);
}
