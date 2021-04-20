Print middle level of perfect binary tree without finding height
Difficulty Level : Medium
 Last Updated : 02 Dec, 2020
Given a perfect binary tree, print nodes of middle level without computing its height. A perfect binary tree is a binary tree in which all interior nodes have two children and all leaves have the same depth or same level.
 

https://www.geeksforgeeks.org/print-middle-level-perfect-binary-tree-without-finding-height/

Output : 4 5 6 7
 

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
The idea is similar to method 2 of finding middle of singly linked list.
Use fast and slow (or tortoise) pointers in each route of the tree. 

Advance fast pointer towards leaf by 2.
Advance slow pointer towards lead by 1.
If fast pointer reaches the leaf print value at the slow pointer
Check if the fast->left->left exists, then recursively move slow pointer by one step and fast pointer by two steps.
If the fast->left->left doesn’t exist (in case of even number of levels), the move both the pointers by one step.






#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has key, pointer to left
child and a pointer to right child */
struct Node {
	int key;
	struct Node *left, *right;
};

/* To create a newNode of tree and return pointer */
struct Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

// Takes two parameters - same initially and
// calls recursively
void printMiddleLevelUtil(Node* a, Node* b)
{
	// Base case e
	if (a == NULL || b == NULL)
		return;

	// Fast pointer has reached the leaf so print
	// value at slow pointer
	if ((b->left == NULL) && (b->right == NULL)) {
		cout << a->key << " ";
		return;
	}

	// Recursive call
	// root.left.left and root.left.right will
	// print same value
	// root.right.left and root.right.right
	// will print same value
	// So we use any one of the condition
	if (b->left->left) {
		printMiddleLevelUtil(a->left, b->left->left);
		printMiddleLevelUtil(a->right, b->left->left);
	}
	else {
		printMiddleLevelUtil(a->left, b->left);
		printMiddleLevelUtil(a->right, b->left);
	}
}

// Main printing method that take a Tree as input
void printMiddleLevel(Node* node)
{
	printMiddleLevelUtil(node, node);
}

// Driver program to test above functions
int main()
{

	Node* n1 = newNode(1);
	Node* n2 = newNode(2);
	Node* n3 = newNode(3);
	Node* n4 = newNode(4);
	Node* n5 = newNode(5);
	Node* n6 = newNode(6);
	Node* n7 = newNode(7);

	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;
	n1->left = n2;
	n1->right = n3;

	printMiddleLevel(n1);
}

// This code is contributed by Prasad Kshirsagar
