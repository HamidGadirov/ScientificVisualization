#include "lic.h"

#include <QDebug>

#include <string>


Lic::Lic(unsigned int xDim, unsigned int yDim)
    :
      dim_x(xDim),
      dim_y(yDim)
{
    texture = std::vector<float>(dim_x * dim_y, 0.0F);

    boxFilterLUT_1 = std::vector<float>(); // Look-up-table filter
    boxFilterLUT_2 = std::vector<float>(); // Look-up-table filter
    texture = generateNoiseTexture(texture); // Generate original noise texture
    for (int i = 0; i < LUT_FILTER_SIZE; ++i)
    {
        boxFilterLUT_1.push_back(i);
        boxFilterLUT_2.push_back(i);
    }
    qDebug() << "LIC Constructed";
}

///		normalize the vector field     ///
void Lic::normalizeVectors(std::vector<float>* vectorField_x, std::vector<float>* vectorField_y)
{
}

///		make white noise as the LIC input texture     ///
std::vector<float> Lic::generateNoiseTexture(std::vector<float> texture)
{
    return texture;
}

std::vector<uint8_t> Lic::mapFlowToTexture(std::vector<float> vectorField_x, std::vector<float> vectorField_y, std::vector<float> texture_in)
{
  std::vector<uint8_t> newTexture(dim_x*dim_y);

    int vectorID;
    int advection_dir;
    int advection_steps;
    int maxAdvection_steps = int(LOWPASS_FILTER_LENGTH * 3);

    float vec_x;
    float vec_y;
    float clipPointX_0;
    float clipPointY_0;
    float clipPointX_1;
    float clipPointY_1;
    float samplePointX;
    float samplePointY;

    float textureValue;
    float accumulatedWeight;
    float sampleWeight;

    float tempLength;
    float segmentLength;
    float currentStreamlineLen;
    float previousStreamlineLen;
    float length_to_id = (LUT_FILTER_SIZE - 1) / LOWPASS_FILTER_LENGTH;

    std::vector<float> weightLUTSelection;

    float accumulated_texture[2];
    float accumulated_weights[2];

    return newTexture;
}

std::vector<uint8_t> Lic::updateTexture(std::vector<float> vectorField_x, std::vector<float> vectorField_y, std::vector<float> texture_in)
{
    //you shouldn't need to edit this!
  
    normalizeVectors(&vectorField_x, &vectorField_y);
    //qDebug() << "Normalized vector field";
    const std::vector<uint8_t> texture_out = mapFlowToTexture(vectorField_x, vectorField_y, texture_in);

    
    //qDebug() << "Mapped flow to texture";

    return texture_out;
}

std::vector<uint8_t> Lic::updateTexture(std::vector<float> vectorField_x, std::vector<float> vectorField_y, std::vector<float> texture_in, unsigned int newDim_x, unsigned int newDim_y)
{
    //you shouldn't need to edit this!

    int dims = newDim_x * newDim_y;
    if (dims != vectorField_x.size() || dims != vectorField_y.size())
    {
        qDebug() << "Dimension mismatch between LIC dimensions and incoming vector fields, aborting";
        std::vector<uint8_t> failed_texture;
        return failed_texture;
    }

    setXDim(newDim_x);
    setYDim(newDim_y);

    //texture = std::vector<float>(dim_x * dim_y, 0.0F);

    normalizeVectors(&vectorField_x, &vectorField_y);
    //qDebug() << "Normalized vector field";
    const std::vector<uint8_t> texture_out = mapFlowToTexture(vectorField_x, vectorField_y, texture_in);


    //qDebug() << "Mapped flow to texture";

    return texture_out;
}

void Lic::resetTexture()
{
    texture = generateNoiseTexture(texture);
}

void Lic::resetTexture(unsigned int newXDim, unsigned int newYDim)
{
    setXDim(newXDim);
    setYDim(newYDim);

    texture = std::vector<float>(dim_x * dim_y, 0.0F);

    texture = generateNoiseTexture(texture);
}
