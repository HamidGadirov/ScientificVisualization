#version 330 core
// isolines fragment shader

uniform vec3 isolineColor;

out vec4 color;

void main()
{
    color = vec4(isolineColor, 1.0F);
}
