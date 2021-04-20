611. Valid Triangle Number
Medium

1266

101

Add to List

Share
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].



public static int triangleNumber(int[] A) {
    Arrays.sort(A);
    int count = 0, n = A.length;
    for (int i=n-1;i>=2;i--) {
        int l = 0, r = i-1;
        while (l < r) {
            if (A[l] + A[r] > A[i]) {
                count += r-l;
                r--;
            }
            else l++;
        }
    }
    return count;
}



Sort nums to simplify the problem
Valid triangle condition: nums[l1] + nums[l2] > nums[l3] (presume l1 < l2 < l3)
arr[] caches the index of the end of l3 for current l2, which can be used as the start of l3 for the same l2 after l1 is increased.
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<int> arr(nums.size());
      int cnt = 0, l3;
      for (int l1 = 0; l1 < nums.size(); ++l1) {
        for (int l2 = l1 + 1; l2 < nums.size(); ++l2) {
          for (l3 = max(arr[l2], l2 + 1); l3 < nums.size() && (nums[l1] + nums[l2] > nums[l3]); ++l3) ;
          arr[l2] = l3;
          cnt += (l3 - l2 - 1);
        }
      }
      return cnt;
    }
};
