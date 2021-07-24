#pragma once

#include "Machine.hh"

class Machine;

class AbstractState
{
  public:
    virtual void sell(Machine &machine , int quantity) = 0;
    virtual void refill(Machine &machine , int quantity) = 0;
    virtual ~AbstractState();
  protected:
    void setState(Machine &machine , AbstractState* state);
    void updateStock(Machine& machine , int quantity);
};

class Normal : public AbstractState
{
  public:
    virtual void sell(Machine &machine , int quantity);
    virtual void refill(Machine &machine , int quantity);
  
    virtual ~Normal();
};

class SoldOut : public AbstractState
{
  public:
    virtual void sell(Machine &machine , int quantity);
    virtual void refill(Machine &machine , int quantity);
    
    virtual ~SoldOut();
};
