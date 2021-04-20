



https://binarysearch.com/problems/List-Partitioning-with-Inequality-Relation



List Partitioning with Inequality Relation
Question 847 of 905
Given a list of integers nums, we want to split the list into two non-empty sublists a and b such that every element in a is less than or equal to every element in b.

Return the smallest length of a that is possible. You can assume that the solution exists.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [2, 0, 1, 4, 3]
Output
3
Explanation
We can split the list into a = [2, 0, 1] and b = [4, 3].







int solve(vector<int>& nums) {
    int n = nums.size();
    int mn[n];
    memset(mn, 0, sizeof mn);
    mn[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        mn[i] = min(nums[i], mn[i + 1]);
    }
    int ans = 0;
    int mx = 0;
    for (int i = 0; i < n - 1; i++) {
        mx = max(mx, nums[i]);
        //   cout<<mx<<" "<<mn[i+1]<<endl;
        if (mx <= mn[i + 1]) {
            return i + 1;
        }
    }
    return ans;
}
