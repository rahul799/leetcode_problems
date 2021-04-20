Given an array of distinct integers and a sum value. Find count of triplets with sum smaller than given sum value. Expected Time Complexity is O(n2).

Examples:

Input : arr[] = {-2, 0, 1, 3}
        sum = 2.
Output : 2
Explanation :  Below are triplets with sum less than 2
               (-2, 0, 1) and (-2, 0, 3) 

Input : arr[] = {5, 1, 3, 4, 7}
        sum = 12.
Output : 4
Explanation :  Below are triplets with sum less than 12
               (1, 3, 4), (1, 3, 5), (1, 3, 7) and 
               (1, 4, 5)










// A Simple C++ program to count triplets with sum smaller 
// than a given value 
#include<bits/stdc++.h> 
using namespace std; 

int countTriplets(int arr[], int n, int sum) 
{ 
	// Initialize result 
	int ans = 0; 

	// Fix the first element as A[i] 
	for (int i = 0; i < n-2; i++) 
	{ 
	// Fix the second element as A[j] 
	for (int j = i+1; j < n-1; j++) 
	{ 
		// Now look for the third number 
		for (int k = j+1; k < n; k++) 
			if (arr[i] + arr[j] + arr[k] < sum) 
				ans++; 
	} 
	} 

	return ans; 
} 

// Driver program 
int main() 
{ 
	int arr[] = {5, 1, 3, 4, 7}; 
	int n = sizeof arr / sizeof arr[0]; 
	int sum = 12; 
	cout << countTriplets(arr, n, sum) << endl; 
	return 0; 
} 
