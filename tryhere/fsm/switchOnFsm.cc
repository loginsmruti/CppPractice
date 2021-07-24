#include <stdio.h>
#include <iostream>

using namespace std;
class State;

enum state{ON=0,OFF};
class Switch {
  private:
    State* offState;
    State* onState;
    State* currState;
  public:
    ~Switch();
    Switch();
    void SetState(int st);
    void on();
    void off();
};
class State{
  public:
    State(){}
    virtual void on(Switch* op){}
    virtual void off(Switch* op){} 
};
class OnState : public State{
  public:
    OnState(){
      cout << "OnState State Initialized" << endl;
    }
    void on(Switch* op);
    void off(Switch* op);
};
class OffState : public State{
  public:
    OffState(){
      cout << "OffState State Initialized" << endl;
    }
    void on(Switch* op);
    void off(Switch* op);
};
Switch::Switch(){
  offState = new OffState();
  onState = new OnState();
  currState=offState;
}
Switch::~Switch(){
  if(offState != NULL)
    delete offState;
  if(onState != NULL)
    delete onState;
}
void Switch::SetState(int newState){
  if(newState == ON)
  {
    currState = onState;
  }
  else if(newState == OFF)
  {
    currState = offState;
  }
}
void Switch::on(){
  currState->on(this);
}
void Switch::off(){
  currState->off(this);
}
void OffState::on(Switch* op){
  cout << "State transition from OFF to ON" << endl;
  op->SetState(ON);
}
void OffState::off(Switch* op){
  cout << "Already in OFF state" << endl;
}
void OnState::on(Switch* op){
  cout << "Already in ON state" << endl;
}
void OnState::off(Switch* op){
  cout << "State transition from ON to OFF" << endl;
  op->SetState(OFF);
}
int main(){
  Switch* swObj = new Switch();
  int ch;
  do{
    switch(ch){
      case 1:     swObj->on();
                  break;
      case 0:     swObj->off();
                  break;
      default :   cout << "Invalid choice"<<endl;
                  break;
    }
    cout << "Enter 0/1: ";
    cin >> ch;  
  }while(true);
  
  //`enter code here`
  
  delete swObj;
  return 0;
}
