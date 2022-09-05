#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_drawVolumeRenderingCheckBox_toggled(bool checked)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_drawVolumeRendering = checked;
}
