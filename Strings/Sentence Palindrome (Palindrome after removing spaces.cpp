Sentence Palindrome (Palindrome after removing spaces, dots, .. etc)
Last Updated: 11-01-2019
Write a program to check if a sentence is palindrome or not. You can ignore white spaces and other characters to consider sentence as a palindrome.

Examples:

Input : str = "Too hot to hoot."
Output : Sentence is palindrome.

Input : str = "Abc def ghi jklm."
Output : Sentence is not palindrome.


// CPP program to find if a sentence is 
// palindrome 
#include <bits/stdc++.h> 
using namespace std; 

// To check sentence is palindrome or not 
bool sentencePalindrome(string str) 
{ 
	int l = 0, h = str.length(); 

	// Lowercase string 
	for (int i = 0; i < h; i++) 
		str[i] = tolower(str[i]); 

	// Compares character until they are equal 
	while (l <= h) { 

		// If there is another symbol in left 
		// of sentence 
		if (!(str[l] >= 'a' && str[l] <= 'z')) 
			l++; 

		// If there is another symbol in right 
		// of sentence 
		else if (!(str[h] >= 'a' && str[h] <= 'z')) 
			h--; 

		// If characters are equal 
		else if (str[l] == str[h]) 
			l++, h--; 

		// If characters are not equal then 
		// sentence is not palindrome 
		else
			return false; 
	} 

	// Returns true if sentence is palindrome 
	return true; 
} 

// Driver program to test sentencePalindrome() 
int main() 
{ 
	string str = "Too hot to hoot."; 

	if (sentencePalindrome(str)) 
		cout << "Sentence is palindrome."; 
	else
		cout << "Sentence is not palindrome."; 

	return 0; 
} 
