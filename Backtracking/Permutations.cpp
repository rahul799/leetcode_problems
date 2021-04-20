6. Permutations
Medium

4127

108

Add to List

Share
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]



class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false); // true if nums[i] is used
        dfs(nums, res, path, used);
        return res;
    }
    
 //here path is basically our permutation  
    
    void dfs( vector<int> & nums, vector<vector<int>> & res, vector<int> & path, vector<bool> & used)
    {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        
        // enumerate possible numbers for current position
        for (int i = 0 ; i < nums.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums, res, path, used);
                // restore
                path.pop_back();
                used[i] = false;
            }
        }
    }
};
