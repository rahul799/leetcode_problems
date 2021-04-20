Maximum product of a triplet (subsequence of size 3) in array



https://practice.geeksforgeeks.org/problems/three-great-candidates/0
Solution
https://www.geeksforgeeks.org/find-maximum-product-of-a-triplet-in-array/


Given an integer array, find a maximum product of a triplet in array.

Examples:

Input:  [10, 3, 5, 6, 20]
Output: 1200
Multiplication of 10, 6 and 20
 
Input:  [-10, -3, -5, -6, -20]
Output: -90

Input:  [1, -4, 3, -6, 7, 0]
Output: 168



 Approach 4: O(n) Time, O(1) Space

Scan the array and compute Maximum, second maximum and third maximum element present in the array.
Scan the array and compute Minimum and second minimum element present in the array.
Return the maximum of product of Maximum, second maximum and third maximum and product of Minimum, second minimum and Maximum element.


// A O(n) C++ program to find maximum product pair in 
// an array. 
#include <bits/stdc++.h> 
using namespace std; 

/* Function to find a maximum product of a triplet 
in array of integers of size n */
int maxProduct(int arr[], int n) 
{ 
	// if size is less than 3, no triplet exists 
	if (n < 3) 
		return -1; 

	// Initialize Maximum, second maximum and third 
	// maximum element 
	int maxA = INT_MIN, maxB = INT_MIN, maxC = INT_MIN; 

	// Initialize Minimum and second mimimum element 
	int minA = INT_MAX, minB = INT_MAX; 

	for (int i = 0; i < n; i++) 
	{ 
		// Update Maximum, second maximum and third 
		// maximum element 
		if (arr[i] > maxA) 
		{ 
			maxC = maxB; 
			maxB = maxA; 
			maxA = arr[i]; 
		} 

		// Update second maximum and third maximum element 
		else if (arr[i] > maxB) 
		{ 
			maxC = maxB; 
			maxB = arr[i]; 
		} 

		// Update third maximum element 
		else if (arr[i] > maxC) 
			maxC = arr[i]; 

		// Update Minimum and second mimimum element 
		if (arr[i] < minA) 
		{ 
			minB = minA; 
			minA = arr[i]; 
		} 

		// Update second mimimum element 
		else if(arr[i] < minB) 
			minB = arr[i]; 
	} 

	return max(minA * minB * maxA, 
			maxA * maxB * maxC); 
} 

// Driver program to test above function 
int main() 
{ 
	int arr[] = { 1, -4, 3, -6, 7, 0 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	int max = maxProduct(arr, n); 

	if (max == -1) 
		cout << "No Triplet Exists"; 
	else
		cout << "Maximum product is " << max; 

	return 0; 
} 



Approach 2: O(n) Time, O(n) Space

Construct four auxiliary arrays leftMax[], rightMax[], leftMin[] and rightMin[] of same size as input array.
Fill leftMax[], rightMax[], leftMin[] and rightMin[] in below manner.
leftMax[i] will contain maximum element on left of arr[i] excluding arr[i]. For index 0, left will contain -1.
leftMin[i] will contain minimum element on left of arr[i] excluding arr[i]. For index 0, left will contain -1.
rightMax[i] will contain maximum element on right of arr[i] excluding arr[i]. For index n-1, right will contain -1.
rightMin[i] will contain minimum element on right of arr[i] excluding arr[i]. For index n-1, right will contain -1.
For all array indexes i except first and last index, compute maximum of arr[i]*x*y where x can be leftMax[i] or leftMin[i] and y can be rightMax[i] or rightMin[i].
Return the maximum from step 3.




// A C++ program to find a maximum product of a triplet 
// in array of integers 
#include <bits/stdc++.h> 
using namespace std; 

/* Function to find a maximum product of a triplet 
in array of integers of size n */
int maxProduct(int arr[], int n) 
{ 
	// if size is less than 3, no triplet exists 
	if (n < 3) 
		return -1; 

	// Construct four auxiliary vectors 
	// of size n and initailize them by -1 
	vector<int> leftMin(n, -1); 
	vector<int> rightMin(n, -1); 
	vector<int> leftMax(n, -1); 
	vector<int> rightMax(n, -1); 

	// will contain max product 
	int max_product = INT_MIN; 

	// to store maximum element on left of array 
	int max_sum = arr[0]; 

	// to store minimum element on left of array 
	int min_sum = arr[0]; 

	// leftMax[i] will contain max element 
	// on left of arr[i] excluding arr[i]. 
	// leftMin[i] will contain min element 
	// on left of arr[i] excluding arr[i]. 
	for (int i = 1; i < n; i++) 
	{ 
		leftMax[i] = max_sum; 
		if (arr[i] > max_sum) 
			max_sum = arr[i]; 

		leftMin[i] = min_sum; 
		if (arr[i] < min_sum) 
			min_sum = arr[i]; 
	} 

	// reset max_sum to store maximum element on 
	// right of array 
	max_sum = arr[n - 1]; 

	// reset min_sum to store minimum element on 
	// right of array 
	min_sum = arr[n - 1]; 

	// rightMax[i] will contain max element 
	// on right of arr[i] excluding arr[i]. 
	// rightMin[i] will contain min element 
	// on right of arr[i] excluding arr[i]. 
	for (int j = n - 2; j >= 0; j--) 
	{ 
		rightMax[j] = max_sum; 
		if (arr[j] > max_sum) 
			max_sum = arr[j]; 

		rightMin[j] = min_sum; 
		if (arr[j] < min_sum) 
			min_sum = arr[j]; 
	} 

	// For all array indexes i except first and 
	// last, compute maximum of arr[i]*x*y where 
	// x can be leftMax[i] or leftMin[i] and 
	// y can be rightMax[i] or rightMin[i]. 
	for (int i = 1; i < n - 1; i++) 
	{ 
		int max1 = max(arr[i] * leftMax[i] * rightMax[i], 
					arr[i] * leftMin[i] * rightMin[i]); 

		int max2 = max(arr[i] * leftMax[i] * rightMin[i], 
					arr[i] * leftMin[i] * rightMax[i]); 

		max_product = max(max_product, max(max1, max2)); 
	} 

	return max_product; 
} 

// Driver program to test above functions 
int main() 
{ 
	int arr[] = { 1, 4, 3, -6, -7, 0 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	int max = maxProduct(arr, n); 

	if (max == -1) 
		cout << "No Triplet Exists"; 
	else
		cout << "Maximum product is " << max; 

	return 0; 
} 

