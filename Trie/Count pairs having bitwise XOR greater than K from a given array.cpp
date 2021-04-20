

https://www.geeksforgeeks.org/count-pairs-having-bitwise-xor-greater-than-k-from-a-given-array/




Count pairs having bitwise XOR greater than K from a given array
Last Updated : 29 Dec, 2020
Given an array arr[]of size N and an integer K, the task is to count the number of pairs from the given array such that the Bitwise XOR of each pair is greater than K. 

 Examples:

Input: arr = {1, 2, 3, 5} , K = 2 
Output: 4 
Explanation: 
Bitwise XOR of all possible pairs that satisfy the given conditions are: 
arr[0] ^ arr[1] = 1 ^ 2 = 3 
arr[0] ^ arr[3] = 1 ^ 5 = 4 
arr[1] ^ arr[3] = 2 ^ 5 = 7 
arr[0] ^ arr[3] = 3 ^ 5 = 6 
Therefore, the required output is 4. 

Input: arr[] = {3, 5, 6,8}, K = 2 
Output: 6 
 

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Naive Approach: The simplest approach to solve this problem is to traverse the given array and generate all possible pairs of the given array and for each pair, check if bitwise XOR of the pair is greater than K or not. If found to be true, then increment the count of pairs having bitwise XOR greater than K. Finally, print the count of such pairs obtained.



Time Complexity:O(N2)
Auxiliary Space:O(1)

Efficient Approach: The problem can be solved using Trie. The idea is to iterate over the given array and for each array element, count the number of elements present in the Trie whose bitwise XOR with the current element is greater than K and insert the binary representation of the current element into the Trie. Finally, print the count of pairs having bitwise XOR greater than K. Follow the steps below to solve the problem:

Create a Trie having root node, say root to store the binary representation of each element of the given array.
Traverse the given array, and count the number of elements present in the Trie whose bitwise XOR with the current element is greater than K and insert the binary representation of the current element.
Finally, print the count of pairs that satisfies the given condition.



// C++ program to implement
// the above approach

#include <bits/stdc++.h>
using namespace std;

// Structure of Trie
struct TrieNode
{
	// Stores binary represention
	// of numbers
	TrieNode *child[2];

	// Stores count of elements
	// present in a node 
	int cnt;
	
	// Function to initialize
	// a Trie Node
	TrieNode() {
		child[0] = child[1] = NULL;
		cnt = 0;
	}
};


// Function to insert a number into Trie
void insertTrie(TrieNode *root, int N) {
	
	// Traverse binary representation of X.
	for (int i = 31; i >= 0; i--) {
		
		// Stores ith bit of N
		bool x = (N) & (1 << i);
		
		// Check if an element already
		// present in Trie having ith bit x.
		if(!root->child[x]) {
			
			// Create a new node of Trie.
			root->child[x] = new TrieNode();
		}
		
		// Update count of elements
		// whose ith bit is x
		root->child[x]->cnt+= 1;
		
		// Update root.
		root= root->child[x]; 
	}
}


// Function to count elements
// in Trie whose XOR with N
// exceeds K
int cntGreater(TrieNode * root, 
				int N, int K)
{
	
	// Stores count of elements
	// whose XOR with N exceeding K
	int cntPairs = 0;
	
	// Traverse binary representation
	// of N and K in Trie
	for (int i = 31; i >= 0 && 
					root; i--) {
									
		// Stores ith bit of N						 
		bool x = N & (1 << i);
		
		// Stores ith bit of K
		bool y = K & (1 << i);
		
		// If the ith bit of K is 1
		if (y) {
			
			// Update root.
			root = 
				root->child[1 - x];
		}
		
		// If the ith bit of K is 0
		else{
			
			// If an element already 
			// present in Trie having
			// ith bit (1 - x)
			if (root->child[1 - x]) {
				
				// Update cntPairs
				cntPairs += 
				root->child[1 - x]->cnt;
			}
			
			// Update root.
			root = root->child[x];
		}
	}
	return cntPairs;
}

// Function to count pairs that 
// satisfy the given conditions.
int cntGreaterPairs(int arr[], int N,
							int K) {
	
	// Create root node of Trie
	TrieNode *root = new TrieNode();
	
	// Stores count of pairs that
	// satisfy the given conditions
	int cntPairs = 0;
	
	// Traverse the given array.
	for(int i = 0;i < N; i++){
		
		// Update cntPairs
		cntPairs += cntGreater(root, 
						arr[i], K);
		
		// Insert arr[i] into Trie.
		insertTrie(root, arr[i]);
	}
	return cntPairs;
}

//Driver code
int main()
{
	int arr[] = {3, 5, 6, 8};
	int K= 2;
	int N = sizeof(arr) / sizeof(arr[0]);
	
	cout<<cntGreaterPairs(arr, N, K);
}
