




Create Palindrome After Deleting at Most K Characters



Given a string s and an integer k return whether you can delete at most k characters such that after the deletion s is a palindrome.

Constraints

n ≤ 1,000 where n is the length of s
Example 1
Input
s = "rzacecarx"
k = 2
Output
true
Explanation
If we remove the second and last character of s then we'd get "racecar" which is a palindrome.

Example 2
Input
s = "abcd"
k = 2
Output
false
Explanation
No matter which character we delete s can't become a palindrome.










bool solve(string s, int k) {
    int size = s.size();
    int dp[size + 1][size + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < size; ++i) {
        dp[i][i] = 1;
    }

    for (int l = 2; l <= size; ++l) {
        for (int i = 0; i < size - 1; ++i) {
            int j = i + l - 1;
            if (l == 2 and s[i] == s[j]) {
                dp[i][j] = 2;
            } else if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    int to_compare = size - dp[0][size - 1];
    if (to_compare <= k) {
        return true;
    }
    return false;
}
