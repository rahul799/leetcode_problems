

List Splitting to Consecutive Subsequences





Given a list of integers nums sorted in ascending order, return whether it can be split into any number of subsequences such that each 
subsequence has at least length 3 and is consecutively increasing.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [1, 2, 3, 3, 4, 5, 6]
Output
true
Explanation
We can split the list to [1, 2, 3] and [3, 4, 5, 6].

Example 2
Input
nums = [1, 2, 4]
Output
false







bool solve(vector<int>& nums) {
    unordered_map<int, int> cnt, subs;
    for (int num : nums) ++cnt[num];
    for (int num : nums)
        if (!cnt[num])
            continue;
        else if (subs[num - 1])
            --cnt[num], --subs[num - 1], ++subs[num];
        else if (cnt[num + 1] && cnt[num + 2])
            --cnt[num], --cnt[num + 1], --cnt[num + 2], ++subs[num + 2];
        else
            return false;
    return true;
}
