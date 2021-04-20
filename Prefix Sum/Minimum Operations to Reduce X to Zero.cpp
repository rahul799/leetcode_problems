1658. Minimum Operations to Reduce X to Zero
Medium

577

13

Add to List

Share
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109








class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int size = nums.size();
        int sum = 0;
        for(int i = 0; i < size; i++) {
            sum += nums[i];
        }
        int target = sum - x;
        if(target == 0) {
            return size;
        }
        int start = 0, maxLength = INT_MIN;
        sum = 0;
        for(int i = 0; i < size; i++) {
            sum += nums[i];
            while(start < i && sum > target) {
                sum-= nums[start++];
            }
            if(start <= i && sum == target) {
                maxLength = max(maxLength, i - start + 1);
            }
        }
        return (maxLength == INT_MIN? -1: (size - maxLength));
    }
};
