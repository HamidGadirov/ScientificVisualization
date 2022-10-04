#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>

void MainWindow::on_simulationShowMinMaxDataCheckBox_toggled(bool checked)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_sendMinMaxToUI = checked;
}

void MainWindow::on_densitySlider_valueChanged(int value)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_simulation.setRhoInjected(static_cast<float>(value) / 10.0F);
}

void MainWindow::on_densitySpinBox_valueChanged(double value)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_simulation.setRhoInjected(static_cast<float>(value));
}

void MainWindow::on_viscositySlider_valueChanged(int value)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_simulation.setViscosity(static_cast<float>(value) / (10.0F * 1000.0F));
}

void MainWindow::on_viscositySpinBox_valueChanged(double value)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_simulation.setViscosity(static_cast<float>(value) / 1000.0F);
}

void MainWindow::on_timestepSlider_valueChanged(int value)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr ->m_simulation.setDt(static_cast<float>(value) / 10.0F);
}

void MainWindow::on_timestepSpinBox_valueChanged(double value)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr ->m_simulation.setDt(static_cast<float>(value));
}

void MainWindow::on_simulationPausePlayPushButton_clicked()
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_isRunning = !(visualizationPtr->m_isRunning);
}

void MainWindow::on_gridpointsSpinBox_valueChanged(int value)
{
    if (value % 2 == 0)
    {
        auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
        visualizationPtr->setDIM(static_cast<size_t>(value));

        ui->scalarDataSlicingSliceIndexHorizontalSlider->setMaximum(value - 1);
        ui->scalarDataSlicingSliceIndexSpinBox->setMaximum(value - 1);
    }
    else
        qDebug() << "Size must be a multiple of 2";
}
