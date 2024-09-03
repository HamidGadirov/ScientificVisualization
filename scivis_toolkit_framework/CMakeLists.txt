cmake_minimum_required(VERSION 3.16)
project(scivis_toolkit_framework VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui OpenGL OpenGLWidgets Widgets)

if (COMMAND qt_standard_project_setup) # Requires Qt 6.3 or higher
    qt_standard_project_setup()
else()
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTOUIC ON)
endif()

set(CMAKE_AUTORCC ON)

qt_add_executable(scivis_toolkit_framework WIN32 MACOSX_BUNDLE
    color.h
    colormap.h
    constants.h
    datatype.h
    datraw.h
    datraw/convert.h datraw/convert.inl
    datraw/endianness.h
    datraw/grid_type.h
    datraw/info.h datraw/info.inl
    datraw/literal.h
    datraw/parse.h datraw/parse.inl
    datraw/raw_reader.h datraw/raw_reader.inl
    datraw/scalar_type.h
    datraw/string.h datraw/string.inl
    datraw/types.h
    datraw/variant.h datraw/variant.inl
    glyph.cpp glyph.h
    interpolation.h
    legend.cpp legend.h
    legendscalardata.h
    legendvectordata.h
    lic.cpp lic.h
    main.cpp
    mainwindow.h mainwindow.ui
    mainwindow_general.cpp
    mainwindow_heightplot.cpp
    mainwindow_isolines.cpp
    mainwindow_lic.cpp
    mainwindow_preprocessing.cpp
    mainwindow_scalardata.cpp
    mainwindow_simulation.cpp
    mainwindow_vectordata.cpp
    mainwindow_volumerendering.cpp
    movingrange.h movingrange.cpp
    pocketfft_hdronly.h
    resources.qrc
    simulation.cpp simulation.h
    texture.cpp texture.h
    visualization.cpp visualization.h
    visualization_input.cpp
    visualization_opengl.cpp
)

target_compile_definitions(scivis_toolkit_framework PRIVATE
    QT_DEPRECATED_WARNINGS
)

# When using the AppleClang, Clang or GNU (GCC) compiler, compile for the native architecture.
# MSVC does not have an equivalent compiler option.
if ((CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR (CMAKE_CXX_COMPILER_ID STREQUAL "GNU"))
    target_compile_options(scivis_toolkit_framework PRIVATE -march=native)
endif()

target_link_libraries(scivis_toolkit_framework PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::OpenGL
    Qt6::OpenGLWidgets
    Qt6::Widgets
)

set_target_properties(scivis_toolkit_framework PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
