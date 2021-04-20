Circular Longest Increasing Subsequence
Given a list of integers nums, find the length of the longest increasing subsequence assuming the subsequence can wrap around to the beginning of the list.

Constraints

n ≤ 1,000 where n is the length of nums.
Example 1
Input
nums = [5, 4, 7, 1, 2, 3]
Output
5
Explanation
One longest increasing subsequence is [1, 2, 3, 5, 7]



Binary Search
The idea is to calculate LIS in \mathcal{O}(N\log N)O(NlogN). Cyclic array just means that the array has been appended to itself and we are then looking at every subarray of length N, starting at some index in the original array.
i.e. Suppose the original array nums has length NN and thus indices in the range [0, N - 1][0,N−1]. Further, let dups be another array, ST dups = nums + numsdups=nums+nums, nums appended to itself. Then circular arrays of nums just mean all the subarrays of length NN in dups and starting at index in [0, N - 1][0,N−1].
So, we do as directed, generate all such subarrays, calculate their LIS and find the max of them.

Implementation
Create a subroutine for calculating LIS in \mathcal{O}(N\log N)O(NlogN) and call it for every subarray as described above.

Time Complexity
Call \mathcal{O}(N\log N)O(NlogN) LIS routine for N times, thus - \mathcal{O}(N^2\log N)O(N 
2
 logN)

Space Complexity
NN size space both for computing LIS as well as for storing temporary NN size subarray, thus - \mathcal{O}(N)O(N)

/*
 *   A sub-routine that calculates LIS in O(N.Log(N)) for a given vector of nums
 *   Look at this awesome resource for learning O(N.log(N)) LIS:
 *   https://cp-algorithms.com/sequences/longest_increasing_subsequence.html#toc-tgt-6
 */
int longestIncreasingSubsequence(vector<int>& nums) {
    int sz = nums.size();
    if (!sz) return 0;

    vector<int> dp(sz + 1, INT_MAX);
    dp[0] = INT_MIN;
    for (int i = 0; i < sz; ++i) {
        int idx = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
        if (idx != sz + 1 && dp[idx - 1] < nums[i]) dp[idx] = nums[i];
    }

    int res = 0;
    for (int i = 1; i <= sz; ++i) res = dp[i] != INT_MAX ? i : res;
    return res;
}

int solve(vector<int>& nums) {
    if (nums.empty()) return 0;

    int sz = nums.size(), res = 0;

    /*
     * generate all possible subarrays and calulate the LIS for them.
     */
    for (int i = 0; i < sz; ++i) {
        vector<int> dups;
        for (int j = 0; j < sz; ++j) dups.push_back(nums[(i + j) % sz]);
        res = max(res, longestIncreasingSubsequence(dups));
    }

    return res;
}
