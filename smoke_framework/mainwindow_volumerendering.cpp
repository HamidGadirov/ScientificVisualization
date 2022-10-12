#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

#include <string>

void MainWindow::on_drawVolumeRenderingCheckBox_toggled(bool checked)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_drawVolumeRendering = checked;

    // Pause the smoke simulation while volume rendering
    visualizationPtr->m_isRunning = !checked;
}

void MainWindow::on_volumeRenderingFragmentShaderSelectionVolumenRenderingRadioButton_clicked()
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_volumeRenderFragShader = Visualization::VolumeRenderFragShader::VolumeRenderer;
}

void MainWindow::on_volumeRenderingFragmentShaderSelectionVolumetricLightingRadioButton_clicked()
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_volumeRenderFragShader = Visualization::VolumeRenderFragShader::VolumetricLighting;
}

void MainWindow::on_volumeRenderingFragmentShaderSelectionVolumeRenderingPreIntegrationRadioButton_clicked()
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_volumeRenderFragShader = Visualization::VolumeRenderFragShader::VolumeRendererPreIntegration;
}

void MainWindow::on_volumeRenderingFragmentShaderSelectionVolumeRenderingOverlayRenderingRadioButton_clicked()
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_volumeRenderFragShader = Visualization::VolumeRenderFragShader::VolumeRendererOverlayRendering;
}

void MainWindow::on_timeStepVolumeRenderingGroupBoxSpinBox_valueChanged(int arg1)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_volumeRenderingTimeStep = static_cast<size_t>(arg1);
    visualizationPtr->opengl_updateTexture();
}

void MainWindow::on_volumeRenderingSyntheticCubeRadioButton_toggled(bool checked)
{
    if (checked)
    {
        auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
        visualizationPtr->m_volumeRenderTexture = Visualization::VolumeRenderTexture::SyntheticCube;
        visualizationPtr->opengl_updateTextureSyntheticCube();
    }
}

void MainWindow::on_volumeRenderingSyntheticSceneRadioButton_toggled(bool checked)
{
    if (checked)
    {
        auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
        visualizationPtr->m_volumeRenderTexture = Visualization::VolumeRenderTexture::SyntheticScene;
        visualizationPtr->opengl_updateTextureSyntheticScene();
    }
}

void MainWindow::on_volumeRenderingDataRawRadioButton_toggled(bool checked)
{
    if (checked)
    {
        auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
        visualizationPtr->m_volumeRenderTexture = Visualization::VolumeRenderTexture::DataRaw;

        if (visualizationPtr->m_datFilePath.empty())
        {
            ui->volumeRenderingDataRawInfoLabel->setText("No .dat file selected");
        }
        else
        {
            ui->volumeRenderingDataRawInfoLabel->setText("Loaded " + QString::fromStdString(visualizationPtr->m_datFilePath));
            visualizationPtr->opengl_updateTextureLoadDataRawFromFile();
        }
    }
}

void MainWindow::on_volumeRenderingSelectDatFilePushButton_clicked()
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_datFilePath = QFileDialog::getOpenFileName(this, tr("Open .dat file"), "", tr("datraw file (*.dat)")).toStdString();

    if (!visualizationPtr->m_datFilePath.empty())
    {
        visualizationPtr->opengl_loadDataRawFromFile();
        ui->volumeRenderingDataRawRadioButton->click();
    }
}

void MainWindow::on_volumeRenderingPausePlayPushButton_clicked()
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_volumeRenderingTimeIsPaused = !visualizationPtr->m_volumeRenderingTimeIsPaused;
}
