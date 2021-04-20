
https://www.geeksforgeeks.org/maximum-sum-possible-for-a-sub-sequence-such-that-no-two-elements-appear-at-a-distance-k-in-the-array/

Given an array of n non-negative numbers, the task is to find the minimum sum of elements (picked from the array) such that at least one element is picked out of every 3 consecutive elements in the array.

Examples :

Input : arr[] = {1, 2, 3}
Output : 1

Input : arr[] = {1, 2, 3, 6, 7, 1}
Output : 4
We pick 3 and 1  (3 + 1 = 4)
Note that there are following subarrays
of three consecutive elements
{1, 2, 3}, {2, 3, 6}, {3, 6, 7} and {6, 7, 1}
We have picked one element from every subarray.

Input : arr[] = {1, 2, 3, 6, 7, 1, 8, 6, 2,
                 7, 7, 1}
Output : 7
The result is obtained as sum of 3 + 1 + 2 + 1

Let sum(i) be the minimum possible sum when arr[i] is part of a solution sum (not necessarily result) and is last picked element. Then our result is minimum of sum(n-1), 
sum(n-2) and sum(n-3) [We must pick at least one of the last three elements].
We can recursively compute sum(i) as sum of arr[i] and minimum(sum(i-1), sum(i-2), sum(i-3)). Since there are overlapping subproblems in recursive structure of problem, we 
an use Dynamic Programming to solve this problem.

Below is the implementation of above idea.

// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the maximum sum possible 
int maxSum(int* arr, int k, int n) 
{ 
	if (n == 0) 
		return 0; 
	if (n == 1) 
		return arr[0]; 
	if (n == 2) 
		return max(arr[0], arr[1]); 

	// dp[i] represent the maximum sum so far 
	// after reaching current position i 
	int dp[n]; 

	// Initialize dp[0] 
	dp[0] = arr[0]; 

	// Initialize the dp values till k since any 
	// two elements included in the sub-sequence 
	// must be atleast k indices apart, and thus 
	// first element and second element 
	// will be k indices apart 
	for (int i = 1; i <= k; i++) 
		dp[i] = max(arr[i], dp[i - 1]); 

	// Fill remaining positions 
	for (int i = k + 1; i < n; i++) 
		dp[i] = max(arr[i], dp[i - (k + 1)] + arr[i]); 

	// Return the maximum sum 
	int max = *(std::max_element(dp, dp + n)); 
	return max; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 6, 7, 1, 3, 8, 2, 4 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 2; 
	cout << maxSum(arr, k, n); 

	return 0; 
} 
