#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_showHeightplotCheckBox_toggled(bool checked)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_drawHeightplot = checked;
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
    ui->heightplotViewRotateX->setValue(visualizationPtr->m_rotationDefault.x());
    ui->heightplotViewRotateY->setValue(visualizationPtr->m_rotationDefault.y());
    ui->heightplotViewRotateZ->setValue(visualizationPtr->m_rotationDefault.z());
}
