/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../smoke_framework/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[154];
    char stringdata0[3023];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 33), // "on_showMinMaxDataCheckBox_tog..."
QT_MOC_LITERAL(45, 0), // ""
QT_MOC_LITERAL(46, 7), // "checked"
QT_MOC_LITERAL(54, 29), // "on_densitySlider_valueChanged"
QT_MOC_LITERAL(84, 5), // "value"
QT_MOC_LITERAL(90, 30), // "on_densitySpinBox_valueChanged"
QT_MOC_LITERAL(121, 31), // "on_viscositySlider_valueChanged"
QT_MOC_LITERAL(153, 32), // "on_viscositySpinBox_valueChanged"
QT_MOC_LITERAL(186, 30), // "on_timestepSlider_valueChanged"
QT_MOC_LITERAL(217, 31), // "on_timestepSpinBox_valueChanged"
QT_MOC_LITERAL(249, 33), // "on_gridpointsSpinBox_valueCha..."
QT_MOC_LITERAL(283, 26), // "on_pausePlayButton_clicked"
QT_MOC_LITERAL(310, 25), // "on_loadDataButton_clicked"
QT_MOC_LITERAL(336, 57), // "on_visualizationProjectionOrt..."
QT_MOC_LITERAL(394, 56), // "on_visualizationProjectionPer..."
QT_MOC_LITERAL(451, 31), // "on_quantizationCheckBox_toggled"
QT_MOC_LITERAL(483, 47), // "on_quantizationBitsComboBox_c..."
QT_MOC_LITERAL(531, 5), // "index"
QT_MOC_LITERAL(537, 31), // "on_gaussianBlurCheckBox_toggled"
QT_MOC_LITERAL(569, 28), // "on_gradientsCheckBox_toggled"
QT_MOC_LITERAL(598, 43), // "on_scalarDataDrawScalarDataCh..."
QT_MOC_LITERAL(642, 41), // "on_scalarDataComboBox_current..."
QT_MOC_LITERAL(684, 42), // "on_scalarDataslicingEnableChe..."
QT_MOC_LITERAL(727, 49), // "on_scalarDataSlicingDirection..."
QT_MOC_LITERAL(777, 49), // "on_scalarDataSlicingDirection..."
QT_MOC_LITERAL(827, 49), // "on_scalarDataSlicingDirection..."
QT_MOC_LITERAL(877, 50), // "on_scalarDataSlicingSliceInde..."
QT_MOC_LITERAL(928, 4), // "arg1"
QT_MOC_LITERAL(933, 49), // "on_scalarDataColorMapComboBox..."
QT_MOC_LITERAL(983, 55), // "on_scalarDataColorMapNumberOf..."
QT_MOC_LITERAL(1039, 48), // "on_scalarDataCustomColorPicke..."
QT_MOC_LITERAL(1088, 57), // "on_scalarDataMappingMappingTy..."
QT_MOC_LITERAL(1146, 58), // "on_scalarDataMappingMappingTy..."
QT_MOC_LITERAL(1205, 66), // "on_scalarDataMappingScalingMo..."
QT_MOC_LITERAL(1272, 50), // "on_scalarDataMappingClampingM..."
QT_MOC_LITERAL(1323, 57), // "on_scalarDataMappingClampingM..."
QT_MOC_LITERAL(1381, 50), // "on_scalarDataMappingClampingM..."
QT_MOC_LITERAL(1432, 57), // "on_scalarDataMappingClampingM..."
QT_MOC_LITERAL(1490, 48), // "on_scalarDataMappingTransferK..."
QT_MOC_LITERAL(1539, 49), // "on_scalarDataMappingTransferK..."
QT_MOC_LITERAL(1589, 39), // "on_vectorDataDrawGlyphsCheckB..."
QT_MOC_LITERAL(1629, 57), // "on_vectorDataNumberOfGlyphsHo..."
QT_MOC_LITERAL(1687, 55), // "on_vectorDataNumberOfGlyphsVe..."
QT_MOC_LITERAL(1743, 41), // "on_vectorDataComboBox_current..."
QT_MOC_LITERAL(1785, 46), // "on_vectorDataGlyphComboBox_cu..."
QT_MOC_LITERAL(1832, 53), // "on_vectorDataGlyphMagnifierDo..."
QT_MOC_LITERAL(1886, 46), // "on_vectorDataGlyphMagnifierSl..."
QT_MOC_LITERAL(1933, 49), // "on_vectorDataColorMapComboBox..."
QT_MOC_LITERAL(1983, 47), // "on_vectorDataNumberOfColorsSp..."
QT_MOC_LITERAL(2031, 39), // "on_isolinesDrawIsolinesCheckB..."
QT_MOC_LITERAL(2071, 36), // "on_isolinesColorPickerButton_..."
QT_MOC_LITERAL(2108, 47), // "on_isolinesUseCurrentScalarDa..."
QT_MOC_LITERAL(2156, 43), // "on_isolinesDataComboBox_curre..."
QT_MOC_LITERAL(2200, 55), // "on_isolinesInterpolationMetho..."
QT_MOC_LITERAL(2256, 53), // "on_isolinesInterpolationMetho..."
QT_MOC_LITERAL(2310, 58), // "on_isolinesAmbiguousCaseDecid..."
QT_MOC_LITERAL(2369, 60), // "on_isolinesAmbiguousCaseDecid..."
QT_MOC_LITERAL(2430, 47), // "on_isolinesNumberOfIsolinesSp..."
QT_MOC_LITERAL(2478, 42), // "on_isolinesRangeRhoMinSpinBox..."
QT_MOC_LITERAL(2521, 42), // "on_isolinesRangeRhoMaxSpinBox..."
QT_MOC_LITERAL(2564, 41), // "on_isolinesRangeRhoMinSlider_..."
QT_MOC_LITERAL(2606, 41), // "on_isolinesRangeRhoMaxSlider_..."
QT_MOC_LITERAL(2648, 33), // "on_showHeightplotCheckBox_tog..."
QT_MOC_LITERAL(2682, 49), // "on_heightplotDataTypeComboBox..."
QT_MOC_LITERAL(2732, 37), // "on_heightplotViewRotateX_valu..."
QT_MOC_LITERAL(2770, 37), // "on_heightplotViewRotateY_valu..."
QT_MOC_LITERAL(2808, 37), // "on_heightplotViewRotateZ_valu..."
QT_MOC_LITERAL(2846, 34), // "on_heightplotResetRotation_cl..."
QT_MOC_LITERAL(2881, 26), // "on_drawLicCheckBox_toggled"
QT_MOC_LITERAL(2908, 38), // "on_drawVolumeRenderingCheckBo..."
QT_MOC_LITERAL(2947, 16), // "setScalarDataMin"
QT_MOC_LITERAL(2964, 3), // "min"
QT_MOC_LITERAL(2968, 16), // "setScalarDataMax"
QT_MOC_LITERAL(2985, 3), // "max"
QT_MOC_LITERAL(2989, 16), // "setVectorDataMin"
QT_MOC_LITERAL(3006, 16) // "setVectorDataMax"

    },
    "MainWindow\0on_showMinMaxDataCheckBox_toggled\0"
    "\0checked\0on_densitySlider_valueChanged\0"
    "value\0on_densitySpinBox_valueChanged\0"
    "on_viscositySlider_valueChanged\0"
    "on_viscositySpinBox_valueChanged\0"
    "on_timestepSlider_valueChanged\0"
    "on_timestepSpinBox_valueChanged\0"
    "on_gridpointsSpinBox_valueChanged\0"
    "on_pausePlayButton_clicked\0"
    "on_loadDataButton_clicked\0"
    "on_visualizationProjectionOrthographicRadioButton_toggled\0"
    "on_visualizationProjectionPerspectiveRadioButton_toggled\0"
    "on_quantizationCheckBox_toggled\0"
    "on_quantizationBitsComboBox_currentIndexChanged\0"
    "index\0on_gaussianBlurCheckBox_toggled\0"
    "on_gradientsCheckBox_toggled\0"
    "on_scalarDataDrawScalarDataCheckBox_toggled\0"
    "on_scalarDataComboBox_currentIndexChanged\0"
    "on_scalarDataslicingEnableCheckBox_toggled\0"
    "on_scalarDataSlicingDirectionXRadioButton_toggled\0"
    "on_scalarDataSlicingDirectionYRadioButton_toggled\0"
    "on_scalarDataSlicingDirectionTRadioButton_toggled\0"
    "on_scalarDataSlicingSliceIndexSpinBox_valueChanged\0"
    "arg1\0on_scalarDataColorMapComboBox_currentIndexChanged\0"
    "on_scalarDataColorMapNumberOfColorsSpinBox_valueChanged\0"
    "on_scalarDataCustomColorPickerPushButton_clicked\0"
    "on_scalarDataMappingMappingTypeScalingRadioButton_toggled\0"
    "on_scalarDataMappingMappingTypeClampingRadioButton_toggled\0"
    "on_scalarDataMappingScalingMovingAverageWindowSpinBox_valueChanged\0"
    "on_scalarDataMappingClampingMinSlider_valueChanged\0"
    "on_scalarDataMappingClampingMinDoubleSpinBox_valueChanged\0"
    "on_scalarDataMappingClampingMaxSlider_valueChanged\0"
    "on_scalarDataMappingClampingMaxDoubleSpinBox_valueChanged\0"
    "on_scalarDataMappingTransferKSlider_valueChanged\0"
    "on_scalarDataMappingTransferKSpinBox_valueChanged\0"
    "on_vectorDataDrawGlyphsCheckBox_toggled\0"
    "on_vectorDataNumberOfGlyphsHorizontalSpinBox_valueChanged\0"
    "on_vectorDataNumberOfGlyphsVerticalSpinBox_valueChanged\0"
    "on_vectorDataComboBox_currentIndexChanged\0"
    "on_vectorDataGlyphComboBox_currentIndexChanged\0"
    "on_vectorDataGlyphMagnifierDoubleSpinBox_valueChanged\0"
    "on_vectorDataGlyphMagnifierSlider_valueChanged\0"
    "on_vectorDataColorMapComboBox_currentIndexChanged\0"
    "on_vectorDataNumberOfColorsSpinBox_valueChanged\0"
    "on_isolinesDrawIsolinesCheckBox_toggled\0"
    "on_isolinesColorPickerButton_clicked\0"
    "on_isolinesUseCurrentScalarDataCheckBox_toggled\0"
    "on_isolinesDataComboBox_currentIndexChanged\0"
    "on_isolinesInterpolationMethodLinearRadioButton_toggled\0"
    "on_isolinesInterpolationMethodNoneRadioButton_toggled\0"
    "on_isolinesAmbiguousCaseDeciderMidpointRadioButton_toggled\0"
    "on_isolinesAmbiguousCaseDeciderAsymptoticRadioButton_toggled\0"
    "on_isolinesNumberOfIsolinesSpinBox_valueChanged\0"
    "on_isolinesRangeRhoMinSpinBox_valueChanged\0"
    "on_isolinesRangeRhoMaxSpinBox_valueChanged\0"
    "on_isolinesRangeRhoMinSlider_valueChanged\0"
    "on_isolinesRangeRhoMaxSlider_valueChanged\0"
    "on_showHeightplotCheckBox_toggled\0"
    "on_heightplotDataTypeComboBox_currentIndexChanged\0"
    "on_heightplotViewRotateX_valueChanged\0"
    "on_heightplotViewRotateY_valueChanged\0"
    "on_heightplotViewRotateZ_valueChanged\0"
    "on_heightplotResetRotation_clicked\0"
    "on_drawLicCheckBox_toggled\0"
    "on_drawVolumeRenderingCheckBox_toggled\0"
    "setScalarDataMin\0min\0setScalarDataMax\0"
    "max\0setVectorDataMin\0setVectorDataMax"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      69,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  428,    2, 0x08,    1 /* Private */,
       4,    1,  431,    2, 0x08,    3 /* Private */,
       6,    1,  434,    2, 0x08,    5 /* Private */,
       7,    1,  437,    2, 0x08,    7 /* Private */,
       8,    1,  440,    2, 0x08,    9 /* Private */,
       9,    1,  443,    2, 0x08,   11 /* Private */,
      10,    1,  446,    2, 0x08,   13 /* Private */,
      11,    1,  449,    2, 0x08,   15 /* Private */,
      12,    0,  452,    2, 0x08,   17 /* Private */,
      13,    0,  453,    2, 0x08,   18 /* Private */,
      14,    1,  454,    2, 0x08,   19 /* Private */,
      15,    1,  457,    2, 0x08,   21 /* Private */,
      16,    1,  460,    2, 0x08,   23 /* Private */,
      17,    1,  463,    2, 0x08,   25 /* Private */,
      19,    1,  466,    2, 0x08,   27 /* Private */,
      20,    1,  469,    2, 0x08,   29 /* Private */,
      21,    1,  472,    2, 0x08,   31 /* Private */,
      22,    1,  475,    2, 0x08,   33 /* Private */,
      23,    1,  478,    2, 0x08,   35 /* Private */,
      24,    1,  481,    2, 0x08,   37 /* Private */,
      25,    1,  484,    2, 0x08,   39 /* Private */,
      26,    1,  487,    2, 0x08,   41 /* Private */,
      27,    1,  490,    2, 0x08,   43 /* Private */,
      29,    1,  493,    2, 0x08,   45 /* Private */,
      30,    1,  496,    2, 0x08,   47 /* Private */,
      31,    0,  499,    2, 0x08,   49 /* Private */,
      32,    1,  500,    2, 0x08,   50 /* Private */,
      33,    1,  503,    2, 0x08,   52 /* Private */,
      34,    1,  506,    2, 0x08,   54 /* Private */,
      35,    1,  509,    2, 0x08,   56 /* Private */,
      36,    1,  512,    2, 0x08,   58 /* Private */,
      37,    1,  515,    2, 0x08,   60 /* Private */,
      38,    1,  518,    2, 0x08,   62 /* Private */,
      39,    1,  521,    2, 0x08,   64 /* Private */,
      40,    1,  524,    2, 0x08,   66 /* Private */,
      41,    1,  527,    2, 0x08,   68 /* Private */,
      42,    1,  530,    2, 0x08,   70 /* Private */,
      43,    1,  533,    2, 0x08,   72 /* Private */,
      44,    1,  536,    2, 0x08,   74 /* Private */,
      45,    1,  539,    2, 0x08,   76 /* Private */,
      46,    1,  542,    2, 0x08,   78 /* Private */,
      47,    1,  545,    2, 0x08,   80 /* Private */,
      48,    1,  548,    2, 0x08,   82 /* Private */,
      49,    1,  551,    2, 0x08,   84 /* Private */,
      50,    1,  554,    2, 0x08,   86 /* Private */,
      51,    0,  557,    2, 0x08,   88 /* Private */,
      52,    1,  558,    2, 0x08,   89 /* Private */,
      53,    1,  561,    2, 0x08,   91 /* Private */,
      54,    1,  564,    2, 0x08,   93 /* Private */,
      55,    1,  567,    2, 0x08,   95 /* Private */,
      56,    1,  570,    2, 0x08,   97 /* Private */,
      57,    1,  573,    2, 0x08,   99 /* Private */,
      58,    1,  576,    2, 0x08,  101 /* Private */,
      59,    1,  579,    2, 0x08,  103 /* Private */,
      60,    1,  582,    2, 0x08,  105 /* Private */,
      61,    1,  585,    2, 0x08,  107 /* Private */,
      62,    1,  588,    2, 0x08,  109 /* Private */,
      63,    1,  591,    2, 0x08,  111 /* Private */,
      64,    1,  594,    2, 0x08,  113 /* Private */,
      65,    1,  597,    2, 0x08,  115 /* Private */,
      66,    1,  600,    2, 0x08,  117 /* Private */,
      67,    1,  603,    2, 0x08,  119 /* Private */,
      68,    0,  606,    2, 0x08,  121 /* Private */,
      69,    1,  607,    2, 0x08,  122 /* Private */,
      70,    1,  610,    2, 0x08,  124 /* Private */,
      71,    1,  613,    2, 0x08,  126 /* Private */,
      73,    1,  616,    2, 0x08,  128 /* Private */,
      75,    1,  619,    2, 0x08,  130 /* Private */,
      76,    1,  622,    2, 0x08,  132 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Double,   28,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Double,   28,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Double,   28,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Float,   72,
    QMetaType::Void, QMetaType::Float,   74,
    QMetaType::Void, QMetaType::Float,   72,
    QMetaType::Void, QMetaType::Float,   74,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_showMinMaxDataCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->on_densitySlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_densitySpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 3: _t->on_viscositySlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_viscositySpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 5: _t->on_timestepSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_timestepSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 7: _t->on_gridpointsSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_pausePlayButton_clicked(); break;
        case 9: _t->on_loadDataButton_clicked(); break;
        case 10: _t->on_visualizationProjectionOrthographicRadioButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->on_visualizationProjectionPerspectiveRadioButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->on_quantizationCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->on_quantizationBitsComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->on_gaussianBlurCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 15: _t->on_gradientsCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 16: _t->on_scalarDataDrawScalarDataCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: _t->on_scalarDataComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->on_scalarDataslicingEnableCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 19: _t->on_scalarDataSlicingDirectionXRadioButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 20: _t->on_scalarDataSlicingDirectionYRadioButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 21: _t->on_scalarDataSlicingDirectionTRadioButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 22: _t->on_scalarDataSlicingSliceIndexSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->on_scalarDataColorMapComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->on_scalarDataColorMapNumberOfColorsSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: _t->on_scalarDataCustomColorPickerPushButton_clicked(); break;
        case 26: _t->on_scalarDataMappingMappingTypeScalingRadioButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 27: _t->on_scalarDataMappingMappingTypeClampingRadioButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 28: _t->on_scalarDataMappingScalingMovingAverageWindowSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 29: _t->on_scalarDataMappingClampingMinSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 30: _t->on_scalarDataMappingClampingMinDoubleSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 31: _t->on_scalarDataMappingClampingMaxSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 32: _t->on_scalarDataMappingClampingMaxDoubleSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 33: _t->on_scalarDataMappingTransferKSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 34: _t->on_scalarDataMappingTransferKSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 35: _t->on_vectorDataDrawGlyphsCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 36: _t->on_vectorDataNumberOfGlyphsHorizontalSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 37: _t->on_vectorDataNumberOfGlyphsVerticalSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 38: _t->on_vectorDataComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 39: _t->on_vectorDataGlyphComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 40: _t->on_vectorDataGlyphMagnifierDoubleSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 41: _t->on_vectorDataGlyphMagnifierSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 42: _t->on_vectorDataColorMapComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 43: _t->on_vectorDataNumberOfColorsSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 44: _t->on_isolinesDrawIsolinesCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 45: _t->on_isolinesColorPickerButton_clicked(); break;
        case 46: _t->on_isolinesUseCurrentScalarDataCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 47: _t->on_isolinesDataComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 48: _t->on_isolinesInterpolationMethodLinearRadioButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 49: _t->on_isolinesInterpolationMethodNoneRadioButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 50: _t->on_isolinesAmbiguousCaseDeciderMidpointRadioButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 51: _t->on_isolinesAmbiguousCaseDeciderAsymptoticRadioButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 52: _t->on_isolinesNumberOfIsolinesSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 53: _t->on_isolinesRangeRhoMinSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 54: _t->on_isolinesRangeRhoMaxSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 55: _t->on_isolinesRangeRhoMinSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 56: _t->on_isolinesRangeRhoMaxSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 57: _t->on_showHeightplotCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 58: _t->on_heightplotDataTypeComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 59: _t->on_heightplotViewRotateX_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 60: _t->on_heightplotViewRotateY_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 61: _t->on_heightplotViewRotateZ_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 62: _t->on_heightplotResetRotation_clicked(); break;
        case 63: _t->on_drawLicCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 64: _t->on_drawVolumeRenderingCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 65: _t->setScalarDataMin((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 66: _t->setScalarDataMax((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 67: _t->setVectorDataMin((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 68: _t->setVectorDataMax((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<float const, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<float const, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<float const, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<float const, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 69)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 69;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 69)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 69;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
