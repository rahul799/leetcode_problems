
Subsequence Sum
Question 178 of 931
Given a list of integers nums, select a subsequence of strictly increasing numbers, where the differences of each two numbers is the same as the differences of their two indexes.

Return the maximum sum of such a subsequence.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [5, 6, 8, 8, 7, 4]
Output
19
Explanation
We pick the subsequence [5, 6, 8] which has the indexes [0, 1, 3]. The differences between each consecutive numbers is [1, 2] which is the same as the differences of their indexes.







// what is the maximum largest sum of all numbers that are equal, because each increasing sequence with j-i == nums[j] - nums[i] means that now they are equal.



int solve(vector<int>& nums) {
    unordered_map<int, int> mp;
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        mp[nums[i] - i] += nums[i];

        res = max(res, mp[nums[i] - i]);
    }
    return res;
}
