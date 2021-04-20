11. Container With Most Water (Medium)
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

 



The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

 

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
Related Topics:
Array, Two Pointers

Similar Questions:

Trapping Rain Water (Hard)
Solution 1. Brute Force
// OJ: https://leetcode.com/problems/container-with-most-water/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int maxArea(vector<int>& A) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            if (!A[i]) continue;
            for (int j = i + 1 + ans / A[i]; j < N; ++j) {
                ans = max(ans, min(A[i], A[j]) * (j - i));
            }
        }
        return ans;
    }
};
Solution 2. Two Pointers
Keep two pointers L = 0, R = N - 1 and move them inwards. They form two edges of the container and the volumn is (R - L) * min(A[L], A[R]).

We start from the container with the maximum width. Now we need to decrease the width and try to increase the height if possible (compromising on width and looking forward to greater height).

The strategy of moving the pointers is that we always move the smaller edge inwards.

The reason is that if we move the greater edge, the volumn of the container won't increase -- the width of the container decreases by one, and the height of the container limited by the smaller edge won't increase.

If the height of the two edges are the same, moving either one is fine because the change won't increase the volumn either way. BUT, we shouldn't break here because the volumn might increase later. Example case [1, 100, 200, 1].

// OJ: https://leetcode.com/problems/container-with-most-water/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/container-with-most-water/discuss/6099/yet-another-way-to-see-what-happens-in-the-on-algorithm
class Solution {
public:
    int maxArea(vector<int>& A) {
        int ans = 0, L = 0, R = A.size() - 1;
        while (L < R) {
            ans = max(ans, (R - L) * min(A[L], A[R]));
            if (A[L] < A[R]) ++L; // Move the smaller edge
            else --R;
        }
        return ans;
    }
};
