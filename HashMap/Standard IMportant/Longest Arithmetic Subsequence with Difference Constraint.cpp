
Longest Arithmetic Subsequence with Difference Constraint
Given a list of integers nums and an integer diff, return the length of the longest arithmetic subsequence where the difference between each consecutive numbers in the subsequence is diff.

Constraints

0 ≤ n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [-2, 0, 3, 6, 1, 9]
diff = 3
Output
4
Explanation
We can pick the subsequence [0, 3, 6, 9].

Example 2
Input
nums = [9, 8, 7, 5, 3]
diff = -2
Output
4
Explanation
We can pick the subsequence [9, 7, 5, 3].

int solve(vector<int>& nums, int diff) {
    int res = 0;
    unordered_map<int, int> hash;

    for (const auto& num : nums) res = max(res, hash[num] = hash[num - diff] + 1);
    return res;
}
