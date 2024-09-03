#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLCDNumber>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::vector<Color> MainWindow::enumToColorMap(ColorMap const colorMap, size_t numberOfColors) const
{
    std::vector<Color> ret;

    switch (colorMap)
    {
        case ColorMap::Grayscale: ret = Texture::createGrayscaleTexture(numberOfColors); break;
        case ColorMap::Turbo: ret = Texture::createTurboTexture(numberOfColors); break;
        case ColorMap::HeatMap: ret = Texture::createHeatTexture(numberOfColors); break;
        case ColorMap::BlueYellow: ret = Texture::createBlueYellowTexture(numberOfColors); break;
        case ColorMap::Custom3Color:
        {
            auto const &customColors = findChildSafe<Visualization*>("visualizationOpenGLWidget")->m_customColors;
            ret = Texture::createThreeColorTexture(customColors[0], customColors[1], customColors[2], numberOfColors);
        }
    }

    return ret;
}

void MainWindow::setScalarDataMin(float const min)
{
    ui->scalarDataMinLcdNumber->display(static_cast<double>(min));
}

void MainWindow::setScalarDataMax(float const max)
{
    ui->scalarDataMaxLcdNumber->display(static_cast<double>(max));
}

void MainWindow::setVectorDataMin(float const min)
{
    ui->vectorDataMinLcdNumber->display(static_cast<double>(min));
}

void MainWindow::setVectorDataMax(float const max)
{
    ui->vectorDataMaxLcdNumber->display(static_cast<double>(max));
}
void MainWindow::on_screenshotPushButton_clicked()
{
    static unsigned int cnt = 0U;
    QImage const image = ui->visualizationOpenGLWidget->grabFramebuffer();
    image.save("screenshot" + QString::number(cnt++) + ".png", "PNG", 100);  // Save using the best quality
}
