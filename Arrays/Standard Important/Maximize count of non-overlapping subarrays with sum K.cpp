Maximize count of non-overlapping subarrays with sum K

Given an array arr[] and an integer K, the task is to print the maximum number of non-overlapping subarrays with a sum equal to K.

Examples:

Input: arr[] = {-2, 6, 6, 3, 5, 4, 1, 2, 8}, K = 10
Output: 3
Explanation: All possible non-overlapping subarrays with sum K(= 10) are {-2, 6, 6}, {5, 4, 1}, {2, 8}. Therefore, the required count is 3.

Input: arr[] = {1, 1, 1}, K = 2
Output: 1

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Approach: The problem can be solved using the concept of prefix sum. Follow the below steps to solve the problem:



Initialize a set to store all the prefix sums obtained up to the current element.
Initialize variables prefixSum and res, to store the prefix sum of the current subarray and the count of subarrays with a sum equal to K respectively.
Iterate over the array and for each array element, update prefixSum by adding to it the current element. Now, check if the value prefixSum – K is already present in the set or 
not. If found to be true, increment res, clear the set, and reset the value of prefixSum.
Repeat the above steps until the entire array is traversed. Finally, print the value of res.



// C++ Program to implement 
// the above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Function to count the maximum 
// number of subarrays with sum K 
int CtSubarr(int arr[], int N, int K) 
{ 

	// Stores all the distinct 
	// prefixSums obtained 
	unordered_set<int> st; 

	// Stores the prefix sum 
	// of the current subarray 
	int prefixSum = 0; 

	st.insert(prefixSum); 

	// Stores the count of 
	// subarrays with sum K 
	int res = 0; 

	for (int i = 0; i < N; i++) { 
		prefixSum += arr[i]; 

		// If a subarray with sum K 
		// is already found 
		if (st.count(prefixSum - K)) { 

			// Increase count 
			res += 1; 

			// Reset prefix sum 
			prefixSum = 0; 

			// Clear the set 
			st.clear(); 
			st.insert(0); 
		} 

		// Insert the prefix sum 
		st.insert(prefixSum); 
	} 
	return res; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { -2, 6, 6, 3, 5, 4, 1, 2, 8 }; 
	int N = sizeof(arr) / sizeof(arr[0]); 
	int K = 10; 
	cout << CtSubarr(arr, N, K); 
}
