Given an arr[] containing n integers and a positive integer k. The problem is to find the length of the longest subarray with sum of the elements divisible by the given value k.
Examples:

Input : arr[] = {2, 7, 6, 1, 4, 5}, k = 3
Output : 4
The subarray is {7, 6, 1, 4} with sum 18,
which is divisible by 3.

Input : arr[] = {-2, 2, -5, 12, -11, -1, 7}
Output : 5




Method 2 (Efficient Approach): Create an array mod_arr[] where mod_arr[i] stores (sum(arr[0]+arr[1]..+arr[i]) % k). Create a hash table having tuple as (ele, idx), where ele represents an element of mod_arr[] and idx represents the element’s index of first occurrence in mod_arr[]. Now, traverse mod_arr[] from i = 0 to n and follow the steps given below.

If mod_arr[i] == 0, then update maxLen = (i + 1).
Else if mod_arr[i] is not present in the hash table, then create tuple (mod_arr[i], i) in the hash table.
Else, get the value associated with mod_arr[i] in the hash table. Let this be idx.
If maxLen < (i – idx), then update maxLen = (i – idx).



// C++ implementation to find the longest subarray 
// with sum divisible by k 
#include <bits/stdc++.h> 

using namespace std; 

// function to find the longest subarray 
// with sum divisible by k 
int longSubarrWthSumDivByK(int arr[], 
						int n, int k) 
{ 
	// unodered map 'um' implemented as 
	// hash table 
	unordered_map<int, int> um; 
	
	// 'mod_arr[i]' stores (sum[0..i] % k) 
	int mod_arr[n], max = 0; 
	int curr_sum = 0; 
	
	// traverse arr[] and build up the 
	// array 'mod_arr[]' 
	for (int i = 0; i < n; i++) 
	{ 
		curr_sum += arr[i]; 
		
		// as the sum can be negative, taking modulo twice 
		mod_arr[i] = ((curr_sum % k) + k) % k;		 
	}	 
	
	for (int i = 0; i < n; i++) 
	{ 
		// if true then sum(0..i) is divisible 
		// by k 
		if (mod_arr[i] == 0) 
			// update 'max' 
			max = i + 1; 
		
		// if value 'mod_arr[i]' not present in 'um' 
		// then store it in 'um' with index of its 
		// first occurrence		 
		else if (um.find(mod_arr[i]) == um.end()) 
			um[mod_arr[i]] = i; 
			
		else
			// if true, then update 'max' 
			if (max < (i - um[mod_arr[i]])) 
				max = i - um[mod_arr[i]];			 
	} 
	
	// required length of longest subarray with 
	// sum divisible by 'k' 
	return max; 
}						 

// Driver program to test above 
int main() 
{ 
	int arr[] = {2, 7, 6, 1, 4, 5}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 3; 
	
	cout << "Length = "
		<< longSubarrWthSumDivByK(arr, n, k); 
		
	return 0;	 
} 
