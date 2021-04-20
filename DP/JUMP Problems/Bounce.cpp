Bounce



https://binarysearch.com/problems/Bounce
You are given a list of integers nums and an integer k. Given you start at index k and at any index i, you can go left or right by exactly nums[i] steps. Return whether
you can reach the end of the list.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [0, 0, 1, 2, 0, 3]
k = 2
Output
true
Explanation
We start at index 2, then jump to index 3 and then jump to the last index 5.

Example 2
Input
nums = [0, 2, 0]
k = 1
Output
false
Explanation
We must reach the last index exactly.





bool dfs(vector<int>& nums, int pos,  vector<bool>& visited) {
    if (pos < 0 || pos >= nums.size()) return false;
    if (pos == nums.size() - 1) return true;
    if (!visited[pos]) {
        visited[pos] = true;
        return dfs(nums, pos + nums[pos], visited) || dfs(nums, pos - nums[pos],visited);
    }
    return false;
}

bool solve(vector<int>& nums, int k) {
        vector<bool> visited;

    visited.resize(nums.size());
    return dfs(nums, k, visited);
}
