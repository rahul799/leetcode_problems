300. Longest Increasing Subsequence.cpp


https://www.youtube.com/watch?v=qW1O1a40-No&ab_channel=AryanMittal

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 0){
            return 0;
        }
        
        vector<int> lis;
        
        lis.push_back(nums[0]);
        
        for(int i = 1; i<n; i++){
            
            if(nums[i] > lis.back()){
                lis.push_back(nums[i]);
            }
            else{
                
                int p = lower_bound(lis.begin(),lis.end(),nums[i]) - lis.begin();
                
                lis[p] = nums[i];
            }
        }
        
        return lis.size();
    }
};
