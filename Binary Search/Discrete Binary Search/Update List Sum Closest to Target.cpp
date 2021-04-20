Update List Sum Closest to Target
Question 933 of 1000
You are given a list of positive integers nums and a positive integer target. Find the smallest number e ≥ 0 such that if we update every number in nums greater than e to e, the resulting list's sum would be closest in absolute value to target.




https://binarysearch.com/problems/Update-List-Sum-Closest-to-Target/editorials/3320119




Constraints




1 ≤ n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [2, 4, 3, 7, 7, 1]
target = 10
Output
2
Explanation
If we pick e = 2, then the resulting list becomes [2, 2, 2, 2, 2, 1] and its sum is 11.

Example 2
Input
nums = [3, 3, 3]
target = 100
Output
3
Explanation
There's no way to increase the sum of this list.




The basic idea is binary search. Even though we are asked to find the minimum absolute difference, we can still compare the target and our result to decide which direction we should go.

Implementation
There is a strange if condition in the code
if (diff > abs(s - target) || (diff == abs(s - target) && target >= s)), but initially it was just if (diff > abs(s - target)), the reason is that the problem has some ambiguous test cases. For example

[1,2], 1   -> 1
[2,2], 3   -> 2
For the first case, 1 and 0 should both be correct, but 0 is considered wrong. For the second case, similarly, 2 and 1 both are correct, but 1 is considered wrong answer. I figured that the author wants the sum to be less than target if the absolute difference is the same, thus we have this if condition

Time Complexity
\mathcal{O}(n*\log d )O(n∗logd), d is the maximum value in nums

Space Complexity






int solve(vector<int>& nums, int target) {
    int m = 0, n = *max_element(nums.begin(), nums.end());
    int diff = INT_MAX, choice = 0;
    while (m <= n) {
        int mid = m + (n - m) / 2, s = 0;
        for (int i : nums) s += (i > mid ? mid : i);
        if (s == target) return mid;
        else if (s > target) n = mid - 1;
        else m = mid + 1;
        if (diff > abs(s - target) || (diff == abs(s - target) && target >= s)) {
            diff = abs(s - target);
            choice = mid;
        }
    }   
    return choice;
}
