https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/

Given an array of integers. Find a peak element in it. An array element is a peak if it is NOT smaller than its neighbours. For corner elements, we need to consider only one neighbour.
Example:

Input: array[]= {5, 10, 20, 15}
Output: 20
The element 20 has neighbours 10 and 15,
both of them are less than 20.
 The idea is based on the technique of Binary Search to check if the middle element is the peak element or not. 
If the middle element is not the peak element, then check if the element on the right side is greater than the middle element 
then there is always a peak element on the right side. If the element on the left side is greater than the middle element then there 
is always a peak element on the left side. Form a recursion and the peak 
element can be found in log n time.


Algorithm:

Create two variables, l and r, initilize l = 0 and r = n-1
Iterate the steps below till l <= r, lowerbound is less than the upperbound
Check if the mid value or index mid = (l+r)/2, is the peak element or not, if yes then print the element and terminate.
Else if the element on the left side of the middle element is greater then check for peak element on the left side, i.e. update r = mid – 1
Else if the element on the right side of the middle element is greater then check for peak element on the right side, i.e. update l = mid + 1




// A C++ program to find a peak element 
// using divide and conquer 
#include <bits/stdc++.h> 
using namespace std; 

// A binary search based function 
// that returns index of a peak element 
int findPeakUtil(int arr[], int low, 
				int high, int n) 
{ 
	// Find index of middle element 
	// (low + high)/2 
	int mid = low + (high - low) / 2; 

	// Compare middle element with its 
	// neighbours (if neighbours exist) 
	if ((mid == 0 || arr[mid - 1] <= arr[mid]) && 
		(mid == n - 1 || arr[mid + 1] <= arr[mid])) 
		return mid; 

	// If middle element is not peak and its 
	// left neighbour is greater than it, 
	// then left half must have a peak element 
	else if (mid > 0 && arr[mid - 1] > arr[mid]) 
		return findPeakUtil(arr, low, (mid - 1), n); 

	// If middle element is not peak and its 
	// right neighbour is greater than it, 
	// then right half must have a peak element 
	else
		return findPeakUtil( 
			arr, (mid + 1), high, n); 
} 

// A wrapper over recursive function findPeakUtil() 
int findPeak(int arr[], int n) 
{ 
	return findPeakUtil(arr, 0, n - 1, n); 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { 1, 3, 20, 4, 1, 0 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Index of a peak point is "
		<< findPeak(arr, n); 
	return 0; 
} 

// This code is contributed by rathbhupendra 
