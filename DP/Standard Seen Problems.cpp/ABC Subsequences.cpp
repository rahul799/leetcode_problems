
https://binarysearch.com/problems/ABC-Subsequences
ABC Subsequences
Given a string s consisting of "a", "b" and "c"s, return the number of subsequences that have i "a" characters, followed by j "b" characters, followed by k "c" 
characters where i, j, k ≥ 1.

Example 1
Input
s = "aabc"
Output
3



Intuition
We can use dynamic programming. dp[i]dp[i] represents the number of subsequences that end with t[i]t[i].

Time complexity: O(|S|)O(∣S∣)
Space complexity: O(1)O(1)

int solve(string s) {
    vector<int> dp(4);
    dp[0] = 1;
    string t = " abc";
    for (char c : s) {
        vector<int> ndp(dp);
        for (int i = 1; i <= 3; ++i)
            if (c == t[i]) ndp[i] += dp[i - 1] + dp[i];
        dp = move(ndp);
    }
    return dp[3];
}
