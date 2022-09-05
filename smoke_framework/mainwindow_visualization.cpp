#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_visualizationProjectionOrthographicRadioButton_toggled(bool checked)
{
    if (checked)
    {
        auto const openGLWidgetPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
        openGLWidgetPtr->setProjectionType(Visualization::ProjectionType::Orthographic);
    }
}

void MainWindow::on_visualizationProjectionPerspectiveRadioButton_toggled(bool checked)
{
    if (checked)
    {
        auto const openGLWidgetPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
        openGLWidgetPtr->setProjectionType(Visualization::ProjectionType::Perspective);
    }
}
