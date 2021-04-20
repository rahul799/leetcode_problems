


https://www.geeksforgeeks.org/minimize-the-maximum-difference-between-the-heights/




Minimize the maximum difference between the heights
Last Updated: 10-07-2019
Given heights of n towers and a value k. We need to either increase or decrease height of every tower by k (only once) where k > 0. The task is to minimize
the difference between the heights of the longest and the shortest tower after modifications, and 
output this difference.



// C++ program to find the minimum possible 
// difference between maximum and minimum 
// elements when we have to add/subtract 
// every number by k 
#include <bits/stdc++.h> 
using namespace std; 

// Modifies the array by subtracting/adding 
// k to every element such that the difference 
// between maximum and minimum is minimized 
int getMinDiff(int arr[], int n, int k) 
{ 
	if (n == 1) 
	return 0; 

	// Sort all elements 
	sort(arr, arr+n); 

	// Initialize result 
	int ans = arr[n-1] - arr[0]; 

	// Handle corner elements 
	int small = arr[0] + k; 
	int big = arr[n-1] - k; 
	if (small > big) 
	swap(small, big); 

	// Traverse middle elements 
	for (int i = 1; i < n-1; i ++) 
	{ 
		int subtract = arr[i] - k; 
		int add = arr[i] + k; 

		// If both subtraction and addition 
		// do not change diff 
		if (subtract >= small || add <= big) 
			continue; 

		// Either subtraction causes a smaller 
		// number or addition causes a greater 
		// number. Update small or big using 
		// greedy approach (If big - subtract 
		// causes smaller diff, update small 
		// Else update big) 
		if (big - subtract <= add - small) 
			small = subtract; 
		else
			big = add; 
	} 

	return min(ans, big - small); 
} 

// Driver function to test the above function 
int main() 
{ 
	int arr[] = {4, 6}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	int k = 10; 
	cout << "\nMaximum difference is "
		<< getMinDiff(arr, n, k); 
	return 0; 
} 
