#ifndef MOVINGAVERAGE_H
#define MOVINGAVERAGE_H

#include <QDebug>

#include <cstddef>
#include <queue>

template <typename T>
class MovingAverage
{
    size_t m_windowSize;
    T const m_initialValue;

    std::queue<T> m_window;
    T m_average;

    void fillWindow();

public:
    MovingAverage(size_t const windowSize, T const &initialValue);

    void update(T const &newValue);
    T average() const;

    void setWindowSize(size_t const windowSize);

    void printWindow() const;
};

template <typename T>
MovingAverage<T>::MovingAverage(size_t const windowSize, T const &initialValue)
:
    m_windowSize(windowSize),
    m_initialValue(initialValue),
    m_average(initialValue)
{
    Q_ASSERT(m_windowSize > 0U);
    fillWindow();
}

template <typename T>
void MovingAverage<T>::setWindowSize(size_t const windowSize)
{
    Q_ASSERT(windowSize > 0);
    m_windowSize = windowSize;
    m_average = m_initialValue;

    // Empty the queue.
    while (!m_window.empty())
        m_window.pop();

    fillWindow();
}

// Fills the moving average window with initial values.
template <typename T>
void MovingAverage<T>::fillWindow()
{
    for (size_t n = 0U; n < m_windowSize; ++n)
        m_window.emplace(m_initialValue);
}

template <typename T>
void MovingAverage<T>::update(T const &newValue)
{
    // Compute new averages.
    m_average -= m_window.front();
    m_average += newValue;

    // Update queue.
    m_window.pop();
    m_window.push(newValue);
}

template <typename T>
T MovingAverage<T>::average() const
{
    return m_average / m_windowSize;
}

template <typename T>
void MovingAverage<T>::printWindow() const
{
    qDebug() << "Printing queue:";
    std::queue<T> tempQueue{m_window};
    while (!tempQueue.empty())
    {
        qDebug() << tempQueue.front();
        tempQueue.pop();
    }
}

#endif // MOVINGAVERAGE_H
