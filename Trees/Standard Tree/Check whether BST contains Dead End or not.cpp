

Check whether BST contains Dead End or not
Last Updated: 08-11-2020
Given a Binary search Tree that contains positive integer values greater than 0. The task is to check whether the BST contains a dead end or not. Here Dead End means, we are not able to insert any element after that node.
Examples:  

Input :        8
             /   \ 
           5      9
         /   \
        2     7
       /
      1               
Output : Yes
Explanation : Node "1" is the dead End because
         after that we cant insert any element.       

Input :       8
            /   \ 
           7     10
         /      /   \
        2      9     13

Output : Yes
Explanation : We can't insert any element at 
              node 9.  
              
              
 If we take a closer look at the problem, we can notice that we basically need to check if there is a leaf node with value x such that x+1 and x-1 exist in BST with the exception of x = 1. For x = 1, we can’t insert 0 as the problem statement says BST contains positive integers only.
To implement the above idea we first traverse the whole BST and store all nodes in a hash_map. We also store all leaves in a separate hash to avoid re-traversal of BST. Finally, we check for every leaf node x, if x-1 and x+1 are present in hash_map or not.
Below is a C++ implementation of the above idea. 





// C++ program check weather BST contains
// dead end or not
#include<bits/stdc++.h>
using namespace std;

// A BST node
struct Node
{
	int data;
	struct Node *left, *right;
};

// A utility function to create a new node
Node *newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

/* A utility function to insert a new Node
with given key in BST */
struct Node* insert(struct Node* node, int key)
{
	/* If the tree is empty, return a new Node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);

	/* return the (unchanged) Node pointer */
	return node;
}

// Function to store all node of given binary search tree
void storeNodes(Node * root, unordered_set<int> &all_nodes,
						unordered_set<int> &leaf_nodes)
{
	if (root == NULL)
		return ;

	// store all node of binary search tree
	all_nodes.insert(root->data);

	// store leaf node in leaf_hash
	if (root->left==NULL && root->right==NULL)
	{
		leaf_nodes.insert(root->data);
		return ;
	}

	// recur call rest tree
	storeNodes(root-> left, all_nodes, leaf_nodes);
	storeNodes(root->right, all_nodes, leaf_nodes);
}

// Returns true if there is a dead end in tree,
// else false.
bool isDeadEnd(Node *root)
{
	// Base case
	if (root == NULL)
		return false ;

	// create two empty hash sets that store all
	// BST elements and leaf nodes respectively.
	unordered_set<int> all_nodes, leaf_nodes;

	// insert 0 in 'all_nodes' for handle case
	// if bst contain value 1
	all_nodes.insert(0);

	// Call storeNodes function to store all BST Node
	storeNodes(root, all_nodes, leaf_nodes);

	// Traversal leaf node and check Tree contain
	// continuous sequence of
	// size tree or Not
	for (auto i = leaf_nodes.begin() ; i != leaf_nodes.end(); i++)
	{
		int x = (*i);

		// Here we check first and last element of
		// continuous sequence that are x-1 & x+1
		if (all_nodes.find(x+1) != all_nodes.end() &&
			all_nodes.find(x-1) != all_nodes.end())
			return true;
	}

	return false ;
}

// Driver program
int main()
{
/*	 8
	/ \
	5 11
	/ \
	2 7
	\
	3
	\
		4 */
	Node *root = NULL;
	root = insert(root, 8);
	root = insert(root, 5);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 7);
	root = insert(root, 11);
	root = insert(root, 4);
	if (isDeadEnd(root) == true)
		cout << "Yes " << endl;
	else
		cout << "No " << endl;
	return 0;
}




