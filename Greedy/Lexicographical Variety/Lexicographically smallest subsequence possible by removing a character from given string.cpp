Lexicographically smallest subsequence possible by removing a character from given string
Last Updated: 18-11-2020
Given a string S of length N, the task is to find the lexicographically smallest subsequence of length (N – 1), i.e. by removing a single character from the given string.

Examples:

Input: S = “geeksforgeeks”
Output: “eeksforgeeks”
Explanation: Lexicographically smallest subsequence possible is “eeksforgeeks”.

Input: S = “zxvsjas”
Output: “xvsjas”
Explanation: Lexicographically smallest subsequence possible is “xvsjas”.

Naive Approach: The simplest approach is to generate all possible subsequences of length (N – 1) from the given string and store all subsequences in an array. 
Now, sort the array and print the string at 0th position for the smallest lexicographically subsequence.

// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the lexicographically
// smallest subsequence of length N-1
void firstSubsequence(string s)
{
	vector<string> allsubseq;

	string k;

	// Generate all subsequence of
	// length N-1
	for (int i = 0; i < s.length(); i++) {

		// Store main value of string str
		k = s;

		// Erasing element at position i
		k.erase(i, 1);
		allsubseq.push_back(k);
	}

	// Sort the vector
	sort(allsubseq.begin(),
		allsubseq.end());

	// Print first element of vector
	cout << allsubseq[0];
}

// Driver Code
int main()
{
	// Given string S
	string S = "geeksforgeeks";

	// Function Call
	firstSubsequence(S);

	return 0;
}



Efficient Approach: To optimize the above approach, the idea is to iterate over the string and check if the ith character is greater that (i + 1)th character, 
then simply remove the ith character and print the remaining string. Otherwise, remove the last element and print the desired
subsequence.


// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the lexicographically
// smallest subsequence of length N-1
void firstSubsequence(string s)
{
	// Store index of character
	// to be deleted
	int isMax = -1;

	// Traverse the string
	for (int i = 0;
		i < s.length() - 1; i++) {

		// If ith character > (i + 1)th
		// character then store it
		if (s[i] > s[i + 1]) {
			isMax = i;
			break;
		}
	}

	// If any character found in non
	// alphabetical order then remove it
	if (isMax >= 0) {
		s.erase(isMax, 1);
	}

	// Otherwise remove last character
	else {
		s.erase(s.length() - 1, 1);
	}

	// Print the resultant subsequence
	cout << s;
}

// Driver Code
int main()
{
	// Given string S
	string S = "geeksforgeeks";

	// Function Call
	firstSubsequence(S);

	return 0;
}




