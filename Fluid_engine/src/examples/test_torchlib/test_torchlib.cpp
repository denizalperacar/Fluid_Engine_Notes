
#include <iostream>
#include "torch/torch.h"

int main() {

  torch::Tensor tensor1 = torch::rand({2, 3});
  torch::Tensor tensor2 = torch::acos(tensor1);
  std::cout << tensor2 << std::endl;

}