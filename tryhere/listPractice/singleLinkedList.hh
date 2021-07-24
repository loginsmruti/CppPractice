#ifndef _SINGLE_LINKED_LIST_
#define _SINGLE_LINKED_LIST_

#include<iostream>

struct Node {
  int data;
  struct Node* next;
};


class SingleLinkedList 
{
   public:
    SingleLinkedList();
    SingleLinkedList(const SingleLinkedList& obj);
    
    ~SingleLinkedList();
    
    SingleLinkedList& operator=(const SingleLinkedList& secondList);
    SingleLinkedList& operator+=(const SingleLinkedList& secondList);
    friend SingleLinkedList operator+(const SingleLinkedList& lhsObj , const SingleLinkedList& rhsObj);

    void insert(int data);
    void append(int data);
    void reverseListRecursiveStyle();     
    void reverseList();     
    
    bool isEmpty() const;
    size_t getContainerSizeRecursiveStyle(Node *node) const;
    size_t getContainerSize() const;
    
    void printNode() const;
    friend std::ostream& operator<<(std::ostream& os , const SingleLinkedList& obj);

   private:
    void swap(SingleLinkedList& otherList);
   
   protected:
    Node* head;
    Node* tail;
};



#endif
