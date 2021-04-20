Maximum MEX from all subarrays of length K
Last Updated: 27-10-2020
Given an array arr[] consisting of N distinct integers and an integer K, the task is to find the maximum MEX from all subarrays of length K.

https://www.geeksforgeeks.org/maximum-mex-from-all-subarrays-of-length-k/	
	
	
	
The MEX is the smallest positive integer that is not present in the array.

Examples:

Input: arr[] = {3, 2, 1, 4}, K = 2
Output: 3
Explanation:
All subarrays having length 2 are {3, 2}, {2, 1}, {1, 4}.
In subarray {3, 2}, the smallest positive integer which is not present is 1.
In subarray {2, 1}, the smallest positive integer which is not present is 3.
In subarray {1, 4}, the smallest positive integer which is not present is 2.

Input: arr[] = {6, 1, 3, 2, 4}, K = 3
Output: 4
Explanation:
All subarrays having length 3 are {6, 1, 3}, {1, 3, 2}, {3, 2, 4}
In subarray {6, 1, 3}, the smallest positive integer which is not present is 2.
In subarray {1, 3, 2}, the smallest positive integer which is not present is 4.
In subarray {3, 2, 4}, the smallest positive integer which is not present is 1.


Naive Approach: The simplest approach is to generate all subarrays of length K and find MEX of every subarray. After finding all the MEX, print the maximum of those obtained.

Time Complexity: O(K * N2)
Auxiliary Space: O(1)

Efficient Approach: To optimize the above approach, the idea is to use the data structure Set and Sliding Window Technique. Follow the steps below to solve the problem:

Initialize a set S to store values that are not present in the current subarray and initially insert 1 to N + 1 number in it because initially, the size of the window is 0.
Traverse over the range [0, K – 1] and erase arr[i] from the set, the first element of the set is MEX of subarray starting from index 0 and length K, initialize a variable mex and store this value in mex.
Now iterate from K to N – 1 and insert arr[i] to set and erase arr[i – K] from it and update mex = max(mex, first element of set).
After the above steps, print mex as maximum MEX among subarray having length K.







// C++ program for the above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Function to return maximum MEX of 
// all K length subarray 
void maxMEX(int arr[], int N, int K) 
{ 
	// Stores element from 1 to N + 1 
	// is nor present in subarray 
	set<int> s; 

	// Store number 1 to N + 1 in set s 
	for (int i = 1; i <= N + 1; i++) 
		s.insert(i); 

	// Find the MEX of K length subarray 
	// starting from index 0 
	for (int i = 0; i < K; i++) 
		s.erase(arr[i]); 

	int mex = *(s.begin()); 

	// Find the MEX of all subarray of 
	// length K by erasing arr[i] 
	// and inserting arr[i-K] 
	for (int i = K; i < N; i++) { 
		s.erase(arr[i]); 

		s.insert(arr[i - K]); 

		// Store first element of set 
		int firstElem = *(s.begin()); 

		// Updating mex 
		mex = max(mex, firstElem); 
	} 

	// Print maximum MEX of all K 
	// length subarray 
	cout << mex << ' '; 
} 

// Driver Code 
int main() 
{ 
	// Given array 
	int arr[] = { 3, 2, 1, 4 }; 

	// Given length of subarray 
	int K = 2; 

	// Size of the array 
	int N = sizeof(arr) / sizeof(arr[0]); 

	// Function Call 
	maxMEX(arr, N, K); 

	return 0; 
} 
