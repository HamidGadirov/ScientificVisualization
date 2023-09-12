#version 330 core
// glyph fragment shader

in vec3 vertPosition;
in float value;

uniform sampler1D textureSampler;

out vec4 color;

void main()
{
    vec3 materialColor = texture(textureSampler, value).rgb;
    color = vec4(materialColor, 1.0F);
}
