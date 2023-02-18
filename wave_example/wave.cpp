#include "wave.h"


namespace wave {

    template<int kBufferSize>
    void accumulateWave(
        std::array<double, kBufferSize> &heightField, 
        Wave1D &wave, double x_min, double x_max,
        int kBufferSize=kBufferSize
        ) {
      const double quarterWaveLength = 0.25 * wave.waveLength_;
      double length = x_max - x_min;
      
      const int start = static_cast<int>(
        (wave.x_ - quarterWaveLength + x_min) * kBufferSize / length
      );

      const int end = static_cast<int>(
        (wave.x_ + quarterWaveLength + x_min) * kBufferSize / length
      );

      for (int i = start; i < end; ++ i) {
        int ind = i;
        if (i < 0) { 
          ind = -(i + 1); 
        } else if (i >= static_cast<int>(kBufferSize)) {
          ind = 2 * kBufferSize - i - 1;
        }

        double distance = std::fabs((i + 0.5) / kBufferSize - x);
        double height = (
          wave.amplitude_ * 0.5 * (
            std::cos( 
              std::min(distance * std::M_PI / quarterWaveLength, std::M_PI) 
            ) + 1.0 
        ));
        heightField[ind] += height;
      }
    }

  // updates the Wave for one frame
  void Wave1D::update(const double& dt, std::vector<double>& bounds) {
    this->_update(dt);
    for (auto& bound : bounds) {
      this->_updateBoundary(checkBoundary(bound), dt);
    }
  }

  // checks if the wave is at the boundary
  bool Wave1D::checkBoundary(
      const double& boundary, 
      const double tolerance = 1e-8
      ) {
    return std::abs(x_ - boundary) < tolerance;
  }

  // moves the wave
  void Wave1D::_update(const double& dt) {
    x_ += dx_ * dt;
  }

  // updates the wave at the boundary
  void Wave1D::_updateBoundary(const bool& atBoundary, const double& dt) {
    if (atBoundary) {
      dx_ *= -1;
      this->_update(dt);
    }
  }

}