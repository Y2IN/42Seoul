#include "RPN.hpp"

void leaks() {
  system("leaks RPN");
}

int main(int ac, char **av) {
  atexit(leaks);
  if (ac != 2) {
    std::cerr <<"Error" << std::endl;
    return 0;
  }
  RPN rpn(av[1]);
  return 0;
}
