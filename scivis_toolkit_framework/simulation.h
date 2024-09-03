#ifndef SIMULATION_H
#define SIMULATION_H

#include "pocketfft_hdronly.h"

#include <vector>

class Simulation
{
    //--- SIMULATION PARAMETERS ------------------------------------------------------------------------
    size_t m_DIM;                 // Size of simulation grid.
    size_t m_numberOfSamples = m_DIM * m_DIM;
    long m_numberOfSamplesLong = static_cast<long>(m_numberOfSamples);

    float m_dt = 0.4F;                  // Simulation time step.
    float m_viscosity = 0.001F;         // Fluid viscosity.
    float m_rhoInjected = 10.0F;        // The amount of density which is injected.

    std::vector<float> m_vx, m_vy;      // (vx,vy)   = velocity field at the current moment.
    std::vector<float> m_vx0, m_vy0;    // (vx0,vy0) = velocity field at the previous moment.
    std::vector<float> m_fx, m_fy;      // (fx,fy)   = user-controlled simulation forces, steered with the mouse.
    std::vector<float> m_rho, m_rho0;   // Smoke density at the current (rho) and previous (rho0) moment.

    // pocketfft parameters
    pocketfft::shape_t m_shapeIn;
    pocketfft::stride_t m_strideIn;
    pocketfft::stride_t m_strideOut;
    pocketfft::shape_t m_axes;

    // Functions

    // Data management
    void initializeDimensions(size_t const DIM);
    void initializeDataStructures();
    void resetData();

    // Algorithm
    void solve();
    void diffuse_matter();
    void set_forces();

public:
    // Functions
    Simulation(size_t const DIM);
    Simulation(Simulation const&) = default;
    Simulation& operator=(Simulation const&) = default;
    Simulation(Simulation&&) = default;
    Simulation& operator=(Simulation&&) = default;
    ~Simulation() = default;

    void doOneSimulationStep();

    // Getters
    [[nodiscard]] std::vector<float> density() const;
    [[nodiscard]] std::vector<float> densityInterpolated(size_t const numberOfRows,
                                                         size_t const numberOfColumns) const;

    [[nodiscard]] std::vector<float> const &velocityX() const;
    [[nodiscard]] std::vector<float> const &velocityY() const;

    [[nodiscard]] std::vector<float> velocityXInterpolated(size_t const numberOfRows,
                                                           size_t const numberOfColumns) const;
    [[nodiscard]] std::vector<float> velocityYInterpolated(size_t const numberOfRows,
                                                           size_t const numberOfColumns) const;

    [[nodiscard]] std::vector<float> velocityMagnitude() const;
    [[nodiscard]] std::vector<float> velocityMagnitudeInterpolated(
        size_t const numberOfRows, size_t const numberOfColums) const;

    [[nodiscard]] std::vector<float> forceFieldXInterpolated(size_t const numberOfRows,
                                                             size_t const numberOfColumns) const;
    [[nodiscard]] std::vector<float> forceFieldYInterpolated(size_t const numberOfRows,
                                                             size_t const numberOfColumns) const;

    [[nodiscard]] std::vector<float> forceFieldMagnitude() const;
    [[nodiscard]] std::vector<float> forceFieldMagnitudeInterpolated(
        size_t const numberOfRows, size_t const numberOfColumns) const;

    [[nodiscard]] float dt() const;
    [[nodiscard]] float viscosity() const;
    [[nodiscard]] float rhoInjected() const;

    [[nodiscard]] float vx(size_t const idx) const;
    [[nodiscard]] float vy(size_t const idx) const;
    [[nodiscard]] float vx0(size_t const idx) const;
    [[nodiscard]] float vy0(size_t const idx) const;

    [[nodiscard]] float fx(size_t const idx) const;
    [[nodiscard]] float fy(size_t const idx) const;
    [[nodiscard]] float rho(size_t const idx) const;

    // Setters
    void setDIM(size_t const DIM);

    void setDt(float const dt);
    void setViscosity(float const viscosity);
    void setRhoInjected(float const rhoInjected);

    void setFx(size_t const idx, float const force);
    void setFy(size_t const idx, float const force);
    void setRho(size_t const idx, float const smokeDensity);
};

#endif // SIMULATION_H
