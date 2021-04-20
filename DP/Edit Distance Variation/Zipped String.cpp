Zipped String
Question 55 of 951
Given lowercase alphabet strings a, b, and c return whether there's any way of obtaining c by merging characters in order from a and b.

Constraints

0 ≤ n ≤ 1,000 where n is the length of a
0 ≤ m ≤ 1,000 where m is the length of b
0 ≤ k ≤ 1,000 where k is the length of c
Example 1
Input
a = "abc"
b = "def"
c = "abdefc"
Output
true
Explanation
abdefc is an interleave since abc and def can be interleaved with: abdefc

Example 2
Input
a = "ab"
b = "cd"
c = "abdc"
Output
false
Explanation
Even though ab is in the right order in abdc, cd is backwards, so this is not an interleaving.



bool solve(string a, string b, string c) {
    if (a.size() + b.size() != c.size()) return false;
    vector<vector<bool>> dp(a.size() + 1, vector<bool>(b.size() + 1, false));
    dp[0][0] = true;
    if(a[0] == c[0]) dp[0][1] = true;
    if(b[0] == c[0]) dp[1][0] = true;

    for (int i = 0; i <= a.size(); i++) {
        for (int j = 0; j <= b.size(); j++) {
            if (j > 0) {
                dp[i][j] = dp[i][j - 1] && b[j - 1] == c[i + j - 1];
            }
            if (i > 0) {
                dp[i][j] = dp[i][j] || (dp[i - 1][j] && a[i - 1] == c[i + j - 1]);
            }
        }
    }
    return dp[a.size()][b.size()];
}
