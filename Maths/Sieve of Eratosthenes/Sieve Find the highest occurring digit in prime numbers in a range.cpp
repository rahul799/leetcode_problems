Find the highest occurring digit in prime numbers in a range
Last Updated: 07-01-2019
	
	
https://www.geeksforgeeks.org/find-highest-occurring-digit-prime-numbers-range/



Given a range L to R, the task is to find the highest occurring digit in prime numbers lie between L and R (both inclusive). If multiple digits have same highest frequency print the largest of them. If no prime number occurs between L and R, output -1.

Examples:

Input : L = 1 and R = 20.
Output : 1
Prime number between 1 and 20 are 2, 3, 5, 7, 11, 13, 17, 19.
1 occur maximum i.e 5 times among 0 to 9.



The idea is to start from L to R, check if the number is prime or not. If prime then increment the frequency of digits (using array) present in the prime number. To check if number is prime or not we can use Sieve of Eratosthenes.

Below is the implementation of this approach:




// C++ program to find the highest occurring digit 
// in prime numbers in a range L to R. 
#include<bits/stdc++.h> 
using namespace std; 

// Sieve of Eratosthenes 
void sieve(bool prime[], int n) 
{ 
	for (int p = 2; p * p <= n; p++) 
	{ 
		if (prime[p] == false) 
			for (int i = p*2; i <= n; i+=p) 
				prime[i] = true; 
	} 
} 

// Returns maximum occurring digits in primes 
// from l to r. 
int maxDigitInPrimes(int L, int R) 
{ 
	bool prime[R+1]; 
	memset(prime, 0, sizeof(prime)); 

	// Finding the prime number up to R. 
	sieve(prime, R); 

	// Initialse frequency of all digit to 0. 
	int freq[10] = { 0 }; 
	int val; 

	// For all number between L to R, check if prime 
	// or not. If prime, incrementing the frequency 
	// of digits present in the prime number. 
	for (int i = L; i <= R; i++) 
	{ 
		if (!prime[i]) 
		{ 
			int p = i; // If i is prime 
			while (p) 
			{ 
				freq[p%10]++; 
				p /= 10; 
			} 
		} 
	} 

	// Finding digit with highest frequency. 
	int max = freq[0], ans = 0; 
	for (int j = 1; j < 10; j++) 
	{ 
		if (max <= freq[j]) 
		{ 
			max = freq[j]; 
			ans = j; 
		} 
	} 

	return ans; 
} 

// Driven Program 
int main() 
{ 
	int L = 1, R = 20; 

	cout << maxDigitInPrimes(L, R) << endl; 
	return 0; 
} 
