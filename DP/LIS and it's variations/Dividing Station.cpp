

Dividing Station
Question 213 of 978
Given a list of distinct positive integers nums, find the largest subset such that every pair of elements in the subset (i, j) satisfies either i % j = 0 or j % i = 0. Return the size of this subset.

Constraints

n ≤ 1,000 where n is the length of nums
Example 1
Input
nums = [3, 5, 10, 20, 21]
Output
3
Explanation
The largest satisfying subset is [5, 10, 20].

Example 2
Input
nums = [1, 3, 6, 24]
Output
4
Explanation
The largest satisfying subset is [1, 3, 6, 24




one case we want to handle in a divisible subset is that every pair of that subset must devide one other



int solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> dp(n, 1);
    if (n <= 1) {
        return n;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
