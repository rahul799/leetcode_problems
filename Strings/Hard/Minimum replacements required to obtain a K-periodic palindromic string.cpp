Minimum replacements required to obtain a K-periodic palindromic string
Last Updated: 06-11-2020
Given a string S of length N and an integer K, the task is to find the minimum character replacements required to make the string palindromic as well as K-periodic.




A K-periodic string can be made only by concatenating several palindromic strings having length K.
All the characters at positions i, K – i – 1, i + K, 2K – i – 1, i + 2K, 3K – i – 1, i + 3K, … for all 0 ≤ i < K, are equal.
The problem reduces to making all the characters equal to the one which appears the maximum number of times at these positions in the given string. Follow the steps below to solve the above problem: 

Initialize a variable ans with 0 that stores the minimum changes required to satisfy the given condition.
Iterate over the range [0, K / 2] using the variable i.
Create a hashmap, mp to store the frequency of each character.
Iterate over the characters in the string starting from i in intervals of K using a variable j and store the frequency of each character.
Iterate the string in reverse, starting from (N – i – 1) in intervals of K using a variable j and store the frequency of each character. If K is odd and i = K / 2, then break out of the loop.
Find the maximum frequency of a character among the visited one and store it in a variable, say curr_max.
After the above steps, if K is odd and i = K/2, then increment ans by (N/K – curr_max)Otherwise, increment ans by (N/K – 2*curr_max).
After the above steps, print the value of ans as the result.


// C++ program for the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find the minimum number 
// of changes to make the string K- 
// periodic and palindrome 
int findMinimumChanges(int N, int K, 
					string S) 
{ 

	// Initialize ans with 0 
	int ans = 0; 

	// Iterate from 0 to (K+1) / 2 
	for (int i = 0; i < (K + 1) / 2; i++) { 

		// Store frequency of character 
		map<char, int> mp; 

		// Iterate through all indices, 
		// i, i+K, i+2k.... and store 
		// the frequency of character 
		for (int j = i; j < N; j += K) { 

			// Increase the frequency 
			// of current character 
			mp[S[j]]++; 
		} 

		// Iterate through all indices 
		// K-i, 2K-i, 3K-i.... and store 
		// the frequency of character 
		for (int j = N - i - 1; 
			j >= 0; j -= K) { 

			// If K is odd & i is samw 
			// as K/2, break the loop 
			if (K & 1 and i == K / 2) 
				break; 

			// Increase the frequency 
			// of current character 
			mp[S[j]]++; 
		} 

		// Find the maximum frequency 
		// of a character among all 
		// visited characters 
		int curr_max = INT_MIN; 
		for (auto p : mp) 
			curr_max = max(curr_max, 
						p.second); 

		// If K is odd and i is same 
		// as K/2 then, only N/K 
		// characters is visited 
		if (K & 1 and i == K / 2) 
			ans += (N / K - curr_max); 

		// Otherwise N/K * 2 characters 
		// has visited 
		else
			ans += (N / K * 2 - curr_max); 
	} 

	// Return the result 
	return ans; 
} 

// Driver Code 
int main() 
{ 
	string S = "aabbcbbcb"; 
	int N = S.length(); 
	int K = 3; 

	// Function Call 
	cout << findMinimumChanges(N, K, S); 

	return 0; 
} 
