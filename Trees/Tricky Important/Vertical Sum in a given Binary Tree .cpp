Vertical Sum in a given Binary Tree | Set 1
Last Updated: 27-08-2020
Given a Binary Tree, find the vertical sum of the nodes that are in the same vertical line. Print all sums through different vertical lines.




We need to check the Horizontal Distances from the root for all nodes. If two nodes have the same Horizontal Distance (HD), then they are on the same vertical line. The idea of HD is simple. HD for root is 0, a right edge (edge connecting to right subtree) is considered as +1 horizontal distance and a left edge is considered as -1 horizontal distance. For example, in the above tree, HD for Node 4 is at -2, HD for Node 2 is -1, HD for 5 and 6 is 0 and HD for node 7 is +2.
We can do an in-order traversal of the given Binary Tree. While traversing the tree, we can recursively calculate HDs. We initially pass the horizontal distance as 0 for root. For left subtree, we pass the Horizontal Distance as Horizontal distance of root minus 1. For right subtree, we pass the Horizontal Distance as Horizontal Distance of root plus 1.

Following is Java implementation for the same. HashMap is used to store the vertical sums for different horizontal distances. Thanks to Nages for suggesting this method.



// C++ program to find Vertical Sum in 
// a given Binary Tree 
#include<bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

// A utility function to create a new 
// Binary Tree node 
Node* newNode(int data) 
{ 
	Node *temp = new Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Traverses the tree in in-order form and 
// populates a hashMap that contains the 
// vertical sum 
void verticalSumUtil(Node *node, int hd, 
					map<int, int> &Map) 
{ 
	// Base case 
	if (node == NULL) return; 

	// Recur for left subtree 
	verticalSumUtil(node->left, hd-1, Map); 

	// Add val of current node to 
	// map entry of corresponding hd 
	Map[hd] += node->data; 

	// Recur for right subtree 
	verticalSumUtil(node->right, hd+1, Map); 
} 

// Function to find vertical sum 
void verticalSum(Node *root) 
{ 
	// a map to store sum of nodes for each 
	// horizontal distance 
	map < int, int> Map; 
	map < int, int> :: iterator it; 

	// populate the map 
	verticalSumUtil(root, 0, Map); 

	// Prints the values stored by VerticalSumUtil() 
	for (it = Map.begin(); it != Map.end(); ++it) 
	{ 
		cout << it->first << ": "
			<< it->second << endl; 
	} 
} 

// Driver program to test above functions 
int main() 
{ 
	// Create binary tree as shown in above figure 
	Node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 
	root->right->left->right = newNode(8); 
	root->right->right->right = newNode(9); 

	cout << "Following are the values of vertical"
			" sums with the positions of the "
			"columns with respect to root\n"; 
	verticalSum(root); 

	return 0; 
} 
// This code is contributed by Aditi Sharma 
