Palindrome Splitting
Given a string s, return the number of ways to partition the string such that each part is a palindrome.

Constraints

n ≤ 15 where n is the length of s.
Example 1
Input
s = "abba"
Output
3
Explanation
We can have the following splits: ["a", "bb", "a"], ["a", "b", "b", "a"], ["abba"]


Intuition
here basically we use the recursion to try generating all possible palindromic substrings
it's approach is similar to stair case problem from i_th index we try to move to j_th index and check if s[i...j] is a palindrome , 
now if it is a palindrome then we check the number of ways to partition s[j+1...s.length()-1]
here i used a Memoization because we are calculating the repeated part again and again





bool is_pal(string &s, int i, int j) {
    while (i <= j) {
        if (s[i++] != s[j--]) {
            return false;
        }
    }
    return true;
}
int helper(string &s, int i, vector<int> &dp) {
    if (i == s.length()) return 1;
    if (dp[i] != -1) return dp[i];
    int ans = 0;
    for (int j = i; j < s.length(); j++) {
        if (is_pal(s, i, j)) {
            ans += helper(s, j + 1, dp);
        }
    }
    return dp[i] = ans;
}
int solve(string s) {
    vector<int> dp(s.length(), -1);
    return helper(s, 0, dp);
}
