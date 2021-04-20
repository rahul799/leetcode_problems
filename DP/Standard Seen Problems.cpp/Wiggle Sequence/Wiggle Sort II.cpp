
324. Wiggle Sort II
Medium

1301

642

Add to List

Share
Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

You may assume the input array always has a valid answer.

 

Example 1:

Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.
Example 2:

Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
0 <= nums[i] <= 5000
It is guaranteed that there will be an answer for the given input nums.
 

Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra spa


1, find the middle element "firstlast", by using nth_element() function,
2, get all the elements less than middle element "firstlast" into the odd positions,
3, get all the elements greater than middle element "firstlast" into the even positions,
4, in all the odd positions, swap all elements that equal to "firstlast" to the left,
5, in all the even positions, swap all elements that equal to "firstlast" to the right.

void wiggleSort(vector<int>& nums) {
        if (nums.size() < 2) return ;

        int size = nums.size();
        nth_element(nums.begin(), nums.begin()+ (size-1)/2, nums.end());
        int firstLast = nums[(size-1)/2];

        int cur0 = 0;
        int cur1 = 1;
        for (int i = 1; i < size; i += 2) {
            while (cur0 < size && nums[cur0] < firstLast) cur0 += 2;
            if (cur0 >= size) break;
            if (nums[i] < firstLast) swap(nums[i],nums[cur0]);
        }

        for (int i = 0; i < size; i += 2) {
            while (cur1 < size && nums[cur1] > firstLast) cur1 += 2;
            if (cur1 >= size) break;
            if (nums[i] > firstLast) {swap(nums[i],nums[cur1]);}
        }

        cur0 = 0;
        int front = size - 1;
        if (size%2 == 0) front = size - 2;
        while (cur0 < front) {
            if (nums[cur0] == firstLast) {
                cur0 += 2;
                continue;
            }
            else if (nums[front] != firstLast) {
                front -= 2;
                continue;
            }
            swap(nums[cur0],nums[front]);
        }

        cur1 = 1;
        front = size - 2;
        if (size%2 == 0) front = size - 1;
        while (cur1 < front) {
            if (nums[cur1] != firstLast) {
                cur1 += 2;
                continue;
            }
            else if (nums[front] == firstLast) {
                front -= 2;
                continue;
            }
            swap(nums[cur1],nums[front]);
        }
    }
