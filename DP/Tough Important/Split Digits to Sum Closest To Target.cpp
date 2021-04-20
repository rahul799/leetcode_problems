



https://binarysearch.com/contest/Weekly-Contest-44-pr2UzmqsSR?questionsetIndex=3



Split Digits to Sum Closest To Target
You are given a string s and an integer target. s represents a decimal number containing digits from 0 to 9. You can partition s into as many parts as you want and take the sum of its parts. Afterwards, return the minimum possible absolute difference to target.

Constraints

1 ≤ n, target ≤ 1,000 where n is the length of s
Example 1
Input
s = "112"
target = 10
Output
3
Explanation
We can partition s into "1" + "12" which sums to 13 and abs(13 - 10) = 3.

Example 2
Input
s = "500"
target = 300
Output
200
Explanation
The best we can do is split s into just "500" and abs(300 - 500) = 200

Example 3
Input
s = "1"
target = 9
Output
8
Explanation
We can only split s into just "1".


we use top down recursion with memo, with keeping certain thing in mind

there is no point in breaking the string in length more than 4 coz the target is max 1000 so we do go beyond it .
if the target is already achieved than we split the string it chunks of length 1
Implementation
we use a dp for memoizing the started of the recursive functions
curr represents the value of the current chunk.
Time Complexity
\mathcal{O}(n \cdot t)O(n⋅t) where n is length of string and t is target.

Space Complexity
\mathcal{O}(n \cdot t)O(n⋅t) coz we created a 2-d array for the states of function .

int help(string& s, int target, int i, vector<vector<int>>& dp) {
    if (target < 0) {
        int ret = 0;
        for (int k = i; k < s.length(); k++) {
            ret += (s[k] - '0');
        }
        return ret - target;
    }
    if (i == s.length()) return target;
    if (dp[i][target] != -1) return dp[i][target];
    int ret = 1e6, curr = 0;
    for (int t = i; t < i + 4 and t < s.length(); t++) {
        curr = curr * 10 + s[t] - '0';
        ret = min(ret, help(s, target - curr, t + 1, dp));
    }
    return dp[i][target] = ret;
}
int solve(string s, int target) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return help(s, target, 0, dp);
}
