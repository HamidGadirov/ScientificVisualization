#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>

void MainWindow::on_isolinesDrawIsolinesCheckBox_toggled(bool checked)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_drawIsolines = checked;
}

void MainWindow::on_isolinesColorPickerButton_clicked()
{
    QColor const colorFromUI = QColorDialog::getColor(Qt::yellow, this);
    if (colorFromUI.isValid())
    {
        auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
        visualizationPtr->m_isolineColor = {static_cast<float>(colorFromUI.redF()),
                                            static_cast<float>(colorFromUI.greenF()),
                                            static_cast<float>(colorFromUI.blueF())};
    }
    else
        qDebug() << "Color dialog did not return a valid color.";
}

void MainWindow::on_isolinesUseCurrentScalarDataCheckBox_toggled(bool checked)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_manuallyChooseIsolineDataType = !checked;
}

void MainWindow::on_isolinesDataComboBox_currentIndexChanged(int index)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");

    switch (index)
    {
        case 0: visualizationPtr->m_currentIsolineDataType = ScalarDataType::Density; break;
        case 1: visualizationPtr->m_currentIsolineDataType = ScalarDataType::VelocityMagnitude; break;
        case 2: visualizationPtr->m_currentIsolineDataType = ScalarDataType::ForceFieldMagnitude; break;
        case 3: visualizationPtr->m_currentIsolineDataType = ScalarDataType::VelocityDivergence; break;
        case 4: visualizationPtr->m_currentIsolineDataType = ScalarDataType::ForceFieldDivergence; break;
    }
}

void MainWindow::on_isolinesNumberOfIsolinesSpinBox_valueChanged(int value)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_numberOfIsolines = static_cast<size_t>(value);
}

void MainWindow::on_isolinesRangeRhoMinSpinBox_valueChanged(double value)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_isolineMinValue = static_cast<float>(value);

    ui->isolinesRangeRhoMinSlider->setValue(static_cast<int>(value * 10.0));
}

void MainWindow::on_isolinesRangeRhoMaxSpinBox_valueChanged(double value)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_isolineMaxValue = static_cast<float>(value);

    ui->isolinesRangeRhoMaxSlider->setValue(static_cast<int>(value * 10.0));
}

void MainWindow::on_isolinesRangeRhoMinSlider_valueChanged(int value)
{
    ui->isolinesRangeRhoMinSpinBox->setValue(static_cast<double>(value / 10.0));
}

void MainWindow::on_isolinesRangeRhoMaxSlider_valueChanged(int value)
{
    ui->isolinesRangeRhoMaxSpinBox->setValue(static_cast<double>(value / 10.0));
}

void MainWindow::on_isolinesInterpolationMethodLinearRadioButton_toggled(bool checked)
{
    if (checked)
    {
        auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
        visualizationPtr->m_isolinesInterpolationMethod = Visualization::IsolinesInterpolationMethod::Linear;
    }
}

void MainWindow::on_isolinesInterpolationMethodNoneRadioButton_toggled(bool checked)
{
    if (checked)
    {
        auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
        visualizationPtr->m_isolinesInterpolationMethod = Visualization::IsolinesInterpolationMethod::None;
    }
}

void MainWindow::on_isolinesAmbiguousCaseDeciderMidpointRadioButton_toggled(bool checked)
{
    if (checked)
    {
        auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
        visualizationPtr->m_isolinesAmbiguousCaseDecider = Visualization::IsolinesAmbiguousCaseDecider::Midpoint;
    }
}

void MainWindow::on_isolinesAmbiguousCaseDeciderAsymptoticRadioButton_toggled(bool checked)
{
    if (checked)
    {
        auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
        visualizationPtr->m_isolinesAmbiguousCaseDecider = Visualization::IsolinesAmbiguousCaseDecider::Asymptotic;
    }
}
