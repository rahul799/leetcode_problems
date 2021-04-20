




https://github.com/ramankgp/Leetcode-Solutions2020/new/master/DP/DP%20with%20Bitmasking





Given a matrix, mat[][] of size N * M, the task is to find the minimum count of operations required to make all elements of at least one row of the given matrix 
prime. In each operation, merge any two rows of the matrix based on the following conditions:

If kth elements of both rows of the matrix, i.e, mat[i][k] and mat[j][k] are prime numbers or composite numbers then kth element of the merged row contains 
min(mat[i][k], mat[j][k]).
Otherwise, kth element of the merged row contains the element which is prime.



Minimum number of operations required to make all elements of at least one row of given Matrix prime








Approach:The problem can be solved using Dynamic programming with Bitmasks. Follow the steps below to solve the problem:

Initialize a variable, say bitmask, where ith bit of bitmask stores if ith column of a row is a prime number or not.
Initialize an array, say dp[], where dp[X] stores the minimum count of operations required to get X count of prime numbers in a row.
Traverse each row of the matrix and for update the value of bitmask for each row. Iterate over the range [(1 << (M - 1)), 0] using variable j and update the 
value of dp[j | bitmask] to min(dp[j | bitmask], dp[j] + 1).
Finally, check if minimum count of operations required to get M prime numbers in a row is greater than N or not i.e, check if dp[(1 << (M - 1))] is greater 
than N or not. If found to be true, then print -1.
Otherwise, print the value of (dp[(1 << (M - 1))] - 1).







// Java program to implement 
// the above approach 

import java.io.*; 
import java.util.*; 

class GFG { 

	// Function to generate all prime 
	// numbers using Sieve of Eratosthenes 
	private static boolean[] prime; 

	// Function to check if a number 
	// is prime or not 
	private static void sieve(int n) 
	{ 
		// prime[i]: Check if i is a 
		// prime number or not 
		prime = new boolean[n + 1]; 

		// Initialize prime[] 
		// array to true 
		Arrays.fill(prime, true); 

		// Iterate over the range 
		// [2, sqrt(n)] 
		for (int p = 2; p * p <= n; 
			p++) { 

			// If p is a prime number 
			if (prime[p] == true) { 

				// Mark all multiples 
				// of i to false 
				for (int i = p * p; 
					i <= n; i += p) 

					// Update i 
					prime[i] = false; 
			} 
		} 
	} 

	// Function to find minimum operations 
	// to make all elements of at least one 
	// row of the matrix as prime numbers 
	private static int MinWays(int[][] a, 
							int n, int m) 
	{ 
		// dp[i]: Stores minimum operations 
		// to get i prime numbers in a row 
		int[] dp = new int[1 << m]; 

		// Initialize dp[] array 
		// to (n + 1) 
		Arrays.fill(dp, n + 1); 

		// Traverse the array 
		for (int i = 0; i < a.length; 
			i++) { 

			// Stores count of prime 
			// numbers in a i-th row 
			int bitmask = BitMask(a[i]); 

			// Iterate over the range 
			// [(1 << m) - 1, 0] 
			for (int j = (1 << m) - 1; 
				j >= 0; j--) { 

				// If a row exist which 
				// contains j prime numbers 
				if (dp[j] != n + 1) { 

					// Update dp[j | bitmask] 
					dp[j | bitmask] 
						= Math.min(dp[j | bitmask], 
								dp[j] + 1); 
				} 
			} 

			// Update dp[bitmask] 
			dp[bitmask] = 1; 
		} 

		// Return minimum operations to get a row 
		// of the matrix with all prime numbers 
		return (dp[(1 << m) - 1] - 1) == (n + 1) 
			? -1
			: (dp[(1 << m) - 1] - 1); 
	} 

	// Function to count prime 
	// numbers in a row 
	private static int BitMask(int[] a) 
	{ 
		// i-th bit of bitmask check if 
		// i-th column is a prime or not 
		int bitmask = 0; 

		// Travere the array 
		for (int i = 0; i < a.length; 
			i++) { 

			// if a[i] is a prime number 
			if (prime[a[i]]) { 

				// Update bitmask 
				bitmask |= (1 << i); 
			} 
		} 
		return bitmask; 
	} 

	// Driver Code 
	public static void main(String[] args) 
	{ 
		int[][] mat = { { 4, 6, 5, 8 }, 
						{ 2, 9, 12, 14 }, 
						{ 32, 7, 18, 16 }, 
						{ 12, 4, 35, 17 } }; 

		// Stores count of columns 
		// in the matrix 
		int m = mat[0].length; 

		// Stores length 
		int n = mat.length; 

		// Calulate all prime numbers in 
		// range [1, max] using sieve 
		int max = 10000; 
		sieve(max); 

		// Function Call 
		System.out.println( 
			MinWays(mat, n, m)); 
	} 
} 

















