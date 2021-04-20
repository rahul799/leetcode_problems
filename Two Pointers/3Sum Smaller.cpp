


259. 3Sum Smaller
Medium

789

81

Add to List

Share
Given an array of n integers nums and an integer target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

Follow up: Could you solve it in O(n2) runtime?

 

Example 1:

Input: nums = [-2,0,1,3], target = 2
Output: 2
Explanation: Because there are two triplets which sums are less than 2:
[-2,0,1]
[-2,0,3]
Example 2:

Input: nums = [], target = 0
Output: 0
Example 3:

Input: nums = [0], target = 0
Output: 0
 

Constraints:

n == nums.length
0 <= n <= 300
-100 <= nums[i] <= 100
-100 <= target <= 100



class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size()<3)return 0;
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size()-2;++i){
            if(nums[i]+nums[i+1]+nums[i+2]>=target)break;
            int j=i+1,k=nums.size()-1;
            while(j<k){
                while(j<k && nums[i]+nums[j]+nums[k]>=target)k--;
                count+=k-j;
                j++;
            }
        }
        return count;
    }
};259. 3Sum Smaller
Medium

789

81

Add to List

Share
Given an array of n integers nums and an integer target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

Follow up: Could you solve it in O(n2) runtime?

 

Example 1:

Input: nums = [-2,0,1,3], target = 2
Output: 2
Explanation: Because there are two triplets which sums are less than 2:
[-2,0,1]
[-2,0,3]
Example 2:

Input: nums = [], target = 0
Output: 0
Example 3:

Input: nums = [0], target = 0
Output: 0
 

Constraints:

n == nums.length
0 <= n <= 300
-100 <= nums[i] <= 100
-100 <= target <= 100
