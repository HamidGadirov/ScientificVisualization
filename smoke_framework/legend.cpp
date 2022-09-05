#include "legend.h"

#include "mainwindow.h"

#include <QDebug>

#include <algorithm>
#include <cmath>

Legend::Legend(QWidget *parent) : QOpenGLWidget(parent)
{
    qDebug() << "Legend constructor";
}

Legend::~Legend()
{
    qDebug() << "Legend destructor";

    makeCurrent();

    glDeleteVertexArrays(1, &m_vao);
    glDeleteBuffers(1, &m_vbo);
    glDeleteBuffers(1, &m_ebo);

    glDeleteTextures(1, &m_textureLocation);
}

void Legend::initializeGL() {
    qDebug() << ":: Initializing OpenGL";
    initializeOpenGLFunctions();

    connect(&m_debugLogger, SIGNAL(messageLogged(QOpenGLDebugMessage)),
            this, SLOT(onMessageLogged(QOpenGLDebugMessage)), Qt::DirectConnection);

    if (m_debugLogger.initialize())
    {
        qDebug() << ":: Logging initialized";
        m_debugLogger.startLogging( QOpenGLDebugLogger::SynchronousLogging );
        m_debugLogger.enableMessages();
    }

    {
        QString const glVersion{reinterpret_cast<const char*>(glGetString(GL_VERSION))};
        qDebug() << ":: Using OpenGL" << qPrintable(glVersion);
    }

    createShaderProgram();

    // Generate buffers
    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ebo);

    glGenTextures(1, &m_textureLocation);
    loadInitialColorMap(); // Load single black color colorMap by default.

    // Buffer data
    glBindVertexArray(m_vao);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(m_vertices.size() * sizeof(Vertex)),
                 m_vertices.data(),
                 GL_STATIC_DRAW);

    // Buffer indices
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(m_indices.size() * sizeof(unsigned short)),
                 m_indices.data(),
                 GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid*>(0));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid*>(2U * sizeof(GLfloat)));
}

void Legend::createShaderProgram()
{
    m_shaderProgramColorMap.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/shaders/passthrough2d.vert");
    m_shaderProgramColorMap.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/scalarData_texture.frag");
    m_shaderProgramColorMap.link();

    m_uniformLocationTexture = m_shaderProgramColorMap.uniformLocation("textureSampler");
    Q_ASSERT(m_uniformLocationTexture != -1);

    m_shaderProgramColorMap.bind();

    qDebug() << "m_shaderProgramColormap initialized.";
}

void Legend::loadInitialColorMap()
{
    // Set texture parameters.
    glBindTexture(GL_TEXTURE_1D, m_textureLocation);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Retrieve default texture.
    auto const mainWindowPtr = qobject_cast<MainWindow*>(parent()->parent());
    std::vector<Color> const defaultColorMap = mainWindowPtr->m_defaultScalarDataColorMap;

    glTexImage1D(GL_TEXTURE_1D,
                 0,
                 GL_RGB32F,
                 static_cast<GLint>(defaultColorMap.size()),
                 0,
                 GL_RGB,
                 GL_FLOAT,
                 defaultColorMap.data());
}

void Legend::updateColorMap(std::vector<Color> const &colorMap)
{
    glBindTexture(GL_TEXTURE_1D, m_textureLocation);
    glTexImage1D(GL_TEXTURE_1D,
                 0,
                 GL_RGB32F,
                 static_cast<GLint>(colorMap.size()),
                 0,
                 GL_RGB,
                 GL_FLOAT,
                 colorMap.data());

    update();
}

void Legend::paintGL()
{
    glUniform1i(m_uniformLocationTexture, 0);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_1D, m_textureLocation);
    glBindVertexArray(m_vao);
    glDrawElements(GL_TRIANGLES,
                   m_indices.size(),
                   GL_UNSIGNED_SHORT,
                   static_cast<GLvoid*>(nullptr));
}

void Legend::resizeGL([[maybe_unused]] int const width, [[maybe_unused]] int const height)
{}

void Legend::onMessageLogged(QOpenGLDebugMessage const &Message) const
{
    qDebug() << "Log from Legend:" << Message;
}
