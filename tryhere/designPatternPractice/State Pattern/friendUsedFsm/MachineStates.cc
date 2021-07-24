
#include "MachineStates.hh"

AbstractState::~AbstractState() 
 { }

void AbstractState::setState(Machine &machine , AbstractState* state) {

  AbstractState* oldState = machine.mState;
  machine.mState = state; 

  delete oldState;
}

void AbstractState::updateStock(Machine& machine , int quantity) {

  machine.mStockQuantity = quantity;
}

void Normal::sell(Machine &machine , int quantity) {

  int currentStock = machine.getCurrentStock();
  
  if(currentStock < quantity) {
    throw std::runtime_error("Not Enough Stock\n");
  }
 
  updateStock(machine , currentStock - quantity);
  if(machine.getCurrentStock() == 0 ) {
    setState(machine , new SoldOut());
  } 

}

void Normal::refill(Machine &machine , int quantity)
{
  int currentStock = machine.getCurrentStock();
  updateStock(machine , currentStock + quantity);
  setState(machine , new Normal());
}

Normal::~Normal() { }

void SoldOut::sell(Machine &machine , int quantity) {

  throw std::runtime_error("Not Enough Stock\n");
}

void SoldOut::refill(Machine &machine , int quantity)
{
  updateStock(machine ,quantity);
  setState(machine , new Normal());
}

SoldOut::~SoldOut() {}

