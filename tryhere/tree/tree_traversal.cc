#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>
 
using namespace std;
 
/* A binary tree node has data, left child and right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* Helper function that allocates a new node with the given data and
   NULL left and right  pointers.*/
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
 
// An iterative process to print preorder traversal of Binary tree
void iterativePreorder(node *root)
{
    // Base Case
    if (root == NULL)
       return;
 
    // Create an empty stack and push root to it
    stack<node *> nodeStack;
    nodeStack.push(root);
 
    while (nodeStack.empty() == false)
    {
        // Pop the top item from stack and print it
        struct node *node = nodeStack.top();
        printf ("%d ", node->data);
        nodeStack.pop();
 
        // Push right and left children of the popped node to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}


// Iterative function to perform in-order traversal of the tree
void inorderIterative(node *root)
{
  // create an empty stack
  stack<node*> stack;

  // start from root node (set current node to root node)
  node *curr = root;

  // if current node is null and stack is also empty, we're done
  while (!stack.empty() || curr != nullptr)
  {
    // if current node is not null, push it to the stack (defer it)
    // and move to its left child
    if (curr != nullptr)
    {
      stack.push(curr);
      curr = curr->left;
    }
    else
    {
      // else if current node is null, we pop an element from the stack,
      // print it and finally set current node to its right child
      curr = stack.top();
      stack.pop();
      cout << curr->data << " ";

      curr = curr->right;
    }
  }
}

// Iterative function to perform post-order traversal of the tree
void postorderIterative(node* root)
{
	// create an empty stack and push root node
	stack<node*> stk;
	stk.push(root);

	// create another stack to store postorder traversal
    stack<int> out;

    // run till stack is not empty
	while (!stk.empty())
	{
	    // we pop a node from the stack and push the data to output stack
		node *curr = stk.top();
		stk.pop();

		out.push(curr->data);

		// push left and right child of popped node to the stack
		if (curr->left)
			stk.push(curr->left);

		if (curr->right)
			stk.push(curr->right);
	}

	// print postorder traversal
	while (!out.empty())
	{
		cout << out.top() << " ";
		out.pop();
	}
}
// Driver program to test above functions
int main()
{
    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  iterativePreorder(root);
  std::cout << "\n\n";
  postorderIterative(root);
  return 0;
}
