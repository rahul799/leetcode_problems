



1216. Valid Palindrome III
Hard

214

5

Add to List

Share
Given a string s and an integer k, find out if the given string is a K-Palindrome or not.

A string is K-Palindrome if it can be transformed into a palindrome by removing at most k characters from it.

 

Example 1:

Input: s = "abcdeca", k = 2
Output: true
Explanation: Remove 'b' and 'e' characters.
 

Constraints:

1 <= s.length <= 1000
s has only lowercase English letters.
1 <= k <= s.length




class Solution {
public:
    bool isValidPalindrome(string s, int k) 
    {
        int N = s.size();
        
        if (N == 1)
            return true;
        
        string t = s;
        reverse(t.begin(), t.end());
        
        if (N - longestCommonSubsequence(s, t) <= k)
            return true;
        else
            return false;
    }
    
    int longestCommonSubsequence(string text1, string text2) 
    {
        int M = text1.size();
        int N = text2.size();
        
        vector<vector<int>> dp (M+1, vector<int>(N+1, 0));
        
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (text1[i] == text2[j])
                {
                    dp[i+1][j+1] = dp[i][j] + 1;
                }
                else
                {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        
        return dp[M][N];
    }
};
