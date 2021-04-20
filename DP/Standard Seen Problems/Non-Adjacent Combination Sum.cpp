Non-Adjacent Combination Sum
Question 3 of 4
You are given a list of positive integers nums and an integer k. Return whether there exists a combination of integers in nums such that their sum is k and none of those elements are adjacent in the original list.

    
    
    
   https://binarysearch.com/room/Weekly-Contest-34-aDD9ZHbeO9?questionsetIndex=2

Constraints

n * k ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [1, 2, 2, 3]
k = 4
Output
true
Explanation
We can pick [1, 3] since they are non-adjacent and sums to 4

Example 2
Input
nums = [1, 3, 1]
k = 4
Output
false
Explanation
We can't pick [1, 3] or [3, 1] since they are adjacent.







bool solve(vector<int>& nums, int sum) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; ++i) {
        dp[i][nums[i]] = 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            if (i) dp[i][j] = dp[i - 1][j] || dp[i][j];
            if (i - 2 >= 0 && j >= nums[i]) {
                dp[i][j] = dp[i - 2][j - nums[i]] || dp[i][j];
            }
        }
    }

    return dp[n - 1][sum] == 1;
}
