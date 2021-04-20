
https://www.geeksforgeeks.org/number-of-distinct-ways-to-represent-a-number-as-sum-of-k-unique-primes/?ref=rp


Given an integer N, and an integer K, the task is to count the number of distinct ways to represent the number N as a sum of K unique primes.

Note: Distinct means, let N = 7 and K = 2, then the only way can be {2,5}, because {5,2} is same as {2,5}. So only 1 way.

Examples:

Input: N = 10, K = 2
Output: 1
Explanation:
The only way is {3, 7} or {7, 3}

Input: N = 100, K = 5
Output: 55
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Approach: The problem can be solved using Dynamic Programming and Sieve of Eratosthenes.

Let dp[i][j][sum] be our 3D DP array, which stores the number of distinct ways to form a sum using j number of primes where the last index of prime selected is i in the prime vector.
The prime numbers can be efficiently computed using Sieve of Eratosthenes. So, we can get a check of prime in O(1) time.
Recurrence:

We can either include this current prime to our sum, or we can exclude it.
dp[i][j][sum] = solve(i+1, j+1, sum+prime[i]) + solve(i+1, j, sum)

Below is the implementation of the above approach :



// C++ program to count the Number 
// of distinct ways to represent 
// a number as K different primes 
#include <bits/stdc++.h> 
using namespace std; 

// Prime vector 
vector<int> prime; 

// Sieve array of prime 
bool isprime[1000]; 

// DP array 
int dp[200][20][1000]; 

void sieve() 
{ 
	// Initialise all numbers 
	// as prime 
	memset(isprime, true, 
		sizeof(isprime)); 

	// Sieve of Eratosthenes. 
	for (int i = 2; i * i <= 1000; 
		i++) 
	{ 
		if (isprime[i]) 
		{ 
			for (int j = i * i; 
				j <= 1000; j += i) 
			{ 
				isprime[j] = false; 
			} 
		} 
	} 
	// Push all the primes into 
	// prime vector 
	for (int i = 2; i <= 1000; i++) 
	{ 
		if (isprime[i]) 
		{ 
			prime.push_back(i); 
		} 
	} 
} 

// Function to get the number of 
// distinct ways to get sum 
// as K different primes 
int CountWays(int i, int j, int sum, 
		int n, int k) 
{ 

	// If index went out of prime 
	// array size or the sum became 
	// larger than n return 0 
	if (i > prime.size() || sum > n) 
	{ 
		return 0; 
	} 

	// If sum becomes equal to n and 
	// j becomes exactly equal to k. 
	// Return 1, else if j is still 
	// not equal to k, return 0 
	if (sum == n) { 
		if (j == k) { 
			return 1; 
		} 
		return 0; 
	} 

	// If sum!=n and still j as 
	// exceeded, return 0 
	if (j == k) 
		return 0; 

	// If that state is already 
	// calculated, return directly 
	// the ans 
	if (dp[i][j][sum]) 
		return dp[i][j][sum]; 

	int inc = 0, exc = 0; 
	// Include the current prime 
	inc = CountWays(i + 1, j + 1, 
				sum + prime[i], 
				n, k); 

	// Exclude the current prime 
	exc = CountWays(i + 1, j, sum, 
				n, k); 

	// Return by memoizing the ans 
	return dp[i][j][sum] = inc + exc; 
} 

// Driver code 
int main() 
{ 

	// Precompute primes by sieve 
	sieve(); 

	int N = 100, K = 5; 
	
	cout << CountWays(0, 0, 0, N, K); 
} 
