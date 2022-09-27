greaterThan(QT_MAJOR_VERSION, 4): QT += widgets # For Qt5
greaterThan(QT_MAJOR_VERSION, 5): QT += widgets opengl openglwidgets # For Qt6

TARGET = smoke_framework
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

SOURCES += \
        glyph.cpp \
        isoline.cpp \
        legend.cpp \
        lic.cpp \
        main.cpp \
        mainwindow_general.cpp \
        mainwindow_heightplot.cpp \
        mainwindow_isolines.cpp \
        mainwindow_lic.cpp \
        mainwindow_preprocessing.cpp \
        mainwindow_scalardata.cpp \
        mainwindow_simulation.cpp \
        mainwindow_vectordata.cpp \
        mainwindow_visualization.cpp\
        mainwindow_volumerendering.cpp \
        simulation.cpp \
        texture.cpp \
        visualization.cpp \
        visualization_input.cpp \
        visualization_opengl.cpp

HEADERS += \
        color.h \
        colormap.h \
        constants.h \
        datatype.h \
        datraw.h \
        datraw/convert.h \
        datraw/convert.inl \
        datraw/endianness.h \
        datraw/grid_type.h \
        datraw/info.h \
        datraw/info.inl \
        datraw/literal.h \
        datraw/parse.h \
        datraw/parse.inl \
        datraw/raw_reader.h \
        datraw/raw_reader.inl \
        datraw/scalar_type.h \
        datraw/string.h \
        datraw/string.inl \
        datraw/types.h \
        datraw/variant.h \
        datraw/variant.inl \
        glyph.h \
        interpolation.h \
        isoline.h \
        legend.h \
        legendscalardata.h \
        legendvectordata.h \
        lic.h \
        mainwindow.h \
        movingaverage.h \
        pocketfft_hdronly.h \
        simulation.h \
        texture.h \
        visualization.h

FORMS += \
        mainwindow.ui

RESOURCES += \
        resources.qrc

macx: {
QMAKE_RPATHDIR += /opt/local/libexec/qt6/lib
}
