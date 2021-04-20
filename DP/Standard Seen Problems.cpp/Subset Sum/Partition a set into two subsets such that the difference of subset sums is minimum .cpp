Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example:

Input:  arr[] = {1, 6, 11, 5} 
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11  



Dynamic Programming
The problem can be solved using dynamic programming when the sum of the elements is not too big. We can create a 2D array dp[n+1][sum+1] where n is number of elements in given set and sum is sum of all elements. We can construct the solution in bottom up manner.

The task is to divide the set into two parts. 
We will consider the following factors for dividing it. 
Let 
  dp[n+1][sum+1] = {1 if some subset from 1st to i'th has a sum 
                      equal to j
                   0 otherwise}
    
    i ranges from {1..n}
    j ranges from {0..(sum of all elements)}  

So      
    dp[n+1][sum+1]  will be 1 if 
    1) The sum j is achieved including i'th item
    2) The sum j is achieved excluding i'th item.

Let sum of all the elements be S.  

To find Minimum sum difference, w have to find j such 
that Min{sum - j*2  : dp[n][j]  == 1 } 
    where j varies from 0 to sum/2

The idea is, sum of S1 is j and it should be closest
to sum/2, i.e., 2*j should be closest to sum.












// A Recursive C program to solve minimum sum partition 
// problem. 
#include <bits/stdc++.h> 
using namespace std; 

// Returns the minimum value of the difference of the two sets. 
int findMin(int arr[], int n) 
{ 
	// Calculate sum of all elements 
	int sum = 0; 
	for (int i = 0; i < n; i++) 
		sum += arr[i]; 

	// Create an array to store results of subproblems 
	bool dp[n+1][sum+1]; 

	// Initialize first column as true. 0 sum is possible 
	// with all elements. 
	for (int i = 0; i <= n; i++) 
		dp[i][0] = true; 

	// Initialize top row, except dp[0][0], as false. With 
	// 0 elements, no other sum except 0 is possible 
	for (int i = 1; i <= sum; i++) 
		dp[0][i] = false; 

	// Fill the partition table in bottom up manner 
	for (int i=1; i<=n; i++) 
	{ 
		for (int j=1; j<=sum; j++) 
		{ 
			// If i'th element is excluded 
			dp[i][j] = dp[i-1][j]; 

			// If i'th element is included 
			if (arr[i-1] <= j) 
				dp[i][j] |= dp[i-1][j-arr[i-1]]; 
		} 
	} 

	// Initialize difference of two sums. 
	int diff = INT_MAX; 
	
	// Find the largest j such that dp[n][j] 
	// is true where j loops from sum/2 t0 0 
	for (int j=sum/2; j>=0; j--) 
	{ 
		// Find the 
		if (dp[n][j] == true) 
		{ 
			diff = sum-2*j; 
			break; 
		} 
	} 
	return diff; 
} 

// Driver program to test above function 
int main() 
{ 
	int arr[] = {3, 1, 4, 2, 2, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "The minimum difference between 2 sets is "
		<< findMin(arr, n); 
	return 0; 
} 
