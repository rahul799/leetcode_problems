673. Number of Longest Increasing Subsequence
Medium

Given an integer array nums, return the number of longest increasing subsequences.

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.



class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
         /* count and length */
        vector<pair<int, int>>LIS(n, {1, 1}); 
        int maxlen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (LIS[i].second == 1 + LIS[j].second) {
                        LIS[i].first += LIS[j].first;
                    } else if (LIS[i].second < 1 + LIS[j].second) {
                        LIS[i].first = LIS[j].first;
                        LIS[i].second = 1 + LIS[j].second;
                    }
                }
            }
            maxlen = max(maxlen, LIS[i].second);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (LIS[i].second == maxlen)
                ans += LIS[i].first;
        }
        
        return ans;
    }
};
