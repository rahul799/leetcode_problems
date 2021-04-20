
https://binarysearch.com/problems/Number-of-Sublists-With-Small-Left-Value



Number of Sublists With Small Left Value
Question 947 of 1000
Given a list of integers nums, return the number of sublists where the first element is not bigger than other numbers in the sublist.

Constraints

0 ≤ n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [1, 3, 5, 2]
Output
8
Explanation
We have the following sublists which meet the criteria:

[1]
[1, 3]
[1, 3, 5]
[1, 3, 5, 2]
[3]
[3, 5]
[5]
[2]



int solve(vector<int>& nums) {
    stack<int> s;
    int ans = 0, n = nums.size();
    for( int i = n - 1; i >= 0; i-- ) {
        while(!s.empty() and nums[s.top()] >= nums[i]) s.pop();
        int last = (s.empty() ? n : s.top());
        ans += (last - i);
        s.push(i);
    }
    return ans;
}
