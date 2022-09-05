#ifndef TEXTURE_H
#define TEXTURE_H

#include "color.h"
#include "colormap.h"

#include <cstddef>
#include <vector>

class Texture
{
public:
    static std::vector<Color> createGrayscaleTexture(size_t const numberOfColors);
    static std::vector<Color> createRainbowTexture(size_t const numberOfColors);
    static std::vector<Color> createHeatTexture(size_t const numberOfColors);
    static std::vector<Color> createBlueYellowTexture(size_t const numberOfColors);
    static std::vector<Color> createTwoColorTexture(Color const color1, Color const color2, size_t const numberOfColors);
    static std::vector<Color> createThreeColorTexture(Color const color1, Color const color2, Color const color3, size_t const numberOfColors);
    // static std::vector<Color> createYourTexture(size_t const numberOfColors);
};

#endif // TEXTURE_H
