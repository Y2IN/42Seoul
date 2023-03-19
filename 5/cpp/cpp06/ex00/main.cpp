#include "Convert.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Invaild number of argument. Check it!" << std::endl;
    return (1);
  }

  std::cout << Convert(av[1]);
  return (0);
}