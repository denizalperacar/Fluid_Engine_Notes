#ifndef WAVE_H
#define WAVE_H

#include <cmath>
#include <vector>
#include <array>

namespace wave {
  class Wave1D {
  public:

    void update(const double& dt, std::vector<double>& bounds);
    bool checkBoundary(const double& boundary, const double tolerance = 1e-8);
    template<int kBufferSize>
    friend void accumulateWave(
      std::array<double, kBufferSize> &heightField, 
      Wave1D &wave, double x_min, double x_max,
      int kBufferSize=kBufferSize
    );

    Wave1D() = delete;
    Wave1D(
        double x, double dx, 
        double waveLength, double amplitude
    ) : x_(x), dx_(dx), waveLength_(waveLength), amplitude_(amplitude) {}

  private:
    double x_;
    double dx_;
    double waveLength_;
    double amplitude_;
    void _update(const double& dt);
    void _updateBoundary(const bool& atBoundary, const double& dt);
  };
}

#endif