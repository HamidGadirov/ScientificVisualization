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
        case 0:
            visualizationPtr->m_currentHeightplotDataType = ScalarDataType::Density;
        break;

        case 1:
            visualizationPtr->m_currentHeightplotDataType = ScalarDataType::VelocityMagnitude;
        break;

        case 2:
            visualizationPtr->m_currentHeightplotDataType = ScalarDataType::ForceFieldMagnitude;
        break;

        case 3:
            visualizationPtr->m_currentHeightplotDataType = ScalarDataType::VelocityDivergence;
        break;

        case 4:
            visualizationPtr->m_currentHeightplotDataType = ScalarDataType::ForceFieldDivergence;
        break;
    }
}

// Heightplot, rotate view along X-axis.
void MainWindow::on_heightplotViewRotateX_valueChanged(int value)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_rotation = {static_cast<float>(value),
                                    visualizationPtr->m_rotation.y(),
                                    visualizationPtr->m_rotation.z()};
    visualizationPtr->opengl_rotateView();
}

// Heightplot, rotate view along Y-axis.
void MainWindow::on_heightplotViewRotateY_valueChanged(int value)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_rotation = {visualizationPtr->m_rotation.x(),
                                    static_cast<float>(value),
                                    visualizationPtr->m_rotation.z()};
    visualizationPtr->opengl_rotateView();
}

// Heightplot, rotate view along Z-axis.
void MainWindow::on_heightplotViewRotateZ_valueChanged(int value)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_rotation = {visualizationPtr->m_rotation.x(),
                                    visualizationPtr->m_rotation.y(),
                                    static_cast<float>(value)};
    visualizationPtr->opengl_rotateView();
}

// Heightplot, reset rotation.
void MainWindow::on_heightplotResetRotation_clicked()
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_rotation = {0.0F, 0.0F, 0.0F};
    visualizationPtr->opengl_rotateView();
}
