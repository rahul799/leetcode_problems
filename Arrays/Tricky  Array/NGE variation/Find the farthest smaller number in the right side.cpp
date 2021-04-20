Find the farthest smaller number in the right side

Given an array arr[] of size N. For every element in the array, the task is to find the index of the farthest element in the array to the right which is smaller than
the current element. If no such number exists then print -1.

Examples:

Input: arr[] = {3, 1, 5, 2, 4}
Output: 3 -1 4 -1 -1
arr[3] is the farthest smallest element to the right of arr[0].
arr[4] is the farthest smallest element to the right of arr[2].
And for the rest of the elements, there is no smaller element to their right.

Input: arr[] = {1, 2, 3, 4, 0}
Output: 4 4 4 4 -1

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Approach: An efficient approach is to create a suffix_min[] array where suffix_min[i] stores the minimum element from the subarray arr[i … N – 1]. Now for any element
arr[i], binary search can be used on the subarray suffix_min[i + 1 … N – 1] to find the farthest smallest element to the right of arr[i].



// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find the farthest 
// smaller number in the right side 
void farthest_min(int a[], int n) 
{ 
	// To store minimum element 
	// in the range i to n 
	int suffix_min[n]; 
	suffix_min[n - 1] = a[n - 1]; 
	for (int i = n - 2; i >= 0; i--) { 
		suffix_min[i] = min(suffix_min[i + 1], a[i]); 
	} 

	for (int i = 0; i < n; i++) { 
		int low = i + 1, high = n - 1, ans = -1; 


// rather than writting the entire bianry search, we can also use binary search opperation
		while (low <= high) { 
			int mid = (low + high) / 2; 

			// If currnet element in the suffix_min 
			// is less than a[i] then move right 
			if (suffix_min[mid] < a[i]) { 
				ans = mid; 
				low = mid + 1; 
			} 
			else
				high = mid - 1; 
		} 

		// Print the required answer 
		cout << ans << " "; 
	} 
} 

// Driver code 
int main() 
{ 
	int a[] = { 3, 1, 5, 2, 4 }; 
	int n = sizeof(a) / sizeof(a[0]); 

	farthest_min(a, n); 

	return 0; 
} 



