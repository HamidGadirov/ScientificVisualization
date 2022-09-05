#ifndef LIC_H
#define LIC_H

#include <cmath>
#include <cstdint>
#include <vector>

class Lic
{
    int const LUT_FILTER_SIZE = 2048;
    float const LOWPASS_FILTER_LENGTH = 10.00000F;

public:
    Lic(unsigned int xDim, unsigned int yDim);

    void setXDim(unsigned int newXDim) { dim_x = newXDim; }
    void setYDim(unsigned int newYDim) { dim_y = newYDim; }

    [[nodiscard]] unsigned int getXDim() const { return dim_x; }
    [[nodiscard]] unsigned int getYDim() const { return dim_y; }
    [[nodiscard]] std::vector<float> getTexture() const { return texture; }

    std::vector<uint8_t> updateTexture(std::vector<float> vectorField_x, std::vector<float> vectorField_y, std::vector<float> texture_in); // Goes through the process of updating the noise texture, returns a vector<float> containing values that make up an updated texture
    std::vector<uint8_t> updateTexture(std::vector<float> vectorField_x, std::vector<float> vectorField_y, std::vector<float> texture_in, unsigned int newDim_x, unsigned int newDim_y); //same as above, but also sets dim_x and dim_y to new values before doing so, and asserts that the incoming vector field is of a matching size.
    void resetTexture(); // resets noise texture to pure random - use if you need to refresh the noise texture
    void resetTexture(unsigned int newXDim, unsigned int newYDim);

private:
    unsigned int dim_x, dim_y;

    int testing_iterator = 0;

    std::vector<float> texture; // texture stored and updated locally
    std::vector<float> boxFilterLUT_1;
    std::vector<float> boxFilterLUT_2;

    std::vector<float> generateNoiseTexture(std::vector<float> texture);

    //Functions to edit:
    void normalizeVectors(std::vector<float>* vectorField_x, std::vector<float>* vectorField_y);
    std::vector<uint8_t> mapFlowToTexture(std::vector<float> vectorField_x, std::vector<float> vectorField_y, std::vector<float> texture_in);

};

#endif // LIC_H
