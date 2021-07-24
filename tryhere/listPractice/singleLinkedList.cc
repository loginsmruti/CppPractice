#include "singleLinkedList.hh"

SingleLinkedList::SingleLinkedList()
  : head(nullptr),
    tail(nullptr)
  { }

SingleLinkedList::SingleLinkedList(const SingleLinkedList& obj)
  : SingleLinkedList() 
{
  Node *curr = obj.head;
  while(curr != nullptr) {
   
   append(curr->data); 
   curr = curr->next; 
  }  
}

SingleLinkedList::~SingleLinkedList()
{
  Node* curr = head;
  while(curr != nullptr) {

    Node *next = curr->next;
    delete curr;
    curr = next;
  }
  head = tail = nullptr;
}

//use copy-swap-idiom
SingleLinkedList& SingleLinkedList::operator=(const SingleLinkedList& secondList)
{
  SingleLinkedList temp(secondList);
  swap(temp);
  
  return *this;
}

SingleLinkedList& SingleLinkedList::operator+=(const SingleLinkedList& secondList)
{
  SingleLinkedList* list = new SingleLinkedList(secondList);

  if(isEmpty()) {
    head = list->head; 
  } 
  else 
    tail->next = list->head;

  tail = list->tail;

  list->head = list->tail = nullptr;
  delete list;

  return *this;
}

SingleLinkedList operator+(const SingleLinkedList& lhsObj , const SingleLinkedList& rhsObj)
{
  SingleLinkedList list(lhsObj);
  
  list += rhsObj; 
  
  return list;
}

void SingleLinkedList::insert(int data)
{
  Node *newNode = new Node;
  newNode->data = data; 
  newNode->next = head;
  head = newNode;

  if(tail == nullptr)
      tail = head;  

}

void SingleLinkedList::append(int data)
{
  Node *newNode = new Node;
  newNode->data = data;
  if(isEmpty()) {
    head = tail = newNode;
    return;
  }
  tail->next = newNode;
  tail = newNode;
}

bool SingleLinkedList::isEmpty() const { return (head == nullptr); }

size_t SingleLinkedList::getContainerSize() const
{
  Node *curr = head;
  size_t count;

  while(nullptr != curr)
  {
    count++;
    curr = curr->next;
  }

  return count;
}

size_t SingleLinkedList::getContainerSizeRecursiveStyle(Node* node) const
{
  if(nullptr  == node)
    return 0;

  return 1 + getContainerSizeRecursiveStyle(node->next);
}

void SingleLinkedList::printNode() const
{
  Node *curr = head;
  while(curr != nullptr)
  {
    std::cout << curr->data << "-->";
    curr = curr->next;
  }
  std::cout << "nullptr";
  std::cout << " [head = " << ((head == nullptr) ? (-1) : (head->data)) << "], [tail = " << 
    ((tail == nullptr) ? (-1) : (tail->data)) << "]" << std::endl;
  
std::cout << "List Size::  " << getContainerSizeRecursiveStyle(head);
}

void SingleLinkedList::swap(SingleLinkedList &other) 
{
    using std::swap;
    swap(this->head, other.head);
    swap(this->tail, other.tail);
}

int main()
{
  SingleLinkedList *list = new SingleLinkedList();
  list->insert(1);
  list->insert(2);
  list->insert(3);
  list->insert(4);
  list->insert(5);
  
  list->printNode();

  return 0;
}
