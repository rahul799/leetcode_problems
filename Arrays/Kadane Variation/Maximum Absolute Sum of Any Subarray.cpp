

1749. Maximum Absolute Sum of Any Subarray
Medium

63

0

Add to List

Share
You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.
 

Example 1:

Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
Example 2:

Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104





int maxAbsoluteSum(vector<int>& nums) {
    int res = 0, max_sum = 0, min_sum = 0;
    for (auto n : nums) {
        max_sum = max(0, n + max_sum);
        min_sum = min(0, n + min_sum);
        res = max({res, max_sum, -min_sum});
    }
    return res;
}




class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        // int mp = 0;
        // int mn = 0;
        // int res = 0;
        // for(auto n: nums){
        //     res += n;
        //     mp = max(mp, res);
        //     mn = min(mn, res);
        // }
        // return mp - mn;
        int cur_max = nums[0],cur_min = nums[0];
        int max_sum = nums[0],min_sum = nums[0];
        
        for(int i=1;i<nums.size();i++){
            int n = nums[i];
            cur_max = max(cur_max+n,n);
            max_sum = max(cur_max,max_sum);
            cur_min = min(cur_min+n,n);
            min_sum = min(min_sum, cur_min);
        }
        return max({0,abs(max_sum),abs(min_sum)});
    }
};
