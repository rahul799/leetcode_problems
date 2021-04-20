

https://binarysearch.com/problems/Window-Limits


Window Limits
You are given a list of integers nums and integers window and limit. Return whether abs(nums[i] - nums[j]) ≤ limit for every i, j such that abs(i - j) < window.

Constraints

1 ≤ n ≤ 100,000 where n is the length of nums
1 ≤ window ≤ n
0 ≤ limit < 2 ** 31
Example 1
Input
nums = [1, 3, 7, 5]
window = 2
limit = 4
Output
true
Explanation
Every number within a window of size 2 has pair differences of at most 4 (from 3 and 7).

Example 2
Input
nums = [1, 3, 7, 5]
window = 3
limit = 4
Output
false
Explanation
Within a window size of 3 we have abs(1 - 7) > 4, so this is above the limit.




Intuition
Rather than checking for every element in the window, just check the maximum and minimum element of the window.
if the property holds for those element than it must hold for other pair of element's inside the window.

Implementation
we maintain two deque's
one to get the maximum and another for the minimum in constant time
for the minq if the element is less the dq.back() pop it until the condition holds and opposite for the maxq.
just check the case where it is invalid.
if no case found return true.
Time Complexity
\mathcal{O}(n)O(n) since we process every element twice once so it's overall linear

Space Complexity
\mathcal{O}(n)O(n) since we maintain two deque so the space it overall linear.

bool solve(vector<int>& nums, int k, int limit) {
    deque<int> minq, maxq;
    for (int i = 0; i < nums.size(); i++) {
        while (!minq.empty() and minq.front() <= i - k) minq.pop_front();
        while (!maxq.empty() and maxq.front() <= i - k) maxq.pop_front();
        while (!minq.empty() and nums[minq.back()] >= nums[i]) minq.pop_back();
        minq.push_back(i);
        while (!maxq.empty() and nums[maxq.back()] <= nums[i]) maxq.pop_back();
        maxq.push_back(i);
        if (!minq.empty() and !maxq.empty() and nums[maxq.front()] - nums[minq.front()] > limit) {
            return false;
        }
    }
    return true;
}
