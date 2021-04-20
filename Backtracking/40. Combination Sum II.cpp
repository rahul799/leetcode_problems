40. Combination Sum II


Share
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]






class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        vector<int> temp;
        vector<bool> used(candidates.size());
        sort(candidates.begin(),candidates.end());
        makeCombi(target,sol,temp,0,candidates);
        return sol;
    }
    void makeCombi(int remain,vector<vector<int>> &ans,vector<int>& temp,int start,vector<int>& candidates){
            if(remain == 0){
                ans.push_back(temp);
            }
             else if(remain<0)
                 return;       
        for(int i=start;i<candidates.size();i++){
            if(i!=start and candidates[i] == candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            makeCombi(remain-candidates[i],ans,temp,i+1,candidates);
            temp.pop_back();
        }
        
    }
};
