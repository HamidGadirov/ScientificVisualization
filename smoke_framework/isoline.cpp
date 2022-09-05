#include "isoline.h"

#include <QDebug>

Isoline::Isoline(std::vector<float> const &values,
                 size_t const DIM,
                 float const isolineRho,
                 float const cellSideLength,
                 InterpolationMethod const interpolationMethod,
                 AmbiguousCaseDecider const ambiguousCaseDecider)
:
    m_values(values),
    m_DIM(DIM),
    m_isolineRho(isolineRho),
    m_cellSideLength(cellSideLength),
    m_ambiguousCaseDecider(ambiguousCaseDecider)
{

}

std::vector<QVector2D> Isoline::vertices() const
{
    return m_vertices;
}
