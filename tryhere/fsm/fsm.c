
#include <stdio.h>
/*****************************************************************
 * typedefs
 *****************************************************************/

typedef enum {
   STATE1,
   STATE2,
   STATE3
} state;

typedef enum {
   NILEVENT,
   EVENT1,
   EVENT2
} event;


typedef void (*action)();

// General functions
void stateEval(event e);
void exit(int status);
void getIOValues(void);

//Actions
void action1_1(void);
void action1_2(void);
void action1_3(void);
void action2_1(void);
void action2_2(void);
void action2_3(void);
void action3_1(void);
void action3_2(void);
void action3_3(void);

typedef struct {
   state nextState;       // Enumerator for the next state
   action actionToDo;     // function-pointer to the action that shall be released in current state
}  stateElement;               // structure for the elements in the state-event matrix


stateElement stateMatrix[3][3] = {
   { {STATE1, action1_1}, {STATE2, action1_2}, {STATE3, action1_3} },
   { {STATE2, action2_1}, {STATE2, action2_2}, {STATE3, action2_3} },
   { {STATE3, action3_1}, {STATE3, action3_2}, {STATE3, action3_3} }
};


state  currentState = STATE1;

int main()
{
   //Initializations
   event  eventOccured = NILEVENT;
   action actionToDo   = action1_1;

   while(1) {
      // event input, NIL-event for non-changing input-alphabet of FSM
      // in real implementation this should be triggered by event registers e.g.
      // evaluation of complex binary expressions could be implemented to release the events

      int e = 0;             

      printf("----------------\n");
      printf("Event to occure: ");
      scanf("%u",&e);
      stateEval( (event) e); // typecast to event enumeration type
      printf("-----------------\n");

   };
   return (0);
}

/********************************************************************************
 * stateEval (event)
 * in Dependancy of an triggered event, the action wich is required by this
 * transition will be returned. The proper action is determined by the current state the
 * automat holds. The current state will then be transitioned to the requestet next
 * state
 ********************************************************************************/

void stateEval(event e)
{
   //determine the State-Matrix-Element in dependany of current state and triggered event
   stateElement stateEvaluation = stateMatrix[currentState][e];

   //do the transition to the next state (set requestet next state to current state)...
   currentState = stateEvaluation.nextState;
   //... and fire the proper action
   (*stateEvaluation.actionToDo)();
}

/**********************************************************************
 * action functions
 **********************************************************************/

void action1_1() {
   printf("action1.1 \n");
}

void action1_2() {
   printf("action1.2 \n");
}

void action1_3() {
   printf("action1.3 \n");
}

void action2_1() {
   printf("action2.1 \n");
}

void action2_2() {
   printf("action2.2 \n");
}

void action2_3() {
   printf("action2.3 \n");
}

void action3_1() {
   printf("action3.1 \n");
}

void action3_2() {
   printf("action3.2 \n");
}

void action3_3() {
   printf("action3.3 \n");
}
