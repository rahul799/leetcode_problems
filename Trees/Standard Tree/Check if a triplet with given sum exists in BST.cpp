Check if a triplet with given sum exists in BST



Given a Binary Search Tree and a SUM. The task is to check if there exists any triplet(group of 3 elements) in the given BST with the given SUM.


Examples:

Input : SUM = 21
Output : YES
There exists a triplet (7, 3, 11) in the 
above given BST with sum 21.



It is known that elements in the inorder traversal of BST are sorted in increasing order. So, the idea is to do in order traversal on the given
BST and store the elements in a vector or array. Now the task reduces to check for a triplet with given sum in a sorted array.

Now to do this, start traversing the array and for every element A[i] check for a pair with sum (SUM – A[i]) in the remaining sorted array.

To do this:
1) Initialize two index variables to find the candidate 
   elements in the sorted array.
       (a) Initialize first to the leftmost index: l = 0
       (b) Initialize second  the rightmost index:  r = ar_size-1
2) Loop while l < r.
       (a) If (A[l] + A[r] == sum)  then return 1
       (b) Else if( A[l] + A[r] <  sum )  then l++
       (c) Else r--    
3) If no such candidates are found in the whole array, 
   return 0
   
   


// C++ program to check if a triplet with 
// given SUM exists in the BST or not 

#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int key; 
	struct Node *left, *right; 
}; 

// A utility function to create a new BST node 
struct Node* newNode(int item) 
{ 
	Node* temp = new Node; 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to do inorder traversal 
// of the BST and store values in a vector 
void inorder(Node* root, vector<int>& vec) 
{ 
	if (root != NULL) { 
		inorder(root->left, vec); 
		vec.push_back(root->key); 
		inorder(root->right, vec); 
	} 
} 


// Function to check if a triplet with given SUM 
// exists in the BST or not 
bool checkForTriplet(Node* root, int sum) 
{ 
	// Vector to store the inorder traversal 
	// of the BST 
	vector<int> vec; 

	// Call inorder() to do the inorder 
	// on the BST and store it in vec 
	inorder(root, vec); 

	// Now, check if any triplet with given sum 
	// exists in the BST or not 
	int l, r; 

	// Now fix the first element one by one and find the 
	// other two elements 
	for (int i = 0; i < vec.size() - 2; i++) { 

		// To find the other two elements, start two index 
		// variables from two corners of the array and move 
		// them toward each other 
		l = i + 1; // index of the first element in the 
		// remaining elements 

		// index of the last element 
		r = vec.size() - 1; 
		while (l < r) { 
			if (vec[i] + vec[l] + vec[r] == sum) { 

				return true; 
			} 
			else if (vec[i] + vec[l] + vec[r] < sum) 
				l++; 
			else // vec[i] + vec[l] + vec[r] > sum 
				r--; 
		} 
	} 

	// If we reach here, then no triplet was found 
	return false; 
} 

// Driver Code 
int main() 
{ 
	/* Let us create following BST 
		50 
		/	 \ 
	30	 70 
	/ \ / \ 
	20 40 60 80 */
	struct Node* root = NULL; 
	root = insert(root, 50); 
	insert(root, 30); 
	insert(root, 20); 
	insert(root, 40); 
	insert(root, 70); 
	insert(root, 60); 
	insert(root, 80); 

	int sum = 120; 

	if (checkForTriplet(root, sum)) 
		cout << "YES"; 
	else
		cout << "NO"; 

	return 0; 
} 
