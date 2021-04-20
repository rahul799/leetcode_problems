
https://binarysearch.com/room/Weekly-Contest-32-oSuVsQ17Hc/editorials/2914004?questionsetIndex=1


Ball Moves





You are given a list of integers nums containing 0s and 1s where a 0 means the cell is empty and 1 means there's a ball there.

Return a new list of integers A of the same length where A[i] is set to the total distance required to move all the balls to A[i]. The distance to move a ball in index j to index i is defined to be abs(j - i).

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input

nums = [1, 1, 0, 1]
Output

[4, 3, 4, 5]


Intuition
if i figure out the total work to move the balls to i-1 index than i can easily figure out the total work to move the balls to i_thindex see how->

all the balls on the left will have to do 1 work more
all the balls on the right will have to do 1 work less
so first i calculated the work for i-1 index
and for work_at_ith_index= work at i-1_th index + left_balls - rightballs



Implementation
i calculated the work at 0_thindex that's the precomputation we have to do
left balls represent the number of balls to the left of index i where as rightballs represent the number of balls to the right of i

Time Complexity
\mathcal{O}(n)O(n) as we calculated the complete work in one go

Space Complexity
\rn





vector<int> solve(vector<int>& nums) {
    if (nums.size() == 0) return {};
    int leftballs = nums[0] == 1;
    int rightballs = accumulate(nums.begin(), nums.end(), 0) - leftballs;
    int n = nums.size();

    int work = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == 1) work += i;
    }
    vector<int> ans(n, 0);
    ans[0] = work;
    for (int i = 1; i < nums.size(); i++) {
        ans[i] = work + leftballs - rightballs;
        work = ans[i];
        rightballs -= nums[i];
        leftballs += nums[i];
    }
    return ans;
}
