#include <iostream>
/*
 * Node will contain and int variable as value
 * and a node pointer to next Node.
 **/
//struct node
//{
//   int value;
//   node * nextPtr;    
//   node(int val)
//   {
//      value = val;
//      nextPtr = NULL;    
//   }
//};

class Node;

class Node
{
   private:  
   int value;
   Node * nextPtr;

   public:
   Node(int val)
   {
      value = val;
      nextPtr = NULL;
   }
   Node* createListFromArray(int * ptr, int arraySize);
   void destroyList(Node * ptr);
   void displayLinkedList(Node *ptr);
};

/*
 * Iterate the passed array one by one and create a node
 * for each element and append it in last node's next pointer.
 * Also keep a track of last node created while iteration to
 * update its next pointer in next iteration.
 * Also store the first node created,that we will returned as
 * root node in end.
 **/
Node* Node::createListFromArray(int * ptr, int arraySize)
{
   Node * nodePtr = NULL;
   Node * rootNodePtr = NULL;
   Node * lastNodePtr = NULL;
   for(int i = 0 ; i < arraySize; i++)
   {
      if(!nodePtr)
      {
         nodePtr = new Node(*(ptr+i));
         if(!rootNodePtr)
            rootNodePtr = nodePtr;    
         if(lastNodePtr)
            lastNodePtr->nextPtr = nodePtr;
      }
      lastNodePtr = nodePtr;
      nodePtr = nodePtr->nextPtr;
   }
   return rootNodePtr;
}
/*
 * Store the next pointer of passed node as temp variable.
 * Delete the current pointer and pass the earlier stored next pointer
 * to destroyList funtion.
 *
 * If ptr is null it means its the end of linked list, so just return
 * because complete linked list is deleted.
 **/
void Node::destroyList(Node * ptr)
{
   if(ptr)
   {
      Node * pNext = ptr->nextPtr;
      delete ptr;
      destroyList(pNext);
   }
}
/*
 * Iterate through all nodes and display content
 * of each node untill end of linked list is reached.
 **/
void Node::displayLinkedList(Node *ptr)
{
   while(ptr != NULL)
   {
      std::cout<<ptr->value<<" ";
      ptr = ptr->nextPtr;
   }
   std::cout<<std::endl;
}
/*
 * Testing functions.
 **/
int main()
{
   int arr[] = {1,2,3,4, 89,1,1,1,0};
   Node *node = new Node();
   node.createListFromArray(arr, sizeof(arr)/sizeof(int));
   displayLinkedList(ptr);
   destroyList(ptr);
   return 0;
}
