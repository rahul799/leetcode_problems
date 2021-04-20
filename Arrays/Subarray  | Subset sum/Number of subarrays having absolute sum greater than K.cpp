https://www.geeksforgeeks.org/number-of-subarrays-having-absolute-sum-greater-than-k-set-2/

Number of subarrays having absolute sum greater than K





Given an integer array arr[] of length N consisting of both positive and negative integers, the task is to find the number of sub-arrays with the absolute value of sum greater than a given positive number K.

Examples:

Input : arr[] = {-1, 0, 1}, K = 0
Output : 4
All possible sub-arrays and there total sum:
{-1} = -1
{0} = 0
{1} = 1
{-1, 0} = -1
{0, 1} = 1
{-1, 0, 1} = 0
Thus, 4 sub-arrays have absolute
value of sum greater than 4.

Input : arr[] = {2, 3, 4}, K = 4
Output : 3





Create a prefix-sum array of the given array.
Sort the prefix-sum array.
Create variable ans, find the number of elements in the prefix-sum array with value lesser than -K or greater than K, and initialize ans with this value.
Now, iterate the sorted prefix-sum array and for every index i, find the index of the first element with value greater than arr[i] + K. Let’s say this index is j.
Then ans can be updated as ans += N – j as the number of elements in the prefix-sum array larger than the value of arr[i]+K will be equal to N – j.
To find the index j, perform binary-search on prefix-sum array. Specifically, find the upper-bound on the value of prefix-sum[i] + k.


// C++ implementation of the above approach 
#include <bits/stdc++.h> 
#define maxLen 30 
using namespace std; 

// Function to find required value 
int findCnt(int arr[], int n, int k) 
{ 
	// Variable to store final answer 
	int ans = 0; 

	// Loop to find prefix-sum 
	for (int i = 1; i < n; i++) { 
		arr[i] += arr[i - 1]; 
		if (arr[i] > k or arr[i] < -1 * k) 
			ans++; 
	} 

	if (arr[0] > k || arr[0] < -1 * k) 
		ans++; 

	// Sorting prefix-sum array 
	sort(arr, arr + n); 

	// Loop to find upper_bound 
	// for each element 
	for (int i = 0; i < n; i++) 
		ans += n - 
	(upper_bound(arr, arr + n, arr[i] + k) - arr); 

	// Returning final answer 
	return ans; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { -1, 4, -5, 6 }; 
	int n = sizeof(arr) / sizeof(int); 
	int k = 0; 

	// Function to find required value 
	cout << findCnt(arr, n, k); 
} 
