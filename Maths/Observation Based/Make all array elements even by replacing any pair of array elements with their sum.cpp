


Make all array elements even by replacing any pair of array elements with their sum




Make all array elements even by replacing any pair of array elements with their sum
Last Updated: 21-12-2020
Given an array arr[] consisting of N positive integers, the task is to make all array elements even by replacing any pair of array elements with their sum.

Examples:

Input: arr[] = {5, 6, 3, 7, 20}
Output: 3
Explanation:
Operation 1: Replace arr[0] and arr[2] by their sum ( = 5 + 3 = 8) modifies arr[] to {8, 6, 8, 7, 20}.
Operation 2: Replace arr[2] and arr[3] by their sum ( = 7 + 8 = 15) modifies arr[] to {8, 6, 15, 15, 20}.
Operation 3: Replace arr[2] and arr[3] by their sum ( = 15 + 15 = 30) modifies arr[] to {8, 6, 30, 30, 20}.

Input: arr[] = {2, 4, 16, 8, 7, 9, 3, 1}
Output: 2

Approach: The idea is to keep replacing two odd array elements by their sum until all array elements are even. Follow the steps below to solve the problem:



Initialize a variable, say moves, to store the minimum number of replacements required.
Calculate the total number of odd elements present in the given array and store it in a variable, say cnt.
If the value of cnt is odd, then print (cnt / 2 + 2) as the result. Otherwise, print cnt / 2 as the result.






// C++ program for the above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Function to find the minimum number 
// of replacements required to make 
// all array elements even 
void minMoves(int arr[], int N) 
{ 
	// Stores the count of odd elements 
	int odd_element_cnt = 0; 

	// Traverse the array 
	for (int i = 0; i < N; i++) { 

		// Increase count of odd elements 
		if (arr[i] % 2 != 0) { 
			odd_element_cnt++; 
		} 
	} 

	// Store number of replacements required 
	int moves = (odd_element_cnt) / 2; 

	// Two extra moves will be required 
	// to make the last odd element even 
	if (odd_element_cnt % 2 != 0) 
		moves += 2; 

	// Print the minimum replacements 
	cout << moves; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { 5, 6, 3, 7, 20 }; 
	int N = sizeof(arr) / sizeof(arr[0]); 

	// Function call 
	minMoves(arr, N); 

	return 0; 
} 
