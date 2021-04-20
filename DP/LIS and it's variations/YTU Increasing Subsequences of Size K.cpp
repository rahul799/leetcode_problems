Increasing Subsequences of Size K
Given a list of integers nums and an integer k, return the number of subsequences of size k that are strictly increasing.

    
    https://binarysearch.com/problems/Increasing-Subsequences-of-Size-K




Mod the result by 10 ** 9 + 7.

Constraints

n ≤ 1,000 where n is the length of nums.
k ≤ 10
Example 1
Input
nums = [1, 2, 3, 0]
k = 2
Output
3
Explanation
We have the following increasing subsequences of size 2: [1, 2], [2, 3], [1, 3]

https://www.geeksforgeeks.org/count-number-increasing-subsequences-size-k/


Approach: The idea is to use Dynamic Programming by define 2D matrix, say dp[][]. dp[i][j] stores the count of increasing subsequences of size i ending with 
element arr[j]. So dp[i][j] can be defined as:

dp[i][j] = 1, where i = 1 and 1 <= j <= n
dp[i][j] = sum(dp[i-1][j]), where 1 < i <= k, i <= j <= n and arr[m] < arr[j] for (i-1) <= m < j.


    
    
    
    

int solve(vector<int>& nums, int k) {
    int n = (int)nums.size(), dp[k][n], ans = 0, mod = 1e9 + 7;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) dp[0][i] = 1;
    for (int l = 1; l < k; l++) {
        for (int i = l; i < n; i++) {
            dp[l][i] = 0;
            for (int j = l - 1; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[l][i] = (dp[l][i] + dp[l - 1][j]) % mod;
                }
            }
        }
    }
    for (int i = k - 1; i < n; i++) {
        ans = (ans + dp[k - 1][i]) % mod;
    }
    return ans;
}
