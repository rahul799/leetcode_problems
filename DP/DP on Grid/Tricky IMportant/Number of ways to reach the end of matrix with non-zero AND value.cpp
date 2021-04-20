Number of ways to reach the end of matrix with non-zero AND value
Last Updated: 25-11-2019
Given an N * N matrix arr[][] consisting of non-negative integers, the task is to find the number of ways to reach arr[N – 1][N – 1] with a non-zero AND value starting from the arr[0][0] by going down or right in every move. Whenever a cell arr[i][j] is reached, ‘AND’ value is updated as currentVal & arr[i][j].

Examples:

Input: arr[][] = {
{1, 1, 1},
{1, 1, 1},
{1, 1, 1}}

Output: 6
All the paths will give non-zero and value.
Thus, number of ways equals 6.

Input: arr[][] = {
{1, 1, 2},
{1, 2, 1},
{2, 1, 1}}
Output: 0






Approach: This problem can be solved using dynamic programming. First, we need to decide the states of the DP. For every cell arr[i][j] and a number X, we will store the number of ways to reach the arr[N – 1][N – 1] from arr[i][j] with non-zero AND where X is the AND value of path till now. Thus, our solution will use 3-dimensional dynamic programming, two for the coordinates of the cells and one for X.

The required recurrence relation is:

dp[i][j][X] = dp[i][j + 1][X & arr[i][j]] + dp[i + 1][j][X & arr[i][j]]







// C++ implementation of the approach 
#include <bits/stdc++.h> 
#define n 3 
#define maxV 20 
using namespace std; 

// 3d array to store 
// states of dp 
int dp[n][n][maxV]; 

// Array to determine whether 
// a state has been solved before 
int v[n][n][maxV]; 

// Function to return the count of required paths 
int countWays(int i, int j, int x, int arr[][n]) 
{ 

	// Base cases 
	if (i == n || j == n) 
		return 0; 

	x = (x & arr[i][j]); 
	if (x == 0) 
		return 0; 

	if (i == n - 1 && j == n - 1) 
		return 1; 

	// If a state has been solved before 
	// it won't be evaluated again 
	if (v[i][j][x]) 
		return dp[i][j][x]; 

	v[i][j][x] = 1; 

	// Recurrence relation 
	dp[i][j][x] = countWays(i + 1, j, x, arr) 
				+ countWays(i, j + 1, x, arr); 

	return dp[i][j][x]; 
} 

// Driver code 
int main() 
{ 
	int arr[n][n] = { { 1, 2, 1 }, 
					{ 1, 1, 0 }, 
					{ 2, 1, 1 } }; 

	cout << countWays(0, 0, arr[0][0], arr); 

	return 0; 
} 






