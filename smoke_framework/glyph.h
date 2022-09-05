#ifndef GLYPH_H
#define GLYPH_H

#include <QVector3D>

#include <utility>
#include <vector>

class Glyph
{
public:
    enum class GlyphType
    {
        Hedgehog,
        Triangle,
        Arrow2D,
        Cone,
        Arrow3D
    };

    static std::pair<std::vector<QVector3D>, std::vector<unsigned short>> hedgehog();
    static std::pair<std::vector<QVector3D>, std::vector<unsigned short>> triangle(float const width);
    static std::pair<std::vector<QVector3D>, std::vector<unsigned short>> arrow2D(float const lineWidth, float const lineHeight, float const triangleWidth);
    static std::pair<std::vector<QVector3D>, std::vector<unsigned short>> cone(float const coneWidth, size_t const numberOfVerticesOnCircle);
    static std::pair<std::vector<QVector3D>, std::vector<unsigned short>> arrow3D(float const cylinderWidth, float const cylinderHeight, float const coneWidth, size_t const numberOfVerticesOnCircle);
};

#endif // GLYPH_H
