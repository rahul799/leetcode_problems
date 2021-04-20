Maximum number of segments of lengths a, b and c
https://www.geeksforgeeks.org/maximum-number-segments-lengths-b-c/

Given a positive integer N, find the maximum number of segments of lengths a, b and c that can be formed from N .












// C++ implementation to divide N into 
// maximum number of segments 
// of length a, b and c 
#include <bits/stdc++.h> 
using namespace std; 

// function to find the maximum 
// number of segments 
int maximumSegments(int n, int a, 
					int b, int c) 
{ 
	// stores the maximum number of 
	// segments each index can have 
	int dp[n + 1]; 
	
	// initialize with -1 
	memset(dp, -1, sizeof(dp)); 

	// 0th index will have 0 segments 
	// base case 
	dp[0] = 0; 

	// traverse for all possible 
	// segments till n 
	for (int i = 0; i < n; i++) 
	{ 
		if (dp[i] != -1) { 
			
			// conditions 
		if(i + a <= n ) 
				dp[i + a] = max(dp[i] + 1, 
							dp[i + a]); 
							
		if(i + b <= n ) 
				dp[i + b] = max(dp[i] + 1, 
							dp[i + b]); 
							
		if(i + c <= n )  
				dp[i + c] = max(dp[i] + 1, 
							dp[i + c]); 
		} 
	} 
	return dp[n]; 
} 

// Driver code 
int main() 
{ 
	int n = 7, a = 5, b = 2, c = 5; 
	cout << maximumSegments(n, a, b, c); 
	return 0; 
} 
