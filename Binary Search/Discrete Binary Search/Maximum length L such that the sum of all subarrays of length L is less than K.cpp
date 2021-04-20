Maximum length L such that the sum of all subarrays of length L is less than K
Last Updated: 09-05-2020
Given an array of length N and an integer K. The task is to find the maximum length L such that all the subarrays of length L have sum of its elements less than K.

Examples:

Input: arr[] = {1, 2, 3, 4, 5}, K = 20
Output: 5
The only subarray of length 5 is the complete
array and (1 + 2 + 3 + 4 + 5) = 15 < 20.

Input: arr[] = {1, 2, 3, 4, 5}, K = 10
Output: 2



// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the maximum sum 
// in a subarray of size k 
int maxSum(int arr[], int n, int k) 
{ 
	// k must be greater 
	if (n < k) { 
		return -1; 
	} 

	// Compute sum of first window of size k 
	int res = 0; 
	for (int i = 0; i < k; i++) 
		res += arr[i]; 

	// Compute sums of remaining windows by 
	// removing first element of previous 
	// window and adding last element of 
	// current window. 
	int curr_sum = res; 
	for (int i = k; i < n; i++) { 
		curr_sum += arr[i] - arr[i - k]; 
		res = max(res, curr_sum); 
	} 

	return res; 
} 

// Function to return the length of subarray 
// Sum of all the subarray of this 
// length is less than or equal to K 
int solve(int arr[], int n, int k) 
{ 
	int max_len = 0, l = 0, r = n, m; 

	// Binary search from l to r as all the 
	// array elements are positive so that 
	// the maximum subarray sum is monotonically 
	// increasing 
	while (l < r) { 
		m = (l + r) / 2; 

		// Check if the subarray sum is 
		// greater than K or not 
		if (maxSum(arr, n, m) > k) 
			r = m; 
		else { 
			l = m + 1; 

			// Update the maximum length 
			max_len = m; 
		} 
	} 
	return max_len; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 1, 2, 3, 4 }; 
	int n = sizeof(arr) / sizeof(int); 
	int k = 7; 

	cout << solve(arr, n, k); 

	return 0; 
} 
