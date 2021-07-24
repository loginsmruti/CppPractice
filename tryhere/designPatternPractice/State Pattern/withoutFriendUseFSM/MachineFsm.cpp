#include "Machine.hh"

int main() {

  Machine machine(10);

  machine.sell(10);
  std::cout << "Sold 10 items" << std::endl;

  try {
    machine.sell(1);
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  machine.refill(20);
  std::cout << "Refilled 20 items" << std::endl;

  machine.sell(10);
  std::cout << "Sold 10 items" << std::endl;
  std::cout << "Remaining " << machine.getCurrentStock() << " items" << std::endl;

  machine.sell(5);
  std::cout << "Sold 5 items" << std::endl;
  std::cout << "Remaining " << machine.getCurrentStock() << " items" << std::endl;

  try {
    machine.sell(10);
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;   
}
