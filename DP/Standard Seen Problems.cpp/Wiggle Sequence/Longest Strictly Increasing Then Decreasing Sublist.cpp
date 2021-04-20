Longest Strictly Increasing Then Decreasing Sublist
Question 698 of 1000
You are given a list of integers nums. Return the length of the longest sublist such that its length is at least 3 and its values are strictly 
increasing and then decreasing. Both the increasing part and the decreasing part must be non-empty.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [7, 1, 3, 5, 2, 0]
Output
5
Explanation
The sublist [1, 3, 5, 2, 0] is strictly increasing then decreasing.

Example 2
Input
nums = [1, 2, 3]
Output
0
Example 3
Input
nums = [3, 2, 1]
Output
0
Example 4
Input
nums = [1, 2, 1, 1]
Output
3


We have two arrays, increasing and decreasing. Increasing[i] = maximum length of increasing subarray that ends with the ith element. 
decreasing[i] = maximum length of decreasing subarray that starts with the ith element. Then, the answer is essentially the maximum value of 
increasing[i]+decreasing[i]-1 for all \mathcal{1\leq{i}\leq{array.size()}}1≤i≤array.size(). We subtract one because we counted the ith element 
twice in the total length.

Finding the values of increasing[i] and decreasing[i] is quite simple.
 , decreasing[i]=decreasing[i+1]+1. Else decreasing[i]=1.

Because we want the length of the subarray to be greater than or equal to three, we only calculate the length when increasing[i] and decreasing[i] are both greater than 1.





int solve(vector<int>& nums) {
    vector<int> decreasing(nums.size(), 1);
    vector<int> increasing(nums.size(), 1);

    for (int i = nums.size() - 2; i >= 0; --i) {
        if (nums[i] > nums[i + 1]) decreasing[i] = decreasing[i + 1] + 1;
    }

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > nums[i - 1]) increasing[i] = increasing[i - 1] + 1;
    }

    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (increasing[i] > 1 && decreasing[i] > 1)
            ans = max(ans, increasing[i] + decreasing[i] - 1);
    }

    if (ans < 3)
        return 0;
    else
        return ans;
}
