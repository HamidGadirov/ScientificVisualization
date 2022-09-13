/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "legendscalardata.h"
#include "legendvectordata.h"
#include "visualization.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *settingsPages;
    QWidget *SimulationSettingsPage;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *showMinMaxDataCheckBox;
    QGroupBox *fluidGroupBox;
    QGridLayout *gridLayout_6;
    QDoubleSpinBox *viscositySpinBox;
    QSlider *densitySlider;
    QLabel *density;
    QSlider *viscositySlider;
    QLabel *viscosity;
    QDoubleSpinBox *densitySpinBox;
    QLabel *densityUnits;
    QLabel *viscosityUnits;
    QGroupBox *timestepGroupBox;
    QGridLayout *gridLayout_7;
    QSlider *timestepSlider;
    QDoubleSpinBox *timestepSpinBox;
    QLabel *timestepUnits;
    QGroupBox *gridpointsGroupBox;
    QGridLayout *gridLayout_8;
    QSlider *gridpointsSlider;
    QSpinBox *gridpointsSpinBox;
    QPushButton *pausePlayButton;
    QPushButton *loadDataButton;
    QWidget *VisualizationPage;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *visualizationProjectionGroupBox;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *visualizationProjectionOrthographicRadioButton;
    QRadioButton *visualizationProjectionPerspectiveRadioButton;
    QWidget *PreprocessingSettingsPage;
    QVBoxLayout *verticalLayout_14;
    QGroupBox *quantizationGroupBox;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *quantizationCheckBox;
    QComboBox *quantizationBitsComboBox;
    QGroupBox *gaussianBlurGroupBox;
    QHBoxLayout *horizontalLayout_14;
    QCheckBox *gaussianBlurCheckBox;
    QGroupBox *gradientsGroupBox;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *gradientsCheckBox;
    QGroupBox *scalarDataSlicingGroupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *scalarDataSlicingDirectionYRadioButton;
    QSpinBox *scalarDataSlicingSliceIndexSpinBox;
    QLabel *scalarDataSlicingSliceIndexLabel;
    QLabel *scalarDataSlicingDirectionLabel;
    QRadioButton *scalarDataSlicingDirectionXRadioButton;
    QCheckBox *scalarDataslicingEnableCheckBox;
    QRadioButton *scalarDataSlicingDirectionTRadioButton;
    QSlider *scalarDataSlicingSliceIndexHorizontalSlider;
    QWidget *scalarDataSettingsPage;
    QVBoxLayout *verticalLayout;
    QCheckBox *scalarDataDrawScalarDataCheckBox;
    QGroupBox *scalarDataTypeGroupBox;
    QVBoxLayout *verticalLayout_5;
    QComboBox *scalarDataComboBox;
    QGroupBox *scalarDataColormapGroupBox;
    QVBoxLayout *verticalLayout_7;
    QComboBox *scalarDataColorMapComboBox;
    QGroupBox *scalarDataNumberOfColorsGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QSlider *scalarDataColorMapNumberOfColorsSlider;
    QSpinBox *scalarDataColorMapNumberOfColorsSpinBox;
    QGroupBox *scalarDataCustomColorMapGroupBox;
    QHBoxLayout *horizontalLayout_10;
    QLabel *scalarDataCustomColorIndexLabel;
    QSpinBox *scalarDataCustomColorSpinBox;
    QPushButton *scalarDataCustomColorPickerPushButton;
    QGroupBox *scalarDataMappingGroupBox;
    QFormLayout *formLayout_5;
    QGroupBox *scalarDataMappingNormalizationGroupBox;
    QHBoxLayout *horizontalLayout_11;
    QRadioButton *scalarDataMappingMappingTypeClampingRadioButton;
    QRadioButton *scalarDataMappingMappingTypeScalingRadioButton;
    QGroupBox *scalarDataMappingTransferGroupBox;
    QHBoxLayout *horizontalLayout_3;
    QSlider *scalarDataMappingTransferKSlider;
    QDoubleSpinBox *scalarDataMappingTransferKSpinBox;
    QGroupBox *scalarDataMappingClampingGroupBox;
    QGridLayout *gridLayout_3;
    QLabel *scalarDataMappingClampingMinLabel;
    QDoubleSpinBox *scalarDataMappingClampingMinDoubleSpinBox;
    QSlider *scalarDataMappingClampingMinSlider;
    QLabel *scalarDataMappingClampingMaxLabel;
    QDoubleSpinBox *scalarDataMappingClampingMaxDoubleSpinBox;
    QSlider *scalarDataMappingClampingMaxSlider;
    QGroupBox *scalarDataMappingScalingGroupBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *scalarDataMappingScalingMovingAverageWindowSizeLabel;
    QSpinBox *scalarDataMappingScalingMovingAverageWindowSpinBox;
    QWidget *vectorDataSettingsPage;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *vectorDataDrawGlyphsCheckBox;
    QGroupBox *vectorDataNumberOfGlyphsGroupBox;
    QGridLayout *gridLayout;
    QSlider *vectorDataNumberOfGlyphsVerticalSlider;
    QSpinBox *vectorDataNumberOfGlyphsVerticalSpinBox;
    QSlider *vectorDataNumberOfGlyphsHorizontalSlider;
    QSpinBox *vectorDataNumberOfGlyphsHorizontalSpinBox;
    QLabel *vectorDataNumberOfGlyphsHorizontalLabel;
    QLabel *vectorDataNumberOfGlyphsVerticalLabel;
    QGroupBox *vectorDataDataTypeGroupBox;
    QVBoxLayout *verticalLayout_8;
    QComboBox *vectorDataComboBox;
    QGroupBox *vectorDataGlyphTypeGroupBox;
    QGridLayout *gridLayout_5;
    QComboBox *vectorDataGlyphComboBox;
    QGroupBox *vectorDataGlyphMagnifierGroupBox;
    QHBoxLayout *horizontalLayout_6;
    QSlider *vectorDataGlyphMagnifierSlider;
    QDoubleSpinBox *vectorDataGlyphMagnifierDoubleSpinBox;
    QGroupBox *vectorDataColorMapGroupBox;
    QVBoxLayout *verticalLayout_9;
    QComboBox *vectorDataColorMapComboBox;
    QGroupBox *vectorDataNumberOfColorsGroupBox;
    QHBoxLayout *horizontalLayout_4;
    QSlider *vectorDataNumberOfColorsSlider;
    QSpinBox *vectorDataNumberOfColorsSpinBox;
    QWidget *isolinesSettingsPage;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *isolinesDrawSettingsGroupBox;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *isolinesDrawIsolinesCheckBox;
    QPushButton *isolinesColorPickerButton;
    QCheckBox *isolinesUseCurrentScalarDataCheckBox;
    QGroupBox *isolinesDataGroupBox;
    QVBoxLayout *verticalLayout_12;
    QComboBox *isolinesDataComboBox;
    QGroupBox *isolinesInterpolationSettingsGroupBox;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *isolinesInterpolationMethodSettingsGroupBox;
    QHBoxLayout *horizontalLayout_16;
    QRadioButton *isolinesInterpolationMethodLinearRadioButton;
    QRadioButton *isolinesInterpolationMethodNoneRadioButton;
    QGroupBox *isolinesAmbiguousCaseDeciderSettingsGroupBox;
    QHBoxLayout *horizontalLayout_15;
    QRadioButton *isolinesAmbiguousCaseDeciderMidpointRadioButton;
    QRadioButton *isolinesAmbiguousCaseDeciderAsymptoticRadioButton;
    QGroupBox *isolinesNumberOfIsolinesGroupBox;
    QHBoxLayout *horizontalLayout_7;
    QSlider *isolinesNumberOfIsolinesSlider;
    QSpinBox *isolinesNumberOfIsolinesSpinBox;
    QGroupBox *isolinesRangeGroupBox;
    QFormLayout *formLayout_6;
    QSlider *isolinesRangeRhoMinSlider;
    QSlider *isolinesRangeRhoMaxSlider;
    QLabel *isolinesRangeRhoMinLabel;
    QLabel *isolinesRangeRhoMaxLabel;
    QDoubleSpinBox *isolinesRangeRhoMinSpinBox;
    QDoubleSpinBox *isolinesRangeRhoMaxSpinBox;
    QWidget *heightplotSettingsPage;
    QVBoxLayout *verticalLayout_13;
    QCheckBox *showHeightplotCheckBox;
    QGroupBox *heightplotDataType;
    QVBoxLayout *verticalLayout_11;
    QComboBox *heightplotDataTypeComboBox;
    QGroupBox *heightplotViewRotationGroupBox;
    QGridLayout *gridLayout_4;
    QLabel *heightplotViewRotationXAxis;
    QDial *heightplotViewRotateZ;
    QDial *heightplotViewRotateY;
    QDial *heightplotViewRotateX;
    QLabel *heightplotViewRotationYAxis;
    QLabel *heightplotViewRotationZAxis;
    QPushButton *heightplotResetRotation;
    QWidget *LICSettingsPage;
    QVBoxLayout *verticalLayout_15;
    QVBoxLayout *LICSettings;
    QCheckBox *drawLicCheckBox;
    QWidget *volumeRenderingSettingsPage;
    QVBoxLayout *verticalLayout_16;
    QCheckBox *drawVolumeRenderingCheckBox;
    QVBoxLayout *openGLWidgetsVerticalLayout;
    Visualization *visualizationOpenGLWidget;
    QGridLayout *legendsAndExtremaGridLayout;
    QLabel *vectorDataLabel;
    LegendVectorData *legendVectorDataOpenGLWidget;
    QLCDNumber *vectorDataMaxLcdNumber;
    QLabel *scalarDataLabel;
    QLCDNumber *scalarDataMinLcdNumber;
    QLCDNumber *vectorDataMinLcdNumber;
    LegendScalarData *legendScalarDataOpenGLWidget;
    QLCDNumber *scalarDataMaxLcdNumber;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 813);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        settingsPages = new QTabWidget(centralWidget);
        settingsPages->setObjectName(QString::fromUtf8("settingsPages"));
        settingsPages->setMaximumSize(QSize(800, 800));
        settingsPages->setAutoFillBackground(true);
        SimulationSettingsPage = new QWidget();
        SimulationSettingsPage->setObjectName(QString::fromUtf8("SimulationSettingsPage"));
        SimulationSettingsPage->setAutoFillBackground(true);
        verticalLayout_3 = new QVBoxLayout(SimulationSettingsPage);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        showMinMaxDataCheckBox = new QCheckBox(SimulationSettingsPage);
        showMinMaxDataCheckBox->setObjectName(QString::fromUtf8("showMinMaxDataCheckBox"));
        showMinMaxDataCheckBox->setChecked(true);

        verticalLayout_3->addWidget(showMinMaxDataCheckBox);

        fluidGroupBox = new QGroupBox(SimulationSettingsPage);
        fluidGroupBox->setObjectName(QString::fromUtf8("fluidGroupBox"));
        fluidGroupBox->setMinimumSize(QSize(150, 150));
        fluidGroupBox->setMaximumSize(QSize(500, 70));
        gridLayout_6 = new QGridLayout(fluidGroupBox);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        viscositySpinBox = new QDoubleSpinBox(fluidGroupBox);
        viscositySpinBox->setObjectName(QString::fromUtf8("viscositySpinBox"));
        viscositySpinBox->setDecimals(2);
        viscositySpinBox->setMinimum(0.100000000000000);
        viscositySpinBox->setMaximum(50.000000000000000);
        viscositySpinBox->setSingleStep(0.100000000000000);
        viscositySpinBox->setValue(1.000000000000000);

        gridLayout_6->addWidget(viscositySpinBox, 3, 1, 1, 1);

        densitySlider = new QSlider(fluidGroupBox);
        densitySlider->setObjectName(QString::fromUtf8("densitySlider"));
        densitySlider->setMinimum(1);
        densitySlider->setMaximum(200);
        densitySlider->setValue(100);
        densitySlider->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(densitySlider, 1, 0, 1, 1);

        density = new QLabel(fluidGroupBox);
        density->setObjectName(QString::fromUtf8("density"));

        gridLayout_6->addWidget(density, 0, 0, 1, 1);

        viscositySlider = new QSlider(fluidGroupBox);
        viscositySlider->setObjectName(QString::fromUtf8("viscositySlider"));
        viscositySlider->setMinimum(1);
        viscositySlider->setMaximum(500);
        viscositySlider->setValue(10);
        viscositySlider->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(viscositySlider, 3, 0, 1, 1);

        viscosity = new QLabel(fluidGroupBox);
        viscosity->setObjectName(QString::fromUtf8("viscosity"));

        gridLayout_6->addWidget(viscosity, 2, 0, 1, 1);

        densitySpinBox = new QDoubleSpinBox(fluidGroupBox);
        densitySpinBox->setObjectName(QString::fromUtf8("densitySpinBox"));
        densitySpinBox->setDecimals(2);
        densitySpinBox->setMinimum(0.100000000000000);
        densitySpinBox->setMaximum(20.000000000000000);
        densitySpinBox->setSingleStep(0.100000000000000);
        densitySpinBox->setValue(10.000000000000000);

        gridLayout_6->addWidget(densitySpinBox, 1, 1, 1, 1);

        densityUnits = new QLabel(fluidGroupBox);
        densityUnits->setObjectName(QString::fromUtf8("densityUnits"));

        gridLayout_6->addWidget(densityUnits, 1, 2, 1, 1);

        viscosityUnits = new QLabel(fluidGroupBox);
        viscosityUnits->setObjectName(QString::fromUtf8("viscosityUnits"));

        gridLayout_6->addWidget(viscosityUnits, 3, 2, 1, 1);


        verticalLayout_3->addWidget(fluidGroupBox);

        timestepGroupBox = new QGroupBox(SimulationSettingsPage);
        timestepGroupBox->setObjectName(QString::fromUtf8("timestepGroupBox"));
        timestepGroupBox->setMaximumSize(QSize(16777215, 100));
        gridLayout_7 = new QGridLayout(timestepGroupBox);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        timestepSlider = new QSlider(timestepGroupBox);
        timestepSlider->setObjectName(QString::fromUtf8("timestepSlider"));
        timestepSlider->setMinimum(1);
        timestepSlider->setMaximum(20);
        timestepSlider->setValue(4);
        timestepSlider->setOrientation(Qt::Horizontal);

        gridLayout_7->addWidget(timestepSlider, 0, 0, 1, 1);

        timestepSpinBox = new QDoubleSpinBox(timestepGroupBox);
        timestepSpinBox->setObjectName(QString::fromUtf8("timestepSpinBox"));
        timestepSpinBox->setDecimals(1);
        timestepSpinBox->setMinimum(0.100000000000000);
        timestepSpinBox->setMaximum(2.000000000000000);
        timestepSpinBox->setSingleStep(0.100000000000000);
        timestepSpinBox->setValue(0.400000000000000);

        gridLayout_7->addWidget(timestepSpinBox, 0, 2, 1, 1);

        timestepUnits = new QLabel(timestepGroupBox);
        timestepUnits->setObjectName(QString::fromUtf8("timestepUnits"));

        gridLayout_7->addWidget(timestepUnits, 0, 3, 1, 1);


        verticalLayout_3->addWidget(timestepGroupBox);

        gridpointsGroupBox = new QGroupBox(SimulationSettingsPage);
        gridpointsGroupBox->setObjectName(QString::fromUtf8("gridpointsGroupBox"));
        gridpointsGroupBox->setMaximumSize(QSize(16777215, 100));
        gridLayout_8 = new QGridLayout(gridpointsGroupBox);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridpointsSlider = new QSlider(gridpointsGroupBox);
        gridpointsSlider->setObjectName(QString::fromUtf8("gridpointsSlider"));
        gridpointsSlider->setMinimum(10);
        gridpointsSlider->setMaximum(200);
        gridpointsSlider->setSingleStep(2);
        gridpointsSlider->setValue(64);
        gridpointsSlider->setTracking(false);
        gridpointsSlider->setOrientation(Qt::Horizontal);
        gridpointsSlider->setTickPosition(QSlider::NoTicks);

        gridLayout_8->addWidget(gridpointsSlider, 0, 0, 1, 1);

        gridpointsSpinBox = new QSpinBox(gridpointsGroupBox);
        gridpointsSpinBox->setObjectName(QString::fromUtf8("gridpointsSpinBox"));
        gridpointsSpinBox->setKeyboardTracking(false);
        gridpointsSpinBox->setMinimum(10);
        gridpointsSpinBox->setMaximum(200);
        gridpointsSpinBox->setSingleStep(2);
        gridpointsSpinBox->setValue(64);

        gridLayout_8->addWidget(gridpointsSpinBox, 0, 1, 1, 1);


        verticalLayout_3->addWidget(gridpointsGroupBox);

        pausePlayButton = new QPushButton(SimulationSettingsPage);
        pausePlayButton->setObjectName(QString::fromUtf8("pausePlayButton"));

        verticalLayout_3->addWidget(pausePlayButton);

        loadDataButton = new QPushButton(SimulationSettingsPage);
        loadDataButton->setObjectName(QString::fromUtf8("loadDataButton"));

        verticalLayout_3->addWidget(loadDataButton, 0, Qt::AlignLeft);

        settingsPages->addTab(SimulationSettingsPage, QString());
        VisualizationPage = new QWidget();
        VisualizationPage->setObjectName(QString::fromUtf8("VisualizationPage"));
        verticalLayout_10 = new QVBoxLayout(VisualizationPage);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        visualizationProjectionGroupBox = new QGroupBox(VisualizationPage);
        visualizationProjectionGroupBox->setObjectName(QString::fromUtf8("visualizationProjectionGroupBox"));
        horizontalLayout_8 = new QHBoxLayout(visualizationProjectionGroupBox);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        visualizationProjectionOrthographicRadioButton = new QRadioButton(visualizationProjectionGroupBox);
        visualizationProjectionOrthographicRadioButton->setObjectName(QString::fromUtf8("visualizationProjectionOrthographicRadioButton"));
        visualizationProjectionOrthographicRadioButton->setChecked(true);

        horizontalLayout_8->addWidget(visualizationProjectionOrthographicRadioButton);

        visualizationProjectionPerspectiveRadioButton = new QRadioButton(visualizationProjectionGroupBox);
        visualizationProjectionPerspectiveRadioButton->setObjectName(QString::fromUtf8("visualizationProjectionPerspectiveRadioButton"));

        horizontalLayout_8->addWidget(visualizationProjectionPerspectiveRadioButton);


        verticalLayout_10->addWidget(visualizationProjectionGroupBox);

        settingsPages->addTab(VisualizationPage, QString());
        PreprocessingSettingsPage = new QWidget();
        PreprocessingSettingsPage->setObjectName(QString::fromUtf8("PreprocessingSettingsPage"));
        verticalLayout_14 = new QVBoxLayout(PreprocessingSettingsPage);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        quantizationGroupBox = new QGroupBox(PreprocessingSettingsPage);
        quantizationGroupBox->setObjectName(QString::fromUtf8("quantizationGroupBox"));
        horizontalLayout_12 = new QHBoxLayout(quantizationGroupBox);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        quantizationCheckBox = new QCheckBox(quantizationGroupBox);
        quantizationCheckBox->setObjectName(QString::fromUtf8("quantizationCheckBox"));

        horizontalLayout_12->addWidget(quantizationCheckBox);

        quantizationBitsComboBox = new QComboBox(quantizationGroupBox);
        quantizationBitsComboBox->addItem(QString());
        quantizationBitsComboBox->addItem(QString());
        quantizationBitsComboBox->addItem(QString());
        quantizationBitsComboBox->addItem(QString());
        quantizationBitsComboBox->setObjectName(QString::fromUtf8("quantizationBitsComboBox"));

        horizontalLayout_12->addWidget(quantizationBitsComboBox);


        verticalLayout_14->addWidget(quantizationGroupBox);

        gaussianBlurGroupBox = new QGroupBox(PreprocessingSettingsPage);
        gaussianBlurGroupBox->setObjectName(QString::fromUtf8("gaussianBlurGroupBox"));
        horizontalLayout_14 = new QHBoxLayout(gaussianBlurGroupBox);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        gaussianBlurCheckBox = new QCheckBox(gaussianBlurGroupBox);
        gaussianBlurCheckBox->setObjectName(QString::fromUtf8("gaussianBlurCheckBox"));

        horizontalLayout_14->addWidget(gaussianBlurCheckBox);


        verticalLayout_14->addWidget(gaussianBlurGroupBox);

        gradientsGroupBox = new QGroupBox(PreprocessingSettingsPage);
        gradientsGroupBox->setObjectName(QString::fromUtf8("gradientsGroupBox"));
        horizontalLayout_13 = new QHBoxLayout(gradientsGroupBox);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        gradientsCheckBox = new QCheckBox(gradientsGroupBox);
        gradientsCheckBox->setObjectName(QString::fromUtf8("gradientsCheckBox"));

        horizontalLayout_13->addWidget(gradientsCheckBox);


        verticalLayout_14->addWidget(gradientsGroupBox);

        scalarDataSlicingGroupBox = new QGroupBox(PreprocessingSettingsPage);
        scalarDataSlicingGroupBox->setObjectName(QString::fromUtf8("scalarDataSlicingGroupBox"));
        gridLayout_2 = new QGridLayout(scalarDataSlicingGroupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scalarDataSlicingDirectionYRadioButton = new QRadioButton(scalarDataSlicingGroupBox);
        scalarDataSlicingDirectionYRadioButton->setObjectName(QString::fromUtf8("scalarDataSlicingDirectionYRadioButton"));

        gridLayout_2->addWidget(scalarDataSlicingDirectionYRadioButton, 1, 4, 1, 1);

        scalarDataSlicingSliceIndexSpinBox = new QSpinBox(scalarDataSlicingGroupBox);
        scalarDataSlicingSliceIndexSpinBox->setObjectName(QString::fromUtf8("scalarDataSlicingSliceIndexSpinBox"));
        scalarDataSlicingSliceIndexSpinBox->setMaximum(63);
        scalarDataSlicingSliceIndexSpinBox->setSingleStep(1);

        gridLayout_2->addWidget(scalarDataSlicingSliceIndexSpinBox, 2, 4, 1, 2);

        scalarDataSlicingSliceIndexLabel = new QLabel(scalarDataSlicingGroupBox);
        scalarDataSlicingSliceIndexLabel->setObjectName(QString::fromUtf8("scalarDataSlicingSliceIndexLabel"));

        gridLayout_2->addWidget(scalarDataSlicingSliceIndexLabel, 2, 2, 1, 1);

        scalarDataSlicingDirectionLabel = new QLabel(scalarDataSlicingGroupBox);
        scalarDataSlicingDirectionLabel->setObjectName(QString::fromUtf8("scalarDataSlicingDirectionLabel"));

        gridLayout_2->addWidget(scalarDataSlicingDirectionLabel, 1, 2, 1, 1);

        scalarDataSlicingDirectionXRadioButton = new QRadioButton(scalarDataSlicingGroupBox);
        scalarDataSlicingDirectionXRadioButton->setObjectName(QString::fromUtf8("scalarDataSlicingDirectionXRadioButton"));
        scalarDataSlicingDirectionXRadioButton->setChecked(true);

        gridLayout_2->addWidget(scalarDataSlicingDirectionXRadioButton, 1, 3, 1, 1);

        scalarDataslicingEnableCheckBox = new QCheckBox(scalarDataSlicingGroupBox);
        scalarDataslicingEnableCheckBox->setObjectName(QString::fromUtf8("scalarDataslicingEnableCheckBox"));
        scalarDataslicingEnableCheckBox->setChecked(false);

        gridLayout_2->addWidget(scalarDataslicingEnableCheckBox, 1, 1, 1, 1);

        scalarDataSlicingDirectionTRadioButton = new QRadioButton(scalarDataSlicingGroupBox);
        scalarDataSlicingDirectionTRadioButton->setObjectName(QString::fromUtf8("scalarDataSlicingDirectionTRadioButton"));

        gridLayout_2->addWidget(scalarDataSlicingDirectionTRadioButton, 1, 5, 1, 1);

        scalarDataSlicingSliceIndexHorizontalSlider = new QSlider(scalarDataSlicingGroupBox);
        scalarDataSlicingSliceIndexHorizontalSlider->setObjectName(QString::fromUtf8("scalarDataSlicingSliceIndexHorizontalSlider"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scalarDataSlicingSliceIndexHorizontalSlider->sizePolicy().hasHeightForWidth());
        scalarDataSlicingSliceIndexHorizontalSlider->setSizePolicy(sizePolicy);
        scalarDataSlicingSliceIndexHorizontalSlider->setMaximum(63);
        scalarDataSlicingSliceIndexHorizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(scalarDataSlicingSliceIndexHorizontalSlider, 2, 3, 1, 1);


        verticalLayout_14->addWidget(scalarDataSlicingGroupBox);

        settingsPages->addTab(PreprocessingSettingsPage, QString());
        scalarDataSettingsPage = new QWidget();
        scalarDataSettingsPage->setObjectName(QString::fromUtf8("scalarDataSettingsPage"));
        scalarDataSettingsPage->setAutoFillBackground(true);
        verticalLayout = new QVBoxLayout(scalarDataSettingsPage);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scalarDataDrawScalarDataCheckBox = new QCheckBox(scalarDataSettingsPage);
        scalarDataDrawScalarDataCheckBox->setObjectName(QString::fromUtf8("scalarDataDrawScalarDataCheckBox"));
        scalarDataDrawScalarDataCheckBox->setChecked(true);

        verticalLayout->addWidget(scalarDataDrawScalarDataCheckBox);

        scalarDataTypeGroupBox = new QGroupBox(scalarDataSettingsPage);
        scalarDataTypeGroupBox->setObjectName(QString::fromUtf8("scalarDataTypeGroupBox"));
        scalarDataTypeGroupBox->setMaximumSize(QSize(16777215, 80));
        verticalLayout_5 = new QVBoxLayout(scalarDataTypeGroupBox);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        scalarDataComboBox = new QComboBox(scalarDataTypeGroupBox);
        scalarDataComboBox->addItem(QString());
        scalarDataComboBox->addItem(QString());
        scalarDataComboBox->addItem(QString());
        scalarDataComboBox->addItem(QString());
        scalarDataComboBox->addItem(QString());
        scalarDataComboBox->setObjectName(QString::fromUtf8("scalarDataComboBox"));

        verticalLayout_5->addWidget(scalarDataComboBox);


        verticalLayout->addWidget(scalarDataTypeGroupBox);

        scalarDataColormapGroupBox = new QGroupBox(scalarDataSettingsPage);
        scalarDataColormapGroupBox->setObjectName(QString::fromUtf8("scalarDataColormapGroupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scalarDataColormapGroupBox->sizePolicy().hasHeightForWidth());
        scalarDataColormapGroupBox->setSizePolicy(sizePolicy1);
        scalarDataColormapGroupBox->setMinimumSize(QSize(150, 200));
        scalarDataColormapGroupBox->setMaximumSize(QSize(500, 160));
        verticalLayout_7 = new QVBoxLayout(scalarDataColormapGroupBox);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        scalarDataColorMapComboBox = new QComboBox(scalarDataColormapGroupBox);
        scalarDataColorMapComboBox->addItem(QString());
        scalarDataColorMapComboBox->addItem(QString());
        scalarDataColorMapComboBox->addItem(QString());
        scalarDataColorMapComboBox->addItem(QString());
        scalarDataColorMapComboBox->addItem(QString());
        scalarDataColorMapComboBox->setObjectName(QString::fromUtf8("scalarDataColorMapComboBox"));

        verticalLayout_7->addWidget(scalarDataColorMapComboBox);

        scalarDataNumberOfColorsGroupBox = new QGroupBox(scalarDataColormapGroupBox);
        scalarDataNumberOfColorsGroupBox->setObjectName(QString::fromUtf8("scalarDataNumberOfColorsGroupBox"));
        scalarDataNumberOfColorsGroupBox->setMinimumSize(QSize(0, 59));
        scalarDataNumberOfColorsGroupBox->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_2 = new QHBoxLayout(scalarDataNumberOfColorsGroupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        scalarDataColorMapNumberOfColorsSlider = new QSlider(scalarDataNumberOfColorsGroupBox);
        scalarDataColorMapNumberOfColorsSlider->setObjectName(QString::fromUtf8("scalarDataColorMapNumberOfColorsSlider"));
        sizePolicy.setHeightForWidth(scalarDataColorMapNumberOfColorsSlider->sizePolicy().hasHeightForWidth());
        scalarDataColorMapNumberOfColorsSlider->setSizePolicy(sizePolicy);
        scalarDataColorMapNumberOfColorsSlider->setMinimum(2);
        scalarDataColorMapNumberOfColorsSlider->setMaximum(256);
        scalarDataColorMapNumberOfColorsSlider->setValue(256);
        scalarDataColorMapNumberOfColorsSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(scalarDataColorMapNumberOfColorsSlider);

        scalarDataColorMapNumberOfColorsSpinBox = new QSpinBox(scalarDataNumberOfColorsGroupBox);
        scalarDataColorMapNumberOfColorsSpinBox->setObjectName(QString::fromUtf8("scalarDataColorMapNumberOfColorsSpinBox"));
        scalarDataColorMapNumberOfColorsSpinBox->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scalarDataColorMapNumberOfColorsSpinBox->sizePolicy().hasHeightForWidth());
        scalarDataColorMapNumberOfColorsSpinBox->setSizePolicy(sizePolicy2);
        scalarDataColorMapNumberOfColorsSpinBox->setMinimumSize(QSize(57, 20));
        scalarDataColorMapNumberOfColorsSpinBox->setMinimum(2);
        scalarDataColorMapNumberOfColorsSpinBox->setMaximum(256);
        scalarDataColorMapNumberOfColorsSpinBox->setValue(256);

        horizontalLayout_2->addWidget(scalarDataColorMapNumberOfColorsSpinBox);


        verticalLayout_7->addWidget(scalarDataNumberOfColorsGroupBox);

        scalarDataCustomColorMapGroupBox = new QGroupBox(scalarDataColormapGroupBox);
        scalarDataCustomColorMapGroupBox->setObjectName(QString::fromUtf8("scalarDataCustomColorMapGroupBox"));
        scalarDataCustomColorMapGroupBox->setMinimumSize(QSize(0, 60));
        horizontalLayout_10 = new QHBoxLayout(scalarDataCustomColorMapGroupBox);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        scalarDataCustomColorIndexLabel = new QLabel(scalarDataCustomColorMapGroupBox);
        scalarDataCustomColorIndexLabel->setObjectName(QString::fromUtf8("scalarDataCustomColorIndexLabel"));

        horizontalLayout_10->addWidget(scalarDataCustomColorIndexLabel);

        scalarDataCustomColorSpinBox = new QSpinBox(scalarDataCustomColorMapGroupBox);
        scalarDataCustomColorSpinBox->setObjectName(QString::fromUtf8("scalarDataCustomColorSpinBox"));
        sizePolicy.setHeightForWidth(scalarDataCustomColorSpinBox->sizePolicy().hasHeightForWidth());
        scalarDataCustomColorSpinBox->setSizePolicy(sizePolicy);
        scalarDataCustomColorSpinBox->setMinimumSize(QSize(0, 20));
        scalarDataCustomColorSpinBox->setMaximum(2);

        horizontalLayout_10->addWidget(scalarDataCustomColorSpinBox);

        scalarDataCustomColorPickerPushButton = new QPushButton(scalarDataCustomColorMapGroupBox);
        scalarDataCustomColorPickerPushButton->setObjectName(QString::fromUtf8("scalarDataCustomColorPickerPushButton"));
        sizePolicy1.setHeightForWidth(scalarDataCustomColorPickerPushButton->sizePolicy().hasHeightForWidth());
        scalarDataCustomColorPickerPushButton->setSizePolicy(sizePolicy1);
        scalarDataCustomColorPickerPushButton->setMinimumSize(QSize(0, 20));

        horizontalLayout_10->addWidget(scalarDataCustomColorPickerPushButton);


        verticalLayout_7->addWidget(scalarDataCustomColorMapGroupBox);


        verticalLayout->addWidget(scalarDataColormapGroupBox);

        scalarDataMappingGroupBox = new QGroupBox(scalarDataSettingsPage);
        scalarDataMappingGroupBox->setObjectName(QString::fromUtf8("scalarDataMappingGroupBox"));
        scalarDataMappingGroupBox->setMaximumSize(QSize(16777215, 300));
        formLayout_5 = new QFormLayout(scalarDataMappingGroupBox);
        formLayout_5->setSpacing(6);
        formLayout_5->setContentsMargins(11, 11, 11, 11);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        scalarDataMappingNormalizationGroupBox = new QGroupBox(scalarDataMappingGroupBox);
        scalarDataMappingNormalizationGroupBox->setObjectName(QString::fromUtf8("scalarDataMappingNormalizationGroupBox"));
        horizontalLayout_11 = new QHBoxLayout(scalarDataMappingNormalizationGroupBox);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        scalarDataMappingMappingTypeClampingRadioButton = new QRadioButton(scalarDataMappingNormalizationGroupBox);
        scalarDataMappingMappingTypeClampingRadioButton->setObjectName(QString::fromUtf8("scalarDataMappingMappingTypeClampingRadioButton"));
        scalarDataMappingMappingTypeClampingRadioButton->setChecked(true);

        horizontalLayout_11->addWidget(scalarDataMappingMappingTypeClampingRadioButton);

        scalarDataMappingMappingTypeScalingRadioButton = new QRadioButton(scalarDataMappingNormalizationGroupBox);
        scalarDataMappingMappingTypeScalingRadioButton->setObjectName(QString::fromUtf8("scalarDataMappingMappingTypeScalingRadioButton"));
        scalarDataMappingMappingTypeScalingRadioButton->setChecked(false);

        horizontalLayout_11->addWidget(scalarDataMappingMappingTypeScalingRadioButton);


        formLayout_5->setWidget(0, QFormLayout::SpanningRole, scalarDataMappingNormalizationGroupBox);

        scalarDataMappingTransferGroupBox = new QGroupBox(scalarDataMappingGroupBox);
        scalarDataMappingTransferGroupBox->setObjectName(QString::fromUtf8("scalarDataMappingTransferGroupBox"));
        scalarDataMappingTransferGroupBox->setMinimumSize(QSize(150, 50));
        scalarDataMappingTransferGroupBox->setMaximumSize(QSize(500, 80));
        horizontalLayout_3 = new QHBoxLayout(scalarDataMappingTransferGroupBox);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        scalarDataMappingTransferKSlider = new QSlider(scalarDataMappingTransferGroupBox);
        scalarDataMappingTransferKSlider->setObjectName(QString::fromUtf8("scalarDataMappingTransferKSlider"));
        scalarDataMappingTransferKSlider->setMinimum(0);
        scalarDataMappingTransferKSlider->setMaximum(200);
        scalarDataMappingTransferKSlider->setValue(100);
        scalarDataMappingTransferKSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(scalarDataMappingTransferKSlider);

        scalarDataMappingTransferKSpinBox = new QDoubleSpinBox(scalarDataMappingTransferGroupBox);
        scalarDataMappingTransferKSpinBox->setObjectName(QString::fromUtf8("scalarDataMappingTransferKSpinBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scalarDataMappingTransferKSpinBox->sizePolicy().hasHeightForWidth());
        scalarDataMappingTransferKSpinBox->setSizePolicy(sizePolicy3);
        scalarDataMappingTransferKSpinBox->setMinimum(0.000000000000000);
        scalarDataMappingTransferKSpinBox->setMaximum(2.000000000000000);
        scalarDataMappingTransferKSpinBox->setSingleStep(0.010000000000000);
        scalarDataMappingTransferKSpinBox->setValue(1.000000000000000);

        horizontalLayout_3->addWidget(scalarDataMappingTransferKSpinBox);


        formLayout_5->setWidget(3, QFormLayout::SpanningRole, scalarDataMappingTransferGroupBox);

        scalarDataMappingClampingGroupBox = new QGroupBox(scalarDataMappingGroupBox);
        scalarDataMappingClampingGroupBox->setObjectName(QString::fromUtf8("scalarDataMappingClampingGroupBox"));
        scalarDataMappingClampingGroupBox->setMinimumSize(QSize(250, 100));
        scalarDataMappingClampingGroupBox->setMaximumSize(QSize(500, 16777215));
        gridLayout_3 = new QGridLayout(scalarDataMappingClampingGroupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        scalarDataMappingClampingMinLabel = new QLabel(scalarDataMappingClampingGroupBox);
        scalarDataMappingClampingMinLabel->setObjectName(QString::fromUtf8("scalarDataMappingClampingMinLabel"));

        gridLayout_3->addWidget(scalarDataMappingClampingMinLabel, 0, 0, 1, 1);

        scalarDataMappingClampingMinDoubleSpinBox = new QDoubleSpinBox(scalarDataMappingClampingGroupBox);
        scalarDataMappingClampingMinDoubleSpinBox->setObjectName(QString::fromUtf8("scalarDataMappingClampingMinDoubleSpinBox"));
        scalarDataMappingClampingMinDoubleSpinBox->setMaximum(255.000000000000000);
        scalarDataMappingClampingMinDoubleSpinBox->setSingleStep(0.010000000000000);

        gridLayout_3->addWidget(scalarDataMappingClampingMinDoubleSpinBox, 0, 1, 2, 1);

        scalarDataMappingClampingMinSlider = new QSlider(scalarDataMappingClampingGroupBox);
        scalarDataMappingClampingMinSlider->setObjectName(QString::fromUtf8("scalarDataMappingClampingMinSlider"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(scalarDataMappingClampingMinSlider->sizePolicy().hasHeightForWidth());
        scalarDataMappingClampingMinSlider->setSizePolicy(sizePolicy4);
        scalarDataMappingClampingMinSlider->setMaximum(25500);
        scalarDataMappingClampingMinSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(scalarDataMappingClampingMinSlider, 1, 0, 1, 1);

        scalarDataMappingClampingMaxLabel = new QLabel(scalarDataMappingClampingGroupBox);
        scalarDataMappingClampingMaxLabel->setObjectName(QString::fromUtf8("scalarDataMappingClampingMaxLabel"));

        gridLayout_3->addWidget(scalarDataMappingClampingMaxLabel, 2, 0, 1, 1);

        scalarDataMappingClampingMaxDoubleSpinBox = new QDoubleSpinBox(scalarDataMappingClampingGroupBox);
        scalarDataMappingClampingMaxDoubleSpinBox->setObjectName(QString::fromUtf8("scalarDataMappingClampingMaxDoubleSpinBox"));
        scalarDataMappingClampingMaxDoubleSpinBox->setMaximum(255.000000000000000);
        scalarDataMappingClampingMaxDoubleSpinBox->setSingleStep(0.010000000000000);
        scalarDataMappingClampingMaxDoubleSpinBox->setValue(1.000000000000000);

        gridLayout_3->addWidget(scalarDataMappingClampingMaxDoubleSpinBox, 2, 1, 2, 1);

        scalarDataMappingClampingMaxSlider = new QSlider(scalarDataMappingClampingGroupBox);
        scalarDataMappingClampingMaxSlider->setObjectName(QString::fromUtf8("scalarDataMappingClampingMaxSlider"));
        scalarDataMappingClampingMaxSlider->setMinimum(1);
        scalarDataMappingClampingMaxSlider->setMaximum(25500);
        scalarDataMappingClampingMaxSlider->setValue(1);
        scalarDataMappingClampingMaxSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(scalarDataMappingClampingMaxSlider, 3, 0, 1, 1);


        formLayout_5->setWidget(2, QFormLayout::LabelRole, scalarDataMappingClampingGroupBox);

        scalarDataMappingScalingGroupBox = new QGroupBox(scalarDataMappingGroupBox);
        scalarDataMappingScalingGroupBox->setObjectName(QString::fromUtf8("scalarDataMappingScalingGroupBox"));
        verticalLayout_4 = new QVBoxLayout(scalarDataMappingScalingGroupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        scalarDataMappingScalingMovingAverageWindowSizeLabel = new QLabel(scalarDataMappingScalingGroupBox);
        scalarDataMappingScalingMovingAverageWindowSizeLabel->setObjectName(QString::fromUtf8("scalarDataMappingScalingMovingAverageWindowSizeLabel"));

        verticalLayout_4->addWidget(scalarDataMappingScalingMovingAverageWindowSizeLabel);

        scalarDataMappingScalingMovingAverageWindowSpinBox = new QSpinBox(scalarDataMappingScalingGroupBox);
        scalarDataMappingScalingMovingAverageWindowSpinBox->setObjectName(QString::fromUtf8("scalarDataMappingScalingMovingAverageWindowSpinBox"));
        scalarDataMappingScalingMovingAverageWindowSpinBox->setMinimum(1);
        scalarDataMappingScalingMovingAverageWindowSpinBox->setMaximum(3600);
        scalarDataMappingScalingMovingAverageWindowSpinBox->setValue(60);

        verticalLayout_4->addWidget(scalarDataMappingScalingMovingAverageWindowSpinBox);


        formLayout_5->setWidget(2, QFormLayout::FieldRole, scalarDataMappingScalingGroupBox);


        verticalLayout->addWidget(scalarDataMappingGroupBox);

        settingsPages->addTab(scalarDataSettingsPage, QString());
        vectorDataSettingsPage = new QWidget();
        vectorDataSettingsPage->setObjectName(QString::fromUtf8("vectorDataSettingsPage"));
        vectorDataSettingsPage->setAutoFillBackground(true);
        verticalLayout_6 = new QVBoxLayout(vectorDataSettingsPage);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        vectorDataDrawGlyphsCheckBox = new QCheckBox(vectorDataSettingsPage);
        vectorDataDrawGlyphsCheckBox->setObjectName(QString::fromUtf8("vectorDataDrawGlyphsCheckBox"));
        vectorDataDrawGlyphsCheckBox->setChecked(false);

        verticalLayout_6->addWidget(vectorDataDrawGlyphsCheckBox);

        vectorDataNumberOfGlyphsGroupBox = new QGroupBox(vectorDataSettingsPage);
        vectorDataNumberOfGlyphsGroupBox->setObjectName(QString::fromUtf8("vectorDataNumberOfGlyphsGroupBox"));
        gridLayout = new QGridLayout(vectorDataNumberOfGlyphsGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        vectorDataNumberOfGlyphsVerticalSlider = new QSlider(vectorDataNumberOfGlyphsGroupBox);
        vectorDataNumberOfGlyphsVerticalSlider->setObjectName(QString::fromUtf8("vectorDataNumberOfGlyphsVerticalSlider"));
        vectorDataNumberOfGlyphsVerticalSlider->setMinimum(1);
        vectorDataNumberOfGlyphsVerticalSlider->setMaximum(200);
        vectorDataNumberOfGlyphsVerticalSlider->setValue(50);
        vectorDataNumberOfGlyphsVerticalSlider->setTracking(true);
        vectorDataNumberOfGlyphsVerticalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(vectorDataNumberOfGlyphsVerticalSlider, 1, 1, 1, 2);

        vectorDataNumberOfGlyphsVerticalSpinBox = new QSpinBox(vectorDataNumberOfGlyphsGroupBox);
        vectorDataNumberOfGlyphsVerticalSpinBox->setObjectName(QString::fromUtf8("vectorDataNumberOfGlyphsVerticalSpinBox"));
        vectorDataNumberOfGlyphsVerticalSpinBox->setKeyboardTracking(false);
        vectorDataNumberOfGlyphsVerticalSpinBox->setMinimum(1);
        vectorDataNumberOfGlyphsVerticalSpinBox->setMaximum(200);
        vectorDataNumberOfGlyphsVerticalSpinBox->setValue(50);

        gridLayout->addWidget(vectorDataNumberOfGlyphsVerticalSpinBox, 1, 3, 1, 1);

        vectorDataNumberOfGlyphsHorizontalSlider = new QSlider(vectorDataNumberOfGlyphsGroupBox);
        vectorDataNumberOfGlyphsHorizontalSlider->setObjectName(QString::fromUtf8("vectorDataNumberOfGlyphsHorizontalSlider"));
        vectorDataNumberOfGlyphsHorizontalSlider->setMinimum(1);
        vectorDataNumberOfGlyphsHorizontalSlider->setMaximum(200);
        vectorDataNumberOfGlyphsHorizontalSlider->setValue(50);
        vectorDataNumberOfGlyphsHorizontalSlider->setTracking(true);
        vectorDataNumberOfGlyphsHorizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(vectorDataNumberOfGlyphsHorizontalSlider, 0, 1, 1, 1);

        vectorDataNumberOfGlyphsHorizontalSpinBox = new QSpinBox(vectorDataNumberOfGlyphsGroupBox);
        vectorDataNumberOfGlyphsHorizontalSpinBox->setObjectName(QString::fromUtf8("vectorDataNumberOfGlyphsHorizontalSpinBox"));
        vectorDataNumberOfGlyphsHorizontalSpinBox->setKeyboardTracking(false);
        vectorDataNumberOfGlyphsHorizontalSpinBox->setMinimum(1);
        vectorDataNumberOfGlyphsHorizontalSpinBox->setMaximum(200);
        vectorDataNumberOfGlyphsHorizontalSpinBox->setValue(50);

        gridLayout->addWidget(vectorDataNumberOfGlyphsHorizontalSpinBox, 0, 2, 1, 2);

        vectorDataNumberOfGlyphsHorizontalLabel = new QLabel(vectorDataNumberOfGlyphsGroupBox);
        vectorDataNumberOfGlyphsHorizontalLabel->setObjectName(QString::fromUtf8("vectorDataNumberOfGlyphsHorizontalLabel"));

        gridLayout->addWidget(vectorDataNumberOfGlyphsHorizontalLabel, 0, 0, 1, 1);

        vectorDataNumberOfGlyphsVerticalLabel = new QLabel(vectorDataNumberOfGlyphsGroupBox);
        vectorDataNumberOfGlyphsVerticalLabel->setObjectName(QString::fromUtf8("vectorDataNumberOfGlyphsVerticalLabel"));

        gridLayout->addWidget(vectorDataNumberOfGlyphsVerticalLabel, 1, 0, 1, 1);


        verticalLayout_6->addWidget(vectorDataNumberOfGlyphsGroupBox);

        vectorDataDataTypeGroupBox = new QGroupBox(vectorDataSettingsPage);
        vectorDataDataTypeGroupBox->setObjectName(QString::fromUtf8("vectorDataDataTypeGroupBox"));
        vectorDataDataTypeGroupBox->setMaximumSize(QSize(16777215, 80));
        verticalLayout_8 = new QVBoxLayout(vectorDataDataTypeGroupBox);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        vectorDataComboBox = new QComboBox(vectorDataDataTypeGroupBox);
        vectorDataComboBox->addItem(QString());
        vectorDataComboBox->addItem(QString());
        vectorDataComboBox->setObjectName(QString::fromUtf8("vectorDataComboBox"));

        verticalLayout_8->addWidget(vectorDataComboBox);


        verticalLayout_6->addWidget(vectorDataDataTypeGroupBox);

        vectorDataGlyphTypeGroupBox = new QGroupBox(vectorDataSettingsPage);
        vectorDataGlyphTypeGroupBox->setObjectName(QString::fromUtf8("vectorDataGlyphTypeGroupBox"));
        vectorDataGlyphTypeGroupBox->setMaximumSize(QSize(16777215, 80));
        gridLayout_5 = new QGridLayout(vectorDataGlyphTypeGroupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        vectorDataGlyphComboBox = new QComboBox(vectorDataGlyphTypeGroupBox);
        vectorDataGlyphComboBox->addItem(QString());
        vectorDataGlyphComboBox->addItem(QString());
        vectorDataGlyphComboBox->addItem(QString());
        vectorDataGlyphComboBox->addItem(QString());
        vectorDataGlyphComboBox->addItem(QString());
        vectorDataGlyphComboBox->setObjectName(QString::fromUtf8("vectorDataGlyphComboBox"));

        gridLayout_5->addWidget(vectorDataGlyphComboBox, 0, 0, 1, 1);


        verticalLayout_6->addWidget(vectorDataGlyphTypeGroupBox);

        vectorDataGlyphMagnifierGroupBox = new QGroupBox(vectorDataSettingsPage);
        vectorDataGlyphMagnifierGroupBox->setObjectName(QString::fromUtf8("vectorDataGlyphMagnifierGroupBox"));
        vectorDataGlyphMagnifierGroupBox->setMaximumSize(QSize(16777215, 80));
        horizontalLayout_6 = new QHBoxLayout(vectorDataGlyphMagnifierGroupBox);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        vectorDataGlyphMagnifierSlider = new QSlider(vectorDataGlyphMagnifierGroupBox);
        vectorDataGlyphMagnifierSlider->setObjectName(QString::fromUtf8("vectorDataGlyphMagnifierSlider"));
        vectorDataGlyphMagnifierSlider->setMaximum(100000);
        vectorDataGlyphMagnifierSlider->setValue(5000);
        vectorDataGlyphMagnifierSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(vectorDataGlyphMagnifierSlider);

        vectorDataGlyphMagnifierDoubleSpinBox = new QDoubleSpinBox(vectorDataGlyphMagnifierGroupBox);
        vectorDataGlyphMagnifierDoubleSpinBox->setObjectName(QString::fromUtf8("vectorDataGlyphMagnifierDoubleSpinBox"));
        vectorDataGlyphMagnifierDoubleSpinBox->setMaximum(1000.000000000000000);
        vectorDataGlyphMagnifierDoubleSpinBox->setValue(50.000000000000000);

        horizontalLayout_6->addWidget(vectorDataGlyphMagnifierDoubleSpinBox);


        verticalLayout_6->addWidget(vectorDataGlyphMagnifierGroupBox);

        vectorDataColorMapGroupBox = new QGroupBox(vectorDataSettingsPage);
        vectorDataColorMapGroupBox->setObjectName(QString::fromUtf8("vectorDataColorMapGroupBox"));
        vectorDataColorMapGroupBox->setMaximumSize(QSize(16777215, 160));
        verticalLayout_9 = new QVBoxLayout(vectorDataColorMapGroupBox);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        vectorDataColorMapComboBox = new QComboBox(vectorDataColorMapGroupBox);
        vectorDataColorMapComboBox->addItem(QString());
        vectorDataColorMapComboBox->addItem(QString());
        vectorDataColorMapComboBox->addItem(QString());
        vectorDataColorMapComboBox->addItem(QString());
        vectorDataColorMapComboBox->setObjectName(QString::fromUtf8("vectorDataColorMapComboBox"));

        verticalLayout_9->addWidget(vectorDataColorMapComboBox);

        vectorDataNumberOfColorsGroupBox = new QGroupBox(vectorDataColorMapGroupBox);
        vectorDataNumberOfColorsGroupBox->setObjectName(QString::fromUtf8("vectorDataNumberOfColorsGroupBox"));
        vectorDataNumberOfColorsGroupBox->setMaximumSize(QSize(16777215, 70));
        horizontalLayout_4 = new QHBoxLayout(vectorDataNumberOfColorsGroupBox);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        vectorDataNumberOfColorsSlider = new QSlider(vectorDataNumberOfColorsGroupBox);
        vectorDataNumberOfColorsSlider->setObjectName(QString::fromUtf8("vectorDataNumberOfColorsSlider"));
        vectorDataNumberOfColorsSlider->setMinimum(2);
        vectorDataNumberOfColorsSlider->setMaximum(256);
        vectorDataNumberOfColorsSlider->setValue(256);
        vectorDataNumberOfColorsSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(vectorDataNumberOfColorsSlider);

        vectorDataNumberOfColorsSpinBox = new QSpinBox(vectorDataNumberOfColorsGroupBox);
        vectorDataNumberOfColorsSpinBox->setObjectName(QString::fromUtf8("vectorDataNumberOfColorsSpinBox"));
        vectorDataNumberOfColorsSpinBox->setMinimum(2);
        vectorDataNumberOfColorsSpinBox->setMaximum(256);
        vectorDataNumberOfColorsSpinBox->setValue(256);

        horizontalLayout_4->addWidget(vectorDataNumberOfColorsSpinBox);


        verticalLayout_9->addWidget(vectorDataNumberOfColorsGroupBox);


        verticalLayout_6->addWidget(vectorDataColorMapGroupBox);

        settingsPages->addTab(vectorDataSettingsPage, QString());
        isolinesSettingsPage = new QWidget();
        isolinesSettingsPage->setObjectName(QString::fromUtf8("isolinesSettingsPage"));
        isolinesSettingsPage->setAutoFillBackground(true);
        verticalLayout_2 = new QVBoxLayout(isolinesSettingsPage);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        isolinesDrawSettingsGroupBox = new QGroupBox(isolinesSettingsPage);
        isolinesDrawSettingsGroupBox->setObjectName(QString::fromUtf8("isolinesDrawSettingsGroupBox"));
        isolinesDrawSettingsGroupBox->setMaximumSize(QSize(16777215, 70));
        horizontalLayout_9 = new QHBoxLayout(isolinesDrawSettingsGroupBox);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        isolinesDrawIsolinesCheckBox = new QCheckBox(isolinesDrawSettingsGroupBox);
        isolinesDrawIsolinesCheckBox->setObjectName(QString::fromUtf8("isolinesDrawIsolinesCheckBox"));

        horizontalLayout_9->addWidget(isolinesDrawIsolinesCheckBox);

        isolinesColorPickerButton = new QPushButton(isolinesDrawSettingsGroupBox);
        isolinesColorPickerButton->setObjectName(QString::fromUtf8("isolinesColorPickerButton"));
        isolinesColorPickerButton->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_9->addWidget(isolinesColorPickerButton);


        verticalLayout_2->addWidget(isolinesDrawSettingsGroupBox);

        isolinesUseCurrentScalarDataCheckBox = new QCheckBox(isolinesSettingsPage);
        isolinesUseCurrentScalarDataCheckBox->setObjectName(QString::fromUtf8("isolinesUseCurrentScalarDataCheckBox"));
        isolinesUseCurrentScalarDataCheckBox->setChecked(true);

        verticalLayout_2->addWidget(isolinesUseCurrentScalarDataCheckBox);

        isolinesDataGroupBox = new QGroupBox(isolinesSettingsPage);
        isolinesDataGroupBox->setObjectName(QString::fromUtf8("isolinesDataGroupBox"));
        isolinesDataGroupBox->setMaximumSize(QSize(16777215, 80));
        verticalLayout_12 = new QVBoxLayout(isolinesDataGroupBox);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        isolinesDataComboBox = new QComboBox(isolinesDataGroupBox);
        isolinesDataComboBox->addItem(QString());
        isolinesDataComboBox->addItem(QString());
        isolinesDataComboBox->addItem(QString());
        isolinesDataComboBox->addItem(QString());
        isolinesDataComboBox->addItem(QString());
        isolinesDataComboBox->setObjectName(QString::fromUtf8("isolinesDataComboBox"));
        isolinesDataComboBox->setEnabled(false);

        verticalLayout_12->addWidget(isolinesDataComboBox);


        verticalLayout_2->addWidget(isolinesDataGroupBox);

        isolinesInterpolationSettingsGroupBox = new QGroupBox(isolinesSettingsPage);
        isolinesInterpolationSettingsGroupBox->setObjectName(QString::fromUtf8("isolinesInterpolationSettingsGroupBox"));
        isolinesInterpolationSettingsGroupBox->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_5 = new QHBoxLayout(isolinesInterpolationSettingsGroupBox);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        isolinesInterpolationMethodSettingsGroupBox = new QGroupBox(isolinesInterpolationSettingsGroupBox);
        isolinesInterpolationMethodSettingsGroupBox->setObjectName(QString::fromUtf8("isolinesInterpolationMethodSettingsGroupBox"));
        isolinesInterpolationMethodSettingsGroupBox->setMinimumSize(QSize(0, 0));
        horizontalLayout_16 = new QHBoxLayout(isolinesInterpolationMethodSettingsGroupBox);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        isolinesInterpolationMethodLinearRadioButton = new QRadioButton(isolinesInterpolationMethodSettingsGroupBox);
        isolinesInterpolationMethodLinearRadioButton->setObjectName(QString::fromUtf8("isolinesInterpolationMethodLinearRadioButton"));
        isolinesInterpolationMethodLinearRadioButton->setChecked(true);

        horizontalLayout_16->addWidget(isolinesInterpolationMethodLinearRadioButton);

        isolinesInterpolationMethodNoneRadioButton = new QRadioButton(isolinesInterpolationMethodSettingsGroupBox);
        isolinesInterpolationMethodNoneRadioButton->setObjectName(QString::fromUtf8("isolinesInterpolationMethodNoneRadioButton"));

        horizontalLayout_16->addWidget(isolinesInterpolationMethodNoneRadioButton);


        horizontalLayout_5->addWidget(isolinesInterpolationMethodSettingsGroupBox);

        isolinesAmbiguousCaseDeciderSettingsGroupBox = new QGroupBox(isolinesInterpolationSettingsGroupBox);
        isolinesAmbiguousCaseDeciderSettingsGroupBox->setObjectName(QString::fromUtf8("isolinesAmbiguousCaseDeciderSettingsGroupBox"));
        isolinesAmbiguousCaseDeciderSettingsGroupBox->setMinimumSize(QSize(0, 0));
        horizontalLayout_15 = new QHBoxLayout(isolinesAmbiguousCaseDeciderSettingsGroupBox);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        isolinesAmbiguousCaseDeciderMidpointRadioButton = new QRadioButton(isolinesAmbiguousCaseDeciderSettingsGroupBox);
        isolinesAmbiguousCaseDeciderMidpointRadioButton->setObjectName(QString::fromUtf8("isolinesAmbiguousCaseDeciderMidpointRadioButton"));
        isolinesAmbiguousCaseDeciderMidpointRadioButton->setChecked(true);

        horizontalLayout_15->addWidget(isolinesAmbiguousCaseDeciderMidpointRadioButton);

        isolinesAmbiguousCaseDeciderAsymptoticRadioButton = new QRadioButton(isolinesAmbiguousCaseDeciderSettingsGroupBox);
        isolinesAmbiguousCaseDeciderAsymptoticRadioButton->setObjectName(QString::fromUtf8("isolinesAmbiguousCaseDeciderAsymptoticRadioButton"));
        isolinesAmbiguousCaseDeciderAsymptoticRadioButton->setMinimumSize(QSize(0, 0));
        isolinesAmbiguousCaseDeciderAsymptoticRadioButton->setChecked(false);

        horizontalLayout_15->addWidget(isolinesAmbiguousCaseDeciderAsymptoticRadioButton);


        horizontalLayout_5->addWidget(isolinesAmbiguousCaseDeciderSettingsGroupBox);


        verticalLayout_2->addWidget(isolinesInterpolationSettingsGroupBox);

        isolinesNumberOfIsolinesGroupBox = new QGroupBox(isolinesSettingsPage);
        isolinesNumberOfIsolinesGroupBox->setObjectName(QString::fromUtf8("isolinesNumberOfIsolinesGroupBox"));
        isolinesNumberOfIsolinesGroupBox->setMaximumSize(QSize(16777215, 80));
        horizontalLayout_7 = new QHBoxLayout(isolinesNumberOfIsolinesGroupBox);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        isolinesNumberOfIsolinesSlider = new QSlider(isolinesNumberOfIsolinesGroupBox);
        isolinesNumberOfIsolinesSlider->setObjectName(QString::fromUtf8("isolinesNumberOfIsolinesSlider"));
        isolinesNumberOfIsolinesSlider->setMinimum(1);
        isolinesNumberOfIsolinesSlider->setMaximum(20);
        isolinesNumberOfIsolinesSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(isolinesNumberOfIsolinesSlider);

        isolinesNumberOfIsolinesSpinBox = new QSpinBox(isolinesNumberOfIsolinesGroupBox);
        isolinesNumberOfIsolinesSpinBox->setObjectName(QString::fromUtf8("isolinesNumberOfIsolinesSpinBox"));
        isolinesNumberOfIsolinesSpinBox->setMinimum(1);
        isolinesNumberOfIsolinesSpinBox->setMaximum(20);

        horizontalLayout_7->addWidget(isolinesNumberOfIsolinesSpinBox);


        verticalLayout_2->addWidget(isolinesNumberOfIsolinesGroupBox);

        isolinesRangeGroupBox = new QGroupBox(isolinesSettingsPage);
        isolinesRangeGroupBox->setObjectName(QString::fromUtf8("isolinesRangeGroupBox"));
        isolinesRangeGroupBox->setMaximumSize(QSize(16777215, 150));
        formLayout_6 = new QFormLayout(isolinesRangeGroupBox);
        formLayout_6->setSpacing(6);
        formLayout_6->setContentsMargins(11, 11, 11, 11);
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        isolinesRangeRhoMinSlider = new QSlider(isolinesRangeGroupBox);
        isolinesRangeRhoMinSlider->setObjectName(QString::fromUtf8("isolinesRangeRhoMinSlider"));
        isolinesRangeRhoMinSlider->setMaximum(100);
        isolinesRangeRhoMinSlider->setValue(5);
        isolinesRangeRhoMinSlider->setOrientation(Qt::Horizontal);

        formLayout_6->setWidget(1, QFormLayout::LabelRole, isolinesRangeRhoMinSlider);

        isolinesRangeRhoMaxSlider = new QSlider(isolinesRangeGroupBox);
        isolinesRangeRhoMaxSlider->setObjectName(QString::fromUtf8("isolinesRangeRhoMaxSlider"));
        isolinesRangeRhoMaxSlider->setMaximum(100);
        isolinesRangeRhoMaxSlider->setValue(5);
        isolinesRangeRhoMaxSlider->setOrientation(Qt::Horizontal);

        formLayout_6->setWidget(3, QFormLayout::LabelRole, isolinesRangeRhoMaxSlider);

        isolinesRangeRhoMinLabel = new QLabel(isolinesRangeGroupBox);
        isolinesRangeRhoMinLabel->setObjectName(QString::fromUtf8("isolinesRangeRhoMinLabel"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, isolinesRangeRhoMinLabel);

        isolinesRangeRhoMaxLabel = new QLabel(isolinesRangeGroupBox);
        isolinesRangeRhoMaxLabel->setObjectName(QString::fromUtf8("isolinesRangeRhoMaxLabel"));

        formLayout_6->setWidget(2, QFormLayout::LabelRole, isolinesRangeRhoMaxLabel);

        isolinesRangeRhoMinSpinBox = new QDoubleSpinBox(isolinesRangeGroupBox);
        isolinesRangeRhoMinSpinBox->setObjectName(QString::fromUtf8("isolinesRangeRhoMinSpinBox"));
        isolinesRangeRhoMinSpinBox->setDecimals(2);
        isolinesRangeRhoMinSpinBox->setMaximum(10.000000000000000);
        isolinesRangeRhoMinSpinBox->setSingleStep(0.100000000000000);
        isolinesRangeRhoMinSpinBox->setValue(0.500000000000000);

        formLayout_6->setWidget(1, QFormLayout::FieldRole, isolinesRangeRhoMinSpinBox);

        isolinesRangeRhoMaxSpinBox = new QDoubleSpinBox(isolinesRangeGroupBox);
        isolinesRangeRhoMaxSpinBox->setObjectName(QString::fromUtf8("isolinesRangeRhoMaxSpinBox"));
        isolinesRangeRhoMaxSpinBox->setDecimals(2);
        isolinesRangeRhoMaxSpinBox->setMaximum(10.000000000000000);
        isolinesRangeRhoMaxSpinBox->setSingleStep(0.100000000000000);
        isolinesRangeRhoMaxSpinBox->setValue(0.500000000000000);

        formLayout_6->setWidget(3, QFormLayout::FieldRole, isolinesRangeRhoMaxSpinBox);


        verticalLayout_2->addWidget(isolinesRangeGroupBox);

        settingsPages->addTab(isolinesSettingsPage, QString());
        heightplotSettingsPage = new QWidget();
        heightplotSettingsPage->setObjectName(QString::fromUtf8("heightplotSettingsPage"));
        verticalLayout_13 = new QVBoxLayout(heightplotSettingsPage);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        showHeightplotCheckBox = new QCheckBox(heightplotSettingsPage);
        showHeightplotCheckBox->setObjectName(QString::fromUtf8("showHeightplotCheckBox"));

        verticalLayout_13->addWidget(showHeightplotCheckBox);

        heightplotDataType = new QGroupBox(heightplotSettingsPage);
        heightplotDataType->setObjectName(QString::fromUtf8("heightplotDataType"));
        heightplotDataType->setMaximumSize(QSize(16777215, 80));
        verticalLayout_11 = new QVBoxLayout(heightplotDataType);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        heightplotDataTypeComboBox = new QComboBox(heightplotDataType);
        heightplotDataTypeComboBox->addItem(QString());
        heightplotDataTypeComboBox->addItem(QString());
        heightplotDataTypeComboBox->addItem(QString());
        heightplotDataTypeComboBox->addItem(QString());
        heightplotDataTypeComboBox->addItem(QString());
        heightplotDataTypeComboBox->setObjectName(QString::fromUtf8("heightplotDataTypeComboBox"));

        verticalLayout_11->addWidget(heightplotDataTypeComboBox);


        verticalLayout_13->addWidget(heightplotDataType);

        heightplotViewRotationGroupBox = new QGroupBox(heightplotSettingsPage);
        heightplotViewRotationGroupBox->setObjectName(QString::fromUtf8("heightplotViewRotationGroupBox"));
        heightplotViewRotationGroupBox->setMaximumSize(QSize(16777215, 200));
        gridLayout_4 = new QGridLayout(heightplotViewRotationGroupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        heightplotViewRotationXAxis = new QLabel(heightplotViewRotationGroupBox);
        heightplotViewRotationXAxis->setObjectName(QString::fromUtf8("heightplotViewRotationXAxis"));
        heightplotViewRotationXAxis->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(heightplotViewRotationXAxis, 0, 0, 1, 1);

        heightplotViewRotateZ = new QDial(heightplotViewRotationGroupBox);
        heightplotViewRotateZ->setObjectName(QString::fromUtf8("heightplotViewRotateZ"));
        heightplotViewRotateZ->setMaximum(180);
        heightplotViewRotateZ->setInvertedAppearance(false);
        heightplotViewRotateZ->setNotchTarget(10.000000000000000);
        heightplotViewRotateZ->setNotchesVisible(true);

        gridLayout_4->addWidget(heightplotViewRotateZ, 1, 2, 1, 1);

        heightplotViewRotateY = new QDial(heightplotViewRotationGroupBox);
        heightplotViewRotateY->setObjectName(QString::fromUtf8("heightplotViewRotateY"));
        heightplotViewRotateY->setMaximum(180);
        heightplotViewRotateY->setNotchTarget(10.000000000000000);
        heightplotViewRotateY->setNotchesVisible(true);

        gridLayout_4->addWidget(heightplotViewRotateY, 1, 1, 1, 1);

        heightplotViewRotateX = new QDial(heightplotViewRotationGroupBox);
        heightplotViewRotateX->setObjectName(QString::fromUtf8("heightplotViewRotateX"));
        heightplotViewRotateX->setMaximum(180);
        heightplotViewRotateX->setNotchTarget(10.000000000000000);
        heightplotViewRotateX->setNotchesVisible(true);

        gridLayout_4->addWidget(heightplotViewRotateX, 1, 0, 1, 1);

        heightplotViewRotationYAxis = new QLabel(heightplotViewRotationGroupBox);
        heightplotViewRotationYAxis->setObjectName(QString::fromUtf8("heightplotViewRotationYAxis"));
        heightplotViewRotationYAxis->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(heightplotViewRotationYAxis, 0, 1, 1, 1);

        heightplotViewRotationZAxis = new QLabel(heightplotViewRotationGroupBox);
        heightplotViewRotationZAxis->setObjectName(QString::fromUtf8("heightplotViewRotationZAxis"));
        heightplotViewRotationZAxis->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(heightplotViewRotationZAxis, 0, 2, 1, 1);


        verticalLayout_13->addWidget(heightplotViewRotationGroupBox);

        heightplotResetRotation = new QPushButton(heightplotSettingsPage);
        heightplotResetRotation->setObjectName(QString::fromUtf8("heightplotResetRotation"));

        verticalLayout_13->addWidget(heightplotResetRotation);

        settingsPages->addTab(heightplotSettingsPage, QString());
        LICSettingsPage = new QWidget();
        LICSettingsPage->setObjectName(QString::fromUtf8("LICSettingsPage"));
        verticalLayout_15 = new QVBoxLayout(LICSettingsPage);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        LICSettings = new QVBoxLayout();
        LICSettings->setSpacing(6);
        LICSettings->setObjectName(QString::fromUtf8("LICSettings"));
        drawLicCheckBox = new QCheckBox(LICSettingsPage);
        drawLicCheckBox->setObjectName(QString::fromUtf8("drawLicCheckBox"));

        LICSettings->addWidget(drawLicCheckBox);


        verticalLayout_15->addLayout(LICSettings);

        settingsPages->addTab(LICSettingsPage, QString());
        volumeRenderingSettingsPage = new QWidget();
        volumeRenderingSettingsPage->setObjectName(QString::fromUtf8("volumeRenderingSettingsPage"));
        verticalLayout_16 = new QVBoxLayout(volumeRenderingSettingsPage);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        drawVolumeRenderingCheckBox = new QCheckBox(volumeRenderingSettingsPage);
        drawVolumeRenderingCheckBox->setObjectName(QString::fromUtf8("drawVolumeRenderingCheckBox"));

        verticalLayout_16->addWidget(drawVolumeRenderingCheckBox);

        settingsPages->addTab(volumeRenderingSettingsPage, QString());

        horizontalLayout->addWidget(settingsPages);

        openGLWidgetsVerticalLayout = new QVBoxLayout();
        openGLWidgetsVerticalLayout->setSpacing(6);
        openGLWidgetsVerticalLayout->setObjectName(QString::fromUtf8("openGLWidgetsVerticalLayout"));
        visualizationOpenGLWidget = new Visualization(centralWidget);
        visualizationOpenGLWidget->setObjectName(QString::fromUtf8("visualizationOpenGLWidget"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(visualizationOpenGLWidget->sizePolicy().hasHeightForWidth());
        visualizationOpenGLWidget->setSizePolicy(sizePolicy5);
        visualizationOpenGLWidget->setMinimumSize(QSize(600, 600));
        visualizationOpenGLWidget->setFocusPolicy(Qt::ClickFocus);

        openGLWidgetsVerticalLayout->addWidget(visualizationOpenGLWidget);

        legendsAndExtremaGridLayout = new QGridLayout();
        legendsAndExtremaGridLayout->setSpacing(6);
        legendsAndExtremaGridLayout->setObjectName(QString::fromUtf8("legendsAndExtremaGridLayout"));
        vectorDataLabel = new QLabel(centralWidget);
        vectorDataLabel->setObjectName(QString::fromUtf8("vectorDataLabel"));

        legendsAndExtremaGridLayout->addWidget(vectorDataLabel, 1, 0, 1, 1);

        legendVectorDataOpenGLWidget = new LegendVectorData(centralWidget);
        legendVectorDataOpenGLWidget->setObjectName(QString::fromUtf8("legendVectorDataOpenGLWidget"));
        sizePolicy2.setHeightForWidth(legendVectorDataOpenGLWidget->sizePolicy().hasHeightForWidth());
        legendVectorDataOpenGLWidget->setSizePolicy(sizePolicy2);
        legendVectorDataOpenGLWidget->setMinimumSize(QSize(400, 25));
        legendVectorDataOpenGLWidget->setMaximumSize(QSize(16777215, 25));

        legendsAndExtremaGridLayout->addWidget(legendVectorDataOpenGLWidget, 1, 2, 1, 1);

        vectorDataMaxLcdNumber = new QLCDNumber(centralWidget);
        vectorDataMaxLcdNumber->setObjectName(QString::fromUtf8("vectorDataMaxLcdNumber"));
        vectorDataMaxLcdNumber->setDigitCount(3);

        legendsAndExtremaGridLayout->addWidget(vectorDataMaxLcdNumber, 1, 3, 1, 1);

        scalarDataLabel = new QLabel(centralWidget);
        scalarDataLabel->setObjectName(QString::fromUtf8("scalarDataLabel"));

        legendsAndExtremaGridLayout->addWidget(scalarDataLabel, 0, 0, 1, 1);

        scalarDataMinLcdNumber = new QLCDNumber(centralWidget);
        scalarDataMinLcdNumber->setObjectName(QString::fromUtf8("scalarDataMinLcdNumber"));
        scalarDataMinLcdNumber->setDigitCount(3);

        legendsAndExtremaGridLayout->addWidget(scalarDataMinLcdNumber, 0, 1, 1, 1);

        vectorDataMinLcdNumber = new QLCDNumber(centralWidget);
        vectorDataMinLcdNumber->setObjectName(QString::fromUtf8("vectorDataMinLcdNumber"));
        vectorDataMinLcdNumber->setDigitCount(3);

        legendsAndExtremaGridLayout->addWidget(vectorDataMinLcdNumber, 1, 1, 1, 1);

        legendScalarDataOpenGLWidget = new LegendScalarData(centralWidget);
        legendScalarDataOpenGLWidget->setObjectName(QString::fromUtf8("legendScalarDataOpenGLWidget"));
        sizePolicy2.setHeightForWidth(legendScalarDataOpenGLWidget->sizePolicy().hasHeightForWidth());
        legendScalarDataOpenGLWidget->setSizePolicy(sizePolicy2);
        legendScalarDataOpenGLWidget->setMinimumSize(QSize(400, 25));
        legendScalarDataOpenGLWidget->setMaximumSize(QSize(16777215, 25));

        legendsAndExtremaGridLayout->addWidget(legendScalarDataOpenGLWidget, 0, 2, 1, 1);

        scalarDataMaxLcdNumber = new QLCDNumber(centralWidget);
        scalarDataMaxLcdNumber->setObjectName(QString::fromUtf8("scalarDataMaxLcdNumber"));
        scalarDataMaxLcdNumber->setDigitCount(3);

        legendsAndExtremaGridLayout->addWidget(scalarDataMaxLcdNumber, 0, 3, 1, 1);


        openGLWidgetsVerticalLayout->addLayout(legendsAndExtremaGridLayout);


        horizontalLayout->addLayout(openGLWidgetsVerticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(scalarDataColorMapNumberOfColorsSlider, &QSlider::valueChanged, scalarDataColorMapNumberOfColorsSpinBox, &QSpinBox::setValue);
        QObject::connect(scalarDataColorMapNumberOfColorsSpinBox, &QSpinBox::valueChanged, scalarDataColorMapNumberOfColorsSlider, &QSlider::setValue);
        QObject::connect(vectorDataNumberOfColorsSlider, &QSlider::valueChanged, vectorDataNumberOfColorsSpinBox, &QSpinBox::setValue);
        QObject::connect(vectorDataNumberOfColorsSpinBox, &QSpinBox::valueChanged, vectorDataNumberOfColorsSlider, &QSlider::setValue);
        QObject::connect(isolinesNumberOfIsolinesSlider, &QSlider::valueChanged, isolinesNumberOfIsolinesSpinBox, &QSpinBox::setValue);
        QObject::connect(isolinesNumberOfIsolinesSpinBox, &QSpinBox::valueChanged, isolinesNumberOfIsolinesSlider, &QSlider::setValue);
        QObject::connect(gridpointsSpinBox, &QSpinBox::valueChanged, gridpointsSlider, &QSlider::setValue);
        QObject::connect(vectorDataNumberOfGlyphsHorizontalSlider, &QSlider::valueChanged, vectorDataNumberOfGlyphsHorizontalSpinBox, &QSpinBox::setValue);
        QObject::connect(vectorDataNumberOfGlyphsHorizontalSpinBox, &QSpinBox::valueChanged, vectorDataNumberOfGlyphsHorizontalSlider, &QSlider::setValue);
        QObject::connect(vectorDataNumberOfGlyphsVerticalSlider, &QSlider::valueChanged, vectorDataNumberOfGlyphsVerticalSpinBox, &QSpinBox::setValue);
        QObject::connect(vectorDataNumberOfGlyphsVerticalSpinBox, &QSpinBox::valueChanged, vectorDataNumberOfGlyphsVerticalSlider, &QSlider::setValue);
        QObject::connect(isolinesUseCurrentScalarDataCheckBox, &QCheckBox::toggled, isolinesDataComboBox, &QComboBox::setDisabled);
        QObject::connect(showMinMaxDataCheckBox, &QCheckBox::toggled, scalarDataMinLcdNumber, &QLCDNumber::setVisible);
        QObject::connect(showMinMaxDataCheckBox, &QCheckBox::toggled, scalarDataMaxLcdNumber, &QLCDNumber::setVisible);
        QObject::connect(showMinMaxDataCheckBox, &QCheckBox::toggled, vectorDataMinLcdNumber, &QLCDNumber::setVisible);
        QObject::connect(showMinMaxDataCheckBox, &QCheckBox::toggled, vectorDataMaxLcdNumber, &QLCDNumber::setVisible);
        QObject::connect(gridpointsSlider, &QSlider::valueChanged, gridpointsSpinBox, &QSpinBox::setValue);
        QObject::connect(scalarDataSlicingSliceIndexHorizontalSlider, &QSlider::valueChanged, scalarDataSlicingSliceIndexSpinBox, &QSpinBox::setValue);

        settingsPages->setCurrentIndex(4);
        quantizationBitsComboBox->setCurrentIndex(0);
        vectorDataGlyphComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Real-time smoke simulation and visualization", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        showMinMaxDataCheckBox->setText(QCoreApplication::translate("MainWindow", "Show minimum/maximum data values", nullptr));
        fluidGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Injected fluid", nullptr));
        density->setText(QCoreApplication::translate("MainWindow", "Density", nullptr));
        viscosity->setText(QCoreApplication::translate("MainWindow", "Viscosity", nullptr));
        densityUnits->setText(QCoreApplication::translate("MainWindow", "kg/m^3", nullptr));
        viscosityUnits->setText(QCoreApplication::translate("MainWindow", "mPa s", nullptr));
        timestepGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Speed (time step)", nullptr));
        timestepUnits->setText(QCoreApplication::translate("MainWindow", "s", nullptr));
        gridpointsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Dimensions (must be even)", nullptr));
        pausePlayButton->setText(QCoreApplication::translate("MainWindow", "Pause / Play", nullptr));
        loadDataButton->setText(QCoreApplication::translate("MainWindow", "Load data", nullptr));
        settingsPages->setTabText(settingsPages->indexOf(SimulationSettingsPage), QCoreApplication::translate("MainWindow", "Simulation", nullptr));
        visualizationProjectionGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Projection", nullptr));
        visualizationProjectionOrthographicRadioButton->setText(QCoreApplication::translate("MainWindow", "Orthographic", nullptr));
        visualizationProjectionPerspectiveRadioButton->setText(QCoreApplication::translate("MainWindow", "Perspective", nullptr));
        settingsPages->setTabText(settingsPages->indexOf(VisualizationPage), QCoreApplication::translate("MainWindow", "Visualization", nullptr));
        quantizationGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Quantization", nullptr));
        quantizationCheckBox->setText(QCoreApplication::translate("MainWindow", "Enable quantization", nullptr));
        quantizationBitsComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        quantizationBitsComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        quantizationBitsComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "4", nullptr));
        quantizationBitsComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        gaussianBlurGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Gaussian blur", nullptr));
        gaussianBlurCheckBox->setText(QCoreApplication::translate("MainWindow", "Enable Gaussian blur", nullptr));
        gradientsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Gradient magnitudes", nullptr));
        gradientsCheckBox->setText(QCoreApplication::translate("MainWindow", "Enable scalar grid to gradient magnitudes mapping", nullptr));
        scalarDataSlicingGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Slicing", nullptr));
        scalarDataSlicingDirectionYRadioButton->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
        scalarDataSlicingSliceIndexLabel->setText(QCoreApplication::translate("MainWindow", "Slice index:", nullptr));
        scalarDataSlicingDirectionLabel->setText(QCoreApplication::translate("MainWindow", "Direction:", nullptr));
        scalarDataSlicingDirectionXRadioButton->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        scalarDataslicingEnableCheckBox->setText(QCoreApplication::translate("MainWindow", "Enable slicing", nullptr));
        scalarDataSlicingDirectionTRadioButton->setText(QCoreApplication::translate("MainWindow", "t", nullptr));
        settingsPages->setTabText(settingsPages->indexOf(PreprocessingSettingsPage), QCoreApplication::translate("MainWindow", "Preprocessing", nullptr));
        scalarDataDrawScalarDataCheckBox->setText(QCoreApplication::translate("MainWindow", "Draw scalar data", nullptr));
        scalarDataTypeGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Data type", nullptr));
        scalarDataComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Density", nullptr));
        scalarDataComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Velocity magnitude", nullptr));
        scalarDataComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Force field magnitude", nullptr));
        scalarDataComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Velocity divergence", nullptr));
        scalarDataComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Force field divergence", nullptr));

        scalarDataColormapGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Color map", nullptr));
        scalarDataColorMapComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Grayscale", nullptr));
        scalarDataColorMapComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Rainbow", nullptr));
        scalarDataColorMapComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Heatmap", nullptr));
        scalarDataColorMapComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Blue to yellow (divergent)", nullptr));
        scalarDataColorMapComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Custom: 3 colors", nullptr));

        scalarDataNumberOfColorsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Number of colors", nullptr));
        scalarDataCustomColorMapGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Custom: 3 color selector", nullptr));
        scalarDataCustomColorIndexLabel->setText(QCoreApplication::translate("MainWindow", "Index", nullptr));
        scalarDataCustomColorPickerPushButton->setText(QCoreApplication::translate("MainWindow", "Pick a color for this index", nullptr));
        scalarDataMappingGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Mapping", nullptr));
        scalarDataMappingNormalizationGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Normalization", nullptr));
        scalarDataMappingMappingTypeClampingRadioButton->setText(QCoreApplication::translate("MainWindow", "Clamping", nullptr));
        scalarDataMappingMappingTypeScalingRadioButton->setText(QCoreApplication::translate("MainWindow", "Scaling", nullptr));
        scalarDataMappingTransferGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Transfer function K", nullptr));
        scalarDataMappingClampingGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Clamping", nullptr));
        scalarDataMappingClampingMinLabel->setText(QCoreApplication::translate("MainWindow", "Minimum", nullptr));
        scalarDataMappingClampingMaxLabel->setText(QCoreApplication::translate("MainWindow", "Maximum", nullptr));
        scalarDataMappingScalingGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Scaling", nullptr));
        scalarDataMappingScalingMovingAverageWindowSizeLabel->setText(QCoreApplication::translate("MainWindow", "Moving average window size", nullptr));
        settingsPages->setTabText(settingsPages->indexOf(scalarDataSettingsPage), QCoreApplication::translate("MainWindow", "Scalar field", nullptr));
        vectorDataDrawGlyphsCheckBox->setText(QCoreApplication::translate("MainWindow", "Draw glyphs", nullptr));
        vectorDataNumberOfGlyphsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Number of glyphs", nullptr));
        vectorDataNumberOfGlyphsHorizontalLabel->setText(QCoreApplication::translate("MainWindow", "Horizontal", nullptr));
        vectorDataNumberOfGlyphsVerticalLabel->setText(QCoreApplication::translate("MainWindow", "Vertical", nullptr));
        vectorDataDataTypeGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Data type", nullptr));
        vectorDataComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Velocity", nullptr));
        vectorDataComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Force field", nullptr));

        vectorDataGlyphTypeGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Glyph type", nullptr));
        vectorDataGlyphComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Hedgehogs", nullptr));
        vectorDataGlyphComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Triangles", nullptr));
        vectorDataGlyphComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Cones", nullptr));
        vectorDataGlyphComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "2D arrows", nullptr));
        vectorDataGlyphComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "3D arrows", nullptr));

        vectorDataGlyphMagnifierGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Glyph magnifier", nullptr));
        vectorDataColorMapGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Color map", nullptr));
        vectorDataColorMapComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Grayscale", nullptr));
        vectorDataColorMapComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Rainbow", nullptr));
        vectorDataColorMapComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Heatmap", nullptr));
        vectorDataColorMapComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Blue to yellow (divergent)", nullptr));

        vectorDataNumberOfColorsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Number of colors", nullptr));
        settingsPages->setTabText(settingsPages->indexOf(vectorDataSettingsPage), QCoreApplication::translate("MainWindow", "Vector field", nullptr));
        isolinesDrawSettingsGroupBox->setTitle(QString());
        isolinesDrawIsolinesCheckBox->setText(QCoreApplication::translate("MainWindow", "Draw isolines", nullptr));
        isolinesColorPickerButton->setText(QCoreApplication::translate("MainWindow", "Pick a color...", nullptr));
        isolinesUseCurrentScalarDataCheckBox->setText(QCoreApplication::translate("MainWindow", "Use same data as current scalar data", nullptr));
        isolinesDataGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Data used to draw isolines", nullptr));
        isolinesDataComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Density", nullptr));
        isolinesDataComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Velocity magnitude", nullptr));
        isolinesDataComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Force field magnitude", nullptr));
        isolinesDataComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Velocity divergence", nullptr));
        isolinesDataComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Force field divergence", nullptr));

        isolinesInterpolationSettingsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Interpolation Settings", nullptr));
        isolinesInterpolationMethodSettingsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Interpolation method", nullptr));
        isolinesInterpolationMethodLinearRadioButton->setText(QCoreApplication::translate("MainWindow", "Linear", nullptr));
        isolinesInterpolationMethodNoneRadioButton->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        isolinesAmbiguousCaseDeciderSettingsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Ambiguous Case Decider", nullptr));
        isolinesAmbiguousCaseDeciderMidpointRadioButton->setText(QCoreApplication::translate("MainWindow", "Midpoint", nullptr));
        isolinesAmbiguousCaseDeciderAsymptoticRadioButton->setText(QCoreApplication::translate("MainWindow", "Asymptotic", nullptr));
        isolinesNumberOfIsolinesGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Number of isolines", nullptr));
        isolinesRangeGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Range", nullptr));
        isolinesRangeRhoMinLabel->setText(QCoreApplication::translate("MainWindow", "Min. value", nullptr));
        isolinesRangeRhoMaxLabel->setText(QCoreApplication::translate("MainWindow", "Max. value", nullptr));
        settingsPages->setTabText(settingsPages->indexOf(isolinesSettingsPage), QCoreApplication::translate("MainWindow", "Isolines", nullptr));
        showHeightplotCheckBox->setText(QCoreApplication::translate("MainWindow", "Show height plot", nullptr));
        heightplotDataType->setTitle(QCoreApplication::translate("MainWindow", "Data used for height", nullptr));
        heightplotDataTypeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Density", nullptr));
        heightplotDataTypeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Velocity magnitude", nullptr));
        heightplotDataTypeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Force field magnitude", nullptr));
        heightplotDataTypeComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Velocity divergence", nullptr));
        heightplotDataTypeComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Force field divergence", nullptr));

        heightplotViewRotationGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Rotation", nullptr));
        heightplotViewRotationXAxis->setText(QCoreApplication::translate("MainWindow", "X-axis", nullptr));
        heightplotViewRotationYAxis->setText(QCoreApplication::translate("MainWindow", "Y-axis", nullptr));
        heightplotViewRotationZAxis->setText(QCoreApplication::translate("MainWindow", "Z-axis", nullptr));
        heightplotResetRotation->setText(QCoreApplication::translate("MainWindow", "Reset rotation", nullptr));
        settingsPages->setTabText(settingsPages->indexOf(heightplotSettingsPage), QCoreApplication::translate("MainWindow", "Height plot", nullptr));
        drawLicCheckBox->setText(QCoreApplication::translate("MainWindow", "Draw LIC", nullptr));
        settingsPages->setTabText(settingsPages->indexOf(LICSettingsPage), QCoreApplication::translate("MainWindow", "LIC", nullptr));
        drawVolumeRenderingCheckBox->setText(QCoreApplication::translate("MainWindow", "Draw volume rendering", nullptr));
        settingsPages->setTabText(settingsPages->indexOf(volumeRenderingSettingsPage), QCoreApplication::translate("MainWindow", "Volume", nullptr));
        vectorDataLabel->setText(QCoreApplication::translate("MainWindow", "Vector data", nullptr));
        scalarDataLabel->setText(QCoreApplication::translate("MainWindow", "Scalar data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
