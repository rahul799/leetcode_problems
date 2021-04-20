XOR of all subarray XORs

https://www.geeksforgeeks.org/xor-subarray-xors/

Given an array of integers, we need to get total XOR of all subarray XORs where subarray XOR can be obtained by XORing all elements of it.


There are two  approaches for  this


// C++ program to get total xor of all subarray xors 
#include <bits/stdc++.h> 
using namespace std; 

// Returns XOR of all subarray xors 
int getTotalXorOfSubarrayXors(int arr[], int N) 
{ 
	// initialize result by 0 as (a xor 0 = a) 
	int res = 0; 

	// select the starting element 
	for (int i=0; i<N; i++) 

		// select the eNding element 
		for (int j=i; j<N; j++) 

			// Do XOR of elements in current subarray 
			for (int k=i; k<=j; k++) 
				res = res ^ arr[k]; 

	return res; 
} 

// Driver code to test above methods 
int main() 
{ 
	int arr[] = {3, 5, 2, 4, 6}; 
	int N = sizeof(arr) / sizeof(arr[0]); 

	cout << getTotalXorOfSubarrayXors(arr, N); 
	return 0; 
} 







Optimised approach

An efficient solution is based on the idea to enumerate all subarrays, we can count frequency of each element occurred totally in all subarrays, if the frequency of an element is odd then it will be included in final result otherwise not.

As in above example, 
3 occurred 5 times,
5 occurred 8 times,
2 occurred 9 times,
4 occurred 8 times,
6 occurred 5 times
So our final result will be xor of all elements which occurred odd number of times
i.e. 3^2^6 = 7

From above occurrence pattern we can observe that number at i-th index will have 
(i + 1) * (N - i) frequency.



// C++ program to get total 
// xor of all subarray xors 
#include <bits/stdc++.h> 
using namespace std; 

// Returns XOR of all subarray xors 
int getTotalXorOfSubarrayXors(int arr[], 
							int N) 
{ 
	// initialize result by 0 
	// as (a XOR 0 = a) 
	int res = 0; 

	// loop over all elements once 
	for (int i = 0; i < N; i++) 
	{ 
		// get the frequency of 
		// current element 
		int freq = (i + 1) * (N - i); 

		// if frequency is odd, then 
		// include it in the result 
		if (freq % 2 == 1) 
			res = res ^ arr[i]; 
	} 

	// return the result 
	return res; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = {3, 5, 2, 4, 6}; 
	int N = sizeof(arr) / sizeof(arr[0]); 

	cout << getTotalXorOfSubarrayXors(arr, N); 
	return 0; 
} 



