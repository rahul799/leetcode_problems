Binomial Coefficient | DP-9

	
https://www.geeksforgeeks.org/binomial-coefficient-dp-9/


Following are common definition of Binomial Coefficients.

A binomial coefficient C(n, k) can be defined as the coefficient of X^k in the expansion of (1 + X)^n.
A binomial coefficient C(n, k) also gives the number of ways, disregarding order, that k objects can be chosen from among n objects; more formally, the number of k-element 
subsets (or k-combinations) of an n-element set.
The Problem
Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k). For example, your function should return 6 for n = 4 and k = 2, and 
it should return 10 for n = 5 and k = 2.



1) Optimal Substructure
The value of C(n, k) can be recursively calculated using following standard formula for Binomial Coefficients.

   C(n, k) = C(n-1, k-1) + C(n-1, k)
   C(n, 0) = C(n, n) = 1
   
   
   
   // C++ program for space optimized Dynamic Programming 
// Solution of Binomial Coefficient 
#include<bits/stdc++.h> 
using namespace std; 

int binomialCoeff(int n, int k) 
{ 
	int C[k+1]; 
	memset(C, 0, sizeof(C)); 

	C[0] = 1; // nC0 is 1 

	for (int i = 1; i <= n; i++) 
	{ 
		// Compute next row of pascal triangle using 
		// the previous row 
		for (int j = min(i, k); j > 0; j--) 
			C[j] = C[j] + C[j-1]; 
	} 
	return C[k]; 
} 

/* Drier program to test above function*/
int main() 
{ 
	int n = 5, k = 2; 
	printf ("Value of C(%d, %d) is %d ", 
			n, k, binomialCoeff(n, k) ); 
	return 0; 
} 





// A Dynamic Programming based solution that uses 
// table dp[][] to calculate the Binomial Coefficient 
// A naive recursive approach with table C++ implementation 
#include <bits/stdc++.h> 
using namespace std; 

// Returns value of Binomial Coefficient C(n, k) 
int binomialCoeffUtil(int n, int k, int** dp) 
{ 
	// If value in lookup table then return 
	if (dp[n][k] != -1) //	 
		return dp[n][k]; 

	// store value in a table before return 
	if (k == 0) { 
		dp[n][k] = 1; 
		return dp[n][k]; 
	} 
	
	// store value in table before return 
	if (k == n) { 
		dp[n][k] = 1; 
		return dp[n][k]; 
	} 
	
	// save value in lookup table before return 
	dp[n][k] = binomialCoeffUtil(n - 1, k - 1, dp) + 
			binomialCoeffUtil(n - 1, k, dp); 
	return dp[n][k]; 
} 

int binomialCoeff(int n, int k) 
{ 
	int** dp; // make a temporary lookup table 
	dp = new int*[n + 1]; 

	// loop to create table dynamically 
	for (int i = 0; i < (n + 1); i++) { 
		dp[i] = new int[k + 1]; 
	} 

	// nested loop to initialise the table with -1 
	for (int i = 0; i < (n + 1); i++) { 
		for (int j = 0; j < (k + 1); j++) { 
			dp[i][j] = -1; 
		} 
	} 

	return binomialCoeffUtil(n, k, dp); 
} 

/* Driver code*/
int main() 
{ 
	int n = 5, k = 2; 
	cout << "Value of C(" << n << ", " << k << ") is "
		<< binomialCoeff(n, k) << endl; 
	return 0; 
} 

// This is code is contributed by MOHAMMAD MUDASSIR 
