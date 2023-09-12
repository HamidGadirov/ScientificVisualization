cmake_minimum_required(VERSION 3.16)
project(scivis_toolkit_framework VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Set up AUTOMOC and some sensible defaults for runtime execution
# When using Qt 6.3, you can replace the code block below with
# qt_standard_project_setup()
set(CMAKE_AUTOMOC ON)
include(GNUInstallDirs)
set(CMAKE_AUTOUIC ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui OpenGL OpenGLWidgets Widgets)

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
    isoline.cpp isoline.h
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
    simulation.cpp simulation.h
    texture.cpp texture.h
    visualization.cpp visualization.h
    visualization_input.cpp
    visualization_opengl.cpp
)
target_compile_definitions(scivis_toolkit_framework PRIVATE
    QT_DEPRECATED_WARNINGS
)

target_link_libraries(scivis_toolkit_framework PRIVATE
    Qt::Core
    Qt::Gui
    Qt::OpenGL
    Qt::OpenGLWidgets
    Qt::Widgets
)


# Resources:
set(resources_resource_files
    "shaders/glyph.frag"
    "shaders/glyph.vert"
    "shaders/heightplot.frag"
    "shaders/heightplot_clamp.vert"
    "shaders/heightplot_scale.vert"
    "shaders/isolines.frag"
    "shaders/isolines.vert"
    "shaders/lic.frag"
    "shaders/lic.vert"
    "shaders/passthrough2d.vert"
    "shaders/scalarData_clamp.vert"
    "shaders/scalarData_customcolormap.frag"
    "shaders/scalarData_scale.vert"
    "shaders/scalarData_texture.frag"
    "shaders/volume_rendering.frag"
    "shaders/volume_rendering.vert"
    "shaders/volume_rendering_lighting.frag"
    "shaders/volume_rendering_overlay_rendering.frag"
    "shaders/volume_rendering_preintegration.frag"
)

qt_add_resources(scivis_toolkit_framework "resources"
    PREFIX
        "/"
    FILES
        ${resources_resource_files}
)

install(TARGETS scivis_toolkit_framework
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Consider using qt_generate_deploy_app_script() for app deployment if
# the project can use Qt 6.3. In that case rerun qmake2cmake with
# --min-qt-version=6.3.
