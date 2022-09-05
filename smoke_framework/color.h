#ifndef COLOR_H
#define COLOR_H

struct Color
{
    float r, g, b;

    Color operator+(Color const other) const
    {
        return {r + other.r,
                g + other.g,
                b + other.b};
    }

    Color operator*(float const scalar) const
    {
        return {r * scalar,
                g * scalar,
                b * scalar};
    }
};

#endif // COLOR_H
