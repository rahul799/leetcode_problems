90. Subsets II

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]


class Solution {
public:
    void subs( vector<vector<int> >&res,vector<int>&nums,int s,int n,vector<int> cur){
        if(s==n+1){
           return ;
        }
        res.push_back(cur);
        for(int i=s;i<n;i++){
           if(i>s && nums[i]==nums[i-1])continue;
            cur.push_back(nums[i]);
             
            subs(res,nums,i+1,n,cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(),nums.end());
        subs(res,nums,0,nums.size(),cur);
        
        return res;
    }
};
