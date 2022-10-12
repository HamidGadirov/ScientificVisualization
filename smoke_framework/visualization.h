#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "color.h"
#include "datatype.h"
#include "datraw.h"
#include "glyph.h"
#include "isoline.h"
#include "movingaverage.h"
#include "simulation.h"
#include "lic.h"

#include <QElapsedTimer>
#include <QOpenGLWidget>
#include <QTimer>
#include <QOpenGLDebugLogger>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>

#include <array>
#include <deque>
#include <string>
#include <utility>

class Visualization : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
    Q_OBJECT

    friend class MainWindow;

    enum class ProjectionType
    {
        Orthographic,
        Perspective
    };

    enum class MappingType
    {
        Scaling,
        Clamping
    };

    enum class SlicingDirection
    {
        x,
        y,
        t
    };

    enum class VolumeRenderTexture
    {
        SyntheticCube,
        SyntheticScene,
        DataRaw
    };

    enum class VolumeRenderFragShader
    {
        VolumeRenderer,
        VolumetricLighting,
        VolumeRendererPreIntegration,
        VolumeRendererOverlayRendering
    };

    QTimer m_timer; // For triggering simulation updates and render events.
    QElapsedTimer m_elapsedTimer; // For measuring elapsed time.
    QOpenGLDebugLogger m_debugLogger;

    //--- VISUALIZATION PARAMETERS ---------------------------------------------------------------------
    bool m_isRunning = true;            // Toggles on/off the animation.
    bool m_sendMinMaxToUI = true;       // Show the min/max values of the scalar data and vector data.
    bool m_drawScalarData = true;       // Draw the smoke or not.
    bool m_drawVectorData = false;      // Draw the vector field or not.
    bool m_drawIsolines = false;        // Draw isolines or not.
    bool m_drawHeightplot = false;      // Draw height plot or not.
    bool m_drawLIC = false;             // Draw LIC or not.
    bool m_drawVolumeRendering = false; // Draw 3D volume rendering or not.

    bool m_volumeRenderingTimeIsPaused = false; // Pause 3D volume rendering
    float m_volumeRenderingPauseTimestamp = 0.0F;

    size_t m_DIM = 64U;             // Size of simulation grid. Must be even.

    float m_cellWidth;		        // Grid cell width
    float m_cellHeight;      		// Grid cell height

    Simulation m_simulation{m_DIM};

    ProjectionType m_projectionType = ProjectionType::Orthographic;

    // Scalar info
    ScalarDataType m_currentScalarDataType = ScalarDataType::Density;
    MappingType m_currentMappingType = MappingType::Clamping;
    float m_scalarDataScale = 0.1F;
    float m_clampMin = 0.0F;                                              // Minimum density we want to visualize.
    float m_clampMax = 1.0F;                                              // Maximum density we want to visualize.
//    float m_clampMax = static_cast<float>(m_simulation.rhoInjected());    // Maximum density we want to visualize.
    float m_transferK = 1.0F;                                             // The K in the transfer function: t(f) = f^K.

    // Custom color map. Only used for scalar data
    bool m_useCustomColorMap = false;
    std::array<Color, 3U> m_customColors{Color{1.0F, 0.0F, 0.0F}, Color{0.0F, 1.0F, 0.0F}, Color{0.0F, 0.0F, 1.0F}};

    // Vector info
    VectorDataType m_currentVectorDataType = VectorDataType::Velocity;
    float m_vectorDataMagnifier = 50.0F;

    // Glyph info
    Glyph::GlyphType m_currentGlyphType = Glyph::GlyphType::Arrow2D;    // Current glyph type in use.
    size_t m_glyphIndicesSize;											// Number of indices of current glyph type.
    size_t m_numberOfGlyphsX = 50U;                                     // Number of glyphs in x-direction.
    size_t m_numberOfGlyphsY = 50U;                                     // Number of glyphs in y-direction.
    float m_glyphCellWidth;
    float m_glyphCellHeight;
    float m_vec_scale = 1000.0F;    									// Glyph scaling factor.

    // Isolines info
    ScalarDataType m_currentIsolineDataType = ScalarDataType::Density;
    bool m_manuallyChooseIsolineDataType = false;
    size_t m_numberOfIsolines = 1U;
    Isoline::InterpolationMethod m_isolineInterpolationMethod = Isoline::InterpolationMethod::Linear;
    Isoline::AmbiguousCaseDecider m_isolineAmbiguousCaseDecider = Isoline::AmbiguousCaseDecider::Midpoint;
    float m_isolineMinValue = 0.5F;
    float m_isolineMaxValue = 0.5F;
    QVector3D m_isolineColor{1.0F, 1.0F, 1.0F};

    // Height plot info
    ScalarDataType m_currentHeightplotDataType = ScalarDataType::Density;
    QVector3D m_rotation{45.0F, 0.0F, 0.0F};

    // LIC info
    Lic m_licObject = Lic(256, 256);

    // Volume rendering info
    size_t m_volumeRenderingTimeStep = 0U;
    VolumeRenderTexture m_volumeRenderTexture = VolumeRenderTexture::SyntheticCube;
    VolumeRenderFragShader m_volumeRenderFragShader = VolumeRenderFragShader::VolumeRenderer;
    std::string m_datFilePath;
    datraw::raw_reader<char>::info_type m_datRawInfo;
    std::vector<std::uint8_t> m_volumeRenderTextureData;

    // Functions
    std::vector<float> velocityDivergence() const;
    std::vector<float> forceFieldDivergence() const;

    std::vector<QVector3D> computeNormals(std::vector<float> height) const;
    std::vector<QVector4D> computePreIntegrationLookupTable(size_t const DIM) const;

    void input_drag(int const mx, int my);

    // OpenGL related members
    GLuint m_vaoScalarData;
    GLuint m_vboScalarPoints;
    GLuint m_vboScalarData;
    GLuint m_eboScalarData;

    GLuint m_vaoGlyphs;
    GLuint m_vboGlyphs;
    GLuint m_eboGlyphs;
    GLuint m_vboModelTransformationMatricesGlyphs;
    GLuint m_vboValuesGlyphs;

    GLuint m_vaoIsolines;
    GLuint m_vboIsolines;
    GLuint m_isolinesTextureLocation;

    GLuint m_vaoHeightplot;
    GLuint m_vboHeightplotPoints;
    GLuint m_vboHeightplotScalarValues;
    GLuint m_vboHeightplotHeight;
    GLuint m_vboHeightplotNormals;
    GLuint m_eboHeightplot;

    GLuint m_vaoLic;
    GLuint m_vboLic;
    GLuint m_licTextureLocation;

    GLuint m_vaoVolumeRendering;
    GLuint m_vboVolumeRendering;
    GLuint m_eboVolumeRendering;
    GLuint m_volumeRenderingTextureLocation;
    GLuint m_volumeRenderingTextureLocationPreIntegrationLookupTable;

    QOpenGLShaderProgram m_shaderProgramScalarDataScaleTexture;
    QOpenGLShaderProgram m_shaderProgramScalarDataScaleCustomColorMap;
    QOpenGLShaderProgram m_shaderProgramScalarDataClampTexture;
    QOpenGLShaderProgram m_shaderProgramScalarDataClampCustomColorMap;
    QOpenGLShaderProgram m_shaderProgramVectorData;
    QOpenGLShaderProgram m_shaderProgramIsolines;
    QOpenGLShaderProgram m_shaderProgramHeightplotScale;
    QOpenGLShaderProgram m_shaderProgramHeightplotClamp;
    QOpenGLShaderProgram m_shaderProgramLic;
    QOpenGLShaderProgram m_shaderProgramVolumeRendering;
    QOpenGLShaderProgram m_shaderProgramVolumeRenderingLighting;
    QOpenGLShaderProgram m_shaderProgramVolumeRenderingPreIntegration;
    QOpenGLShaderProgram m_shaderProgramVolumeRenderingOverlayRendering;

    GLint m_uniformLocationScalarDataScaleTexture_rangeMin;
    GLint m_uniformLocationScalarDataScaleTexture_rangeMax;
    GLint m_uniformLocationScalarDataScaleTexture_transferK;
    GLint m_uniformLocationScalarDataScaleTexture_projection;
    GLint m_uniformLocationScalarDataScaleTexture_texture;

    GLint m_uniformLocationScalarDataScaleCustomColorMap_rangeMin;
    GLint m_uniformLocationScalarDataScaleCustomColorMap_rangeMax;
    GLint m_uniformLocationScalarDataScaleCustomColorMap_transferK;
    GLint m_uniformLocationScalarDataScaleCustomColorMap_projection;
    GLint m_uniformLocationScalarDataScaleCustomColorMap_colorMapColors;

    GLint m_uniformLocationScalarDataClampTexture_clampMin;
    GLint m_uniformLocationScalarDataClampTexture_clampMax;
    GLint m_uniformLocationScalarDataClampTexture_transferK;
    GLint m_uniformLocationScalarDataClampTexture_projection;
    GLint m_uniformLocationScalarDataClampTexture_texture;

    GLint m_uniformLocationScalarDataClampCustomColorMap_clampMin;
    GLint m_uniformLocationScalarDataClampCustomColorMap_clampMax;
    GLint m_uniformLocationScalarDataClampCustomColorMap_transferK;
    GLint m_uniformLocationScalarDataClampCustomColorMap_projection;
    GLint m_uniformLocationScalarDataClampCustomColorMap_colorMapColors;

    GLint m_uniformLocationProjectionColorMapInstanced;
    GLint m_uniformLocationTextureColorMapInstanced;

    GLint m_uniformLocationIsolines_projection;
    GLint m_uniformLocationIsolines_color;

    GLint m_uniformLocationHeightplotScale_rangeMin;
    GLint m_uniformLocationHeightplotScale_rangeMax;
    GLint m_uniformLocationHeightplotScale_transferK;
    GLint m_uniformLocationHeightplotScale_projection;
    GLint m_uniformLocationHeightplotScale_view;
    GLint m_uniformLocationHeightplotScale_normal;
    GLint m_uniformLocationHeightplotScale_material;
    GLint m_uniformLocationHeightplotScale_light;
    GLint m_uniformLocationHeightplotScale_texture;

    GLint m_uniformLocationHeightplotClamp_clampMin;
    GLint m_uniformLocationHeightplotClamp_clampMax;
    GLint m_uniformLocationHeightplotClamp_transferK;
    GLint m_uniformLocationHeightplotClamp_projection;
    GLint m_uniformLocationHeightplotClamp_view;
    GLint m_uniformLocationHeightplotClamp_normal;
    GLint m_uniformLocationHeightplotClamp_material;
    GLint m_uniformLocationHeightplotClamp_light;
    GLint m_uniformLocationHeightplotClamp_texture;

    GLint m_uniformLocationLic_projection;
    GLint m_uniformLocationLicTexture;

    GLint m_uniformLocationVolumeRendering_iTime;
    GLint m_uniformLocationVolumeRendering_iResolution;
    GLint m_uniformLocationVolumeRenderingTexture;

    GLint m_uniformLocationVolumeRendering_iTimeLighting;
    GLint m_uniformLocationVolumeRendering_iResolutionLighting;
//    GLint m_uniformLocationVolumeRenderingTextureLighting;

    GLint m_uniformLocationVolumeRenderingPreIntegration_iTime;
    GLint m_uniformLocationVolumeRenderingPreIntegration_iResolution;
    GLint m_uniformLocationVolumeRenderingPreIntegrationTexture;
    GLint m_uniformLocationVolumeRenderingPreIntegrationTextureLookupTable;

    GLint m_uniformLocationVolumeRenderingOverlayRendering_iTime;
    GLint m_uniformLocationVolumeRenderingOverlayRendering_iResolution;
    GLint m_uniformLocationVolumeRenderingOverlayRenderingTexture;

    GLuint m_scalarDataTextureLocation;
    GLuint m_vectorDataTextureLocation;

    QMatrix4x4 m_projectionTransformationMatrix;
    QMatrix4x4 m_viewTransformationMatrix;

    QMatrix3x3 m_normalTransformationMatrix;

    QVector4D m_materialConstants{0.5F, 0.5F, 1.0F, 5.0F};
    QVector3D m_lightPosition{300.0F, 300.0F, 200.0F};

    MovingAverage<QVector2D> m_minMaxDensity{60U, {0.0F, 0.0F}};

    void applyPreprocessing(std::vector<float> &scalarValues);

    // Quantization
    bool m_useQuantization = false;
    unsigned int m_quantizationBits = 2U;
    void applyQuantization(std::vector<float> &scalarValues) const;

    // Gaussian blur
    bool m_useGaussianBlur = false;
    void applyGaussianBlur(std::vector<float> &scalarValues) const;

    // Gradients
    bool m_useGradients = false;
    void applyGradients(std::vector<float> &scalarValues) const;

    std::vector<QVector3D> hsv2rgb(std::vector<QVector3D> c) const;

    // Slicing
    bool m_useSlicing = false;
    size_t const m_slicingWindowSize = m_DIM;
    SlicingDirection m_slicingDirection = SlicingDirection::x;
    size_t m_sliceIdx = 0U;
    std::deque<std::vector<float>> m_scalarValuesWindow{m_slicingWindowSize, std::vector<float>(m_DIM * m_DIM, 0.0F)};

    void applySlicing(std::vector<float> &scalarValues);


    // Indices used in OpenGL indexed rendering
    std::vector<unsigned short> m_indices;


    // OpenGL related functions
    void opengl_generateObjects();
    void opengl_createShaderPrograms();
    void opengl_deleteObjects();

    void opengl_createShaderProgramScalarDataScaleTexture();
    void opengl_createShaderProgramScalarDataScaleCustomColorMap();
    void opengl_createShaderProgramScalarDataClampTexture();
    void opengl_createShaderProgramScalarDataClampCustomColorMap();
    void opengl_createShaderProgramColorMapInstanced();
    void opengl_createShaderProgramIsolines();
    void opengl_createShaderProgramHeightplotScale();
    void opengl_createShaderProgramHeightplotClamp();
    void opengl_createShaderProgramLic();
    void opengl_createShaderProgramVolumeRendering();
    void opengl_createShaderProgramVolumeRenderingLighting();
    void opengl_createShaderProgramVolumeRenderingPreIntegration();
    void opengl_createShaderProgramVolumeRenderingOverlayRendering();

    void opengl_loadScalarDataTexture(std::vector<Color> const &colorMap);
    void opengl_loadVectorDataTexture(std::vector<Color> const &colorMap);
    void opengl_loadLicTexture(std::vector<uint8_t> const &licTexture);

    void opengl_setupAllBuffers();
    void opengl_setupScalarData();
    void opengl_updateScalarPoints();
    void drawScalarData();
    void opengl_drawScalarData(std::vector<float> const &scalarValues);

    void opengl_setupGlyphs();
    void opengl_bufferSingleGlyph();
    void opengl_setupGlyphsPerInstanceData();
    void drawGlyphs();

    void opengl_setupIsolines();
    void opengl_drawIsolines();

    void opengl_setupHeightplot();
    void opengl_drawHeightplot();
    void opengl_rotateView();

    void opengl_setupLic();
    void opengl_updateLicPoints();
    void opengl_drawLic();

    void opengl_setupVolumeRendering();
    void opengl_updateTexture();
    void opengl_updatePreIntegrationLookupTable();
    void opengl_updateTextureSyntheticCube();
    void opengl_updateTextureSyntheticScene();
    void opengl_updateTextureLoadDataRawFromFile();
    void opengl_loadDataRawFromFile();
    void opengl_drawVolumeRendering();

protected:
    void initializeGL();
    void resizeGL(int const newWidth, int const newHeight);
    void paintGL();

    void mouseMoveEvent(QMouseEvent *ev);

private slots:
    void onMessageLogged(QOpenGLDebugMessage const &Message) const;

public slots:
    void do_one_simulation_step();

public:
    Visualization(QWidget *parent = nullptr);
    ~Visualization();

    // Setters
    void setDIM(size_t const DIM);

    void setNumberOfGlyphsX(size_t const numberOfGlyphsX);
    void setNumberOfGlyphsY(size_t const numberOfGlyphsY);

    void setProjectionType(ProjectionType const &projectionType);
};

#endif // VISUALIZATION_H
