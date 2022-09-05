#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_drawLicCheckBox_toggled(bool checked)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_drawLIC = checked;
}
