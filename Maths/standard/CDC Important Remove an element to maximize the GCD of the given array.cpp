
Remove an element to maximize the GCD of the given array
Difficulty Level : Hard
 Last Updated : 23 Jul, 2019
Given an array arr[] of length N ≥ 2. The task is to remove an element from the given array such that the GCD of the array after removing it is maximized.

Examples:

Input: arr[] = {12, 15, 18}
Output: 6
Remove 12: GCD(15, 18) = 3
Remove 15: GCD(12, 18) = 6
Remove 18: GCD(12, 15) = 3

Input: arr[] = {14, 17, 28, 70}
Output: 14

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Approach:



Idea is to find the GCD value of all the sub-sequences of length (N – 1) and removing the element which is not present in the sub-sequence with that GCD. The maximum GCD found would be the answer.
To find the GCD of the sub-sequences optimally, maintain a prefixGCD[] and a suffixGCD[] array using single state dynamic programming.
The maximum value of GCD(prefixGCD[i – 1], suffixGCD[i + 1]) is the required answer.




// C++ implementation of the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the maximized gcd 
// after removing a single element 
// from the given array 
int MaxGCD(int a[], int n) 
{ 

	// Prefix and Suffix arrays 
	int Prefix[n + 2]; 
	int Suffix[n + 2]; 

	// Single state dynamic programming relation 
	// for storing gcd of first i elements 
	// from the left in Prefix[i] 
	Prefix[1] = a[0]; 
	for (int i = 2; i <= n; i += 1) { 
		Prefix[i] = __gcd(Prefix[i - 1], a[i - 1]); 
	} 

	// Initializing Suffix array 
	Suffix[n] = a[n - 1]; 

	// Single state dynamic programming relation 
	// for storing gcd of all the elements having 
	// greater than or equal to i in Suffix[i] 
	for (int i = n - 1; i >= 1; i -= 1) { 
		Suffix[i] = __gcd(Suffix[i + 1], a[i - 1]); 
	} 

	// If first or last element of 
	// the array has to be removed 
	int ans = max(Suffix[2], Prefix[n - 1]); 

	// If any other element is replaced 
	for (int i = 2; i < n; i += 1) { 
		ans = max(ans, __gcd(Prefix[i - 1], Suffix[i + 1])); 
	} 

	// Return the maximized gcd 
	return ans; 
} 

// Driver code 
int main() 
{ 
	int a[] = { 14, 17, 28, 70 }; 
	int n = sizeof(a) / sizeof(a[0]); 

	cout << MaxGCD(a, n); 

	return 0; 
} 




Time Complexity: O(N * log(M)) wh



