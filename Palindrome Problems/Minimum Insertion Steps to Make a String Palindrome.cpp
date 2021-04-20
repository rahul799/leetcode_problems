







1312. Minimum Insertion Steps to Make a String Palindrome
Hard

581

9

Add to List

Share
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
Example 4:

Input: s = "g"
Output: 0
Example 5:

Input: s = "no"
Output: 1
 

Constraints:

1 <= s.length <= 500
All characters of s are lower case English letters.









Solved using Longest Palindromic Subsequence Problem

Find length of LPS
Return len(s)-len(lps)
class Solution {
public:
    int minInsertions(string s) {
        int l = s.size();
        vector<vector<int>> dp(l,vector<int>(l,-1));
        int lps_len = lps(s,0,l-1,dp);
        
        return l-lps_len;
    }
    
    int lps(string &s, int i, int j, vector<vector<int>> &dp){
        if(i>j){
            return 0;
        } 
        if(i==j){
            return dp[i][j] = 1;
        }
        if(dp[i][j]==-1){   
            if(s[i]==s[j]){
                dp[i][j]=(2+lps(s,i+1,j-1,dp));
            }else{
                dp[i][j] = max(lps(s,i+1,j,dp),lps(s,i,j-1,dp));
            }
        }
        return dp[i][j];
    }
};
