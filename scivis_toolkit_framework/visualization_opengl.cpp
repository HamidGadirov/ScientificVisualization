#include "visualization.h"

#include "mainwindow.h"

#include <QVector2D>
#include <QVector4D>

#include <cmath>

// Generate all necessary VAOs, VBOs, EBOs and texture names
void Visualization::opengl_generateObjects()
{
    glGenVertexArrays(1, &m_vaoScalarData);
    glGenBuffers(1, &m_vboScalarPoints);
    glGenBuffers(1, &m_vboScalarData);
    glGenBuffers(1, &m_eboScalarData);
    glGenTextures(1, &m_scalarDataTextureLocation);

    glGenVertexArrays(1, &m_vaoGlyphs);
    glGenBuffers(1, &m_vboGlyphs);
    glGenBuffers(1, &m_eboGlyphs);
    glGenBuffers(1, &m_vboModelTransformationMatricesGlyphs);
    glGenBuffers(1, &m_vboValuesGlyphs);
    glGenTextures(1, &m_vectorDataTextureLocation);

    glGenVertexArrays(1, &m_vaoIsolines);
    glGenBuffers(1, &m_eboIsolines);

    glGenVertexArrays(1, &m_vaoHeightplot);
    glGenBuffers(1, &m_vboHeightplotPoints);
    glGenBuffers(1, &m_vboHeightplotScalarValues);
    glGenBuffers(1, &m_vboHeightplotHeight);
    glGenBuffers(1, &m_vboHeightplotNormals);
    glGenBuffers(1, &m_eboHeightplot);

    glGenVertexArrays(1, &m_vaoLic);
    glGenBuffers(1, &m_vboLic);
    glGenTextures(1, &m_licNoiseTexture);
    glGenTextures(1, &m_licVelocityField);

    glGenVertexArrays(1, &m_vaoVolumeRendering);
    glGenBuffers(1, &m_vboVolumeRendering);
    glGenTextures(1, &m_volumeRenderingTextureLocation);
    glGenTextures(1, &m_volumeRenderingTextureLocationPreIntegrationLookupTable);
}

void Visualization::opengl_createShaderPrograms()
{
    opengl_createShaderProgramScalarDataScaleTexture();
    opengl_createShaderProgramScalarDataScaleCustomColorMap();
    opengl_createShaderProgramScalarDataClampTexture();
    opengl_createShaderProgramScalarDataClampCustomColorMap();
    opengl_createShaderProgramColorMapInstanced();
    opengl_createShaderProgramIsolines();
    opengl_createShaderProgramHeightplotScale();
    opengl_createShaderProgramHeightplotClamp();
    opengl_createShaderProgramLic();
    opengl_createShaderProgramVolumeRendering();
    opengl_createShaderProgramVolumeRenderingLighting();
    opengl_createShaderProgramVolumeRenderingPreIntegration();
    opengl_createShaderProgramVolumeRenderingOverlayRendering();
}

void Visualization::opengl_setupAllBuffers()
{
    opengl_setupScalarData();
    opengl_setupGlyphs();
    opengl_setupIsolines();
    opengl_setupHeightplot();
    opengl_setupLic();
    opengl_setupVolumeRendering();
}

void Visualization::opengl_deleteObjects()
{
    glDeleteVertexArrays(1, &m_vaoScalarData);
    glDeleteBuffers(1, &m_vboScalarPoints);
    glDeleteBuffers(1, &m_vboScalarData);
    glDeleteBuffers(1, &m_eboScalarData);

    glDeleteVertexArrays(1, &m_vaoGlyphs);
    glDeleteBuffers(1, &m_vboGlyphs);
    glDeleteBuffers(1, &m_eboGlyphs);
    glDeleteBuffers(1, &m_vboModelTransformationMatricesGlyphs);
    glDeleteBuffers(1, &m_vboValuesGlyphs);

    glDeleteVertexArrays(1, &m_vaoIsolines);
    glDeleteBuffers(1, &m_eboIsolines);

    glDeleteVertexArrays(1, &m_vaoHeightplot);
    glDeleteBuffers(1, &m_vboHeightplotPoints);
    glDeleteBuffers(1, &m_vboHeightplotHeight);
    glDeleteBuffers(1, &m_vboHeightplotScalarValues);
    glDeleteBuffers(1, &m_vboHeightplotNormals);
    glDeleteBuffers(1, &m_eboHeightplot);

    glDeleteBuffers(1, &m_vaoLic);
    glDeleteBuffers(1, &m_vboLic);
    glDeleteTextures(1, &m_licNoiseTexture);
    glDeleteTextures(1, &m_licVelocityField);

    glDeleteTextures(1, &m_scalarDataTextureLocation);
    glDeleteTextures(1, &m_vectorDataTextureLocation);

    glDeleteVertexArrays(1, &m_vaoVolumeRendering);
    glDeleteBuffers(1, &m_vboVolumeRendering);
    glDeleteTextures(1, &m_volumeRenderingTextureLocation);
    glDeleteTextures(1, &m_volumeRenderingTextureLocationPreIntegrationLookupTable);
}

void Visualization::opengl_loadScalarDataTexture(std::vector<Color> const &colorMap)
{
    glBindTexture(GL_TEXTURE_1D, m_scalarDataTextureLocation);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage1D(GL_TEXTURE_1D,
                 0,
                 GL_RGB32F,
                 static_cast<GLint>(colorMap.size()),
                 0,
                 GL_RGB,
                 GL_FLOAT,
                 colorMap.data());
}

void Visualization::opengl_setupScalarData()
{
    glBindVertexArray(m_vaoScalarData);

    glBindBuffer(GL_ARRAY_BUFFER, m_vboScalarPoints);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(m_DIM * m_DIM * 2U * sizeof(float)),
                 static_cast<GLvoid*>(nullptr),
                 GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0U);
    glVertexAttribPointer(0U, 2, GL_FLOAT, GL_FALSE, 0U, reinterpret_cast<GLvoid*>(0));

    glBindBuffer(GL_ARRAY_BUFFER, m_vboScalarData);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(m_DIM * m_DIM * sizeof(float)),
                 static_cast<GLvoid*>(nullptr),
                 GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(1U);
    glVertexAttribPointer(1U, 1, GL_FLOAT, GL_FALSE, 0U, reinterpret_cast<GLvoid*>(0));

    size_t const numberOfTriangleStripIndices = (m_DIM - 1U) * (2U * m_DIM + 2U) - 2U;

    // When the grid is resized, this function is called again, hence we need to clear m_indices.
    m_indices.clear();
    m_indices.reserve(numberOfTriangleStripIndices);

    for (unsigned short stripIdx = 0U; stripIdx < (m_DIM * (m_DIM - 1U)); stripIdx += m_DIM)
    {
        unsigned short lastUsedIdx;
        for (unsigned short idx = stripIdx; idx < (stripIdx + m_DIM); ++idx)
        {
            m_indices.push_back(idx);

            lastUsedIdx = static_cast<unsigned short>(idx + m_DIM);
            m_indices.push_back(lastUsedIdx);
        }

        // Add degenerate vertices to start rendering the next strip without requiring a new (expensive) draw call.
        // Note: there's no special case for the last triangle, so a couple of redundant indices are added.
        m_indices.push_back(lastUsedIdx); // Repeat last added vertex.
        m_indices.push_back(static_cast<unsigned short>(stripIdx + m_DIM)); // Add first vertex of next strip, so that it will appear twice.
    }

    // No primitive restart, so the last (degenerated) triangles can be removed.
    m_indices.erase(m_indices.end() - 2U, m_indices.end());

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_eboScalarData);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(m_indices.size() * sizeof(unsigned short)),
                 m_indices.data(),
                 GL_STATIC_DRAW);
}

void Visualization::opengl_setupIsolines()
{
    glBindVertexArray(m_vaoIsolines);

    // Reuse the scalar data points buffer, but with indices exclusive to isolines
    glBindBuffer(GL_ARRAY_BUFFER, m_vboScalarPoints);

    // Set vertex coordinates to location 0
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0U, 2, GL_FLOAT, GL_FALSE, 0U, reinterpret_cast<GLvoid*>(0));

    // Reuse the scalar data buffer.
    glBindBuffer(GL_ARRAY_BUFFER, m_vboScalarData);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1U, 1, GL_FLOAT, GL_FALSE, 0U, reinterpret_cast<GLvoid*>(0));

    m_numberOfIsolinesIndices = 4U; // Placeholder value. Set this to the length of the index list.

    std::vector<unsigned short> indices;
    indices.reserve(m_numberOfIsolinesIndices);

    // Replace the placeholder code below with code that, for each quad in the grid, computes its
    // four indices and adds it to the indices vector.
    indices.push_back(0U);
    indices.push_back(m_DIM / 2U);
    indices.push_back((m_DIM / 2U) + (m_DIM / 2U) * m_DIM);
    indices.push_back(m_DIM * (m_DIM / 2U));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_eboIsolines);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(indices.size() * sizeof(unsigned short)),
                 indices.data(),
                 GL_STATIC_DRAW);
}

void Visualization::opengl_setupGlyphs()
{
    opengl_bufferSingleGlyph();
    opengl_setupGlyphsPerInstanceData();
}

void Visualization::opengl_bufferSingleGlyph()
{
    std::pair<std::vector<QVector3D>, std::vector<unsigned short>> singleGlyph;

    switch (m_currentGlyphType)
    {
        case Glyph::GlyphType::Hedgehog:
            singleGlyph = Glyph::hedgehog();
        break;

        case Glyph::GlyphType::Triangle:
            singleGlyph = Glyph::triangle(0.3F);
        break;

        case Glyph::GlyphType::Arrow2D:
            singleGlyph = Glyph::arrow2D(0.1F, 0.5F, 0.3F);
        break;

        case Glyph::GlyphType::Cone:
            singleGlyph = Glyph::cone(0.3F, 10);
        break;

        case Glyph::GlyphType::Arrow3D:
            singleGlyph = Glyph::arrow3D(0.1F, 0.5F, 0.3F, 10U);
        break;
    }

    auto const glyphVertices = singleGlyph.first;
    auto const glyphIndices = singleGlyph.second;
    m_glyphIndicesSize = glyphIndices.size();

    glBindVertexArray(m_vaoGlyphs);

    // Buffer a single glyph.
    glBindBuffer(GL_ARRAY_BUFFER, m_vboGlyphs);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(glyphVertices.size() * 3U * sizeof(float)),
                 glyphVertices.data(),
                 GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<GLvoid*>(0));

    // Buffer indices for the glyph.
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_eboGlyphs);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(m_glyphIndicesSize * sizeof(unsigned short)),
                 glyphIndices.data(),
                 GL_STATIC_DRAW);
}

void Visualization::opengl_setupGlyphsPerInstanceData()
{
    // Buffering section starts here.
    glBindVertexArray(m_vaoGlyphs);

    glBindBuffer(GL_ARRAY_BUFFER, m_vboValuesGlyphs);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(m_numberOfGlyphsX * m_numberOfGlyphsY * sizeof(float)),
                 static_cast<GLvoid*>(nullptr),
                 GL_DYNAMIC_DRAW);

    // Buffer values.
    static bool firstRun = true;
    if (firstRun)
    {
        glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<GLvoid*>(0));
        glEnableVertexAttribArray(1);
        glVertexAttribDivisor(1, 1);
    }

    // Buffer model transformation matrices.
    glBindBuffer(GL_ARRAY_BUFFER, m_vboModelTransformationMatricesGlyphs);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(m_numberOfGlyphsX * m_numberOfGlyphsY * 16U * sizeof(float)),
                 static_cast<GLvoid*>(nullptr),
                 GL_DYNAMIC_DRAW);

    // A location can maximally hold 4 values, so for a 4x4 matrix,
    // 4 attribute pointers need to be defined.
    if (firstRun)
    {
        firstRun = false;
        for (unsigned int columnIdx = 0; columnIdx < 4; ++columnIdx)
        {
            glVertexAttribPointer(2 + columnIdx,
                                  4,
                                  GL_FLOAT,
                                  GL_FALSE,
                                  16U * sizeof(float),
                                  reinterpret_cast<GLvoid*>(4U * sizeof(float) * columnIdx));
            glEnableVertexAttribArray(2 + columnIdx);
            glVertexAttribDivisor(2 + columnIdx, 1);
        }
    }
}

void Visualization::opengl_setupHeightplot()
{
    glBindVertexArray(m_vaoHeightplot);

    glBindBuffer(GL_ARRAY_BUFFER, m_vboHeightplotPoints);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(m_DIM * m_DIM * 2U * sizeof(float)),
                 static_cast<GLvoid*>(nullptr),
                 GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<GLvoid*>(0));

    glBindBuffer(GL_ARRAY_BUFFER, m_vboHeightplotHeight);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(m_DIM * m_DIM * sizeof(float)),
                 static_cast<GLvoid*>(nullptr),
                 GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<GLvoid*>(0));

    glBindBuffer(GL_ARRAY_BUFFER, m_vboHeightplotScalarValues);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(m_DIM * m_DIM * sizeof(float)),
                 static_cast<GLvoid*>(nullptr),
                 GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<GLvoid*>(0));

    glBindBuffer(GL_ARRAY_BUFFER, m_vboHeightplotNormals);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(m_DIM * m_DIM * 3U * sizeof(float)),
                 static_cast<GLvoid*>(nullptr),
                 GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<GLvoid*>(0));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_eboHeightplot);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(m_indices.size() * sizeof(unsigned short)),
                 m_indices.data(),
                 GL_STATIC_DRAW);
}

void Visualization::opengl_setupLic()
{
    glBindVertexArray(m_vaoLic);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboLic);

    glEnableVertexAttribArray(0U);
    glVertexAttribPointer(0U, 2, GL_FLOAT, GL_FALSE, 2U * sizeof(QVector2D), reinterpret_cast<GLvoid*>(0));

    glEnableVertexAttribArray(1U);
    glVertexAttribPointer(1U, 2, GL_FLOAT, GL_FALSE, 2U * sizeof(QVector2D), reinterpret_cast<GLvoid*>(2U * sizeof(GLfloat)));

    glBindBuffer(GL_ARRAY_BUFFER, m_vboLic);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(8U * sizeof(QVector2D)),
                 nullptr,
                 GL_STATIC_DRAW);
}

// Render a window-sized quad.
void Visualization::opengl_setupVolumeRendering()
{
    struct Vertex
    {
        QVector2D coordinate;
        QVector2D uv;
    };

    /* Create a triangle with the bottom-left vertex at (-1, -1), the top-left corner above the screen-space quad,
     * and the bottom-right corner to the right of the screen-space quad. The top-right corner of the screen-space quad
     * lies on the hypothenuse. The UV coordinates are adjusted accordingly.
     * This may slightly speed up rendering compared to drawing two triangles by reducing the number of fragment shader helper invocations.
     * The parts of the triangle that lie outside of the screen-space quad will be clipped in practice and do not cause extra fragment shader invocations.
     * Ref: https://stackoverflow.com/questions/2588875/whats-the-best-way-to-draw-a-fullscreen-quad-in-opengl-3-2
     */
    std::array<Vertex, 3U> const vertices{{{QVector2D{-1.0F, -1.0F}, QVector2D{0.0F, 0.0F}},
                                           {QVector2D{ 3.0F, -1.0F}, QVector2D{2.0F, 0.0F}},
                                           {QVector2D{-1.0F,  3.0F}, QVector2D{0.0F, 2.0F}}}};

    // Buffer data
    glBindVertexArray(m_vaoVolumeRendering);

    glBindBuffer(GL_ARRAY_BUFFER, m_vboVolumeRendering);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(vertices.size() * sizeof(Vertex)),
                 vertices.data(),
                 GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid*>(0));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid*>(2U * sizeof(GLfloat)));

    // Load synthetic cube data by default
    opengl_updateTextureSyntheticCube();

    opengl_updatePreIntegrationLookupTable();
}

static GLint uniformLocationWithCheck(QOpenGLShaderProgram const &openGLShaderProgram, char const * const filePath)
{
    GLint const loc = openGLShaderProgram.uniformLocation(filePath);
    if (loc == -1)
        qDebug() << "Warning: retrieving uniform location for" << filePath << "has failed.";

    return loc;
};

void Visualization::opengl_createShaderProgramScalarDataScaleTexture()
{
    m_shaderProgramScalarDataScaleTexture.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/shaders/scalarData_scale.vert");
    m_shaderProgramScalarDataScaleTexture.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/scalarData_texture.frag");
    m_shaderProgramScalarDataScaleTexture.link();

    m_uniformLocationScalarDataScaleTexture_texture = uniformLocationWithCheck(m_shaderProgramScalarDataScaleTexture, "textureSampler");

    m_uniformLocationScalarDataScaleTexture_rangeMin = uniformLocationWithCheck(m_shaderProgramScalarDataScaleTexture, "rangeMin");
    m_uniformLocationScalarDataScaleTexture_rangeMax = uniformLocationWithCheck(m_shaderProgramScalarDataScaleTexture, "rangeMax");
    m_uniformLocationScalarDataScaleTexture_transferK = uniformLocationWithCheck(m_shaderProgramScalarDataScaleTexture, "transferK");

    qDebug() << "m_shaderProgramScalarDataScaleTexture initialized.";
}

void Visualization::opengl_createShaderProgramScalarDataScaleCustomColorMap()
{
    m_shaderProgramScalarDataScaleCustomColorMap.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/shaders/scalarData_scale.vert");
    m_shaderProgramScalarDataScaleCustomColorMap.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/scalarData_customcolormap.frag");
    m_shaderProgramScalarDataScaleCustomColorMap.link();

    m_uniformLocationScalarDataScaleCustomColorMap_colorMapColors = uniformLocationWithCheck(m_shaderProgramScalarDataScaleCustomColorMap, "colorMapColors");

    m_uniformLocationScalarDataScaleCustomColorMap_rangeMin = uniformLocationWithCheck(m_shaderProgramScalarDataScaleCustomColorMap, "rangeMin");
    m_uniformLocationScalarDataScaleCustomColorMap_rangeMax = uniformLocationWithCheck(m_shaderProgramScalarDataScaleCustomColorMap, "rangeMax");
    m_uniformLocationScalarDataScaleCustomColorMap_transferK = uniformLocationWithCheck(m_shaderProgramScalarDataScaleCustomColorMap, "transferK");

    qDebug() << "m_shaderProgramScalarDataScaleCustomColorMap initialized.";
}

void Visualization::opengl_createShaderProgramScalarDataClampTexture()
{
    m_shaderProgramScalarDataClampTexture.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/shaders/scalarData_clamp.vert");
    m_shaderProgramScalarDataClampTexture.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/scalarData_texture.frag");
    m_shaderProgramScalarDataClampTexture.link();

    m_uniformLocationScalarDataClampTexture_texture = uniformLocationWithCheck(m_shaderProgramScalarDataClampTexture, "textureSampler");

    m_uniformLocationScalarDataClampTexture_clampMin = uniformLocationWithCheck(m_shaderProgramScalarDataClampTexture, "clampMin");
    m_uniformLocationScalarDataClampTexture_clampMax = uniformLocationWithCheck(m_shaderProgramScalarDataClampTexture, "clampMax");
    m_uniformLocationScalarDataClampTexture_transferK = uniformLocationWithCheck(m_shaderProgramScalarDataClampTexture, "transferK");

    qDebug() << "m_shaderProgramScalarDataClampTexture initialized.";
}

void Visualization::opengl_createShaderProgramScalarDataClampCustomColorMap()
{
    m_shaderProgramScalarDataClampCustomColorMap.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/shaders/scalarData_clamp.vert");
    m_shaderProgramScalarDataClampCustomColorMap.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/scalarData_customcolormap.frag");
    m_shaderProgramScalarDataClampCustomColorMap.link();

    m_uniformLocationScalarDataClampCustomColorMap_colorMapColors = uniformLocationWithCheck(m_shaderProgramScalarDataClampCustomColorMap, "colorMapColors");

    m_uniformLocationScalarDataClampCustomColorMap_clampMin = uniformLocationWithCheck(m_shaderProgramScalarDataClampCustomColorMap, "clampMin");
    m_uniformLocationScalarDataClampCustomColorMap_clampMax = uniformLocationWithCheck(m_shaderProgramScalarDataClampCustomColorMap, "clampMax");
    m_uniformLocationScalarDataClampCustomColorMap_transferK = uniformLocationWithCheck(m_shaderProgramScalarDataClampCustomColorMap, "transferK");

    qDebug() << "m_shaderProgramScalarDataClampCustomColorMap initialized.";
}

void Visualization::opengl_createShaderProgramColorMapInstanced()
{
    m_shaderProgramVectorData.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/shaders/glyph.vert");
    m_shaderProgramVectorData.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/glyph.frag");
    m_shaderProgramVectorData.link();

    m_uniformLocationTextureColorMapInstanced = uniformLocationWithCheck(m_shaderProgramVectorData, "textureSampler");

    qDebug() << "m_shaderProgramVectorData initialized.";
}

void Visualization::opengl_createShaderProgramIsolines()
{
    m_shaderProgramIsolines.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/shaders/isolines.vert");
    m_shaderProgramIsolines.addShaderFromSourceFile(QOpenGLShader::Geometry, ":/shaders/isolines.geom");
    m_shaderProgramIsolines.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/isolines.frag");
    m_shaderProgramIsolines.link();

    m_uniformLocationIsolines_useInterpolation = uniformLocationWithCheck(m_shaderProgramIsolines, "useInterpolation");
    m_uniformLocationIsolines_ambiguousCaseMidpoint = uniformLocationWithCheck(m_shaderProgramIsolines, "ambiguousCaseMidpoint");
    m_uniformLocationIsolines_color = uniformLocationWithCheck(m_shaderProgramIsolines, "isolineColor");
    m_uniformLocationIsolines_rho = uniformLocationWithCheck(m_shaderProgramIsolines, "rho");

    qDebug() << "m_shaderProgramIsolines initialized.";
}

void Visualization::opengl_createShaderProgramHeightplotScale()
{
    m_shaderProgramHeightplotScale.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/shaders/heightplot_scale.vert");
    m_shaderProgramHeightplotScale.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/heightplot.frag");
    m_shaderProgramHeightplotScale.link();

    m_uniformLocationHeightplotScale_rangeMin = uniformLocationWithCheck(m_shaderProgramHeightplotScale, "rangeMin");
    m_uniformLocationHeightplotScale_rangeMax = uniformLocationWithCheck(m_shaderProgramHeightplotScale, "rangeMax");
    m_uniformLocationHeightplotScale_transferK = uniformLocationWithCheck(m_shaderProgramHeightplotScale, "transferK");

    m_uniformLocationHeightplotScale_projection = uniformLocationWithCheck(m_shaderProgramHeightplotScale, "projectionTransform");
    m_uniformLocationHeightplotScale_view = uniformLocationWithCheck(m_shaderProgramHeightplotScale, "viewTransform");
    m_uniformLocationHeightplotScale_normal = uniformLocationWithCheck(m_shaderProgramHeightplotScale, "normalTransform");

    m_uniformLocationHeightplotScale_material = uniformLocationWithCheck(m_shaderProgramHeightplotScale, "material");
    m_uniformLocationHeightplotScale_light = uniformLocationWithCheck(m_shaderProgramHeightplotScale, "lightPosition");

    m_uniformLocationHeightplotScale_texture = uniformLocationWithCheck(m_shaderProgramHeightplotScale, "textureSampler");

    qDebug() << "m_shaderProgramHeightplotScale initialized.";
}

void Visualization::opengl_createShaderProgramHeightplotClamp()
{
    m_shaderProgramHeightplotClamp.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/shaders/heightplot_clamp.vert");
    m_shaderProgramHeightplotClamp.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/heightplot.frag");
    m_shaderProgramHeightplotClamp.link();

    m_uniformLocationHeightplotClamp_clampMin = uniformLocationWithCheck(m_shaderProgramHeightplotClamp, "clampMin");
    m_uniformLocationHeightplotClamp_clampMax = uniformLocationWithCheck(m_shaderProgramHeightplotClamp, "clampMax");
    m_uniformLocationHeightplotClamp_transferK = uniformLocationWithCheck(m_shaderProgramHeightplotClamp, "transferK");

    m_uniformLocationHeightplotClamp_projection = uniformLocationWithCheck(m_shaderProgramHeightplotClamp, "projectionTransform");
    m_uniformLocationHeightplotClamp_view = uniformLocationWithCheck(m_shaderProgramHeightplotClamp, "viewTransform");
    m_uniformLocationHeightplotClamp_normal = uniformLocationWithCheck(m_shaderProgramHeightplotClamp, "normalTransform");

    m_uniformLocationHeightplotClamp_material = uniformLocationWithCheck(m_shaderProgramHeightplotClamp, "material");
    m_uniformLocationHeightplotClamp_light = uniformLocationWithCheck(m_shaderProgramHeightplotClamp, "lightPosition");

    m_uniformLocationHeightplotClamp_texture = uniformLocationWithCheck(m_shaderProgramHeightplotClamp, "textureSampler");

    qDebug() << "m_shaderProgramHeightplotClamp initialized.";
}

void Visualization::opengl_createShaderProgramLic()
{
    m_shaderProgramLic.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/shaders/lic.vert");
    m_shaderProgramLic.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/lic.frag");
    m_shaderProgramLic.link();

    m_uniformLocationLicNoiseTexture = uniformLocationWithCheck(m_shaderProgramLic, "noiseTexture");
    m_uniformLocationLicVelocityField = uniformLocationWithCheck(m_shaderProgramLic, "velocityField");

    m_uniformLocationLicStreamlineLength = uniformLocationWithCheck(m_shaderProgramLic, "streamlineLength");
    m_uniformLocationLicStepSize = uniformLocationWithCheck(m_shaderProgramLic, "stepSize");

    m_shaderProgramLic.bind();

    qDebug() << "m_shaderProgramLic initialized.";
}

void Visualization::opengl_createShaderProgramVolumeRendering()
{
    m_shaderProgramVolumeRendering.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/shaders/volume_rendering.vert");
    m_shaderProgramVolumeRendering.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/volume_rendering.frag");
    m_shaderProgramVolumeRendering.link();

    m_uniformLocationVolumeRendering_iTime = uniformLocationWithCheck(m_shaderProgramVolumeRendering, "iTime");

    m_uniformLocationVolumeRendering_iResolution = uniformLocationWithCheck(m_shaderProgramVolumeRendering, "iResolution");

    m_uniformLocationVolumeRenderingTexture = uniformLocationWithCheck(m_shaderProgramVolumeRendering, "textureSampler");

    m_shaderProgramVolumeRendering.bind();

    qDebug() << "m_shaderProgramVolumeRendering initialized.";
}

void Visualization::opengl_createShaderProgramVolumeRenderingLighting()
{
    m_shaderProgramVolumeRenderingLighting.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/shaders/volume_rendering.vert");
    m_shaderProgramVolumeRenderingLighting.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/volume_rendering_lighting.frag");
    m_shaderProgramVolumeRenderingLighting.link();

    m_uniformLocationVolumeRendering_iTimeLighting = uniformLocationWithCheck(m_shaderProgramVolumeRenderingLighting, "iTime");

    m_uniformLocationVolumeRendering_iResolutionLighting = uniformLocationWithCheck(m_shaderProgramVolumeRenderingLighting, "iResolution");

    m_shaderProgramVolumeRenderingLighting.bind();

    qDebug() << "m_shaderProgramVolumeRenderingLighting initialized.";
}

void Visualization::opengl_createShaderProgramVolumeRenderingPreIntegration()
{
    m_shaderProgramVolumeRenderingPreIntegration.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/shaders/volume_rendering.vert");
    m_shaderProgramVolumeRenderingPreIntegration.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/volume_rendering_preintegration.frag");
    m_shaderProgramVolumeRenderingPreIntegration.link();

    m_uniformLocationVolumeRenderingPreIntegration_iTime = uniformLocationWithCheck(m_shaderProgramVolumeRenderingPreIntegration, "iTime");

    m_uniformLocationVolumeRenderingPreIntegration_iResolution = uniformLocationWithCheck(m_shaderProgramVolumeRenderingPreIntegration, "iResolution");

    m_uniformLocationVolumeRenderingPreIntegrationTexture = uniformLocationWithCheck(m_shaderProgramVolumeRenderingPreIntegration, "textureSampler");

    m_uniformLocationVolumeRenderingPreIntegrationTextureLookupTable = uniformLocationWithCheck(m_shaderProgramVolumeRenderingPreIntegration, "lookupTable");

    m_shaderProgramVolumeRenderingPreIntegration.bind();

    qDebug() << "m_shaderProgramVolumeRenderingPreIntegration initialized.";
}

void Visualization::opengl_createShaderProgramVolumeRenderingOverlayRendering()
{
    m_shaderProgramVolumeRenderingOverlayRendering.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/shaders/volume_rendering.vert");
    m_shaderProgramVolumeRenderingOverlayRendering.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/volume_rendering_overlay_rendering.frag");
    m_shaderProgramVolumeRenderingOverlayRendering.link();

    m_uniformLocationVolumeRenderingOverlayRendering_iTime = uniformLocationWithCheck(m_shaderProgramVolumeRenderingOverlayRendering, "iTime");

    m_uniformLocationVolumeRenderingOverlayRendering_iResolution = uniformLocationWithCheck(m_shaderProgramVolumeRenderingOverlayRendering, "iResolution");

    m_uniformLocationVolumeRenderingOverlayRenderingTexture = uniformLocationWithCheck(m_shaderProgramVolumeRenderingOverlayRendering, "textureSampler");

    m_shaderProgramVolumeRenderingOverlayRendering.bind();

    qDebug() << "m_shaderProgramVolumeRenderingOverlayRendering initialized.";
}

void Visualization::opengl_loadVectorDataTexture(std::vector<Color> const &colorMap)
{
    glBindTexture(GL_TEXTURE_1D, m_vectorDataTextureLocation);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage1D(GL_TEXTURE_1D,
                 0,
                 GL_RGB32F,
                 static_cast<GLint>(colorMap.size()),
                 0,
                 GL_RGB,
                 GL_FLOAT,
                 colorMap.data());
}

void Visualization::opengl_generateAndLoadLicNoiseTexture()
{
    // Generate the noise texture
    std::vector<float> const noiseTexture = m_lic.noiseTexture(m_licTextureWidth, m_licTextureHeight);

    // Set the texture parameters
    glBindTexture(GL_TEXTURE_2D, m_licNoiseTexture);

    // These are the defaults and do not need to be set explicitly.
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Send the texture to the GPU
    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RED,
                 m_licTextureWidth,
                 m_licTextureHeight,
                 0,
                 GL_RED,
                 GL_FLOAT,
                 noiseTexture.data());
}

void Visualization::opengl_loadLicVelocityField(std::vector<float> const &velocityField)
{
    glBindTexture(GL_TEXTURE_2D, m_licVelocityField);

    // These are the defaults and do not need to be set explicitly.
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RG32F,
                 static_cast<GLsizei>(m_DIM),
                 static_cast<GLsizei>(m_DIM),
                 0,
                 GL_RG,
                 GL_FLOAT,
                 velocityField.data());
}

void Visualization::opengl_updateScalarPoints()
{
    // Recompute and upload grid coordinates.
    std::vector<QVector2D> scalarPoints;
    scalarPoints.reserve(m_DIM * m_DIM);

    for (size_t j = 0U; j < m_DIM; ++j)
    {
        for (size_t i = 0U; i < m_DIM; ++i)
        {
            auto const iFloat = static_cast<float>(i);
            auto const jFloat = static_cast<float>(j);

            QVector2D const v0{m_cellWidth  + iFloat * m_cellWidth - 1.0F,
                               m_cellHeight + jFloat * m_cellHeight - 1.0F};

            scalarPoints.push_back(v0);
        }
    }

    glBindBuffer(GL_ARRAY_BUFFER, m_vboScalarPoints);
    glBufferSubData(GL_ARRAY_BUFFER,
                    0,
                    static_cast<GLsizeiptr>(scalarPoints.size() * 2U * sizeof(float)),
                    scalarPoints.data());

    glBindBuffer(GL_ARRAY_BUFFER, m_vboHeightplotPoints);
    glBufferSubData(GL_ARRAY_BUFFER,
                    0,
                    static_cast<GLsizeiptr>(scalarPoints.size() * 2U * sizeof(float)),
                    scalarPoints.data());
}

void Visualization::opengl_updateLicPoints()
{
    // Recompute and upload grid coordinates for the quad that the LIC texture is rendered to.
    std::vector<QVector2D> licCoordsAndTexCoords;
    licCoordsAndTexCoords.reserve(8U);

    float const min = m_cellWidth - 1.0F;
    float const max = static_cast<float>(m_DIM) * m_cellWidth - 1.0F;

    // Top left OpenGL coordinate.
    licCoordsAndTexCoords.emplace_back(min, max);
    licCoordsAndTexCoords.emplace_back(0.0F, 1.0F);

    // Bottom left
    licCoordsAndTexCoords.emplace_back(min, min);
    licCoordsAndTexCoords.emplace_back(0.0F, 0.0F);

    // Top right
    licCoordsAndTexCoords.emplace_back(max, max);
    licCoordsAndTexCoords.emplace_back(1.0F, 1.0F);

    // Bottom right
    licCoordsAndTexCoords.emplace_back(max, min);
    licCoordsAndTexCoords.emplace_back(1.0F, 0.0F);

    glBindBuffer(GL_ARRAY_BUFFER, m_vboLic);
    glBufferSubData(GL_ARRAY_BUFFER,
                    0,
                    static_cast<GLsizeiptr>(licCoordsAndTexCoords.size() * sizeof(QVector2D)),
                    licCoordsAndTexCoords.data());
}

void Visualization::opengl_drawScalarData(std::vector<float> const &scalarValues)
{
    switch (m_currentMappingType)
    {
        case MappingType::Scaling:
        {
            if (m_useCustomColorMap)
            {
                m_shaderProgramScalarDataScaleCustomColorMap.bind();

                auto const currentMinMaxIt = std::minmax_element(scalarValues.cbegin(), scalarValues.cend());
                QVector2D const currentMinMax{*currentMinMaxIt.first, *currentMinMaxIt.second};

                m_minMaxDensity.update(currentMinMax);
                QVector2D const minMaxRange{m_minMaxDensity.range()};

                // Send values to GUI.
                if (m_sendMinMaxToUI)
                {
                    auto const mainWindowPtr = qobject_cast<MainWindow*>(parent()->parent());
                    Q_ASSERT(mainWindowPtr != nullptr);
                    mainWindowPtr->setScalarDataMin(minMaxRange.x());
                    mainWindowPtr->setScalarDataMax(minMaxRange.y());
                }

                glUniform1f(m_uniformLocationScalarDataScaleCustomColorMap_rangeMin, minMaxRange.x());
                glUniform1f(m_uniformLocationScalarDataScaleCustomColorMap_rangeMax, minMaxRange.y());
                glUniform1f(m_uniformLocationScalarDataScaleCustomColorMap_transferK, m_transferK);

                GLfloat const *ptrToFirstElement = &m_customColors[0].r;
                glUniform3fv(m_uniformLocationScalarDataScaleCustomColorMap_colorMapColors, 3, ptrToFirstElement);
            }
            else
            {
                m_shaderProgramScalarDataScaleTexture.bind();

                auto const currentMinMaxIt = std::minmax_element(scalarValues.cbegin(), scalarValues.cend());
                QVector2D const currentMinMax{*currentMinMaxIt.first, *currentMinMaxIt.second};

                m_minMaxDensity.update(currentMinMax);
                QVector2D const minMaxRange{m_minMaxDensity.range()};

                // Send values to GUI.
                if (m_sendMinMaxToUI)
                {
                    auto const mainWindowPtr = qobject_cast<MainWindow*>(parent()->parent());
                    Q_ASSERT(mainWindowPtr != nullptr);
                    mainWindowPtr->setScalarDataMin(minMaxRange.x());
                    mainWindowPtr->setScalarDataMax(minMaxRange.y());
                }

                glUniform1f(m_uniformLocationScalarDataScaleTexture_rangeMin, minMaxRange.x());
                glUniform1f(m_uniformLocationScalarDataScaleTexture_rangeMax, minMaxRange.y());
                glUniform1f(m_uniformLocationScalarDataScaleTexture_transferK, m_transferK);

                glUniform1i(m_uniformLocationScalarDataScaleTexture_texture, 0);
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_1D, m_scalarDataTextureLocation);
            }
        }
        break;

        case MappingType::Clamping:
        {
            if (m_useCustomColorMap)
            {
                m_shaderProgramScalarDataClampCustomColorMap.bind();

                // Send values to GUI.
                if (m_sendMinMaxToUI)
                {
                    auto const mainWindowPtr = qobject_cast<MainWindow*>(parent()->parent());
                    Q_ASSERT(mainWindowPtr != nullptr);
                    mainWindowPtr->setScalarDataMin(m_clampMin);
                    mainWindowPtr->setScalarDataMax(m_clampMax);
                }

                glUniform1f(m_uniformLocationScalarDataClampCustomColorMap_clampMin, m_clampMin);
                glUniform1f(m_uniformLocationScalarDataClampCustomColorMap_clampMax, m_clampMax);
                glUniform1f(m_uniformLocationScalarDataClampCustomColorMap_transferK, m_transferK);

                GLfloat const *ptrToFirstElement = &m_customColors[0].r;
                glUniform3fv(m_uniformLocationScalarDataClampCustomColorMap_colorMapColors, 3, ptrToFirstElement);
            }
            else
            {
                m_shaderProgramScalarDataClampTexture.bind();

                // Send values to GUI.
                if (m_sendMinMaxToUI)
                {
                    auto const mainWindowPtr = qobject_cast<MainWindow*>(parent()->parent());
                    Q_ASSERT(mainWindowPtr != nullptr);
                    mainWindowPtr->setScalarDataMin(m_clampMin);
                    mainWindowPtr->setScalarDataMax(m_clampMax);
                }

                glUniform1f(m_uniformLocationScalarDataClampTexture_clampMin, m_clampMin);
                glUniform1f(m_uniformLocationScalarDataClampTexture_clampMax, m_clampMax);
                glUniform1f(m_uniformLocationScalarDataClampTexture_transferK, m_transferK);

                glUniform1i(m_uniformLocationScalarDataClampTexture_texture, 0);
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_1D, m_scalarDataTextureLocation);
            }
        }
        break;
    }

    glBindVertexArray(m_vaoScalarData);

    // Copy scalars to GPU buffer
    glBindBuffer(GL_ARRAY_BUFFER, m_vboScalarData);
    glBufferSubData(GL_ARRAY_BUFFER,
                    0,
                    static_cast<GLsizeiptr>(scalarValues.size() * sizeof(float)),
                    scalarValues.data());

    glDrawElements(GL_TRIANGLE_STRIP,
                   static_cast<GLsizei>(m_indices.size()),
                   GL_UNSIGNED_SHORT,
                   static_cast<GLvoid*>(nullptr));
}

void Visualization::opengl_drawIsolines()
{
    float const stepsize = [&]()
    {
        if (m_numberOfIsolines > 1)
            return (m_isolineMaxValue - m_isolineMinValue) / (m_numberOfIsolines - 1);

        return 1.0F;
    }();

    std::vector<float> scalarValues;

    switch (m_manuallyChooseIsolineDataType ? m_currentIsolineDataType : m_currentScalarDataType)
    {
    case ScalarDataType::Density: scalarValues = m_simulation.density(); break;
    case ScalarDataType::ForceFieldMagnitude: scalarValues = m_simulation.forceFieldMagnitude(); break;
    case ScalarDataType::VelocityMagnitude: scalarValues = m_simulation.velocityMagnitude(); break;
    case ScalarDataType::VelocityDivergence: scalarValues = velocityDivergence(); break;
    case ScalarDataType::ForceFieldDivergence: scalarValues = forceFieldDivergence(); break;
    }

    std::vector<Color> const colorMap = Texture::createTurboTexture(m_numberOfIsolines);
    for (size_t n = 0U; n < m_numberOfIsolines; ++n)
    {
        float const currentIsolineValue = m_isolineMinValue + (n * stepsize);

        m_shaderProgramIsolines.bind();
        switch (m_isolinesInterpolationMethod)
        {
        case IsolinesInterpolationMethod::Linear:
            glUniform1i(m_uniformLocationIsolines_useInterpolation, GL_TRUE);
            break;

        case IsolinesInterpolationMethod::None:
            glUniform1i(m_uniformLocationIsolines_useInterpolation, GL_FALSE);
            break;
        }

        switch (m_isolinesAmbiguousCaseDecider)
        {
        case IsolinesAmbiguousCaseDecider::Midpoint:
            glUniform1i(m_uniformLocationIsolines_ambiguousCaseMidpoint, GL_TRUE);
            break;

        case IsolinesAmbiguousCaseDecider::Asymptotic:
            glUniform1i(m_uniformLocationIsolines_ambiguousCaseMidpoint, GL_FALSE);
            break;
        }

        glUniform1f(m_uniformLocationIsolines_rho, currentIsolineValue);

        if (m_numberOfIsolines == 1U)
            glUniform3fv(m_uniformLocationIsolines_color, 1, &m_isolineColor[0]);
        else
            glUniform3f(m_uniformLocationIsolines_color, colorMap[n].r, colorMap[n].g, colorMap[n].b);

        glBindVertexArray(m_vaoIsolines);

        glDrawElements(GL_LINES_ADJACENCY, m_numberOfIsolinesIndices, GL_UNSIGNED_SHORT, static_cast<GLvoid*>(nullptr));
    }
}

void Visualization::opengl_drawHeightplot()
{
    std::vector<float> scalarValues;
    std::vector<float> heightValues;

    switch (m_currentScalarDataType)
    {
        case ScalarDataType::Density: scalarValues = m_simulation.density(); break;
        case ScalarDataType::ForceFieldMagnitude: scalarValues = m_simulation.forceFieldMagnitude(); break;
        case ScalarDataType::VelocityMagnitude: scalarValues = m_simulation.velocityMagnitude(); break;
        case ScalarDataType::VelocityDivergence: scalarValues = velocityDivergence(); break;
        case ScalarDataType::ForceFieldDivergence: scalarValues = forceFieldDivergence(); break;
    }

    switch (m_currentHeightplotDataType)
    {
        case ScalarDataType::Density: heightValues = m_simulation.density(); break;
        case ScalarDataType::ForceFieldMagnitude: heightValues = m_simulation.forceFieldMagnitude(); break;
        case ScalarDataType::VelocityMagnitude: heightValues = m_simulation.velocityMagnitude(); break;
        case ScalarDataType::VelocityDivergence: heightValues = velocityDivergence(); break;
        case ScalarDataType::ForceFieldDivergence: heightValues = forceFieldDivergence(); break;
    }

    switch (m_currentMappingType)
    {
        case MappingType::Scaling:
        {
            m_shaderProgramHeightplotScale.bind();
            glUniformMatrix4fv(m_uniformLocationHeightplotScale_projection, 1, GL_FALSE, m_projectionTransformationMatrix.data());
            glUniformMatrix4fv(m_uniformLocationHeightplotScale_view, 1, GL_FALSE, m_viewTransformationMatrix.data());
            glUniformMatrix3fv(m_uniformLocationHeightplotScale_normal, 1, GL_FALSE, m_normalTransformationMatrix.data());

            glUniform4fv(m_uniformLocationHeightplotScale_material, 1, &m_materialConstants[0]);
            glUniform3fv(m_uniformLocationHeightplotScale_light, 1, &m_lightPosition[0]);

            auto const currentMinMaxIt = std::minmax_element(scalarValues.cbegin(), scalarValues.cend());
            QVector2D const currentMinMax{*currentMinMaxIt.first, *currentMinMaxIt.second};

            m_minMaxDensity.update(currentMinMax);
            QVector2D const minMaxRange{m_minMaxDensity.range()};

            // Send values to GUI.
            if (m_sendMinMaxToUI)
            {
                auto const mainWindowPtr = qobject_cast<MainWindow*>(parent()->parent());
                Q_ASSERT(mainWindowPtr != nullptr);
                mainWindowPtr->setScalarDataMin(minMaxRange.x());
                mainWindowPtr->setScalarDataMax(minMaxRange.y());
            }

            glUniform1f(m_uniformLocationHeightplotScale_rangeMin, minMaxRange.x());
            glUniform1f(m_uniformLocationHeightplotScale_rangeMax, minMaxRange.y());
            glUniform1f(m_uniformLocationHeightplotScale_transferK, m_transferK);

            glUniform1i(m_uniformLocationHeightplotScale_texture, 0);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_1D, m_scalarDataTextureLocation);
        }
        break;

        case MappingType::Clamping:
        {
            m_shaderProgramHeightplotClamp.bind();
            glUniformMatrix4fv(m_uniformLocationHeightplotClamp_projection, 1, GL_FALSE, m_projectionTransformationMatrix.data());
            glUniformMatrix4fv(m_uniformLocationHeightplotClamp_view, 1, GL_FALSE, m_viewTransformationMatrix.data());
            glUniformMatrix3fv(m_uniformLocationHeightplotClamp_normal, 1, GL_FALSE, m_normalTransformationMatrix.data());

            glUniform4fv(m_uniformLocationHeightplotClamp_material, 1, &m_materialConstants[0]);
            glUniform3fv(m_uniformLocationHeightplotClamp_light, 1, &m_lightPosition[0]);

            // Send values to GUI.
            auto const mainWindowPtr = qobject_cast<MainWindow*>(parent()->parent());
            Q_ASSERT(mainWindowPtr != nullptr);
            mainWindowPtr->setScalarDataMin(m_clampMin);
            mainWindowPtr->setScalarDataMax(m_clampMax);

            glUniform1f(m_uniformLocationHeightplotClamp_clampMin, m_clampMin);
            glUniform1f(m_uniformLocationHeightplotClamp_clampMax, m_clampMax);
            glUniform1f(m_uniformLocationHeightplotClamp_transferK, m_transferK);

            glUniform1i(m_uniformLocationHeightplotClamp_texture, 0);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_1D, m_scalarDataTextureLocation);
        }
        break;
    }

    // Add scaling for nicer results
    std::transform(heightValues.begin(), heightValues.end(), heightValues.begin(),
                   [](float x){ return x * (1.0F / 9.0F); });

    std::vector<QVector3D> normals = computeNormals(heightValues);

    glBindVertexArray(m_vaoHeightplot);

    // Copy scalars to GPU buffer
    glBindBuffer(GL_ARRAY_BUFFER, m_vboHeightplotScalarValues);
    glBufferSubData(GL_ARRAY_BUFFER,
                    0,
                    static_cast<GLsizeiptr>(scalarValues.size() * sizeof(float)),
                    scalarValues.data());

    glBindBuffer(GL_ARRAY_BUFFER, m_vboHeightplotHeight);
    glBufferSubData(GL_ARRAY_BUFFER,
                    0,
                    static_cast<GLsizeiptr>(heightValues.size() * sizeof(float)),
                    heightValues.data());

    glBindBuffer(GL_ARRAY_BUFFER, m_vboHeightplotNormals);
    glBufferSubData(GL_ARRAY_BUFFER,
                    0,
                    static_cast<GLsizeiptr>(normals.size() * 3U * sizeof(float)),
                    normals.data());

    glDrawElements(GL_TRIANGLE_STRIP,
                   static_cast<GLsizei>(m_indices.size()),
                   GL_UNSIGNED_SHORT,
                   static_cast<GLvoid*>(nullptr));
}

void Visualization::opengl_drawLic()
{
    std::vector<float> const &velocityX = m_simulation.velocityX();
    std::vector<float> const &velocityY = m_simulation.velocityY();

    // Combine the two velocity vectors into one interleaved vector
    auto const velocityField = [&]()
    {
        std::vector<float> tmp;
        tmp.reserve(2U * m_DIM * m_DIM);

        for (std::size_t idx = 0U; idx < m_DIM * m_DIM; ++idx)
        {
            // Do not use QVector2D's normalize() function, which uses std::hypot to avoid overflow, which makes it slower than this direct implementation.
            float const magnitude = std::sqrt(std::pow(velocityX[idx], 2.0F) + std::pow(velocityY[idx], 2.0F));
            float const scale = magnitude == 0.0F ? 0.0F : 1.0F / magnitude;

            tmp.push_back(velocityX[idx] * scale);
            tmp.push_back(velocityY[idx] * scale);
        }
        return tmp;
    }();

    opengl_loadLicVelocityField(velocityField);

    m_shaderProgramLic.bind();

    glUniform1i(m_uniformLocationLicNoiseTexture, 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_licNoiseTexture);

    glUniform1i(m_uniformLocationLicVelocityField, 1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_licVelocityField);

    glUniform1i(m_uniformLocationLicStreamlineLength, m_licStreamlineLength);
    glUniform1f(m_uniformLocationLicStepSize, m_licStepSize);

    glBindVertexArray(m_vaoLic);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void Visualization::opengl_updateTexture()
{
    switch (m_volumeRenderTexture)
    {
    case VolumeRenderTexture::DataRaw: opengl_updateTextureSyntheticCube(); break;
    case VolumeRenderTexture::SyntheticCube: opengl_updateTextureSyntheticScene(); break;
    case VolumeRenderTexture::SyntheticScene: opengl_updateTextureLoadDataRawFromFile(); break;
    }
}

void Visualization::opengl_updatePreIntegrationLookupTable()
{
    int const DIM = 32; //256; //64;

    std::vector<QVector4D> const lookupTable = computePreIntegrationLookupTable(DIM);

    // Set parameters and upload 2D texture data
    glBindTexture(GL_TEXTURE_2D, m_volumeRenderingTextureLocationPreIntegrationLookupTable);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGBA,
                 DIM,
                 DIM,
                 0,
                 GL_RGBA,
                 GL_FLOAT,
                 lookupTable.data());
}

void Visualization::opengl_updateTextureSyntheticCube()
{
    // Generate synthetic 3D volume data
    auto const ABCvolume = [](QVector3D texCoord)
    {
        QVector3D const center1{0.25F, 0.25F, 0.25F};
        QVector3D const center2{0.75F, 0.75F, 0.75F};

        float const dist1 = (texCoord - center1).length();
        float const dist2 = (texCoord - center2).length();

        float const intensity1 = 0.35F * (std::sin(14.0F * dist1) + 1.0F);
        float const intensity2 = 0.25F * (std::sin(16.0F * dist2) + 1.0F);

        return intensity1 + intensity2;
    };

    std::vector<float> textureData;
    size_t const size = 64U;
    size_t const sizeFloat = static_cast<float>(size);
    textureData.reserve(size * size * size);
    for (size_t w = 0U; w < size; ++w)
    {
        for (size_t v = 0U; v < size; ++v)
        {
            for (size_t u = 0U; u < size; ++u)
            {
                float const uNormalized = (1.0F / sizeFloat) * static_cast<float>(u);
                float const vNormalized = (1.0F / sizeFloat) * static_cast<float>(v);
                float const wNormalized = (1.0F / sizeFloat) * static_cast<float>(w);
                textureData.push_back(ABCvolume({uNormalized, vNormalized, wNormalized}));
            }
        }
    }

    // Set parameters and upload 3D texture data
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_3D, m_volumeRenderingTextureLocation);

    // The texture stores densities, not colors. However, we still have to provide a border "color" for OpenGL.
    // Only the first ("red") of these four values will be read.
    std::array<GLfloat, 4U> const borderValue{0.0F, 0.0F, 0.0F, 0.0F};
    glTexParameterfv(GL_TEXTURE_3D, GL_TEXTURE_BORDER_COLOR, borderValue.data());
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_BORDER);

    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage3D(GL_TEXTURE_3D,
                 0,
                 GL_RED,
                 size,
                 size,
                 size,
                 0,
                 GL_RED,
                 GL_FLOAT,
                 textureData.data());
}

void Visualization::opengl_updateTextureSyntheticScene()
{
    qDebug() << "Not implemented";
}

void Visualization::opengl_loadDataRawFromFile()
{
    qDebug() << "Reading .dat file:" << m_datFilePath.c_str();

    using reader = datraw::raw_reader<char>;
    auto r = reader::open(m_datFilePath);

    m_datRawInfo = r.info();
    qDebug() << "Components:" << m_datRawInfo.components();
    qDebug() << "Resolution:" << m_datRawInfo.resolution();
    qDebug() << "Dimensions:" << m_datRawInfo.dimensions();
    qDebug() << "Number of time steps:" << m_datRawInfo.time_steps();
    qDebug() << "Attempt to load the following files:";
    for (unsigned timeStep = 0U; timeStep < m_datRawInfo.time_steps(); ++timeStep)
        qDebug() << r.info().multi_file_name(timeStep).c_str();

    QDebug debugFormat = qDebug();
    debugFormat << "Format:";
    switch (m_datRawInfo.format())
    {
    case datraw::scalar_type::uint8:  debugFormat << "uint8";  break;
    case datraw::scalar_type::uint16: debugFormat << "uint16"; break;

    default:
        debugFormat << "other";
        break;
    }

    size_t const totalCubeSize = m_datRawInfo.resolution()[0] * m_datRawInfo.resolution()[1] * m_datRawInfo.resolution()[2] * m_datRawInfo.time_steps();
    m_volumeRenderTextureData.resize(totalCubeSize);
    std::fill(m_volumeRenderTextureData.begin(), m_volumeRenderTextureData.end(), 0.0F);

    /*
    // For generating debugging data
    for (size_t cubeIdx = 0U; cubeIdx < 8U; ++cubeIdx)
    {
        size_t offset;
        switch (cubeIdx)
        {
            case 0U: offset = 0U; break;
            case 1U: offset = 256U; break;
            case 2U: offset = 512U * 512U * 256U; break;
            case 3U: offset = 512U * 512U * 256U + 256U; break;
            case 4U: offset = 512U * 256U; break;
            case 5U: offset = 512U * 256U + 256U; break;
            case 6U: offset = 512U * 512U * 256U + 512U * 256U; break;
            case 7U: offset = 512U * 512U * 256U + 256U + 512U * 256U; break;
        }
        for (size_t zIdx = 0U; zIdx < 256U; ++zIdx)
            for (size_t yIdx = 0U; yIdx < 256U; ++yIdx)
                for (size_t xIdx = 0U; xIdx < 256U; ++xIdx)
                    m_volumeRenderTextureData[offset + zIdx * 512U * 512U + yIdx * 512U + xIdx] = cubeIdx * (255U / 8U);
    }
    */

    size_t cubeIdx = 0U;
    std::vector<std::uint8_t> cubeSmall;
    while (r)
    {
        cubeSmall.resize(r.read_current(nullptr, 0));
        r.read_current(cubeSmall.data(), cubeSmall.size());
        r.move_next();

        size_t offset;
        switch (cubeIdx)
        {
            case 0U: offset = 0U; break;
            case 1U: offset = 256U; break;
            case 2U: offset = 512U * 512U * 256U; break;
            case 3U: offset = 512U * 512U * 256U + 256U; break;
            case 4U: offset = 512U * 256U; break;
            case 5U: offset = 512U * 256U + 256U; break;
            case 6U: offset = 512U * 512U * 256U + 512U * 256U; break;
            case 7U: offset = 512U * 512U * 256U + 256U + 512U * 256U; break;
        }

        size_t cubeSmallIdx = 0U;
        for (size_t zIdx = 0U; zIdx < 256U; ++zIdx)
            for (size_t yIdx = 0U; yIdx < 256U; ++yIdx)
                for (size_t xIdx = 0U; xIdx < 256U; ++xIdx)
                    m_volumeRenderTextureData[offset + zIdx * 512U * 512U + yIdx * 512U + xIdx] = cubeSmall[cubeSmallIdx++];

        ++cubeIdx;

        qDebug() << "Loaded a time step";
    }
}

// Assumes m_volumeRenderTextureData and m_datRawInfo have been initialized
void Visualization::opengl_updateTextureLoadDataRawFromFile()
{
    // Set texture parameters and upload 3D texture data
    glBindTexture(GL_TEXTURE_3D, m_volumeRenderingTextureLocation);

    // The texture stores densities, not colors. However, we still have to provide a border "color" for OpenGL.
    // Only the first ("red") of these four values will be read.
    std::array<GLfloat, 4U> const borderValue{0.0F, 0.0F, 0.0F, 0.0F};
    glTexParameterfv(GL_TEXTURE_3D, GL_TEXTURE_BORDER_COLOR, borderValue.data());
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_BORDER);

    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    GLenum textureDataType;
    switch (m_datRawInfo.format())
    {
    case datraw::scalar_type::uint8:  textureDataType = GL_UNSIGNED_BYTE;  break;
    case datraw::scalar_type::uint16: textureDataType = GL_UNSIGNED_SHORT; break;

    default:
        qWarning() << "3D texture data format not recognized";
        return;
    }

    glTexImage3D(GL_TEXTURE_3D,
                 0,
                 GL_RED,
                 512U,
                 512U,
                 512U,
                 /*
                 m_datRawInfo.resolution()[0],
                 m_datRawInfo.resolution()[1],
                 m_datRawInfo.resolution()[2],
                 */
                 0,
                 GL_RED,
                 textureDataType,
                 m_volumeRenderTextureData.data());
}


void Visualization::opengl_drawVolumeRendering()
{
    std::array<float, 2U> const iResolution{static_cast<float>(width()),
                                            static_cast<float>(height())};

    // If the visualization is *not* paused, then we use the current amount of elapsed time.
    // Otherwise, this step is skipped and we use the time stamp value that was last set.
    if (!m_volumeRenderingTimeIsPaused)
        m_volumeRenderingPauseTimestamp = static_cast<float>(m_elapsedTimer.elapsed()) / 1000.0F;

    switch (m_volumeRenderFragShader)
    {
    case VolumeRenderFragShader::VolumeRenderer:
        m_shaderProgramVolumeRendering.bind();
        glUniform2fv(m_uniformLocationVolumeRendering_iResolution, 1, iResolution.data());
        glUniform1f(m_uniformLocationVolumeRendering_iTime, m_volumeRenderingPauseTimestamp);

        glUniform1i(m_uniformLocationVolumeRenderingTexture, 0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_3D, m_volumeRenderingTextureLocation);
        break;

    case VolumeRenderFragShader::VolumetricLighting:
        m_shaderProgramVolumeRenderingLighting.bind();
        glUniform2fv(m_uniformLocationVolumeRendering_iResolutionLighting, 1, iResolution.data());
        glUniform1f(m_uniformLocationVolumeRendering_iTimeLighting, m_volumeRenderingPauseTimestamp);
        break;

    case VolumeRenderFragShader::VolumeRendererPreIntegration:
        m_shaderProgramVolumeRenderingPreIntegration.bind();
        glUniform2fv(m_uniformLocationVolumeRenderingPreIntegration_iResolution, 1, iResolution.data());
        glUniform1f(m_uniformLocationVolumeRenderingPreIntegration_iTime, m_volumeRenderingPauseTimestamp);

        glUniform1i(m_uniformLocationVolumeRenderingPreIntegrationTexture, 0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_3D, m_volumeRenderingTextureLocation);

        glUniform1i(m_uniformLocationVolumeRenderingPreIntegrationTextureLookupTable, 1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, m_volumeRenderingTextureLocationPreIntegrationLookupTable);
        break;

    case VolumeRenderFragShader::VolumeRendererOverlayRendering:
        m_shaderProgramVolumeRenderingOverlayRendering.bind();
        glUniform2fv(m_uniformLocationVolumeRenderingOverlayRendering_iResolution, 1, iResolution.data());
        glUniform1f(m_uniformLocationVolumeRenderingOverlayRendering_iTime, m_volumeRenderingPauseTimestamp);

        glUniform1i(m_uniformLocationVolumeRenderingOverlayRenderingTexture, 0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_3D, m_volumeRenderingTextureLocation);
        break;
    }

    glBindVertexArray(m_vaoVolumeRendering);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Visualization::opengl_rotateView()
{
    m_viewTransformationMatrix.setToIdentity();

    m_viewTransformationMatrix.translate(0.0F, 0.0F, -2.0F);

    m_viewTransformationMatrix.rotate(m_rotation.x(), 1.0F, 0.0F, 0.0F);
    m_viewTransformationMatrix.rotate(m_rotation.y(), 0.0F, 1.0F, 0.0F);
    m_viewTransformationMatrix.rotate(m_rotation.z(), 0.0F, 0.0F, 1.0F);

    m_normalTransformationMatrix = m_viewTransformationMatrix.normalMatrix();
}
