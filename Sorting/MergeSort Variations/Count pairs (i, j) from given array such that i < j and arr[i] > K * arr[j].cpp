
Count pairs (i, j) from given array such that i < j and arr[i] > K * arr[j]



Count pairs (i, j) from given array such that i < j and arr[i] > K * arr[j]
Last Updated: 17-12-2020
Given an array arr[] of length N and an integer K, the task is to count the number of pairs (i, j) such that i < j and arr[i] > K * arr[j].

Examples:

Input: arr[] = {5, 6, 2, 5}, K = 2
Output: 2
Explanation: The array consists of two such pairs:
(5, 2): Index of 5 and 2 are 0, 2 respectively. Therefore, the required conditions (0 < 2 and 5 > 2 * 2) are satisfied.
(6, 2): Index of 6 and 2 are 1, 2 respectively. Therefore, the required conditions (0 < 2 and 6 > 2 * 2) are satisfied.

Input: arr[] = {4, 6, 5, 1}, K = 2
Output: 3

Naive Approach: The simplest approach to solve the problem is to traverse the array and for every index, find numbers having indices greater than it, such that the element in it when multiplied by K is less than the element at the current index.


  
  
  Follow the below steps to solve the problem:

Initialize a variable, say cnt, with 0 to count the total number of required pairs.
Traverse the array from left to right.
For each possible index, say i, traverse the indices i + 1 to N – 1 and increase the value of cnt by 1 if any element, say arr[j], is found such that arr[j] * K is less than arr[i].
After complete traversal of the array, print cnt as the required count of pairs.
  
  
 https://www.geeksforgeeks.org/count-pairs-i-j-from-given-array-such-that-i-j-and-arri-k-arrj/
  
  
  
 // C++ program for the above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Function to find the count required pairs 
int getPairs(int arr[], int N, int K) 
{ 
	// Stores count of pairs 
	int count = 0; 

	// Traverse the array 
	for (int i = 0; i < N; i++) { 

		for (int j = i + 1; j < N; j++) { 

			// Check if the condition 
			// is satisfied or not 
			if (arr[i] > K * arr[i + 1]) 
				count++; 
		} 
	} 
	cout << count; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { 5, 6, 2, 1 }; 
	int N = sizeof(arr) / sizeof(arr[0]); 
	int K = 2; 

	// Function Call 
	getPairs(arr, N, K); 

	return 0; 
} 






Efficient Approach: The idea is to use the concept of merge sort and then count pairs according to the given conditions. Follow the steps below to solve the problem:

Initialize a variable, say answer, to count the number of pairs satisfying the given condition.
Repeatedly partition the array into two equal halves or almost equal halves until one element is left in each partition.
Call a recursive function that counts the umber of times the condition arr[i] > K * arr[j] and i < j is satisfied after merging the two partitions.
Perform it by initializing two variables, say i and j, for the indices of the first and second half respectively.
Increment j till arr[i] > K * arr[j] and j < size of the second half. Add (j – (mid + 1)) to the answer and increment i.
After completing the above steps, print the value of answer as the required number of pairs.
  
  
  
  
  
  // C++ program for the above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Function to merge two sorted arrays 
int merge(int arr[], int temp[], 
		int l, int m, int r, int K) 
{ 
	// i: index to left subarray 
	int i = l; 

	// j: index to right subarray 
	int j = m + 1; 

	// Stores count of pairs that 
	// satisfy the given condition 
	int cnt = 0; 

	for (int l = 0; i <= m; i++) { 
		bool found = false; 

		// Traverse to check for the 
		// valid conditions 
		while (j <= r) { 

			// If condition satifies 
			if (arr[i] >= K * arr[j]) { 
				found = true; 
			} 
			else
				break; 
			j++; 
		} 

		// While a[i] > K*a[j] satisfies 
		// increase j 

		// All elements in the right 
		// side of the left subarray 
		// also satisies 
		if (found) { 
			cnt += j - (m + 1); 
			j--; 
		} 
	} 

	// Sort the two given arrays and 
	// store in the resultant array 
	int k = l; 
	i = l; 
	j = m + 1; 

	while (i <= m && j <= r) { 

		if (arr[i] <= arr[j]) 
			temp[k++] = arr[i++]; 
		else
			temp[k++] = arr[j++]; 
	} 

	// Elements which are left 
	// in the left subarray 
	while (i <= m) 
		temp[k++] = arr[i++]; 

	// Elements which are left 
	// in the right subarray 
	while (j <= r) 
		temp[k++] = arr[j++]; 

	for (int i = l; i <= r; i++) 
		arr[i] = temp[i]; 

	// Return the count obtained 
	return cnt; 
} 

// Function to partiton array into two halves 
int mergeSortUtil(int arr[], int temp[], 
				int l, int r, int K) 
{ 
	int cnt = 0; 
	if (l < r) { 

		// Same as (l + r) / 2, but avoids 
		// overflow for large l and h 
		int m = (l + r) / 2; 

		// Sort first and second halves 
		cnt += mergeSortUtil(arr, temp, 
							l, m, K); 
		cnt += mergeSortUtil(arr, temp, 
							m + 1, r, K); 

		// Call the merging function 
		cnt += merge(arr, temp, l, 
					m, r, K); 
	} 

	return cnt; 
} 

// Function to print the count of 
// required pairs using Merge Sort 
int mergeSort(int arr[], int N, int K) 
{ 
	int temp[N]; 

	cout << mergeSortUtil(arr, temp, 0, 
						N - 1, K); 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 5, 6, 2, 5 }; 
	int N = sizeof(arr) / sizeof(arr[0]); 
	int K = 2; 

	// Function Call 
	mergeSort(arr, N, K); 

	return 0; 
} 
