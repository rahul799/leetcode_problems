





Lexicographically smallest string formed by appending a character from the first K characters of a given string
Last Updated: 10-05-2019
Given a string S consisting of lowercase alphabets. The task is to find the lexicographically smallest string X of the same length only that can be formed using the operation given below:

In a single operation, select any one character among the at most first K characters of string S, remove it from string S and append it to string X. Apply this operation as many times as he wants.

Examples:

Input: str = “gaurang”, k=3
Output: agangru
Remove ‘a’ in the first step and append to X.
Remove ‘g’ in the second step and append to X.
Remove ‘a’ in the third step and append to X.
Remove ‘n’ in the third step and append to X.

Pick the lexicographically smallest character at every step from the first K characters to get the
string “agangru”



Input: str = “geeksforgeeks”, k=5
Output: eefggeekkorss

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Approach:

Find the smallest character in the first k characters in the string S.
Delete the smallest character found from the string.
Append the smallest character found to the new string X.
Repeat the above steps till the string s is empty.



// C++ program to find the new string 
// after performing deletions and append 
// operation in the string s 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find the new string thus 
// formed by removing characters 
string newString(string s, int k) 
{ 
	// new string 
	string X = ""; 

	// Remove characters until 
	// the string is empty 
	while (s.length() > 0) { 

		char temp = s[0]; 

		// Traverse to find the smallest character in the 
		// first k characters 
		for (long long i = 1; i < k and i < s.length(); i++) { 
			if (s[i] < temp) { 
				temp = s[i]; 
			} 
		} 

		// append the smallest character 
		X = X + temp; 

		// removing the lexicographically smallest 
		// character from the string 
		for (long long i = 0; i < k; i++) { 
			if (s[i] == temp) { 

				s.erase(s.begin() + i); 
				break; 
			} 
		} 
	} 

	return X; 
} 

// Driver Code 
int main() 
{ 

	string s = "gaurang"; 
	int k = 3; 

	cout << newString(s, k); 
} 
