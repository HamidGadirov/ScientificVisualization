#version 330 core
// Height plot fragment shader

in float value;
in float shading;
in float heightChange;

uniform sampler1D textureSampler;

out vec4 color;

void main()
{
  vec3 gray = vec3(0.3F, 0.3F, 0.3F);

    // TODO:
    // - Use the height value to obtain the correct color from the color map.
    // - Use the height change variable to show areas of low change in gray, but areas of large change in color (use linear interpolation).
    color = vec4(0.0F, 0.5F, 1.0F, 1.0F) * shading * heightChange * texture(textureSampler, value); // Placeholder computation
}
