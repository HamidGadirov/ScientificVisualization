#ifndef MOVINGRANGE_H
#define MOVINGRANGE_H

#include <QDebug>
#include <QVector2D>

#include <cstddef>
#include <queue>

class MovingRange
{
    size_t m_windowSize;
    QVector2D const m_initialValue;

    std::queue<QVector2D> m_window;
    QVector2D m_range;

    void fillWindow();

public:
    MovingRange(size_t const windowSize, QVector2D const initialValue);

    void update(QVector2D const newValue);
    [[nodiscard]] QVector2D range() const;

    void setWindowSize(size_t const windowSize);

    void printWindow() const;
};

#endif // MOVINGRANGE_H
