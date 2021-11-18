#include<iostream>

template <class Type>
class stackADT
{
  public:
    virtual void initializeStack() = 0;
    //Method to initialize the stack to an empty state. //Postcondition: Stack is empty.
    virtual bool isEmptyStack() const = 0;
    //Function to determine whether the stack is empty. //Postcondition: Returns true if the stack is empty,
    //    otherwise returns false.
    virtual bool isFullStack() const = 0;
    //Function to determine whether the stack is full. //Postcondition: Returns true if the stack is full, // otherwise returns false.
    virtual void push(const Type& newItem) = 0;
    //Function to add newItem to the stack.
    //Precondition: The stack exists and is not full. //Postcondition: The stack is changed and newItem is added // to the top of the stack.
    virtual Type top() const = 0;
    //Function to return the top element of the stack. //Precondition: The stack exists and is not empty. //Postcondition: If the stack is empty, the program
    // terminates; otherwise, the top element of the stack
    //    is returned.
    virtual void pop() = 0;
    //Function to remove the top element of the stack. //Precondition: The stack exists and is not empty. //Postcondition: The stack is changed and the top element
    //    is removed from the stack.
};

//Definition of the node template <class Type>
struct nodeType
{
  Type info;
  nodeType<Type> *link; 
};

template <class Type>
class linkedStackType: public stackADT<Type> {
  public:
    const linkedStackType<Type>& operator=
      (const linkedStackType<Type>&);
    //Overload the assignment operator.
    bool isEmptyStack() const;
    //Function to determine whether the stack is empty. //Postcondition: Returns true if the stack is empty; // otherwise returns false.
    bool isFullStack() const;
    //Function to determine whether the stack is full. //Postcondition: Returns false.
    void initializeStack();
    //Function to initialize the stack to an empty state. //Postcondition: The stack elements are removed;
    // stackTop = NULL;
    void push(const Type& newItem);
    //Function to add newItem to the stack. //Precondition: The stack exists and is not full. //Postcondition: The stack is changed and newItem is // added to the top of the stack.
    Type top() const;
    //Function to return the top element of the stack. //Precondition: The stack exists and is not empty. //Postcondition: If the stack is empty, the program
    // terminates; otherwise, the top element of
    //    the stack is returned.
    void pop();
    //Function to remove the top element of the stack. //Precondition: The stack exists and is not empty. //Postcondition: The stack is changed and the top
    //    element is removed from the stack.
    linkedStackType();
    //Default constructor
    //Postcondition: stackTop = NULL;
    linkedStackType(const linkedStackType<Type>& otherStack); //Copy constructor
    ~linkedStackType();
    //Destructor
    //Postcondition: All the elements of the stack are removed.
  private:
    nodeType<Type> *stackTop; //pointer to the stack
    void copyStack(const linkedStackType<Type>& otherStack); //Function to make a copy of otherStack. 
    //Postcondition: A copy of otherStack is created and assigned to this stack.
};

template <class Type> linkedStackType<Type>::linkedStackType() {
  stackTop = NULL;
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const {
  return(stackTop == NULL); } //end isEmptyStack
  template <class Type>
  bool linkedStackType<Type>::isFullStack() const {
    return false;
  } //end isFullStack


template <class Type>
void linkedStackType<Type>:: initializeStack() {
  rodeType<Type> *temp; //pointer to delete the node
  while (stackTop != NULL) //while there are elements in //the stack
  {
    temp = stackTop;    //set temp to point to the
    //current node
    stackTop = stackTop->link; //advance stackTop to the //next node
    delete temp; //deallocate memory occupied by temp

  }
}

template <class Type>
void linkedStackType<Type>::push(const Type& newElement) {
  nodeType<Type> *newNode; //pointer to create the new node
  newNode = new nodeType<Type>; //create the node
  newNode->info = newElement; //store newElement in the node 
  newNode->link = stackTop; //insert newNode before stackTop 
  stackTop = newNode; //set stackTop to point to the
  //top node
} //end push


template <class Type>
Type linkedStackType<Type>::top() const {
  assert(stackTop != NULL); //if stack is empty, //terminate the program
  return stackTop->info; //return the top element 
}//end top


  template <class Type>
  void linkedStackType<Type>::pop() {
    nodeType<Type> *temp; //pointer to deallocate memory
    if (stackTop != NULL)
    {
      temp = stackTop; //set temp to point to the top node
      stackTop = stackTop->link; //advance stackTop to the //next node
      delete temp;    //delete the top node
    }
    else
      cout << "Cannot remove from an empty stack." << endl;
  }//end pop

template <class Type>
void linkedStackType<Type>::copyStack
(const linkedStackType<Type>& otherStack) nodeType<Type> *newNode, *current, *last;
if (stackTop != NULL) //if stack is nonempty, make it empty initializeStack();
if (otherStack.stackTop == NULL)
  stackTop = NULL;
  else
{
  {
    temp = stackTop; //set temp to point to the top node
    stackTop = stackTop->link; //advance stackTop to the //next node
    delete temp;    //delete the top node
    current = otherStack.stackTop; //set current to point //to the stack to be copied
    //copy the stackTop element of the stack 
    stackTop = new nodeType<Type>; //create the node
    stackTop->info = current->info; //copy the info 
    stackTop->link = NULL; //set the link field to NULL 
    last = stackTop; //set last to point to the node 
    current = current->link; //set current to point to the
    //next node

    //copy the remaining stack 
    while (current != NULL)
    {
      newNode = new nodeType<Type>;
      newNode->info = current->info;
      newNode->link = NULL;
      last->link = newNode;
      last = newNode;
      current = current->link; }//end while
  }//end else
} //end copyStack

//copy constructor
template <class Type> linkedStackType<Type>::linkedStackType(
    const linkedStackType<Type>& otherStack)
{
  copyStack(otherStack); }//end copy constructor
  //destructor
  template <class Type> linkedStackType<Type>::~linkedStackType() {
    initializeStack(); }//end destructor


    template <class Type>
    const linkedStackType<Type>& linkedStackType<Type>::operator=
    stackTop = NULL;
{
  return *this; }//end operator=


#include <iostream>
#include "linkedStack.h"
  using namespace std;
  void testCopy(linkedStackType<int> OStack);
int main()
{
  linkedStackType<int> stack; linkedStackType<int> otherStack; linkedStackType<int> newStack;
  //Add elements into stack
  stack.push(34);
  stack.push(43);
  stack.push(27);
  //Use the assignment operator to copy the elements
  //of stack into newStack
  newStack = stack;
  cout << "After the assignment operator, newStack: " << endl;
  //Output the elements of newStack 
  while (!newStack.isEmptyStack())
  {
    cout << newStack.top() << endl;
    newStack.pop();
  }
  otherStack = stack;
  cout << "Testing the copy constructor." << endl; testCopy(otherStack);

  testCopy(otherStack);

  cout << "After the copy constructor, otherStack: " << endl;
  while (!otherStack.isEmptyStack())
  {
    cout << otherStack.top() << endl;
    otherStack.pop();
  }
  return 0;
}

//Function to test the copy constructor 
void testCopy(linkedStackType<int> OStack)
{
  cout << "Stack in the function testCopy:" << endl;
  while (!OStack.isEmptyStack())
  {
    cout << OStack.top() << endl;
    OStack.pop();
  }
}

