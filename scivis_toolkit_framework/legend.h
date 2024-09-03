#ifndef LEGEND_H
#define LEGEND_H

#include "color.h"

#include <QOpenGLDebugLogger>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>

#include <vector>

class Legend : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
    Q_OBJECT

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
    void initializeGL() override;
    void resizeGL(int const newWidth, int const newHeight) override;
    void paintGL() override;

private slots:
    void onMessageLogged(QOpenGLDebugMessage const &Message) const;

public:
    Legend(QWidget *parent = nullptr);
    Legend(Legend const&) = delete;
    Legend& operator=(Legend const&) = delete;
    Legend(Legend&&) = delete;
    Legend& operator=(Legend&&) = delete;
    ~Legend() override;

    void updateColorMap(std::vector<Color> const &colorMap);
};

#endif // LEGEND_H
