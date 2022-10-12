#include "simulation.h"

#include "interpolation.h"

#include <QDebug>

#include <cmath>

#include <fstream> // load data

//init_simulation: Initialize simulation data structures as a function of the grid size 'n'. (This used to be init_simulation.)
//                 Although the simulation takes place on a 2D grid, we allocate all data structures as 1D arrays.
Simulation::Simulation(size_t const DIM)
    :
      m_DIM(DIM)
{
    initializeDataStructures();
}

void Simulation::initializeDimensions(size_t const DIM)
{
    m_DIM = DIM;
    m_numberOfSamples = m_DIM * m_DIM;
    m_numberOfSamplesLong = static_cast<long>(m_numberOfSamples);
}

void Simulation::initializeDataStructures()
{
    m_fx.resize(m_numberOfSamples, 0.0F);
    m_fy.resize(m_numberOfSamples, 0.0F);
    m_rho.resize(m_numberOfSamples, 0.0F);
    m_rho0.resize(m_numberOfSamples, 0.0F);

    m_vx.resize(m_numberOfSamples, 0.0F);
    m_vy.resize(m_numberOfSamples, 0.0F);
    m_vx0.resize(m_numberOfSamples, 0.0F);
    m_vy0.resize(m_numberOfSamples, 0.0F);

    // Set pocketfft parameters
    shape_in = {m_DIM, m_DIM};
    stride_in = {static_cast<long>(m_DIM * sizeof(float)), sizeof(float)};
    stride_out = {static_cast<long>((m_DIM + 2U) * sizeof(float)), sizeof(std::complex<float>)};
    axes = {0U, 1U};
}

void Simulation::resetData()
{
    std::fill(m_fx.begin(), m_fx.end(), 0.0F);
    std::fill(m_fy.begin(), m_fy.end(), 0.0F);
    std::fill(m_rho.begin(), m_rho.end(), 0.0F);
    std::fill(m_rho0.begin(), m_rho0.end(), 0.0F);

    std::fill(m_vx.begin(), m_vx.end(), 0.0F);
    std::fill(m_vy.begin(), m_vy.end(), 0.0F);
    std::fill(m_vx0.begin(), m_vx0.end(), 0.0F);
    std::fill(m_vy0.begin(), m_vy0.end(), 0.0F);
}

void Simulation::solve()
{
    // n is an integer alias for m_DIM.
    int const n = static_cast<int>(m_DIM);

    auto const applyTimeStep = [=](float const v, float const v0) { return v + m_dt * v0; };
    std::transform(m_vx.cbegin(), m_vx.cend(), m_vx0.cbegin(), m_vx.begin(), applyTimeStep);
    std::transform(m_vy.cbegin(), m_vy.cend(), m_vy0.cbegin(), m_vy.begin(), applyTimeStep);

    // Copy the current velocity field to the previous velocity field
    m_vx0 = m_vx;
    m_vy0 = m_vy;

    {
        // Pointer aliases for simpler C-style access
        float * const vx  = m_vx.data();
        float * const vy  = m_vy.data();
        float * const vx0 = m_vx0.data();
        float * const vy0 = m_vy0.data();

        for (int i = 0; i < n; ++i)
        {
            float const x = (0.5F / n) + i * (1.0F / n);
            for (int j = 0; j < n; ++j)
            {
                float const y = (0.5F / n) + j * (1.0F / n);

                float const x0 = n * (x - m_dt * vx0[i + n * j]) - 0.5F;
                float const y0 = n * (y - m_dt * vy0[i + n * j]) - 0.5F;

                auto i0 = static_cast<int>(std::floor(x0));
                float const s = x0 - i0;
                i0 = (n + (i0 % n)) % n;
                int const i1 = (i0 + 1) % n;

                int j0 = static_cast<int>(std::floor(y0));
                float const t = y0 - j0;
                j0 = (n + (j0 % n)) % n;
                int const j1 = (j0 + 1) % n;

                vx[i + n * j] = (1 - s) * ((1 - t) * vx0[i0 + n * j0]
                              + t * vx0[i0 + n * j1])
                              + s * ((1 - t) * vx0[i1 + n * j0]
                              + t * vx0[i1 + n * j1]);

                vy[i + n * j] = (1 - s) * ((1 - t) * vy0[i0 + n * j0]
                              + t * vy0[i0 + n * j1])
                              + s * ((1 - t) * vy0[i1 + n * j0]
                              + t * vy0[i1 + n * j1]);
            }
        }
    }

    // Copy the current velocity field to the previous velocity field
    m_vx0 = m_vx;
    m_vy0 = m_vy;

    std::vector<std::complex<float>> vx0_fft(m_DIM * (m_DIM / 2U + 1U));
    std::vector<std::complex<float>> vy0_fft(m_DIM * (m_DIM / 2U + 1U));

    pocketfft::r2c(shape_in, stride_in, stride_out, axes, true, m_vx0.data(), vx0_fft.data(), 1.0F);
    pocketfft::r2c(shape_in, stride_in, stride_out, axes, true, m_vy0.data(), vy0_fft.data(), 1.0F);

    for (size_t j = 0U; j < m_DIM; ++j)
    {
        size_t const m = (m_DIM / 2U) + 1U; // Number of columns in the FFT matrix
        for (size_t i = 0U; i < m; ++i)
        {
            auto const x = static_cast<float>(i);
            float const y = j <= (m_DIM / 2U) ? static_cast<float>(j) : static_cast<float>(j) - m_DIM;
            float const r = std::pow(x, 2.0F) + std::pow(y, 2.0F);
            if (r == 0.0F)
                continue;

            size_t const idx = i + (m * j);

            std::complex<float> const U{vx0_fft[idx]};
            std::complex<float> const V{vy0_fft[idx]};

            float const filterFactor = std::exp(-r * m_dt * m_viscosity);
            vx0_fft[idx].real(filterFactor * ((1.0F - x * x / r) * U.real() - x * y / r * V.real()));
            vx0_fft[idx].imag(filterFactor * ((1.0F - x * x / r) * U.imag() - x * y / r * V.imag()));

            vy0_fft[idx].real(filterFactor * (-y * x / r * U.real() + (1.0F - y * y / r) * V.real()));
            vy0_fft[idx].imag(filterFactor * (-y * x / r * U.imag() + (1.0F - y * y / r) * V.imag()));
        }
    }

    float const normalizationFactor = 1.0F / (m_DIM * m_DIM);
    // Note: stride_in and stride_out are now reversed
    pocketfft::c2r(shape_in, stride_out, stride_in, axes, false, vx0_fft.data(), m_vx.data(), normalizationFactor);
    pocketfft::c2r(shape_in, stride_out, stride_in, axes, false, vy0_fft.data(), m_vy.data(), normalizationFactor);
}

// diffuse_matter: This function diffuses matter that has been placed in the velocity field. It's almost identical to the
// velocity diffusion step in the function above. The input matter densities are in m_rho0 and the result is written into m_rho.
void Simulation::diffuse_matter()
{
    // n is an integer alias for m_DIM.
    int const n = static_cast<int>(m_DIM);

    // Use the underlying pointer to access the elements using integers/longs instead of size_t and casts.
    float * const vx  = m_vx.data();
    float * const vy  = m_vy.data();
    float * const rho = m_rho.data();
    float * const rho0 = m_rho0.data();

    float x, y, x0, y0, s, t;
    int i, j, i0, j0, i1, j1;

    for (j = 0, y = 0.5F / n; j < n; ++j, y += 1.0F / n)
    {
        for (i = 0, x = 0.5F / n; i < n ; ++i, x += 1.0F / n)
        {
            x0 = n * (x - m_dt * vx[i + n * j]) - 0.5F;
            y0 = n * (y - m_dt * vy[i + n * j]) - 0.5F;
            i0 = static_cast<int>(std::floor(x0));
            s = x0 - i0;
            i0 = (n + (i0 % n)) % n;
            i1 = (i0 + 1) % n;
            j0 = static_cast<int>(std::floor(y0));
            t = y0 - j0;
            j0 = (n + (j0 % n)) % n;
            j1 = (j0 + 1) % n;
            rho[i + n * j] = (1 - s) * ((1 - t) * rho0[i0 + n * j0]
                                    + t * rho0[i0 + n * j1])
                                    + s * ((1 - t) * rho0[i1 + n * j0]
                                    + t * rho0[i1 + n * j1]);
        }
    }
}

//set_forces: copy user-controlled forces to the force vectors that are sent to the solver.
//            Also dampen forces and matter density to get a stable simulation.
void Simulation::set_forces()
{
    // Reduce density and copy to current density.
    std::transform(m_rho.cbegin(), m_rho.cend(), m_rho0.begin(),
                   std::bind(std::multiplies<>(), std::placeholders::_1, 0.995F));

    // Reduce force.
    std::transform(m_fx.begin(), m_fx.end(), m_fx.begin(),
                   std::bind(std::multiplies<>(), std::placeholders::_1, 0.85F));
    std::transform(m_fy.begin(), m_fy.end(), m_fy.begin(),
                   std::bind(std::multiplies<>(), std::placeholders::_1, 0.85F));

    // Copy forces to velocities.
    std::copy(m_fx.cbegin(), m_fx.cend(), m_vx0.begin());
    std::copy(m_fy.cbegin(), m_fy.cend(), m_vy0.begin());
}

//do_one_simulation_step: Do one complete cycle of the simulation:
//      - set_forces:
//      - solve:            read forces from the user
//      - diffuse_matter:   compute a new set of velocities
//      - gluPostRedisplay: draw a new visualization frame

void Simulation::do_one_simulation_step()
{
    set_forces();
    solve();
    diffuse_matter();
}


// Getters
std::vector<float> Simulation::density() const
{
    return m_rho;
}

std::vector<float> Simulation::densityInterpolated(size_t const numberOfRows, size_t const numberOfColumns) const
{
    return interpolation::interpolateSquareVector(m_rho, m_DIM, numberOfRows, numberOfColumns);
}

std::vector<float> Simulation::velocityXInterpolated(size_t const numberOfRows, size_t const numberOfColumns) const
{
    return interpolation::interpolateSquareVector(m_vx, m_DIM, numberOfRows, numberOfColumns);
}

std::vector<float> Simulation::velocityYInterpolated(size_t const numberOfRows, size_t const numberOfColumns) const
{
    return interpolation::interpolateSquareVector(m_vy, m_DIM, numberOfRows, numberOfColumns);
}

std::vector<float> Simulation::velocityMagnitudeInterpolated(size_t const numberOfRows, size_t const numberOfColums) const
{
    return interpolation::interpolateSquareVector(velocityMagnitude(), m_DIM, numberOfRows, numberOfColums);
}

std::vector<float> Simulation::forceFieldXInterpolated(size_t const numberOfRows, size_t const numberOfColumns) const
{
    return interpolation::interpolateSquareVector(m_fx, m_DIM, numberOfRows, numberOfColumns);
}

std::vector<float> Simulation::forceFieldYInterpolated(size_t const numberOfRows, size_t const numberOfColumns) const
{
    return interpolation::interpolateSquareVector(m_fy, m_DIM, numberOfRows, numberOfColumns);
}

std::vector<float> Simulation::forceFieldMagnitudeInterpolated(size_t const numberOfRows, size_t const numberOfColumns) const
{
    return interpolation::interpolateSquareVector(forceFieldMagnitude(), m_DIM, numberOfRows, numberOfColumns);
}

// Note that the dimensions of m_vx and m_vy are larger than what is returned.
// This is because the internal algorithm needs one more row and column.
std::vector<float> Simulation::velocityMagnitude() const
{
    auto const length = [](auto const vx, auto const vy) { return std::sqrt(std::pow(vx, 2.0F) + std::pow(vy, 2.0F)); };

    std::vector<float> velocityMagnitude;
    std::transform(m_vx.cbegin(), m_vx.cbegin() + m_numberOfSamplesLong, m_vy.cbegin(), std::back_inserter(velocityMagnitude),
                   length);

    return velocityMagnitude;
}

std::vector<float> Simulation::forceFieldMagnitude() const
{
    auto const length = [](auto const fx, auto const fy) { return std::sqrt(std::pow(fx, 2.0F) + std::pow(fy, 2.0F)); };

    std::vector<float> forceFieldMagnitude;
    std::transform(m_fx.cbegin(), m_fx.cend(), m_fy.cbegin(), std::back_inserter(forceFieldMagnitude),
                   length);

   return forceFieldMagnitude;
}

float Simulation::dt() const
{
    return m_dt;
}

float Simulation::viscosity() const
{
    return m_viscosity;
}

float Simulation::rhoInjected() const
{
    return m_rhoInjected;
}

float Simulation::vx(size_t const idx) const
{
    return m_vx[idx];
}

float Simulation::vy(size_t const idx) const
{
    return m_vy[idx];
}

float Simulation::vx0(size_t const idx) const
{
    return m_vx0[idx];
}

float Simulation::vy0(size_t const idx) const
{
    return m_vy0[idx];
}

float Simulation::fx(size_t const idx) const
{
    return m_fx[idx];
}

float Simulation::fy(size_t const idx) const
{
    return m_fy[idx];
}

float Simulation::rho(size_t const idx) const
{
    return m_rho[idx];
}

// Setters
void Simulation::setDIM(size_t const DIM)
{
    initializeDimensions(DIM);
    initializeDataStructures();
    resetData();
}

void Simulation::setDt(float const dt)
{
    m_dt = dt;
}

void Simulation::setViscosity(float const viscosity)
{
    m_viscosity = viscosity;
}

void Simulation::setRhoInjected(float const rhoInjected)
{
    m_rhoInjected = rhoInjected;
}

void Simulation::setFx(size_t const idx, float const force)
{
    m_fx[idx] = force;
}

void Simulation::setFy(size_t const idx, float const force)
{
    m_fy[idx] = force;
}

void Simulation::setRho(size_t const idx, float const smokeDensity)
{
    m_rho[idx] = smokeDensity;
}
