https://binarysearch.com/problems/Double-String-Concatenation

Double String Concatenation
You are given a lowercase alphabet string s. In one operation, you can remove, insert or update any character in s. Return the minimum number of operations required such that s = t + t for any t.

Constraints

0 ≤ n ≤ 100 where n is the length of s
Example 1
Input
s = "abczbdc"
Output
2
Explanation
If we replace the "z" to "a" and remove the "d", then we get s = "abc" + "abc"


int helper(string &s1, string &s2, int i = 0, int j = 0) {
    int n = s1.length(), m = s2.length();
    if (n == 0) {
        return m;
    }
    if (m == 0) {
        return n;
    }
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = n; i >= 0; i--) {
        for (int j = m; j >= 0; j--) {
            if (i >= n) {
                dp[i][j] = m - j;
            } else if (j >= m) {
                dp[i][j] = n - i;
            } else if (s1[i] == s2[j]) {
                dp[i][j] = dp[i + 1][j + 1];
            } else {
                dp[i][j] = 1 + min({dp[i + 1][j + 1], dp[i + 1][j], dp[i][j + 1]});
            }
        }
    }
    return dp[0][0];
}

int solve(string s) {
    int n = s.length();
    int res = n;
    for (int i = 0; i < n; i++) {
        string s1 = s.substr(0, i), s2 = s.substr(i);
        res = min(res, helper(s1, s2));
    }
    return res;
}
