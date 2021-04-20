



1793. Maximum Score of a Good Subarray
Hard

145

11

Add to List

Share
You are given an array of integers nums (0-indexed) and an integer k.

The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.

Return the maximum possible score of a good subarray.

 

Example 1:

Input: nums = [1,4,3,7,4,5], k = 3
Output: 15
Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15. 
Example 2:

Input: nums = [5,5,4,5,4,1,1,1], k = 0
Output: 20
Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 2 * 104
0 <= k < nums.length









class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i = k, j = k, ans = nums[k], minval = nums[k];
        while(i - 1 >= 0 && j + 1 < nums.size()){
            int leftval = nums[i-1];
            int rightval = nums[j + 1];
            
            int leftmin = min(leftval, minval);
            int rightmin = min(rightval, minval);
                if(leftmin > rightmin ){
                    
                    i--, 
                    minval = leftmin;
                    ans = max(ans, (j- i + 1)*leftmin);
                }
            else {
                
                j++, 
                minval = rightmin;
                ans =  max(ans, (j- i + 1)*rightmin);
            }
        }
        
        while(i - 1 >= 0){
            int leftval = nums[i-1];
            int leftmin = min(leftval ,minval);
            i--;
            minval = leftmin;
            ans = max(ans, leftmin*(j - i + 1));
            
        }
         while (j+1 < nums.size()) {
            int rightval = nums[j+1];
            int rightmin = min(rightval, minval);
            j++;
            minval = rightmin;
            ans = max(ans, rightmin*(j-i+1));
        }
        return ans;
    }
};
