#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_showHeightPlotCheckBox_toggled(bool checked)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_drawHeightplot = checked;

    // The height plot is the only visualization that uses the depth test.
    visualizationPtr->makeCurrent();

    if (checked)
        glEnable(GL_DEPTH_TEST);
    else
        glDisable(GL_DEPTH_TEST);
}

void MainWindow::on_heightplotDataTypeComboBox_currentIndexChanged(int index)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");

    switch (index)
    {
        case 0: visualizationPtr->m_currentHeightplotDataType = ScalarDataType::Density; break;
        case 1: visualizationPtr->m_currentHeightplotDataType = ScalarDataType::VelocityMagnitude; break;
        case 2: visualizationPtr->m_currentHeightplotDataType = ScalarDataType::ForceFieldMagnitude; break;
        case 3: visualizationPtr->m_currentHeightplotDataType = ScalarDataType::VelocityDivergence; break;
        case 4: visualizationPtr->m_currentHeightplotDataType = ScalarDataType::ForceFieldDivergence; break;
    }
}

void MainWindow::on_heightPlotMaterialConstantsKADoubleSpinBox_valueChanged(double arg1)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_materialConstants.setX(static_cast<float>(arg1));
}

void MainWindow::on_heightPlotMaterialConstantsKDDoubleSpinBox_valueChanged(double arg1)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_materialConstants.setY(static_cast<float>(arg1));
}

void MainWindow::on_heightPlotMaterialConstantsKSDoubleSpinBox_valueChanged(double arg1)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_materialConstants.setZ(static_cast<float>(arg1));
}

void MainWindow::on_heightPlotMaterialConstantsAlphaDoubleSpinBox_valueChanged(double arg1)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_materialConstants.setW(static_cast<float>(arg1));
}

void MainWindow::on_heightPlotLightPositionXDoubleSpinBox_valueChanged(double arg1)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_lightPosition.setX(static_cast<float>(arg1));
}

void MainWindow::on_heightPlotLightPositionYDoubleSpinBox_valueChanged(double arg1)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_lightPosition.setY(static_cast<float>(arg1));
}

void MainWindow::on_heightPlotLightPositionZDoubleSpinBox_valueChanged(double arg1)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_lightPosition.setZ(static_cast<float>(arg1));
}

void MainWindow::on_heightplotViewRotateX_valueChanged(int value)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_rotation.setX(static_cast<float>(value));
    visualizationPtr->opengl_rotateView();
}

void MainWindow::on_heightplotViewRotateY_valueChanged(int value)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_rotation.setY(static_cast<float>(value));
    visualizationPtr->opengl_rotateView();
}

void MainWindow::on_heightplotViewRotateZ_valueChanged(int value)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_rotation.setZ(static_cast<float>(value));
    visualizationPtr->opengl_rotateView();
}

void MainWindow::on_heightplotResetRotation_clicked()
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_rotation = visualizationPtr->m_rotationDefault;
    visualizationPtr->opengl_rotateView();

    // Reset the dials in the GUI
    ui->heightplotViewRotateX->setValue(static_cast<int>(visualizationPtr->m_rotationDefault.x()));
    ui->heightplotViewRotateY->setValue(static_cast<int>(visualizationPtr->m_rotationDefault.y()));
    ui->heightplotViewRotateZ->setValue(static_cast<int>(visualizationPtr->m_rotationDefault.z()));
}
