Given an array of n integers, each integer is greater than 1. The task is to find the number of Full binary tree from the given integers, such that each non-node leaf node value is the product of its children value. 
Given that, each integer can be used multiple times in a full binary tree.
Examples:

Input : arr[] = { 2, 3, 4, 6 }.
Output : 7
There can be 7 full binary tree with the given product property.

// Four trees with single nodes
2  3  4  6

// Three trees with three nodes
  4   ,
 / \
2   2

  6    ,
 / \
2   3

  6
 / \
3   2  

We find maximum value in given array and create an array to store presence of elements in this array. The idea is, for all multiples of each integer less than the maximum value of the array, try to make full binary tree if the multiple is present in the array.
Observe that for any full binary tree with given property, the smaller values will always be at the last level. So, try to find the number of such full binary tree from the minimum value of the array to maximum value of the array.

Algorithm to solve the problem:
1. Initialize possible number of such full binary tree for each element equal to 1. Since single node also contribute to the answer.
2. For each element of the array, arr[i], from minimum value to maximum value of array.
……a) For each multiple of arr[i], find if multiple is present or not.
……b) If yes, then the number of such possible full binary tree for multiple of arr[i], say m, is equal to the product of the number of such possible full binary tree of arr[i] and number of such possible full binary tree of arr[i]/m.












// C++ program to find number of full binary tree 
// such that each node is product of its children. 
#include<bits/stdc++.h> 
using namespace std; 

// Return the number of all possible full binary 
// tree with given product property. 
int numoffbt(int arr[], int n) 
{ 
	// Finding the minimum and maximum values in 
	// given array. 
	int maxvalue = INT_MIN, minvalue = INT_MAX; 
	for (int i = 0; i < n; i++) 
	{ 
		maxvalue = max(maxvalue, arr[i]); 
		minvalue = min(minvalue, arr[i]); 
	} 

	int mark[maxvalue + 2]; 
	int value[maxvalue + 2]; 
	memset(mark, 0, sizeof(mark)); 
	memset(value, 0, sizeof(value)); 

	// Marking the presence of each array element 
	// and initialising the number of possible 
	// full binary tree for each integer equal 
	// to 1 because single node will also 
	// contribute as a full binary tree. 
	for (int i = 0; i < n; i++) 
	{ 
		mark[arr[i]] = 1; 
		value[arr[i]] = 1; 
	} 

	// From minimum value to maximum value of array 
	// finding the number of all possible Full 
	// Binary Trees. 
	int ans = 0; 
	for (int i = minvalue; i <= maxvalue; i++) 
	{ 
		// Find if value present in the array 
		if (mark[i]) 
		{ 
			// For each multiple of i, less than 
			// equal to maximum value of array 
			for (int j = i + i; 
				j <= maxvalue && j/i <= i; j += i) 
			{ 
				// If multiple is not present in the 
				// array then continue. 
				if (!mark[j]) 
					continue; 

				// Finding the number of possible Full 
				// binary trees for multiple j by 
				// multiplying number of possible Full 
				// binary tree from the number i and 
				// number of possible Full binary tree 
				// from i/j. 
				value[j] = value[j] + (value[i] * value[j/i]); 

				// Condition for possiblity when left 
				// chid became right child and vice versa. 
				if (i != j/i) 
					value[j] = value[j] + (value[i] * value[j/i]); 
			} 
		} 

		ans += value[i]; 
	} 

	return ans; 
} 

// Driven Program 
int main() 
{ 
	int arr[] = { 2, 3, 4, 6 }; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	cout << numoffbt(arr, n) << endl; 
	return 0; 
} 
