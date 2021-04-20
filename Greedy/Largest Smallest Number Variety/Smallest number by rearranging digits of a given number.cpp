Smallest number by rearranging digits of a given number
Last Updated: 31-10-2018
Find the Smallest number (Not leading Zeros) which can be obtained by rearranging the digits of given number.

Examples:

Input: n = 846903
Output: 304689

Input: n = 55010
Output: 10055
Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution.
Steps to find the smallest number.

Count the frequency of each digit in the number.
Place the smallest digit (except 0) at the left most of required number.
and decrement the frequency of that digit by 1.
Place all remaining digits in ascending order from left to right.










// C++ program for finding smallest number 
// from digits of given number 
#include<iostream> 
using namespace std; 

// function to find the smallest number 
int smallest(int num) 
{ 
	// initialize frequency of each digit to Zero 
	int freq[10] = {0}; 

	// count frequency of each digit in the number 
	while (num) 
	{ 
		int d = num % 10; // extract last digit 
		freq[d]++; // increment counting 
		num = num / 10; //remove last digit 
	} 

	// Set the LEFTMOST digit to minimum expect 0 
	int result = 0; 
	for (int i = 1 ; i <= 9 ; i++) 
	{ 
		if (freq[i]) 
		{ 
			result = i; 
			freq[i]--; 
			break; 
		} 
	} 

	// arrange all remaining digits 
	// in ascending order 
	for (int i = 0 ; i <= 9 ; i++) 
		while (freq[i]--) 
			result = result * 10 + i; 

	return result; 
} 

// Driver Program 
int main() 
{ 
	int num = 570107; 
	cout << smallest(num); 
	return 0; 
} 
