#ifndef ISOLINE_H
#define ISOLINE_H

#include <QVector2D>

#include <array>
#include <functional>
#include <optional>
#include <vector>

using namespace std::placeholders;

class Isoline
{

public:
    enum class AmbiguousCaseDecider
    {
        Midpoint,
        Asymptotic
    };

private:
    std::vector<QVector2D> m_vertices;
    std::vector<float> m_values;
    size_t const m_DIM;
    float const m_isolineRho;
    float const m_cellSideLength;
    QVector2D const m_vertex0;
    Isoline::AmbiguousCaseDecider const m_ambiguousCaseDecider;

public:
    enum class InterpolationMethod
    {
        Linear,
        None
    };

    Isoline(std::vector<float> const &values,
            size_t const valuesSideSize,
            float const isolineRho,
            float const cellSideLength,
            InterpolationMethod const interpolationMethod,
            AmbiguousCaseDecider const ACG);

    std::vector<QVector2D> vertices() const;
};

#endif // ISOLINE_H
