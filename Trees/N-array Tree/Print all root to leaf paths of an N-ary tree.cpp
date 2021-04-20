Print all root to leaf paths of an N-ary tree
Last Updated: 16-12-2020
Given an N-Ary tree, the task is to print all root to leaf paths of the given N-ary Tree.

Examples:

Input:
                        1
                      /   \
                   2      3
                 /      /   \
              4      5     6
                           /   \
                        7      8

Output:
1 2 4
1 3 5
1 3 6 7
1 3 6 8

Input:
                          1
                        / | \
                      2  5  3
                    / \        \
                   4   5       6
Output:
1 2 4
1 2 5
1 5
1 3 6



Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Approach: The idea to solve this problem is to start traversing the N-ary tree using depth-first search and keep inserting every node encountered in a vector until a leaf node is encountered. Whenever a leaf node is encountered, print the elements stored in the vector as the current root-to-leaf path traversed and remove the last added leaf and check for the next combination.

Below is the implementation of the above approach



// C++ program for the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Strcuture of an N ary tree node 
class Node { 
public: 
	int data; 
	vector<Node*> child; 

	// Parameterized Constructor 
	Node(int x) 
		: data(x) 
	{ 
	} 
}; 

// Function to print the root to leaf 
// path of the given N-ary Tree 
void printPath(vector<int> vec) 
{ 
	// Print elements in the vector 
	for (int ele : vec) { 
		cout << ele << " "; 
	} 
	cout << endl; 
} 

// Utility function to print all 
// root to leaf paths of an Nary Tree 
void printAllRootToLeafPaths( 
	Node* root, vector<int> vec) 
{ 
	// If root is null 
	if (!root) 
		return; 

	// Insert current node's 
	// data into the vector 
	vec.push_back(root->data); 

	// If current node is a leaf node 
	if (root->child.empty()) { 

		// Print the path 
		printPath(vec); 

		// Pop the leaf node 
		// and return 
		vec.pop_back(); 
		return; 
	} 

	// Recur for all children of 
	// the current node 
	for (int i = 0; 
		i < root->child.size(); i++) 

		// Recursive Function Call 
		printAllRootToLeafPaths( 
			root->child[i], vec); 
} 

// Function to print root to leaf path 
void printAllRootToLeafPaths(Node* root) 
{ 
	// If root is null, return 
	if (!root) 
		return; 

	// Stores the root to leaf path 
	vector<int> vec; 

	// Utility function call 
	printAllRootToLeafPaths(root, vec); 
} 

// Driver Code 
int main() 
{ 
	// Given N-Ary tree 
	Node* root = new Node(1); 
	(root->child).push_back(new Node(2)); 
	(root->child).push_back(new Node(3)); 
	(root->child[0]->child).push_back(new Node(4)); 
	(root->child[1]->child).push_back(new Node(5)); 
	(root->child[1]->child).push_back(new Node(6)); 
	(root->child[1]->child[1]->child) 
		.push_back(new Node(7)); 
	(root->child[1]->child[1]->child) 
		.push_back(new Node(8)); 

	// Function Call 
	printAllRootToLeafPaths(root); 

	return 0; 
} 
