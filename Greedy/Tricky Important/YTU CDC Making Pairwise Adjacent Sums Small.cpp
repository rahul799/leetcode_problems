


Making Pairwise Adjacent Sums Small
You are given a list of non-negative integers nums and a non-negative integer k. Consider an operation where we select a single positive integer in nums and decrement it by 1.

Compute the minimum number of operations required such that every pair of adjacent values in the list sums to ≤ k. Return the result mod 10 ** 9 + 7.

Constraints

2 ≤ n ≤ 100,000 where n is the length of nums
0 ≤ k ≤ 10 ** 9
0 ≤ nums[i] ≤ 10 ** 9 for all 0 ≤ i < n
Example 1
Input
nums = [3, 5, 1, 4]
k = 4
Output
5
Explanation
We can decrement the list to [2, 2, 1, 3] which is a total of 5 decrements. Note that the sum of every adjacent pair is ≤ 4.


nce that happens, nums[0] + nums[1] fits the constraints and we can therefore ignore nums[0] from here on out, but now we have the same problem to solve exactly the list is one element shorter, and we can apply the above logic again and again until the list contains exactly two numbers.

Implementation
The intended solution is therefore as follows - decrement nums[0] until it is less than or equal to kk. After that, loop from 1 to len(nums) - 1 and greedily decrease nums[i] just enough so that nums[i-1] + nums[i] is less than or equal to kk.




  int solve(vector<int>& l, int x) {
        long long ret = 0;
        if (l[0] > x) {
            ret += l[0] - x;
            l[0] = x;
        }
        for (int i = 1; i < l.size(); i++) {
            if (l[i - 1] + l[i] > x) {
                ret += l[i - 1] + l[i] - x;
                l[i] = x - l[i - 1];
            }
        }
        return ret % 1000000007;
    }
