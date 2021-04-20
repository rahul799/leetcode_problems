Minimize Amplitude After K Operations
Question 870 of 907
You are given a list of integers nums. Consider an operation where you pick any number in nums and

If the number is even, divide it by two.
Otherwise, multiply it by two.
Given that you can make any number of operations, return the minimum max(nums) - min(nums) value possible.

Constraints

1 ≤ n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [20, 9, 8]
Output
2
Explanation
We can divide 20 to get [10, 9, 8]. Then 10 - 8 = 2





int solve(vector<int>& nums) {
    set<long long> vals;
    for (int val : nums) {
        if (val % 2)
            vals.insert(2LL * val);
        else
            vals.insert(val);
    }
    long long ans = *vals.rbegin() - *vals.begin();
    while (*vals.rbegin() % 2 == 0) {
        long long curr = *vals.rbegin();
        vals.erase(curr);
        vals.insert(curr / 2);
        ans = min(ans, *vals.rbegin() - *vals.begin());
    }
    return ans;
}
