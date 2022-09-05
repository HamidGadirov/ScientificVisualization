#include "glyph.h"

#include "constants.h"

#include <cmath>

std::pair<std::vector<QVector3D>, std::vector<unsigned short>> Glyph::hedgehog()
{
    std::vector<QVector3D> hedgehog;
    hedgehog.reserve(2U);

    hedgehog.emplace_back(0.0F, 0.0F, 0.0F);
    hedgehog.emplace_back(0.0F, 1.0F, 0.0F);

    std::vector<unsigned short> const indices = {0U, 1U};

    return make_pair(hedgehog, indices);
}

std::pair<std::vector<QVector3D>, std::vector<unsigned short>> Glyph::triangle(float const width)
{
   std::vector<QVector3D> triangle;
   triangle.reserve(3);

   triangle.emplace_back(-width / 2.0F, 0.0F, 0.0F);
   triangle.emplace_back( width / 2.0F, 0.0F, 0.0F);
   triangle.emplace_back(         0.0F, 1.0F, 0.0F);

   std::vector<unsigned short> const indices = {0U, 1U, 2U};

   return make_pair(triangle, indices);
}

std::pair<std::vector<QVector3D>, std::vector<unsigned short>> Glyph::arrow2D(float const lineWidth, float const lineHeight, float const triangleWidth)
{
    std::vector<QVector3D> arrow2D;
    arrow2D.reserve(3 * 3);

    arrow2D.emplace_back(-lineWidth / 2.0F, 0.0F,       0.0F);
    arrow2D.emplace_back( lineWidth / 2.0F, 0.0F,       0.0F);
    arrow2D.emplace_back(-lineWidth / 2.0F, lineHeight, 0.0F);
    arrow2D.emplace_back( lineWidth / 2.0F, lineHeight, 0.0F);

    arrow2D.emplace_back(-triangleWidth / 2.0F, lineHeight, 0.0F);
    arrow2D.emplace_back( triangleWidth / 2.0F, lineHeight, 0.0F);
    arrow2D.emplace_back(                 0.0F, 1.0F,       0.0F);

    std::vector<unsigned short> const indices = {0U, 1U, 2U, 3U, 3U, 4U, 5U, 6U};

    return make_pair(arrow2D, indices);
}

std::pair<std::vector<QVector3D>, std::vector<unsigned short>> Glyph::cone(float const coneWidth, size_t const numberOfVerticesOnCircle)
{
    std::vector<QVector3D> cone;

    float const deltaT = (2.0F * constants::pi) / static_cast<float>(numberOfVerticesOnCircle);

    cone.emplace_back(0.0F, 0.0F, 0.0F); // origin, has index 0

    for (size_t tIdx = 0U; tIdx < numberOfVerticesOnCircle; ++tIdx)
    {
        float const circleT = 0.0F + (static_cast<float>(tIdx) * deltaT);
        float const x = std::cos(circleT) * coneWidth / 2.0F;
        float const z = std::sin(circleT) * coneWidth / 2.0F;
        cone.emplace_back(x, 0.0F, z);
    }

    cone.emplace_back(0.0F, 1.0F, 0.0F); // end, has index numberOfVerticesOnCircle + 1

    // fill vector with indices for indexed drawing
    std::vector<unsigned short> indices;
    indices.reserve(6U * numberOfVerticesOnCircle);

    // bottom of cone
    auto previousIdx = static_cast<unsigned short>(numberOfVerticesOnCircle);
    for (unsigned short idx = 1U; idx <= numberOfVerticesOnCircle; ++idx)
    {
        indices.push_back(previousIdx);
        indices.push_back(0U);
        indices.push_back(idx);
        previousIdx = idx;
    }

    // pointy part of cone
    previousIdx = static_cast<unsigned short>(numberOfVerticesOnCircle);
    for (unsigned short idx = 1U; idx <= numberOfVerticesOnCircle; ++idx)
    {
        indices.push_back(previousIdx);
        indices.push_back(static_cast<unsigned short>(numberOfVerticesOnCircle) + 1U);
        indices.push_back(idx);
        previousIdx = idx;
    }

    return make_pair(cone, indices);
}

std::pair<std::vector<QVector3D>, std::vector<unsigned short>> Glyph::arrow3D(float const cylinderWidth, float const cylinderHeight, float const coneWidth, size_t const numberOfVerticesOnCircle)
{
    std::vector<QVector3D> arrow3D;

    float const deltaT = (2.0F * constants::pi) / static_cast<float>(numberOfVerticesOnCircle);

    arrow3D.emplace_back(0.0F, 0.0F, 0.0F); // origin of cylinder, idx = 0
    unsigned short numberOfVerticesCylinder = 1U;
    for (size_t tIdx = 0; tIdx < numberOfVerticesOnCircle; ++tIdx)
    {
        float const circleT = 0.0F + (static_cast<float>(tIdx) * deltaT);
        float const x = std::cos(circleT) * cylinderWidth / 2.0F;
        float const z = std::sin(circleT) * cylinderWidth / 2.0F;
        arrow3D.emplace_back(x, 0.0F, z);                        // idx = 2 * tIdx
        arrow3D.emplace_back(x, cylinderHeight, z);             // idx = 2 * tIdx + 1
        numberOfVerticesCylinder += 2U;
    }

    arrow3D.emplace_back(0.0F, cylinderHeight, 0.0F); // origin of cone, idx = 2 * numberOfVerticesOnCircle
    unsigned short numberOfVerticesCone = 1U;
    for (size_t tIdx = 0; tIdx < numberOfVerticesOnCircle; ++tIdx)
    {
        float const circleT = 0.0F + (static_cast<float>(tIdx) * deltaT);
        float const x = std::cos(circleT) * coneWidth / 2.0F;
        float const z = std::sin(circleT) * coneWidth / 2.0F;
        arrow3D.emplace_back(x, cylinderHeight, z);
        ++numberOfVerticesCone;
    }

    arrow3D.emplace_back(0.0F, 1.0F, 0.0F); // end of cone
    ++numberOfVerticesCone;

    // fill vector with indices for indexed drawing
    std::vector<unsigned short> indices;

    // bottom of cylinder
    unsigned short previousIdx = numberOfVerticesCylinder - 2U;
    for (unsigned short idx = 1U; idx < numberOfVerticesCylinder; idx += 2U)
    {
        indices.push_back(previousIdx);
        indices.push_back(0);
        indices.push_back(idx);
        previousIdx = idx;
    }

    // pipe of cylinder
    previousIdx = 1U;
    unsigned short previousIdx2 = 2U;
    for (unsigned short idx = 3U; idx <= numberOfVerticesCylinder; ++idx)
    {
        indices.push_back(previousIdx);
        indices.push_back(previousIdx2);
        indices.push_back(idx);
        previousIdx = previousIdx2;
        previousIdx2 = idx;
    }

    // bottom of cone
    unsigned short startIdx = numberOfVerticesCylinder; // idx of origin of cone
    unsigned short finalIdx = numberOfVerticesCylinder + numberOfVerticesCone - 1U;
    previousIdx = finalIdx - 1U;
    for (unsigned short idx = startIdx + 1U; idx < finalIdx; ++idx)
    {
        indices.push_back(previousIdx);
        indices.push_back(startIdx);
        indices.push_back(idx);
        previousIdx = idx;
    }

    // pointy part of cone
    previousIdx = finalIdx - 1U;
    for (unsigned short idx = startIdx + 1U; idx < finalIdx; ++idx)
    {
        indices.push_back(previousIdx);
        indices.push_back(finalIdx);
        indices.push_back(idx);
        previousIdx = idx;
    }

    return make_pair(arrow3D, indices);
}
