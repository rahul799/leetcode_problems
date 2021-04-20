
Maximum Length Bitonic Subarray | Set 1 (O(n) time and O(n) space)

Given an array A[0 … n-1] containing n positive integers, a subarray A[i … j] is bitonic if there is a k with i <= k <= j such that A[i] <= A[i + 1] … = A[k + 1] >= .. A[j – 1] > = A[j]. Write a function that takes an array as argument and returns the length of the maximum length bitonic subarray.
Expected time complexity of the solution is O(n)

Simple Examples
1) A[] = {12, 4, 78, 90, 45, 23}, the maximum length bitonic subarray is {4, 78, 90, 45, 23} which is of length 5.

2) A[] = {20, 4, 1, 2, 3, 4, 2, 10}, the maximum length bitonic subarray is {1, 2, 3, 4, 2} which is of length 5.

Extreme Examples
1) A[] = {10}, the single element is bitnoic, so output is 1.

2) A[] = {10, 20, 30, 40}, the complete array itself is bitonic, so output is 4



// C++ program to find length of 
// the longest bitonic subarray 
#include <bits/stdc++.h> 
using namespace std; 

int bitonic(int arr[], int n) 
{ 
	// Length of increasing subarray 
	// ending at all indexes 
	int inc[n]; 
	
	// Length of decreasing subarray 
	// starting at all indexes 
	int dec[n]; 
	int i, max; 

	// length of increasing sequence 
	// ending at first index is 1 
	inc[0] = 1; 

	// length of increasing sequence 
	// starting at first index is 1 
	dec[n-1] = 1; 

	// Step 1) Construct increasing sequence array 
	for (i = 1; i < n; i++) 
	inc[i] = (arr[i] >= arr[i-1])? inc[i-1] + 1: 1; 

	// Step 2) Construct decreasing sequence array 
	for (i = n-2; i >= 0; i--) 
	dec[i] = (arr[i] >= arr[i+1])? dec[i+1] + 1: 1; 

	// Step 3) Find the length of 
	// maximum length bitonic sequence 
	max = inc[0] + dec[0] - 1; 
	for (i = 1; i < n; i++) 
		if (inc[i] + dec[i] - 1 > max) 
			max = inc[i] + dec[i] - 1; 

	return max; 
} 

/* Driver code */
int main() 
{ 
	int arr[] = {12, 4, 78, 90, 45, 23}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "nLength of max length Bitnoic Subarray is " << bitonic(arr, n); 
	return 0; 
} 

// This is code is contributed by rathbhupendra 
