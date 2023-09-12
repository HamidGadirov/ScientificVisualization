#ifndef LIC_H
#define LIC_H

#include <random>
#include <vector>

class Lic
{
    std::mt19937 m_generator;
    std::uniform_real_distribution<float> m_distribution;

public:
    Lic();

    std::vector<float> noiseTexture(int const dimX, int const dimY);
};

#endif // LIC_H
