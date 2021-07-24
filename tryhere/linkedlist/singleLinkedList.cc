#include <iostream>
#include "singleLinkedList.hh"

LinkedList::LinkedList(): head(nullptr), tail(nullptr) 
{
}

LinkedList::LinkedList(const LinkedList &list): LinkedList() // call base constructor
{
    Node *curr = list.head;
    while(curr != nullptr)
    {
        this->append(curr->data);
        curr = curr->next;
    }
}

LinkedList::~LinkedList()
{
    Node *curr = head;
    while (curr != nullptr)
    {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
    head = tail = nullptr;
}

void LinkedList::swap(LinkedList &other) 
{
    using std::swap;
    swap(this->head, other.head);
    swap(this->tail, other.tail);
}

// Operator '=': use copy-and-swap idiom
LinkedList & LinkedList::operator=(const LinkedList &other)
{
    LinkedList temp(other); // Use copy constructor to make deep local copy
    this->swap(temp);       // Swap contents, destroy local list with old data
    return *this;
}

LinkedList & LinkedList::operator+=(const LinkedList &rhs)
{
    LinkedList *addition = new LinkedList(rhs); // make deep copy of passed in list
    if (this->isEmpty())
        head = addition->head;
    else
        tail->next = addition->head;
    tail = addition->tail;

    // Destroy deep copy members but not what they point to
    addition->head = addition->tail = nullptr;
    delete addition;

    return *this;
}

LinkedList operator+(const LinkedList &lhs, const LinkedList &rhs)
{
    LinkedList result(lhs); // make deep local copy 
    result += rhs;
    return result;
}

bool LinkedList::isEmpty() const
{
    return head == nullptr;
}

void LinkedList::append(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    if (isEmpty())
    { 
        head = tail = new_node;
        return;
    }
    tail->next = new_node;
    tail = new_node;
}

void LinkedList::insert(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    if (tail == nullptr)
        tail = head;
}
//reverse
void LinkedList::reverse() 
{
  Node* current = head;
  Node* prev  = nullptr;
  Node*  next = nullptr;

  while(current != nullptr)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev; 
}

void LinkedList::print() const
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
}


size_t LinkedList::getListSize(Node* ptrNode) const
{
   Node *curr = obj;
  
  if(nullptr  == curr)
    return 0;

  return 1 + getListSiz(curr->next);
}

int main() 
{
  LinkedList *list = new LinkedList();
  list->insert(1);
  list->insert(2);
  list->insert(3);
  list->insert(4);
  list->insert(5);
  
  list->print();

  return 0;
}
