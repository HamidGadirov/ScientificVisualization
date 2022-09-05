#version 330 core
// Colormap fragment shader

in float value;

uniform sampler1D textureSampler;

out vec4 color;

void main()
{
    vec3 texColor = texture(textureSampler, value).rgb;
    color = vec4(texColor, 1.0F);
}
