



45. Jump Game II
Medium

3869

174

Add to List

Share
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 105





class Solution {
public:
    int jump(vector<int>& A) {
        int n = A.size();
    
         if(n == 0){
        return 0;
    }
    int maxReachPos = A[0];
    int curMaxReachPos = A[0];
    int curStep = 1;
    for(int i = 1; i <= min(n-1, maxReachPos); i++){
        if(i == n - 1){
            return curStep;
        }
    curMaxReachPos = max(curMaxReachPos, i + A[i]);

        if(i == maxReachPos){
            maxReachPos = curMaxReachPos;
            curStep++;
        }
    }
    return 0;
        
    }
};
