#include "visualization.h"

#include "constants.h"
#include "mainwindow.h"

#include <QDebug>
#include <QVector3D>

#include <algorithm>
#include <array>
#include <cmath>
#include <vector>

Visualization::Visualization(QWidget *parent) : QOpenGLWidget(parent)
{
    qDebug() << "Visualization constructor";

    // Start the simulation loop.
    m_timer.start(17); // Each frame takes 17ms, making the simulation run at approximately 60 FPS
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(do_one_simulation_step()));

    m_elapsedTimer.start();
}

Visualization::~Visualization()
{
    makeCurrent();

    qDebug() << "Visualization destructor";

    opengl_deleteObjects();
}

void Visualization::do_one_simulation_step()
{
    if (m_isRunning)
        m_simulation.do_one_simulation_step();

    update();
}

void Visualization::initializeGL() {
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

    glClearColor(0.2F, 0.1F, 0.2F, 1.0F);


    // Retrieve default textures.
    auto const mainWindowPtr = qobject_cast<MainWindow*>(parent()->parent());
    std::vector<Color> const defaultScalarDataColorMap = mainWindowPtr->m_defaultScalarDataColorMap;
    std::vector<Color> const defaultVectorDataColorMap = mainWindowPtr->m_defaultVectorDataColorMap;

    opengl_generateObjects();
    opengl_createShaderPrograms();

    opengl_setupAllBuffers();

    opengl_loadScalarDataTexture(defaultScalarDataColorMap);
    opengl_loadVectorDataTexture(defaultVectorDataColorMap);
    opengl_loadLicTexture(std::vector<uint8_t>()); // Initially provide an empty texture

    opengl_rotateView();
}

void Visualization::paintGL()
{
    glBindVertexArray(0U);

    // Clear the screen before rendering
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // The height plot, LIC and volume rendering must be drawn by themselves.
    // The scalar data, isolines and vector data drawing can be combined.
    if (m_drawHeightplot)
    {
        opengl_drawHeightplot();
        return;
    }

    if (m_drawLIC)
    {
        opengl_drawLic();
        return;
    }

    if (m_drawVolumeRendering)
    {
        opengl_drawVolumeRendering();
        return;
    }

    if (m_drawScalarData)
        drawScalarData();

    if (m_drawIsolines)
    {
        m_shaderProgramIsolines.bind();
        glUniformMatrix4fv(m_uniformLocationIsolines_projection, 1, GL_FALSE, m_projectionTransformationMatrix.data());
        glUniform3fv(m_uniformLocationIsolines_color, 1, &m_isolineColor[0]);
        opengl_drawIsolines();
    }

    if (m_drawVectorData)
    {
        m_shaderProgramVectorData.bind();
        glUniformMatrix4fv(m_uniformLocationProjectionColorMapInstanced, 1, GL_FALSE, m_projectionTransformationMatrix.data());
        glUniform1i(m_uniformLocationTextureColorMapInstanced, 0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_1D, m_vectorDataTextureLocation);
        drawGlyphs();
    }
}

void Visualization::resizeGL(int const width, int const height)
{
    m_cellWidth  = static_cast<float>(width) / static_cast<float>(m_DIM + 1U);
    m_cellHeight = static_cast<float>(height) / static_cast<float>(m_DIM + 1U);

    m_projectionTransformationMatrix.setToIdentity();

    switch (m_projectionType)
    {
        case ProjectionType::Orthographic:
            m_projectionTransformationMatrix.ortho(0.0F, width,
                                                   0.0F, height,
                                                   -50.0F, 50.0F);
        break;

        case ProjectionType::Perspective:
            m_projectionTransformationMatrix.perspective(30.0F, 1.0F, 0.2F, 1300.0F);
            m_projectionTransformationMatrix.lookAt({300.0F, 300.0F, 1200.0F}, {300.0F, 300.0F, 0.0F}, {0.0F, 1.0F, 0.0F});
        break;
    }

    m_glyphCellWidth = static_cast<float>(width) / static_cast<float>(m_numberOfGlyphsX + 1U);
    m_glyphCellHeight = static_cast<float>(height) / static_cast<float>(m_numberOfGlyphsY + 1U);

    opengl_updateScalarPoints();
    opengl_updateLicPoints();
}

void Visualization::drawGlyphs()
{
    std::vector<float> vectorMagnitude;
    std::vector<float> vectorDirectionX;
    std::vector<float> vectorDirectionY;
    switch (m_currentVectorDataType)
    {
        case VectorDataType::Velocity:
            vectorMagnitude = m_simulation.velocityMagnitudeInterpolated(m_numberOfGlyphsX, m_numberOfGlyphsY);
            vectorDirectionX = m_simulation.velocityXInterpolated(m_numberOfGlyphsX, m_numberOfGlyphsY);
            vectorDirectionY = m_simulation.velocityYInterpolated(m_numberOfGlyphsX, m_numberOfGlyphsY);
        break;

        case VectorDataType::ForceField:
            vectorMagnitude = m_simulation.forceFieldMagnitudeInterpolated(m_numberOfGlyphsX, m_numberOfGlyphsY);
            vectorDirectionX = m_simulation.forceFieldXInterpolated(m_numberOfGlyphsX, m_numberOfGlyphsY);
            vectorDirectionY = m_simulation.forceFieldYInterpolated(m_numberOfGlyphsX, m_numberOfGlyphsY);
        break;
    }

    // Scale the magnitudes to where these become visible.
    std::transform(vectorMagnitude.begin(), vectorMagnitude.end(), vectorMagnitude.begin(),
                   std::bind(std::multiplies<>(), std::placeholders::_1, m_vectorDataMagnifier));

    if (m_sendMinMaxToUI && !vectorMagnitude.empty())
    {
        auto const currentMinMaxIt = std::minmax_element(vectorMagnitude.cbegin(), vectorMagnitude.cend());
        QVector2D const currentMinMax{*currentMinMaxIt.first, *currentMinMaxIt.second};

        // Send values to GUI.
        auto const mainWindowPtr = qobject_cast<MainWindow*>(parent()->parent());
        Q_ASSERT(mainWindowPtr != nullptr);
        mainWindowPtr->setVectorDataMin(currentMinMax.x());
        mainWindowPtr->setVectorDataMax(currentMinMax.y());
    }

    size_t const numberOfInstances = m_numberOfGlyphsX * m_numberOfGlyphsY;

    // Create model transformation matrices
    std::vector<float> modelTransformationMatrices;
    /* Fill the container modelTransformationMatrices here...
     * Use the following variables:
     * modelTransformationMatrix: This vector should contain the result.
     * m_DIM: The grid dimensions of the simulation.
     * m_cellWidth, m_cellHeight: A cell, made up of 4 simulation grid points, has the size m_cellWidth * m_cellHeight for the visualization.
     * m_numberOfGlyphsX (horizontal)
     * m_numberOfGlyphsY (vertical)
     * m_glyphCellWidth, m_glyphCellHeight: Use these as a small offset from the border of the OpenGL window.
     *                                      Having this little border around the visualization prevents a left-pointing arrow
     *                                      on the left side of the window to become invisible and thus convey no information.
     * vectorDirectionX, vectorDirectionY: To which direction the glyph should point. Row-major, size given by the m_numberOfGlyphs*.
     * vectorMagnitude: Use this value to scale the glyphs. I.e. higher values are visualized using larger glyphs. Row-major, size given by the m_numberOfGlyphs*.
     */
    modelTransformationMatrices = std::vector<float>(numberOfInstances * 16U, 0.0F); // Remove this placeholder initialization


    glBindVertexArray(0);

    // Buffering section starts here.
    glBindVertexArray(m_vaoGlyphs);

    glBindBuffer(GL_ARRAY_BUFFER, m_vboValuesGlyphs);
    glBufferSubData(GL_ARRAY_BUFFER,
                    0,
                    static_cast<GLsizeiptr>(vectorMagnitude.size() * sizeof(float)),
                    vectorMagnitude.data());

    // Buffer model transformation matrices.
    glBindBuffer(GL_ARRAY_BUFFER, m_vboModelTransformationMatricesGlyphs);
    void * const dataPtr = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
    memcpy(dataPtr, modelTransformationMatrices.data(), modelTransformationMatrices.size() * sizeof(float));
    glUnmapBuffer(GL_ARRAY_BUFFER);

    if (m_currentGlyphType == Glyph::GlyphType::Hedgehog)
        glDrawElementsInstanced(GL_LINES,
                                static_cast<GLsizei>(m_glyphIndicesSize),
                                GL_UNSIGNED_SHORT,
                                reinterpret_cast<GLvoid*>(0),
                                static_cast<GLsizei>(numberOfInstances));
    else
        glDrawElementsInstanced(GL_TRIANGLE_STRIP,
                                static_cast<GLsizei>(m_glyphIndicesSize),
                                GL_UNSIGNED_SHORT,
                                reinterpret_cast<GLvoid*>(0),
                                static_cast<GLsizei>(numberOfInstances));
}


void Visualization::applyQuantization(std::vector<float> &scalarValues) const
{
    // Convert the floating point values to (8 bit) unsigned integers,
    // so that the data can be treated as an image.
    // The image's pixel values are in the range [0, 255].
    float const maxValue = *std::max_element(scalarValues.cbegin(), scalarValues.cend());
    std::vector<unsigned int> image;
    image.reserve(scalarValues.size());
    for (auto const x : scalarValues)
        image.push_back(static_cast<unsigned int>(std::lroundf(x / maxValue * 255.0F)));


    // Apply quantization to std::vector<unsigned int> image here.
    // The variable m_quantizationBits ('n' in the lecture slides) is set in the GUI and can be used here.
    // L needs to be set to the appropriate value and will be used to set the clamping range in the GUI.

    unsigned int const L = 1U; // placeholder value
    qDebug() << "Quantization not implemented";

    // Convert the image's data back to floating point values, so that it can be processed as usual.
    scalarValues = std::vector<float>{image.cbegin(), image.cend()};

    // Force the clamping range in the GUI to be [0, L].
    auto const mainWindowPtr = qobject_cast<MainWindow*>(parent()->parent());
    Q_ASSERT(mainWindowPtr != nullptr);
    mainWindowPtr->on_scalarDataMappingClampingMaxSlider_valueChanged(0);
    mainWindowPtr->on_scalarDataMappingClampingMaxSlider_valueChanged(100 * static_cast<int>(L));
}

void Visualization::applyGaussianBlur(std::vector<float> &scalarValues) const
{
    // Implement Gaussian blur here, applied on the values of the scalarValues container.
    // First, define a 3x3 matrix for the kernel.
    // (Use a C-style 2D array, a std::array of std::array's, or a std::vector of std::vectors)

    qDebug() << "Gaussian blur not implemented";
}

void Visualization::applyGradients(std::vector<float> &scalarValues) const
{
    // Implement Gradient extraction here, applied on the values of the scalarValues container.
    // First, define a 3x3 Sobel kernels (for x and y directions).
    // (Use a C-style 2D array, a std::array of std::array's, or a std::vector of std::vectors)
    // Convolve the values of the scalarValues container with the Sobel kernels
    // Calculate the Gradient magnitude
    // Calculate the Gradient direction
    // Visualize the Gradient magnitude

    qDebug() << "applyGradients not implemented";
}

/* This function receives a *reference* to a std::vector<float>,
 * which acts as a pointer. Modifying scalarValues here will result
 * in the scalarValues passed to this function to be modified.
 * You may also define a new "std::vector<float> v" here, fill it with
 * new values and assign it to scalarValues to replace it,
 * e.g. "scalarValues = v;".
 *
 * m_sliceIdx contains the value set in the GUI.
 * m_DIM contains the current dimensions of the square (m_DIM * m_DIM).
 * m_slicingWindowSize contains the size of the window (here, also m_DIM).
 * m_slicingDirection contains the slicing direction set in the GUI and
 *    is already handled in a switch statement.
 */
void Visualization::applySlicing(std::vector<float> &scalarValues)
{
    qDebug() << "Slicing not implemented";
    // Add code here and below to complete the implementation

    switch (m_slicingDirection)
    {
    case SlicingDirection::x:
        // xIdx is constant
        qDebug() << "Slicing in x not implemented";
        break;

    case SlicingDirection::y:
        // yIdx is constant
        qDebug() << "Slicing in y not implemented";
        break;

    case SlicingDirection::t:
        // t is constant
        qDebug() << "Slicing in t not implemented";
        break;
    }
}

void Visualization::applyPreprocessing(std::vector<float> &scalarValues)
{
    if (m_useQuantization)
        applyQuantization(scalarValues);

    if (m_useGaussianBlur)
        applyGaussianBlur(scalarValues);

    if (m_useGradients)
        applyGradients(scalarValues);

    if (m_useSlicing)
        applySlicing(scalarValues);
}

void Visualization::drawScalarData()
{
    std::vector<float> scalarValues;

    switch (m_currentScalarDataType)
    {
        case ScalarDataType::Density:
            scalarValues = m_simulation.density();
        break;

        case ScalarDataType::ForceFieldMagnitude:
            scalarValues = m_simulation.forceFieldMagnitude();
        break;

        case ScalarDataType::VelocityMagnitude:
            scalarValues = m_simulation.velocityMagnitude();
        break;

        case ScalarDataType::VelocityDivergence:
            scalarValues = velocityDivergence();
        break;

        case ScalarDataType::ForceFieldDivergence:
            scalarValues = forceFieldDivergence();
        break;
    }

    applyPreprocessing(scalarValues);
    opengl_drawScalarData(scalarValues);
}

std::vector<float> Visualization::velocityDivergence() const
{
    std::vector<float> velocityDivergence;
    velocityDivergence.resize(m_DIM * m_DIM);

    auto const backwardFiniteDifference = [&](size_t const idx, size_t const previousX_idx, size_t const previousY_idx)
    {
        return (m_simulation.vx(idx) - m_simulation.vx(previousX_idx)) / m_cellWidth +
               (m_simulation.vy(idx) - m_simulation.vy(previousY_idx)) / m_cellHeight;
    };

    velocityDivergence.at(0) = backwardFiniteDifference(0, m_DIM - 1, (m_DIM - 1) * m_DIM);
    for (size_t idx = 1; idx < m_DIM; ++idx)
        velocityDivergence.at(idx) = backwardFiniteDifference(idx, idx - 1, idx + (m_DIM - 1) * m_DIM);

    for (size_t idx = m_DIM; idx < (m_DIM - 1) * m_DIM; ++idx)
    {
        if (idx % m_DIM == 0)
            velocityDivergence.at(idx) = backwardFiniteDifference(idx, idx + m_DIM - 1, idx - m_DIM);
        else
            velocityDivergence.at(idx) = backwardFiniteDifference(idx, idx - 1, idx - m_DIM);
    }

    velocityDivergence.at((m_DIM - 1) * m_DIM) = backwardFiniteDifference((m_DIM - 1) * m_DIM, m_DIM * m_DIM - 1, 0);
    for (size_t idx = (m_DIM - 1) * m_DIM + 1; idx < m_DIM * m_DIM; ++idx)
        velocityDivergence.at(idx) = backwardFiniteDifference(idx, idx - 1, idx - (m_DIM - 1) * m_DIM);

    return velocityDivergence;
}

std::vector<float> Visualization::forceFieldDivergence() const
{
    std::vector<float> forceFieldDivergence;
    forceFieldDivergence.resize(m_DIM * m_DIM);

    auto const backwardFiniteDifference = [&](size_t const idx, size_t const previousX_idx, size_t const previousY_idx)
    {
        return (m_simulation.fx(idx) - m_simulation.fx(previousX_idx)) / m_cellWidth +
               (m_simulation.fy(idx) - m_simulation.fy(previousY_idx)) / m_cellHeight;
    };

    forceFieldDivergence.at(0) = backwardFiniteDifference(0, m_DIM - 1, (m_DIM - 1) * m_DIM);
    for (size_t idx = 1; idx < m_DIM; ++idx)
        forceFieldDivergence.at(idx) = backwardFiniteDifference(idx, idx - 1, idx + (m_DIM - 1) * m_DIM);

    for (size_t idx = m_DIM; idx < (m_DIM - 1) * m_DIM; ++idx)
    {
        if (idx % m_DIM == 0)
            forceFieldDivergence.at(idx) = backwardFiniteDifference(idx, idx + m_DIM - 1, idx - m_DIM);
        else
            forceFieldDivergence.at(idx) = backwardFiniteDifference(idx, idx - 1, idx - m_DIM);
    }

    forceFieldDivergence.at((m_DIM - 1) * m_DIM) = backwardFiniteDifference((m_DIM - 1) * m_DIM, m_DIM * m_DIM - 1, 0);
    for (size_t idx = (m_DIM - 1) * m_DIM + 1; idx < m_DIM * m_DIM; ++idx)
        forceFieldDivergence.at(idx) = backwardFiniteDifference(idx, idx - 1, idx - (m_DIM - 1) * m_DIM);

    return forceFieldDivergence;
}

std::vector<QVector3D> Visualization::computeNormals(std::vector<float> heights) const
{
    return std::vector<QVector3D>(heights.size(), QVector3D(0,0,1));
}

void Visualization::onMessageLogged(QOpenGLDebugMessage const &Message) const
{
    qDebug() << "Log from Visualization:" << Message;
}

// Setters
void Visualization::setDIM(size_t const DIM)
{
    // Stop the simulation, do all resizing, then continue.
    m_timer.stop();

    m_DIM = DIM;
    m_numberOfGlyphsX = m_DIM;
    m_numberOfGlyphsY = m_DIM;
    opengl_setupAllBuffers();
    resizeGL(width(), height());
    m_simulation.setDIM(m_DIM);
    m_timer.start();
}

void Visualization::setNumberOfGlyphsX(size_t const numberOfGlyphsX)
{
    m_numberOfGlyphsX = numberOfGlyphsX;
    opengl_setupGlyphsPerInstanceData();
}

void Visualization::setNumberOfGlyphsY(size_t const numberOfGlyphsY)
{
    m_numberOfGlyphsY = numberOfGlyphsY;
    opengl_setupGlyphsPerInstanceData();
}

void Visualization::setProjectionType(ProjectionType const &projectionType)
{
    m_projectionType = projectionType;
    resizeGL(width(), height());
}
