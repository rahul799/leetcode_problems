Adjacent Differences
Question 442 of 978
Given a list of integers nums sorted in ascending order, remove k integers from the list such that the maximum difference between any two adjacent integers is minimized, and return the difference.

Constraints

n ≤ 1,000 where n is the length of nums
Example 1
Input
nums = [5, 10, 20, 300, 1000]
k = 2
Output
10
Explanation
Remove [300, 1000] to get the result of 10.







We will remove the elements from edges because removing an element from in between will increase the maximum difference.
Now after removing k elements from any of the edges, we will get a contiguous sublist of size n-k. So we will use the sliding window approach to find the minimum-maximum difference between any two adjacent elements by finding out the maximum difference in each window of size n-k. And minimum of those will be the answer.

Corner cases - when k is greater than or equal to n-1, then the answer will always be 0.

Time Complexity - O(n)
Space Complexity - O(n)

int solve(vector<int>& nums, int k) {
    int n = nums.size();
    if (n - 1 <= k) return 0;
    vector<int> diff;
    for (int i = 1; i < n; i++) {
        diff.push_back(nums[i] - nums[i - 1]);
    }
    int m = n - k - 1;
    deque<int> q;
    q.push_front(0);
    for (int i = 1; i < m; i++) {
        while (!q.empty() && diff[q.back()] <= diff[i]) q.pop_back();
        q.push_back(i);
    }
    int ans = diff[q.front()];
    for (int i = m; i < diff.size(); i++) {
        while (!q.empty() && q.front() <= i - m) q.pop_front();
        while (!q.empty() && diff[q.back()] <= diff[i]) q.pop_back();
        q.push_back(i);
        ans = min(ans, diff[q.front()]);
    }
    return ans;
}
