#pragma once

#include "Machine.hh"

class Machine;

class AbstractState
{
  public:
    virtual void sell(Machine *machine , int quantity) = 0;
    virtual void refill(Machine *machine , int quantity) = 0;
    virtual ~AbstractState();
};

class Normal : public AbstractState
{
  public:
    Normal() { std::cout<<"Normal state ctor called\n"; };
    virtual void sell(Machine *machine , int quantity);
    virtual void refill(Machine *machine , int quantity);
  
    virtual ~Normal();
};

class SoldOut : public AbstractState
{
  public:
    SoldOut() { std::cout<<"SoldOut state ctor called\n"; };
    virtual void sell(Machine *machine , int quantity);
    virtual void refill(Machine *machine , int quantity);
    
    virtual ~SoldOut();
};
