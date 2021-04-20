https://binarysearch.com/problems/Max-Multiplied-Pairings-Sequel

Max Multiplied Pairings Sequel
You are given two lists of integers nums and multipliers.

For each i = 0 to i = multiplers.length - 1, inclusive, perform the following operation:

Remove one integer e from either the beginning or the end of nums
Add multipliers[i] * e to your running total
Return the maximum total possible after performing the operations.

Constraints

0 ≤ m ≤ n ≤ 1,000 where n is the length of nums and m is the length of multipliers
Example 1
Input
nums = [5, 2, -7]
multipliers = [2, 4, -1]
Output
25
Explanation
We can get 5 * 2 + 2 * 4 + -7 * -1 = 25





vector<vector<int>> dp;

int helper(vector<int>& nums, vector<int>& multiplier, int idx, int start, int end) {
    if (idx == multiplier.size()) return 0;

    if (start == end) return dp[idx][start] = nums[start] * multiplier[idx];
    if (dp[idx][start] != -1) return dp[idx][start];

    int op1 = nums[start] * multiplier[idx] + helper(nums, multiplier, idx + 1, start + 1, end);

    int op2 = nums[end] * multiplier[idx] + helper(nums, multiplier, idx + 1, start, end - 1);

    return dp[idx][start] = max(op1, op2);
}

int solve(vector<int>& nums, vector<int>& multipliers) {
    dp.clear();
    dp.resize(nums.size(), vector<int>(multipliers.size(), -1));
    return helper(nums, multipliers, 0, 0, nums.size() - 1);
}
