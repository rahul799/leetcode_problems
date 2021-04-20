698. Partition to K Equal Sum Subsets

Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

 
 
 
 
 class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(k == 0 or sum % k != 0)  return false;
        vector<bool> seen(nums.size());
        return dfs(nums, k -1, sum/k, 0, 0, seen);
    }
    bool dfs(vector<int> &nums, int k, int target, int sum, int start, vector<bool> &seen) {
        if(k == 0)  return true;
        if(sum == target)   return dfs(nums, k-1, target, 0, 0, seen);
        
        for(int i = start; i < nums.size(); i++) {
            if(!seen[i]) {
                seen[i] = 1;
                if(dfs(nums, k, target, sum+nums[i], i+1, seen))    return true;
                
                seen[i] = 0;
            }
        }
        return false;
    }
};





class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(k == 0 or sum % k != 0)  return false;
        vector<bool> seen(nums.size());
        return dfs(nums, k, sum/k, 0, 0, seen);
    }
    bool dfs(vector<int> &nums, int k, int target, int sum, int start, vector<bool> &seen) {
        if(k == 1)  return true;
        if(sum == target)   return dfs(nums, k-1, target, 0, 0, seen);
        
        for(int i = start; i < nums.size(); i++) {
            if(!seen[i]) {
                seen[i] = 1;
                if(dfs(nums, k, target, sum+nums[i], i+1, seen))    return true;
                
                seen[i] = 0;
            }
        }
        return false;
    }
};
