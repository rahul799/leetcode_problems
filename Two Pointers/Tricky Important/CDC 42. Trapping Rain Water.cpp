
42. Trapping Rain Water
Hard

10550

159

Add to List

Share
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105







class Solution {
public:
    int trap(vector<int>& A) {
         int summap = 0;
        int sumtot = 0;
        int n = A.size(); 
        
        for(int i = 0; i < n; i++) summap += A[i];
        
        int left = 0, right = n - 1;
        int leftbar = 0, rightbar = 0;
        while(left <= right) {
            leftbar = max(A[left], leftbar);
            rightbar = max(A[right], rightbar);
            
            if(leftbar <= rightbar) {
                sumtot += leftbar;
                left++;
            } else {
                sumtot += rightbar;
                right--;
            }
        }
        
        return sumtot - summap;
    }
        
    
};
// class Solution {
// public:
//     int trap(int A[], int n) {
       
// };
