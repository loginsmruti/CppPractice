#ifndef LINKED_LIST_H
#define LINKED_LIST_H


class LinkedList
{
    private:
        struct Node
        {
            int data = 0;
            Node *next = nullptr;
        };

    public:
        LinkedList();
        LinkedList(const LinkedList &list);
        ~LinkedList();
        LinkedList & operator=(const LinkedList &other);
        LinkedList & operator+=(const LinkedList &rhs);
        friend LinkedList operator+(const LinkedList &lhs, const LinkedList &rhs);

        bool isEmpty() const;
        void append(int value); // add to end
        void insert(int value); // add to beginning
        void print() const;
        void reverse();
        size_t getListSize(Node* ptrNode) const;

    protected:       
        // Protected so that derived class can modify these directly
        Node *head;
        Node *tail; // allows O(1) append

    private:
        void swap(LinkedList &other);

};

#endif
