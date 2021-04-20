55. Jump Game

Share
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 3 * 10^4
0 <= nums[i][j] <= 10^5





class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return true;
        
        int max_so_far = 0;
        
        for(int i = 0; i < n-1; i++){
    // when we reached a zero index
            if(nums[i] == 0 and i == max_so_far)
                return false;
            
            if(i + nums[i] >= n-1)
                return true;
            max_so_far = max(max_so_far, i + nums[i]);
        }
        return false;
    }
};












TLE

// //backtracking approach

// class Solution {
// public:
//     bool canJumpFromPosition(int position, vector<int>& nums) {
        
//      if (position == nums.size() - 1) {
//             return true;
//         }
//    int a = position + nums[position];
//         int b = nums.size() - 1;
//         int furthestJump = min(a, b);
//         for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++) {
//             if (canJumpFromPosition(nextPosition, nums)) {
//                 return true;
//             }
//         }
//         return false;
//     }

//     public:
//     bool canJump(vector<int>& nums) {
//         return canJumpFromPosition(0, nums);
//     }

        
    
// };
