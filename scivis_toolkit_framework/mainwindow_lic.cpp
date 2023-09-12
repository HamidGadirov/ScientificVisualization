#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_drawLicCheckBox_toggled(bool checked)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_drawLIC = checked;
}

void MainWindow::on_LICNoiseTextureGenerateNewPushButton_clicked()
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->opengl_generateAndLoadLicNoiseTexture();
}

void MainWindow::on_LICStreamlineLengthSpinBox_valueChanged(int arg1)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_licStreamlineLength = arg1;

}

void MainWindow::on_LICStepSizeFactorDoubleSpinBox_valueChanged(double arg1)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->setLicStepSize(static_cast<float>(arg1));

    ui->LICStepSizeFactorHorizontalSlider->setValue(arg1 * 100.0);
}

void MainWindow::on_LICStepSizeFactorHorizontalSlider_valueChanged(int value)
{
    ui->LICStepSizeFactorDoubleSpinBox->setValue(static_cast<double>(value / 100.0));
}
