

Longest Sublist of 1s After K Sets
You are given a list of integers nums containing 1s and 0s and an integer k. Given that you can set at most k 0s to 1s, return the length of the longest sublist containing all 1s.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [1, 1, 1, 0, 0, 1, 0]
k = 2
Output
6
Explanation
We can set the two middle 0s to 1s and then the list becomes [1, 1, 1, 1, 1, 1, 0].


int solve(vector<int>& nums, int k) {
    int n = nums.size();
    int i = 0, cnt = 0, ans = 0;
    for (int j = 0; j < n; j++) {
        if (nums[j] == 0) {
            cnt++;
        }
        while (cnt > k) {
            if (nums[i] == 0) {
                cnt--;
            }
            i++;
        }
        ans = max(ans, j - i + 1);
    }
    return ans;
}
