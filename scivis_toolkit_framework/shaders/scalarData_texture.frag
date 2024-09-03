#version 330 core
// scalarData_texture fragment shader

in float value;

uniform sampler1D textureSampler;

out vec4 color;

void main()
{
    color = texture(textureSampler, value);
}
