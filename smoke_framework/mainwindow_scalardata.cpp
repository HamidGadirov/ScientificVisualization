#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>

// Scalar data, general functions.
void MainWindow::updateScalarDataColorMapGlobally() const
{
    std::vector<Color> const colorMapToUse = enumToColorMap(m_scalarDataColorMap, m_numberOfColorsScalarData);

    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->opengl_loadScalarDataTexture(colorMapToUse);

    // The visualization class needs to load different shader programs based on this boolean
    visualizationPtr->m_useCustomColorMap = m_scalarDataColorMap == ColorMap::Custom3Color;

    auto const scalarDataLegendPtr = findChildSafe<Legend*>("legendScalarDataOpenGLWidget");
    scalarDataLegendPtr->updateColorMap(colorMapToUse);
}


// Scalar data, draw on/off.
void MainWindow::on_scalarDataDrawScalarDataCheckBox_toggled(bool checked)
{
    auto const openGLWidgetPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    openGLWidgetPtr->m_drawScalarData = checked;
}

// Scalar data, data type.
void MainWindow::on_scalarDataComboBox_currentIndexChanged(int index)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");

    switch (index)
    {
        case 0:
            visualizationPtr->m_currentScalarDataType = ScalarDataType::Density;
        break;

        case 1:
            visualizationPtr->m_currentScalarDataType = ScalarDataType::VelocityMagnitude;
        break;

        case 2:
            visualizationPtr->m_currentScalarDataType = ScalarDataType::ForceFieldMagnitude;
        break;

        case 3:
            visualizationPtr->m_currentScalarDataType = ScalarDataType::VelocityDivergence;
        break;

        case 4:
            visualizationPtr->m_currentScalarDataType = ScalarDataType::ForceFieldDivergence;
        break;
    }
}


// Scalar data, color map.
void MainWindow::on_scalarDataColorMapComboBox_currentIndexChanged(int index)
{
    switch (index)
    {
        case 0:
            m_scalarDataColorMap = ColorMap::Grayscale;
            ui->scalarDataColorMapNumberOfColorsSlider->setDisabled(false);
            ui->scalarDataColorMapNumberOfColorsSpinBox->setDisabled(false);
        break;

        case 1:
            m_scalarDataColorMap = ColorMap::Rainbow;
            ui->scalarDataColorMapNumberOfColorsSlider->setDisabled(false);
            ui->scalarDataColorMapNumberOfColorsSpinBox->setDisabled(false);
        break;

        case 2:
            m_scalarDataColorMap = ColorMap::HeatMap;
            ui->scalarDataColorMapNumberOfColorsSlider->setDisabled(false);
            ui->scalarDataColorMapNumberOfColorsSpinBox->setDisabled(false);
        break;

        case 3:
            m_scalarDataColorMap = ColorMap::BlueYellow;
            ui->scalarDataColorMapNumberOfColorsSlider->setDisabled(false);
            ui->scalarDataColorMapNumberOfColorsSpinBox->setDisabled(false);
        break;

        case 4:
            m_scalarDataColorMap = ColorMap::Custom3Color;
            ui->scalarDataColorMapNumberOfColorsSlider->setValue(3);
            ui->scalarDataColorMapNumberOfColorsSlider->setDisabled(true);
            ui->scalarDataColorMapNumberOfColorsSpinBox->setDisabled(true);
        break;
    }

    updateScalarDataColorMapGlobally();
}

void MainWindow::on_scalarDataColorMapNumberOfColorsSpinBox_valueChanged(int value)
{
    m_numberOfColorsScalarData = static_cast<size_t>(value);
    updateScalarDataColorMapGlobally();
}

void MainWindow::on_scalarDataCustomColorPickerPushButton_clicked()
{
    size_t const colorIdx = static_cast<size_t>(ui->scalarDataCustomColorSpinBox->value());
    Q_ASSERT(colorIdx <= 2U);

    auto const selectedColorPtr = &findChildSafe<Visualization*>("visualizationOpenGLWidget")->m_customColors[colorIdx];

    QColor previousColor;
    previousColor.setRgbF(selectedColorPtr->r, selectedColorPtr->g, selectedColorPtr->b);

    QColor const colorFromUI = QColorDialog::getColor(previousColor, this);
    if (colorFromUI.isValid())
    {
        Color const customColor{static_cast<float>(colorFromUI.redF()),
                                static_cast<float>(colorFromUI.greenF()),
                                static_cast<float>(colorFromUI.blueF())};
	
        *selectedColorPtr = customColor;
        updateScalarDataColorMapGlobally();
    }
    else
        qDebug() << "Color dialog did not return a valid color.";
}

// Scalar data, mapping type.
void MainWindow::on_scalarDataMappingMappingTypeScalingRadioButton_toggled(bool checked)
{
    if (checked)
    {
        auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
        visualizationPtr->m_currentMappingType = Visualization::MappingType::Scaling;
    }
}

void MainWindow::on_scalarDataMappingMappingTypeClampingRadioButton_toggled(bool checked)
{
    if (checked)
    {
        auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
        visualizationPtr->m_currentMappingType = Visualization::MappingType::Clamping;
    }
}


// Scalar data, mapping, scaling.
void MainWindow::on_scalarDataMappingScalingMovingAverageWindowSpinBox_valueChanged(int arg1)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_minMaxDensity.setWindowSize(static_cast<size_t>(arg1));
}


// Scalar data, mapping, clamping.
void MainWindow::on_scalarDataMappingClampingMinSlider_valueChanged(int value)
{
    ui->scalarDataMappingClampingMinDoubleSpinBox->setValue(static_cast<double>(value) / 100.0);
}

void MainWindow::on_scalarDataMappingClampingMinDoubleSpinBox_valueChanged(double arg1)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_clampMin = static_cast<float>(arg1);
}

void MainWindow::on_scalarDataMappingClampingMaxSlider_valueChanged(int value)
{
    ui->scalarDataMappingClampingMaxDoubleSpinBox->setValue(static_cast<double>(value) / 100.0);
}

void MainWindow::on_scalarDataMappingClampingMaxDoubleSpinBox_valueChanged(double arg1)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_clampMax = static_cast<float>(arg1);
}


// Scalar data, transfer function.
void MainWindow::on_scalarDataMappingTransferKSlider_valueChanged(int value)
{
    ui->scalarDataMappingTransferKSpinBox->setValue(static_cast<double>(value) / 100.0);
}

void MainWindow::on_scalarDataMappingTransferKSpinBox_valueChanged(double value)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->m_transferK = static_cast<float>(value);
}
