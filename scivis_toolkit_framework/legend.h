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
