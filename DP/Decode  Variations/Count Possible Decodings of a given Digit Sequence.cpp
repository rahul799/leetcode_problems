Count Possible Decodings of a given Digit Sequence
Last Updated: 24-04-2020
Let 1 represent ‘A’, 2 represents ‘B’, etc. Given a digit sequence, count the number of possible decodings of the given digit sequence.
Examples:

Input:  digits[] = "121"
Output: 3
// The possible decodings are "ABA", "AU", "LA"

Input: digits[] = "1234"
Output: 3
// The possible decodings are "ABCD", "LCD", "AWD"
An empty digit sequence is considered to have one decoding. It may be assumed that the input contains valid digits from 0 to 9 and there are no leading 0’s, no extra trailing 0’s and no two or more consecutive 0’s.

Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution.
This problem is recursive and can be broken in sub-problems. We start from end of the given digit sequence. We initialize the total count of decodings as 0. We recur for two subproblems.
1) If the last digit is non-zero, recur for remaining (n-1) digits and add the result to total count.
2) If the last two digits form a valid character (or smaller than 27), recur for remaining (n-2) digits and add the result to total count.

Following is the implementation of the above approach.




// A naive recursive C++ implementation to count number of decodings 
// that can be formed from a given digit sequence 
#include <iostream> 
#include <cstring> 
using namespace std; 

// Given a digit sequence of length n, 
// returns count of possible decodings by 
// replacing 1 with A, 2 woth B, ... 26 with Z 
int countDecoding(char *digits, int n) 
{ 
	// base cases 
	if (n == 0 || n == 1) 
		return 1; 
	if (digits[0]=='0') 
		return 0; 
	
	// for base condition "01123" should return 0 
	int count = 0; // Initialize count 

	// If the last digit is not 0, 
	// then last digit must add to the number of words 
	if (digits[n-1] > '0') 
		count = countDecoding(digits, n-1); 

	// If the last two digits form a number smaller 
	// than or equal to 26, then consider 
	// last two digits and recur 
	if (digits[n-2] == '1' || 
				(digits[n-2] == '2' && digits[n-1] < '7') ) 
		count += countDecoding(digits, n-2); 

	return count; 
} 

// Driver program to test above function 
int main() 
{ 
	char digits[] = "1234"; 
	int n = strlen(digits); 
	cout << "Count is " << countDecoding(digits, n); 
	return 0; 
} 
// Modified by Atanu Sen 
