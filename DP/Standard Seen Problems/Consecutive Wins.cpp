Consecutive Wins
You are given integers n and k. Given that n represents the number of games you will play, return the number of ways in which you win k or less games consecutively. Mod the result by 10 ** 9 + 7.

Constraints

n ≤ 10,000
k ≤ 10
Example 1
Input
n = 3
k = 2
Output
7
Explanation
Here are the ways in which we can win 2 or fewer times consecutively:

"LLL"
"WLL"
"LWL"
"LLW"
"WWL"
"LWW"
"WLW"






int mod = 1e9 + 7;

int help(int n, int curr, int k, vector<vector<int>>& dp) {
    if (curr > k) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (dp[n][curr] != -1) {
        return dp[n][curr];
    }

    int ans = 0;
    ans += help(n - 1, curr + 1, k, dp);
    ans %= mod;
    ans += help(n - 1, 0, k, dp);
    ans %= mod;

    return dp[n][curr] = ans;
}
int solve(int n, int k) {
        vector<vector<int>> dp;

    dp.resize(n + 1, vector<int>(k + 1, -1));
    if (k == 0) {
        return 1;
    }
    return help(n, 0, k, dp);
}



















