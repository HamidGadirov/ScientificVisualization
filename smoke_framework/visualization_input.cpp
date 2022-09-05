#include "visualization.h"

#include <QDebug>
#include <QMouseEvent>

void Visualization::mouseMoveEvent(QMouseEvent *ev)
{
    // The mx, my coordinates are given from the UI with (0,0) at top left.
    // Here (0,0) is converted to bottom left, as the Visualization requires it.
    int const mx = ev->x();
    int const my = height() - ev->y();

    input_drag(mx, my);
}

// drag: When the user drags with the mouse, add a force that corresponds to the direction of the mouse
//       cursor movement. Also inject some new matter into the field at the mouse location.
void Visualization::input_drag(int const mx, int my)
{
    // Remembers last mouse location.
    static int lmx = 0;
    static int lmy = 0;

    // Compute the array index that corresponds to the cursor location.
    // X ranges from 0 (left) to m_DIM (right)
    // Y ranges from 0 (bottom) to m_DIM (top)
    auto X = static_cast<size_t>(std::floor(static_cast<float>(m_DIM + 1) * (static_cast<float>(mx) / static_cast<float>(width()))));
    auto Y = static_cast<size_t>(std::floor(static_cast<float>(m_DIM + 1) * (static_cast<float>(my) / static_cast<float>(height()))));
    X = std::clamp(X, static_cast<size_t>(0), m_DIM - 1);
    Y = std::clamp(Y, static_cast<size_t>(0), m_DIM - 1);

    // Add force at the cursor location.
    float dx = mx - lmx;
    float dy = my - lmy;
    float const length = std::sqrt(std::pow(dx, 2.0F) + std::pow(dy, 2.0F));

    if (length != 0.0F)
    {
        dx *= 0.1F / length;
        dy *= 0.1F / length;
    }

    size_t const idx = X + Y * m_DIM;

    m_simulation.setFx(idx, m_simulation.fx(idx) + dx);
    m_simulation.setFy(idx, m_simulation.fy(idx) + dy);
    m_simulation.setRho(idx, m_simulation.rhoInjected());

    // Store the current mouse position as the previous mouse position.
    lmx = mx;
    lmy = my;
}
