
#include <iostream>
#include "torch/torch.h"


int main () {

  // tensor configuration
  c10::TensorOptions options = torch::TensorOptions()
    .dtype(torch::kFloat32)
    .layout(torch::kStrided)
    .device(torch::kCPU)
    .requires_grad(true);

  torch::Tensor tensor = torch::randn({100,3}, options);
  std::cout << tensor * 2.0 + tensor << std::endl;

  // at::parallel_for
  // do the ray cutting the 3D voxel area.
  // testing 

}