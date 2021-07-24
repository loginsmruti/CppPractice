#include <iostream>

/* Node class */
class Node 
{
   private:
    int key;
    Node* left;
    Node* right;
   
   public:

    Node() { key = -1; left = nullptr; right = nullptr; };

    void setKey(int aKey) { key = aKey; };

    void setLeft(Node* aLeft) { left = aLeft; };

    void setRight(Node* aRight) { right = aRight; };

    int Key() { return key; };

    Node* Left() { return left; };

    Node* Right() { return right; };
};

/* Tree class */
class Tree 
{
   Node* root;

   public:

    Tree();
    ~Tree();
    Node* Root() { return root; };
    void addNode(int key);
    void inOrder(Node* n);
    void preOrder(Node* n);
    void postOrder(Node* n);

   private:

    void addNode(int key, Node* leaf);
    void freeNode(Node* leaf);
};

/* Constructor */
Tree::Tree() 
{
   root = nullptr;
}

/* Destructor */
Tree::~Tree() 
{
   freeNode(root);
}

/* Free the node */
void Tree::freeNode(Node* leaf)
{
   if ( leaf != nullptr )
   {
      freeNode(leaf->Left());
      freeNode(leaf->Right());
      delete leaf;
   }
}

/* Add a node */
void Tree::addNode(int key) 
{
   // No elements. Add the root
   if ( root == nullptr ) {
      std::cout << "add root node ... " << key << std::endl;
      Node* n = new Node();
      n->setKey(key);
      root = n;
   }
   else {
      std::cout << "add other node ... " << key << std::endl;
      addNode(key, root);
   }
}

// Add a node (private)
void Tree::addNode(int key, Node* leaf)
{
   if ( key <= leaf->Key() ) {
      if ( leaf->Left() != nullptr )
         addNode(key, leaf->Left());
      else {
         Node* n = new Node();
         n->setKey(key);
         leaf->setLeft(n);
      }
   }
   else {
      if ( leaf->Right() != nullptr )
         addNode(key, leaf->Right());
      else {
         Node* n = new Node();
         n->setKey(key);
         leaf->setRight(n);
      }
   }
}

// Print the tree in-order
// Traverse the left sub-tree, root, right sub-tree
void Tree::inOrder(Node* n)
{
   if ( n ) {
      inOrder(n->Left());
      std::cout << n->Key() << " ";
      inOrder(n->Right());
   }
}

// Print the tree pre-order
// Traverse the root, left sub-tree, right sub-tree
void Tree::preOrder(Node* n) 
{
   if ( n ) {
      std::cout << n->Key() << " ";
      preOrder(n->Left());
      preOrder(n->Right());
   }
}

// Print the tree post-order
// Traverse left sub-tree, right sub-tree, root
void Tree::postOrder(Node* n) 
{
   if ( n ) {
      postOrder(n->Left());
      postOrder(n->Right());
      std::cout << n->Key() << " ";
   }
}


// Test main program
int main() 
{
   Tree* tree = new Tree();

   tree->addNode(30);
   tree->addNode(10);
   tree->addNode(20);
   tree->addNode(40);
   tree->addNode(50);

   std::cout << "In order traversal" << std::endl;
   tree->inOrder(tree->Root());
   std::cout << std::endl;

   std::cout << "Pre order traversal" << std::endl;
   tree->preOrder(tree->Root());
   std::cout << std::endl;

   std::cout << "Post order traversal" << std::endl;
   tree->postOrder(tree->Root());
   std::cout << std::endl;

   delete tree;
 
   return 0;
}
