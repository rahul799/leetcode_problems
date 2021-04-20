1745. Palindrome Partitioning IV
Hard

104

1

Add to List

Share
Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.​​​​​

A string is said to be palindrome if it the same string when reversed.

 

Example 1:

Input: s = "abcbdd"
Output: true
Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.
Example 2:

Input: s = "bcbddxy"
Output: false
Explanation: s cannot be split into 3 palindromes.
 

Constraints:

3 <= s.length <= 2000
s​​​​​​ consists only of lowercase English letters.

https://leetcode.com/problems/palindrome-partitioning-iv/discuss/1042902/Here's-your-Cake


To cut a cake in 3 pieces, we need 2 cuts. Hence, if we can pick 2 indices (p, s) in the array, we can cut the string in 3 parts. This would look like :

str[0...p] + str[p + 1, ... s - 1] + str[s, ... n - 1]
For the constraints, notice that :

The first part is non-empty, implying that p >= 0
The second part is non-empty, implying that p + 1 <= s - 1
The third part is non-empty, implying that s <= n - 1
So, for each cut, we need to determine if a particular substring is a palindrome. Let's create a DP table which can answer the queries of the form,

Is the substring str[i...j] a palindrome?

This is a very standard DP table, and you might've also encountered it in other Palindrome Partition problems. To summarise,

Prepare the DP table in O(n^2).
Pick every (p, s) pairs in the array. (There are n^2 such pairs).
Query the DP table in O(1) to see whether any partition is a palindrome.
class Solution {
public:
    bool checkPartitioning(string str) {
        int n = str.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        /* dp[i][j] is true if str[i...j] is palindrome */
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                int len = j - i + 1;
                if(len == 1) {
                    dp[i][j] = true;
                }
                else if(len == 2) {
                    dp[i][j] = (str[i] == str[j]);
                }
                else {
                    dp[i][j] = (str[i] == str[j]) and (dp[i + 1][j - 1]);
                }
            }
        }
        
        for(int p = 0; p < n; p++) {
            for(int s = p + 2; s < n; s++) {
                auto left = dp[0][p];
                auto mid = dp[p + 1][s - 1];
                auto right = dp[s][n - 1];
                if(left and mid and right) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
