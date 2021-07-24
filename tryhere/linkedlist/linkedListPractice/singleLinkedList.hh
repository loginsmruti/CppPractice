#pragma once

class SingleLinkedList
{
  private:

  struct Node {
    int data = 0;
    Node* next = nullptr;
  };
  
  protected:
    Node *head;
    Node *tail;
    
  public:
  
    SingleLinkedList();
    ~SingleLinkedList();
    SingleLinkedList(const SingleLinkedList& other);
    
    bool isListEmpty();
    void append(int data); //append data to the end of list
    void insert(int data); //insert data into the begining of list
    void reverse();
    std::ostream& operator<<( std::ostream& os , const SingleLinkedList& list);
    
    SingleLinkedList& operator+(const SingleLinkedList& listOne , const SingleLinkedList& listTwo);
    SingleLinkedList& operator=(const SingleLinkedList& list);
  
};
