#include "lic.h"

Lic::Lic()
{
    // Setup and seed the random number generator
    std::random_device rd;
    m_generator = std::mt19937(rd());
    m_distribution = std::uniform_real_distribution<float>{0.0F, 1.0F};
}

std::vector<float> Lic::noiseTexture(int const dimX, int const dimY)
{
    std::vector<float> noiseTexture;
    noiseTexture.reserve(dimX * dimY);

    for (int i = 0; i < dimX * dimY; ++i)
        noiseTexture.push_back(m_distribution(m_generator));

    return noiseTexture;
}
