#include "Machine.hh"

int main() {

  Machine machine(20);

  try {
    machine.sell(10);
  }
  catch(std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  machine.refill(10);
  std::cout << "refilled 10 items" << std::endl;

  machine.sell(20);
  std::cout << "sold 20 items" << std::endl;

  machine.refill(10);

  try {
    machine.sell(10);
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;   
}
