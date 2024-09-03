#include "movingrange.h"

#include <algorithm>

MovingRange::MovingRange(size_t const windowSize, QVector2D const initialValue)
:
    m_windowSize(windowSize),
    m_initialValue(initialValue),
    m_range(initialValue)
{
    Q_ASSERT(m_windowSize > 0U);
    fillWindow();
}

void MovingRange::setWindowSize(size_t const windowSize)
{
    Q_ASSERT(windowSize > 0);
    m_windowSize = windowSize;
    m_range = m_initialValue;

    // Empty the queue.
    while (!m_window.empty())
        m_window.pop();

    fillWindow();
}

// Fills the moving range window with initial values.
void MovingRange::fillWindow()
{
    for (size_t n = 0U; n < m_windowSize; ++n)
        m_window.emplace(m_initialValue);
}

void MovingRange::update(QVector2D const newValue)
{
    // Update queue.
    m_window.pop();
    m_window.push(newValue);

    float min = newValue.x();
    float max = newValue.y();

    std::queue<QVector2D> tempQueue{m_window};
    while (!tempQueue.empty())
    {
        QVector2D const val =  tempQueue.front();
        min = std::min(min, val.x());
        max = std::max(max, val.y());
        tempQueue.pop();
    }

    m_range = QVector2D{min, max};
}

QVector2D MovingRange::range() const
{
    return m_range;
}

void MovingRange::printWindow() const
{
    qDebug() << "Printing queue:";
    std::queue<QVector2D> tempQueue{m_window};
    while (!tempQueue.empty())
    {
        qDebug() << tempQueue.front();
        tempQueue.pop();
    }
}
