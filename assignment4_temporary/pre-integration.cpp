#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <ios>
#include <iostream>
#include <vector>
// #include <Magick++.h>
// #include <opencv2/opencv.hpp>

// using namespace Magick;
// using namespace cv;

// Define colors for the colormap
float const colorNode0[3U] = { 0.0F, 0.0F, 1.0F };  // blue
float const colorNode1[3U] = { 1.0F, 1.0F, 1.0F };  // white
float const colorNode2[3U] = { 1.0F, 0.0F, 0.0F };  // red

float composedColor[4U] = { 0.0F };

// TODO: modify the transferFunction and add necessary functions

std::array<float, 4U> transferFunction(float value)
{
    value /= 255.0F; // to range [0...1]

    float alpha = value * 0.1F; // value;

    if (value < 0.2F)
        alpha = 0.0F;

    float color0[3U] = { 0.0F };
    std::copy(std::begin(colorNode0), std::end(colorNode0), std::begin(color0));
    float color1[3U] = { 0.0F };
    std::copy(std::begin(colorNode1), std::end(colorNode1), std::begin(color1));

    float t = 0.0F;
    if (value < 0.5F)
    {
        t = 2.0F * value;
    }
    else
    {
        t = 2.0F * (value - 0.5F);
        std::copy(std::begin(colorNode1), std::end(colorNode1), std::begin(color0));
        std::copy(std::begin(colorNode2), std::end(colorNode2), std::begin(color1));
    }

    std::array<float, 4U> color;

    color[3U] = alpha;

    for (size_t idx = 0U; idx < 3U; ++idx) // rgb
        color[idx] = color0[idx] * (1.0F - t) + color1[idx] * t;

    return color;
}

void writeImage(std::vector<std::array<float, 4U>> image)
{
    size_t const xDim = 256U;
    size_t const yDim = 256U;

    std::ofstream outStream{"pre-integrated.ppm"};
    outStream.exceptions(std::ofstream::failbit);

    try
    {
        outStream << "P3\n" << xDim << ' ' << yDim << "\n255\n";
        for (size_t yIdx = 0U; yIdx < yDim; ++yIdx)
        {
            for (size_t xIdx = 0U; xIdx < xDim; ++xIdx)
            {
                size_t const imageIdx = (yIdx * xDim) + xIdx;
                for (size_t rgbIdx = 0U; rgbIdx < 3U; ++rgbIdx)
                {
                    auto const valAsFloat = image[imageIdx][rgbIdx];
                    auto const valAsUint = std::clamp(static_cast<unsigned int>(valAsFloat * 255.0F), 0U, 255U);
                    outStream << valAsUint
                              << (xIdx == (xDim - 1U) and rgbIdx == 2U ? '\n' : ' ');

                }
            }
            outStream << '\n';
        }
    }
    catch (std::ios_base::failure const &fail)
    {
        std::cout << "Exception thrown when writing to file: " << fail.what() << '\n';
        std::exit(EXIT_FAILURE);
    }
}

int main()
{
    // 2D color image
    // float color2D[256U][256U][4U] = { 0.0F };

    // TODO: add pre-integration table calculations

    // TODO: convert obtained array to an image

    // you can use writeImage function to save the image (as in the example) or
    // use any libraries (e.g. ImageMagick or OpenCV) you would like
    std::vector<std::array<float, 4U>> image;
    for (size_t yIdx = 0U; yIdx < 256U; ++yIdx)
        for (size_t xIdx = 0U; xIdx < 256U; ++xIdx)
            image.emplace_back(std::array<float, 4U>{static_cast<float>(yIdx) / 255.0F,
                                                     static_cast<float>(xIdx) / 255.0F,
                                                     static_cast<float>(255U - xIdx) / 255.0F,
                                                     255.0F});

    writeImage(image);

}
