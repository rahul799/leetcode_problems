

https://www.geeksforgeeks.org/maximum-sum-of-even-indexed-elements-obtained-by-right-shift-on-an-even-sized-subarray/

Maximum sum of even indexed elements obtained by right shift on an even sized subarray

Given an array arr[], we need to find the maximum sum of the even indexed elements that can be obtained by performing right shift operation on any sub-array of even length by 1.

Examples:

Input: arr[] = {5, 1, 3, 4, 5, 6}
Output: 15
Explanation:
We can perform a right shift on index 2 to 5 then resulting array is:
arr[] = {5, 1, 6, 3, 4, 5}
Sum of elements at even indexes = 5 + 6 + 4 = 15

Input: arr[] = {7, 9, 1, 8, 3, 10, 4, 12}
Output: 39
Explanation:
We can perform a right shift on index 0 to 7 then resulting array is:
arr[] = {12, 7, 9, 1, 8, 3, 10, 4}
Sum of elements at even indexes = 12 + 9 + 8 + 10 = 39

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Naive Approach: The naive approach is to right shift every possible subarray of even length by one and find the sum of elements at even index for all the array formed after every possible subarray shifts. The maximum sum in all the array is the required result.



	
We will use the above concepts to solve this problem. Below are the steps:

Create two arrays(say arr1[] and arr2[]) such that arr1[] will store the consecutive difference of the element in the array arr[] as:
{(a[1] – a[0]), (a[3] – a[2]), . . ., (a[n]-a[n-1])}
And arr2[] will store the consecutive difference of the element in the array arr[] as:

{(a[1] – a[2]), (a[3] – a[4]), . . ., (a[n-1]-a[n])}
Then find the maximum subarray sum using Kadane’s Algorithm in the above two array formed.
Now the maximum sum is the sum of element at even indexes in the original array(arr[]) + maximum subarray sum of the two arrays arr1[] and arr2[].
	
	
	


// C++ program for the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Kadane's Algorithm to find 
// the maximum sum sub array 
int kadane(vector<int> v) 
{ 
	int maxSoFar = 0; 
	int maxEndingHere = 0; 

	// Iterate array v 
	for (int i = 0; i < v.size(); i++) { 

		maxEndingHere += v[i]; 

		// Update the maximum 
		maxSoFar = max(maxEndingHere, 
					maxSoFar); 

		// Update maxEndingHere to 0 if it 
		// is less than 0 
		maxEndingHere 
			= max(maxEndingHere, 0); 
	} 

	// Return maximum sum 
	return maxSoFar; 
} 

// Function to find the sum 
// of even indexed elements 
// after modification in array. 
int sumOfElements(int* arr, int n) 
{ 
	int sum = 0; 

	// Find initial sum of 
	// even indexed elements 
	for (int i = 0; i < n; i++) { 
		if (i % 2 == 0) 
			sum += arr[i]; 
	} 

	// Create two vectors to store 
	// the consecutive differences 
	// of elements 
	vector<int> v1; 
	vector<int> v2; 

	for (int i = 1; i < n; i += 2) { 

		v1.push_back(arr[i] 
					- arr[i - 1]); 

		if (i + 1 < n) { 
			v2.push_back(arr[i] 
						- arr[i + 1]); 
		} 
	} 

	// Find the maximum sum subarray 
	int option1 = kadane(v1); 
	int option2 = kadane(v2); 

	// Add the maximum value 
	// to initial sum 
	int ans = sum + max(option1, 
						option2); 

	// Return the answer 
	return ans; 
} 

// Driver Code 
int main() 
{ 
	// Given array arr[] 
	int arr[] = { 5, 1, 3, 4, 5, 6 }; 

	int N = sizeof(arr) / sizeof(arr[0]); 

	// Function Call 
	cout << sumOfElements(arr, N); 
	return 0; 
} 
