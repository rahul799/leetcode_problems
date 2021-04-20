
647. Palindromic Substrings
Medium

3792

134

Add to List

Share
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Note:

The input string length won't exceed 1000.








class Solution {
public:
    int countSubstrings(string s) {
	int n = s.size();

	// dp[left][right] represent whether the substring [left,right] is palindromic or not
	// row index is the left index of substring, column index is the right index of substring
	int dp[n][n];

	// init the matrix with zero
	memset(dp, 0, sizeof(dp));

	int count = 0;

	// each character in the string is a palindromic string, so set dp[i][i] to 1
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
		count++;
	}


	for (int right = 1; right < n; right++) {
		for (int left = 0; left < right; left++) {
			// a substring is palindromic if the characters at left index and right index are equal and:
			// 1) left and right index are next to each other OR
			// 2) the substring [left+1,right-1] is palindromic (which was already determined)
			if (s[left] == s[right] && (left+1==right || dp[left+1][right-1])) {
				dp[left][right] = 1;
				count++;
			}
		}
	}

	return count;
}
};
