#ifndef LEGEND_H
#define LEGEND_H

#include "color.h"

#include <QOpenGLWidget>
#include <QOpenGLDebugLogger>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>

class Legend : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
    Q_OBJECT

    struct Vertex
    {
        float x;
        float y;
        float value;
    };

    QOpenGLDebugLogger m_debugLogger;

    GLuint m_vao;
    GLuint m_vbo;
    GLuint m_ebo;
    GLuint m_textureLocation;
    GLint m_uniformLocationTexture;

    QOpenGLShaderProgram m_shaderProgramColorMap;

    // The legend is a rectangle, drawn as two triangles.
    static std::array<Vertex, 4U> constexpr m_vertices{Vertex{-1.0F,  1.0F, 0.0F},  // Top left.
                                                       Vertex{-1.0F, -1.0F, 0.0F},  // Bottom left.
                                                       Vertex{ 1.0F,  1.0F, 1.0F},  // Top right.
                                                       Vertex{ 1.0F, -1.0F, 1.0F}}; // Bottom right.
    static std::array<unsigned short, 6U> constexpr m_indices{0U, 1U, 2U,
                                                              1U, 3U, 2U};

    // OpenGL related functions
    void createShaderProgram();
    void loadInitialColorMap();

protected:
    void initializeGL();
    void resizeGL(int const newWidth, int const newHeight);
    void paintGL();

private slots:
    void onMessageLogged(QOpenGLDebugMessage const &Message) const;

public:
    Legend(QWidget *parent = nullptr);
    ~Legend();

    void updateColorMap(std::vector<Color> const &colorMap);
};

#endif // LEGEND_H
