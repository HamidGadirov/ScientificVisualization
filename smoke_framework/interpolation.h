#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <cmath>
#include <vector>

#include <QDebug>

namespace interpolation
{
    /* Input
     * values: You may assume this is of the type std::vector<float>. This contains the values (e.g. densities) to be interpolated.
     * sideSize: The input size of the square matrix "values". This is equal to m_DIM in the Simulation and Visualization classes.
     * xMax, yMax: The desired dimensions of the output vector. xMax is the horizontal size (number of columns), yMax is the vertical size (number of rows).
     *
     * Output
     * interpolatedValues: A 1D row-major container of std::vector<float> type containing the interpolated values.
     */
    template <typename inVector>
    std::vector<float> interpolateSquareVector(inVector const &values, size_t const sideSize, size_t const xMax, size_t const yMax)
    {
        std::vector<float> interpolatedValues;

        return interpolatedValues;
    }
};

#endif // INTERPOLATION_H
