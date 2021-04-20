https://www.geeksforgeeks.org/longest-even-length-substring-sum-first-second-half/



Last Updated: 07-02-2019
Given a string ‘str’ of digits, find the length of the longest substring of ‘str’, such that the length of the substring is 2k digits and sum of left k digits is equal to the sum of right k digits.
Examples :

Input: str = "123123"
Output: 6
The complete string is of even length and sum of first and second
half digits is same

Input: str = "1538023"
Output: 4
The longest substring with same first and second half sum is "5380"


Optimised version
// A O(n^2) time and O(1) extra space solution 
#include<bits/stdc++.h> 
using namespace std; 

int findLength(string str, int n) 
{ 
	int ans = 0; // Initialize result 

	// Consider all possible midpoints one by one 
	for (int i = 0; i < n-1; i++) 
	{ 
		/* For current midpoint 'i', keep expanding substring on 
		both sides, if sum of both sides becomes equal update 
		ans */
		int l = i, r = i + 1; 

		/* initialize left and right sum */
		int lsum = 0, rsum = 0; 

		/* move on both sides till indexes go out of bounds */
		while (r < n && l >= 0) 
		{ 
			lsum += str[l] - '0'; 
			rsum += str[r] - '0'; 
			if (lsum == rsum) 
				ans = max(ans, r-l+1); 
			l--; 
			r++; 
		} 
	} 
	return ans; 
} 

// Driver program to test above function 
int main() 
{ 
	string str = "123123"; 
	cout << "Length of the substring is " << findLength(str, str.length()); 
	return 0; 
} 


DP approach


// A O(n^2) time and O(n) extra space solution 
#include<bits/stdc++.h> 
using namespace std; 

int findLength(string str, int n) 
{ 
	int sum[n+1]; // To store cumulative sum from first digit to nth digit 
	sum[0] = 0; 

	/* Store cumulative sum of digits from first to last digit */
	for (int i = 1; i <= n; i++) 
		sum[i] = (sum[i-1] + str[i-1] - '0'); /* convert chars to int */

	int ans = 0; // initialize result 

	/* consider all even length substrings one by one */
	for (int len = 2; len <= n; len += 2) 
	{ 
		for (int i = 0; i <= n-len; i++) 
		{ 
			int j = i + len - 1; 

			/* Sum of first and second half is same than update ans */
			if (sum[i+len/2] - sum[i] == sum[i+len] - sum[i+len/2]) 
				ans = max(ans, len); 
		} 
	} 
	return ans; 
} 

// Driver program to test above function 
int main() 
{ 
	string str = "123123"; 
	cout << "Length of the substring is " << findLength(str, str.length()); 
	return 0; 
} 







