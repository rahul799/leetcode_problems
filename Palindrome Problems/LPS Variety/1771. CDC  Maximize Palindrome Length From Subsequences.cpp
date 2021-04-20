
1771. Maximize Palindrome Length From Subsequences
Hard

152

5

Add to List

Share
You are given two strings, word1 and word2. You want to construct a string in the following manner:

Choose some non-empty subsequence subsequence1 from word1.
Choose some non-empty subsequence subsequence2 from word2.
Concatenate the subsequences: subsequence1 + subsequence2, to make the string.
Return the length of the longest palindrome that can be constructed in the described manner. If no palindromes can be constructed, return 0.

A subsequence of a string s is a string that can be made by deleting some (possibly none) characters from s without changing the order of the remaining characters.

A palindrome is a string that reads the same forward as well as backward.

 

Example 1:

Input: word1 = "cacb", word2 = "cbba"
Output: 5
Explanation: Choose "ab" from word1 and "cba" from word2 to make "abcba", which is a palindrome.
Example 2:

Input: word1 = "ab", word2 = "ab"
Output: 3
Explanation: Choose "ab" from word1 and "a" from word2 to make "aba", which is a palindrome.
Example 3:

Input: word1 = "aa", word2 = "bb"
Output: 0
Explanation: You cannot construct a palindrome from the described method, so return 0.
 

Constraints:

1 <= word1.length, word2.length <= 1000
word1 and word2 consist of lowercase English letters.
  
  
  


class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int dp[s.size() + 1][s.size() + 1];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            dp[i][i] = 1;
            for(int j = i-1; j >=0; --j){
                if(s[i] == s[j]){
                    dp[j][i] = dp[j+1][i-1] + 2;
                    if(j < word1.size() && i >= word1.size()) {
                        ans = max(ans, dp[j][i]);  // left side is in word1 and right side is in word2, that is a valid answer.
                    }
                }else{
                    dp[j][i] = max(dp[j][i-1], dp[j+1][i]);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string word = word1+word2;
        int n = word.size();
        auto dp = vector(n, vector<int>(n, 0));
        int res = 0;
        dp[n-1][n-1] = 1;
        for (int i = n-2; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i+1; j < n; j++) {
                if (word[i] == word[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                    if (i < word1.size() && j >= word1.size()) 
                        res = max(res, dp[i][j]);
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return res;
    }
};
