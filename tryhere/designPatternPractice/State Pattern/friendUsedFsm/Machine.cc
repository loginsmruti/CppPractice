#include "Machine.hh"

Machine::Machine(int stockQuantity) :
  mStockQuantity(stockQuantity),
  mState(new Normal())
  { }

Machine::~Machine() {
  delete mState;
  mState = NULL;
}

void Machine::sell(int stockQuantity) {
  mState->sell(*this , stockQuantity);
}

void Machine::refill(int stockQuantity) {
  mState->refill(*this , stockQuantity);
}

int Machine::getCurrentStock() {
  return mStockQuantity;
}
