#ifndef DATATYPE_H
#define DATATYPE_H

enum class ScalarDataType
{
    Density,
    VelocityMagnitude,
    ForceFieldMagnitude,
    VelocityDivergence,
    ForceFieldDivergence
};

enum class VectorDataType
{
    Velocity,
    ForceField
};

#endif // DATATYPE_H
