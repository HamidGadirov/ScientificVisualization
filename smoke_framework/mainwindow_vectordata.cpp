#include "mainwindow.h"
#include "ui_mainwindow.h"

// Vector data, general functions.
void MainWindow::updateVectorDataColorMapGlobally() const
{
    std::vector<Color> const colorMapToUse = enumToColorMap(m_vectorDataColorMap, m_numberOfColorsVectorData);

    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    visualizationPtr->opengl_loadVectorDataTexture(colorMapToUse);

    auto const vectorDataLegendPtr = findChildSafe<Legend*>("legendVectorDataOpenGLWidget");
    vectorDataLegendPtr->updateColorMap(colorMapToUse);
}

// Vector data, draw on/off.
void MainWindow::on_vectorDataDrawGlyphsCheckBox_toggled(bool checked)
{
    auto const openGLWidgetPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    openGLWidgetPtr->m_drawVectorData = checked;
}

// Vector data, number of glyphs.
void MainWindow::on_vectorDataNumberOfGlyphsHorizontalSpinBox_valueChanged(int arg1)
{
    auto const openGLWidgetPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    openGLWidgetPtr->setNumberOfGlyphsX(static_cast<size_t>(arg1));
}

void MainWindow::on_vectorDataNumberOfGlyphsVerticalSpinBox_valueChanged(int arg1)
{
    auto const openGLWidgetPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
    openGLWidgetPtr->setNumberOfGlyphsY(static_cast<size_t>(arg1));
}

// Vector data, data type.

void MainWindow::on_vectorDataComboBox_currentIndexChanged(int index)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");

    switch (index)
    {
        case 0:
            visualizationPtr->m_currentVectorDataType = VectorDataType::Velocity;
        break;

        case 1:
            visualizationPtr->m_currentVectorDataType = VectorDataType::ForceField;
        break;
    }
}

void MainWindow::on_vectorDataGlyphComboBox_currentIndexChanged(int index)
{
    auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");

    switch (index)
    {
        case 0:
            visualizationPtr->m_currentGlyphType = Glyph::GlyphType::Hedgehog;
        break;

        case 1:
            visualizationPtr->m_currentGlyphType = Glyph::GlyphType::Triangle;
        break;

        case 2:
            visualizationPtr->m_currentGlyphType = Glyph::GlyphType::Cone;
        break;

        case 3:
            visualizationPtr->m_currentGlyphType = Glyph::GlyphType::Arrow2D;
        break;

        case 4:
            visualizationPtr->m_currentGlyphType = Glyph::GlyphType::Arrow3D;
        break;
    }

    visualizationPtr->opengl_bufferSingleGlyph();
}

// Vector data, glyph magnifier.
void MainWindow::on_vectorDataGlyphMagnifierSlider_valueChanged(int value)
{
    ui->vectorDataGlyphMagnifierDoubleSpinBox->setValue(static_cast<double>(value) / 100.0);
}

void MainWindow::on_vectorDataGlyphMagnifierDoubleSpinBox_valueChanged(double arg1)
{
        auto const visualizationPtr = findChildSafe<Visualization*>("visualizationOpenGLWidget");
        visualizationPtr->m_vectorDataMagnifier = static_cast<float>(arg1);
}

// Vector data, color map.
void MainWindow::on_vectorDataColorMapComboBox_currentIndexChanged(int index)
{
    switch (index)
    {
        case 0:
            m_vectorDataColorMap = ColorMap::Grayscale;
        break;

        case 1:
            m_vectorDataColorMap = ColorMap::Rainbow;
        break;

        case 2:
            m_vectorDataColorMap = ColorMap::HeatMap;
        break;

        case 3:
            m_vectorDataColorMap = ColorMap::BlueYellow;
        break;
    }

    updateVectorDataColorMapGlobally();
}

void MainWindow::on_vectorDataNumberOfColorsSpinBox_valueChanged(int value)
{
    m_numberOfColorsVectorData = static_cast<size_t>(value);
    updateVectorDataColorMapGlobally();
}
