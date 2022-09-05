#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_quantizationCheckBox_toggled(bool checked)
{
    auto const openGLWidgetPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    openGLWidgetPtr->m_useQuantization = checked;

    // When checked, send the current value of the spinbox to the backend by triggering it with
    // its current index.
    if (checked)
        on_quantizationBitsComboBox_currentIndexChanged(ui->quantizationBitsComboBox->currentIndex());
}

void MainWindow::on_quantizationBitsComboBox_currentIndexChanged(int index)
{
    auto const openGLWidgetPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    // Convert the index (0, 1, 2, 3, ..) into a power of two (1, 2, 4, 8, ..).
    // The corresponding numbers (as text) in the GUI's combobox are matched manually.
    openGLWidgetPtr->m_quantizationBits = 1U << static_cast<unsigned int>(index);
}

void MainWindow::on_gaussianBlurCheckBox_toggled(bool checked)
{
    auto const openGLWidgetPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    openGLWidgetPtr->m_useGaussianBlur = checked;
}

void MainWindow::on_gradientsCheckBox_toggled(bool checked)
{
    auto const openGLWidgetPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    openGLWidgetPtr->m_useGradients = checked;
}

void MainWindow::on_scalarDataslicingEnableCheckBox_toggled(bool checked)
{
    auto const openGLWidgetPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    openGLWidgetPtr->m_useSlicing = checked;
}

void MainWindow::on_scalarDataSlicingDirectionXRadioButton_toggled(bool checked)
{
    if (checked)
    {
        auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
        visualizationPtr->m_slicingDirection = Visualization::SlicingDirection::x;
    }
}

void MainWindow::on_scalarDataSlicingDirectionYRadioButton_toggled(bool checked)
{
    if (checked)
    {
        auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
        visualizationPtr->m_slicingDirection = Visualization::SlicingDirection::y;
    }
}

void MainWindow::on_scalarDataSlicingDirectionTRadioButton_toggled(bool checked)
{
    if (checked)
    {
        auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
        visualizationPtr->m_slicingDirection = Visualization::SlicingDirection::t;
    }
}

void MainWindow::on_scalarDataSlicingSliceIndexSpinBox_valueChanged(int arg1)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_sliceIdx = static_cast<size_t>(arg1);
}
