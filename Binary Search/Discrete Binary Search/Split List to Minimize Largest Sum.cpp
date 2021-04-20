
Split List to Minimize Largest Sum
Question 839 of 905
Given a list of non-negative integers nums and an integer k, you can split the list into k non-empty sublists.

Return the minimum largest sum of the k sublists.

Constraints

k ≤ n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [1, 3, 2, 4, 9]
k = 2
Output
10
Explanation
We can split the list into these 2 sublists: [1, 3, 2, 4] and [9].







int sublistCount(vector<int>& nums, long long threshold) {
    int ret = 1;
    long long leftover = threshold;
    for (int val : nums) {
        if (val > leftover) {
            ret++;
            leftover = threshold;
        }
        leftover -= val;
    }
    return ret;
}

int solve(vector<int>& nums, int k) {
    long long lhs = *max_element(nums.begin(), nums.end());
    long long rhs = accumulate(nums.begin(), nums.end(), 0LL);
    while (lhs < rhs) {
        long long mid = (lhs + rhs) / 2;
        if (sublistCount(nums, mid) <= k)
            rhs = mid;
        else
            lhs = mid + 1;
    }
    return lhs;
}
