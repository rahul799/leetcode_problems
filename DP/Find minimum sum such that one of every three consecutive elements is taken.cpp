Find minimum sum such that one of every three consecutive elements is taken


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
Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
Let sum(i) be the minimum possible sum when arr[i] is part of a solution sum (not necessarily result) and is last picked element. Then our result is minimum of sum(n-1), 
sum(n-2) and sum(n-3) [We must pick at least one of the last three elements].
We can recursively compute sum(i) as sum of arr[i] and minimum(sum(i-1), sum(i-2), sum(i-3)). Since there are overlapping subproblems in recursive structure of problem, we 
can use Dynamic Programming to solve this problem.

Below is the implementation of above idea.


// A Dynamic Programming based C++ program to 
// find minimum possible sum of elements of array 
// such that an element out of every three 
// consecutive is picked. 
#include <iostream> 
using namespace std; 

// A utility function to find minimum of 
// 3 elements 
int minimum(int a, int b, int c) 
{ 
	return min(min(a, b), c); 
} 

// Returns minimum possible sum of elements such 
// that an element out of every three consecutive 
// elements is picked. 
int findMinSum(int arr[], int n) 
{ 
	// Create a DP table to store results of 
	// subproblems. sum[i] is going to store 
	// minimum possible sum when arr[i] is 
	// part of the solution. 
	int sum[n]; 

	// When there are less than or equal to 
	// 3 elements 
	sum[0] = arr[0]; 
	sum[1] = arr[1]; 
	sum[2] = arr[2]; 

	// Iterate through all other elements 
	for (int i=3; i<n; i++) 
	sum[i] = arr[i] + 
			minimum(sum[i-3], sum[i-2], sum[i-1]); 

	return minimum(sum[n-1], sum[n-2], sum[n-3]); 
} 

// Driver code 
int main() 
{ 
	int arr[] = {1, 2, 3, 20, 2, 10, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Min Sum is " << findMinSum(arr, n); 
	return 0; 
} 








