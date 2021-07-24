#include "MachineStates.hh"

AbstractState::~AbstractState() 
 { }

void Normal::sell(Machine *machine , int quantity) {

  int currentStock = machine->getCurrentStock();
  
  if(currentStock < quantity) {
    throw std::runtime_error("Not Enough Stock\n");
  }
 
  machine->updateStock(currentStock - quantity);
  if(machine->getCurrentStock() == 0 ) {
    machine->setCurrentState(new SoldOut());

    std::cout << "Machine state moved to SoldOut\n";

    delete this;
  } 
}

void Normal::refill(Machine *machine , int quantity)
{
  int currentStock = machine->getCurrentStock();
  machine->updateStock(currentStock + quantity);
  machine->setCurrentState(new Normal());
  std::cout << "Machine state moved to Normal\n";
  
  delete this;
}

Normal::~Normal() { std::cout << "Normal state dtor called.\n"; }

void SoldOut::sell(Machine *machine , int quantity) {

  throw std::runtime_error("Not Enough Stock\n");
}

void SoldOut::refill(Machine *machine , int quantity)
{
  machine->updateStock(quantity);
  machine->setCurrentState(new Normal());
  std::cout << "Machine state moved to Normal\n";

  delete this;
}

SoldOut::~SoldOut() { std::cout << " SoldOut state dtor called.\n"; }
