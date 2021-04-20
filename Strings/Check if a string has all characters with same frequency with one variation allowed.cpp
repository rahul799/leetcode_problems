Given a string of lowercase alphabets, find if it can be converted to a Valid String by removing 1 or 0 characters. A “valid” string is a string str such that 
for all distinct characters in str each such character occurs the same number of times in it.

	
https://www.geeksforgeeks.org/check-if-a-string-has-all-characters-with-same-frequency-with-one-variation-allowed/

Examples :

Input : string str = "abbca"
Output : Yes
We can make it valid by removing "c"

Input : string str = "aabbcd"
Output : No
We need to remove at least two characters
to make it valid.

Input : string str = "abbccd"
Output : No


// C++ program to check if a string can be made 
// valid by removing at most 1 character. 
#include<bits/stdc++.h> 
using namespace std; 

// Assuming only lower case characters 
const int CHARS = 26; 

/* To check a string S can be converted to a “valid” 
string by removing less than or equal to one 
character. */
bool isValidString(string str) 
{ 
	int freq[CHARS] = {0}; 

	// freq[] : stores the frequency of each 
	// character of a string 
	for (int i=0; i<str.length(); i++) 
		freq[str[i]-'a']++; 

	// Find first character with non-zero frequency 
	int i, freq1 = 0, count_freq1 = 0; 
	for (i=0; i<CHARS; i++) 
	{ 
		if (freq[i] != 0) 
		{ 
			freq1 = freq[i]; 
			count_freq1 = 1; 
			break; 
		} 
	} 

	// Find a character with frequency different 
	// from freq1. 
	int j, freq2 = 0, count_freq2 = 0; 
	for (j=i+1; j<CHARS; j++) 
	{ 
		if (freq[j] != 0) 
		{ 
			if (freq[j] == freq1) 
			count_freq1++; 
			else
			{ 
				count_freq2 = 1; 
				freq2 = freq[j]; 
				break; 
			} 
		} 
	} 

	// If we find a third non-zero frequency 
	// or count of both frequencies become more 
	// than 1, then return false 
	for (int k=j+1; k<CHARS; k++) 
	{ 
		if (freq[k] != 0) 
		{ 
			if (freq[k] == freq1) 
			count_freq1++; 
			if (freq[k] == freq2) 
			count_freq2++; 
			else // If we find a third non-zero freq 
			return false; 
		} 

		// If counts of both frequencies is more than 1 
		if (count_freq1 > 1 && count_freq2 > 1) 
		return false; 
	} 

	// Return true if we reach here 
	return true; 
} 

// Driver code 
int main() 
{ 
	char str[] = "abcbc"; 

	if (isValidString(str)) 
		cout << "YES" << endl; 
	else
		cout << "NO" << endl; 
	return 0; 
} 
