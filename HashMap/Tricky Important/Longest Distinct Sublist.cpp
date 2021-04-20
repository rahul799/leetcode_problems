Longest Distinct Sublist
Given a list of integers nums, return the length of the longest contiguous sublist where all its elements are distinct.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [5, 1, 3, 5, 2, 3, 4, 1]
Output
5
Explanation
The longest list of distinct elements is [5, 2, 3, 4, 1].







int solve(vector<int>& nums) {
    int n = nums.size();
    int len = 0;
    int s = -1;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (mp.find(nums[i]) != mp.end()) {
            s = max(mp[nums[i]], s);
        }
        len = max(len, i - s);
        mp[nums[i]] = i;
    }
    return len;
}
