Count of Nodes whose both immediate children are its prime factor

Count of Nodes whose both immediate children are its prime factors

Given a Binary Tree, the task is to print the count of nodes having both children and both of them are its prime factors.



Input: 
                  1
                /   \ 
              15     20
             /  \   /  \ 
            3    5 4     2 
                    \    / 
                     2  3  
Output: 1
Explanation: 
Children of 15 (3, 5) are prime factors of 15

Input:
                  7
                /  \ 
              210   14 
             /  \      \
            70   14     30
           / \         / \
          2   5       3   5
                      /
                     23 
Output: 2
Explanation: 
Children of 70 (2, 5) are prime factors of 70
Children of 30 (3, 5) are prime factors of 30





// C++ program for Counting nodes 
// whose immediate children are its factors 

#include <bits/stdc++.h> 
using namespace std; 

int N = 1000000; 

// To store all prime numbers 
vector<int> prime; 

void SieveOfEratosthenes() 
{ 
	// Create a boolean array "prime[0..N]" 
	// and initialize all entries it as true. 
	// A value in prime[i] will finally 
	// be false if i is Not a prime, else true. 
	bool check[N + 1]; 
	memset(check, true, sizeof(check)); 

	for (int p = 2; p * p <= N; p++) { 

		// If prime[p] is not changed, 
		// then it is a prime 
		if (check[p] == true) { 

			prime.push_back(p); 

			// Update all multiples of p 
			// greater than or equal to 
			// the square of it 
			// numbers which are multiples of p 
			// and are less than p^2 
			// are already marked. 
			for (int i = p * p; i <= N; i += p) 
				check[i] = false; 
		} 
	} 
} 

// A Tree node 
struct Node { 
	int key; 
	struct Node *left, *right; 
}; 

// Utility function to create a new node 
Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return (temp); 
} 

// function to check and print if 
// immediate children of a node 
// are its factors or not 
bool areChilrenPrimeFactors(struct Node* parent, 
							struct Node* a, 
							struct Node* b) 
{ 
	if (prime[a->key] && prime[b->key] 
		&& (parent->key % a->key == 0 
			&& parent->key % b->key == 0)) 
		return true; 
	else
		return false; 
} 

// Function to get the count of full Nodes in 
// a binary tree 
unsigned int getCount(struct Node* node) 
{ 
	// If tree is empty 
	if (!node) 
		return 0; 
	queue<Node*> q; 

	// Initialize count of ful/l nodes 
	// having children as their factors 
	int count = 0; 

	// Do level order traversal 
	// starting from root 
	q.push(node); 
	while (!q.empty()) { 
		struct Node* temp = q.front(); 
		q.pop(); 

		if (temp->left && temp->right) { 
			if (areChilrenPrimeFactors( 
					temp, temp->left, 
					temp->right)) 
				count++; 
		} 

		if (temp->left != NULL) 
			q.push(temp->left); 
		if (temp->right != NULL) 
			q.push(temp->right); 
	} 
	return count; 
} 

// Function to find total no of nodes 
// In a given binary tree 
int findSize(struct Node* node) 
{ 
	// Base condition 
	if (node == NULL) 
		return 0; 

	return 1 
		+ findSize(node->left) 
		+ findSize(node->right); 
} 

// Driver Code 
int main() 
{ 
	/*	 10 
			/ \ 
		2	 5 
			/ \ 
			18 12 
			/ \ / \ 
			2 3 3 2 
					/ 
					7 
	*/

	// Create Binary Tree as shown 
	Node* root = newNode(10); 

	root->left = newNode(2); 
	root->right = newNode(5); 

	root->right->left = newNode(18); 
	root->right->right = newNode(12); 

	root->right->left->left = newNode(2); 
	root->right->left->right = newNode(3); 
	root->right->right->left = newNode(3); 
	root->right->right->right = newNode(2); 
	root->right->right->right->left = newNode(7); 

	// To save all prime numbers 
	SieveOfEratosthenes(); 

	// Print all nodes having 
	// children as their factors 
	cout << getCount(root) << endl; 

	return 0; 
} 
