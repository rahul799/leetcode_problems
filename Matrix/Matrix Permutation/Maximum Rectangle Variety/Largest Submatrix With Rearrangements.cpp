
1727. Largest Submatrix With Rearrangements
Medium

102

3

Add to List

Share
You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.

Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.

 

Example 1:



Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
Output: 4
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.
Example 2:



Input: matrix = [[1,0,1,0,1]]
Output: 3
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 3.
Example 3:

Input: matrix = [[1,1,0],[1,0,1]]
Output: 2
Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
Example 4:

Input: matrix = [[0,0],[0,0]]
Output: 0
Explanation: As there are no 1s, no submatrix of 1s can be formed and the area is 0.
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m * n <= 105
matrix[i][j] is 0 or 1.


This question is an extension of https://leetcode.com/problems/max-area-of-island/



https://leetcode.com/problems/largest-submatrix-with-rearrangements/discuss/1020710/C%2B%2B-Clean-and-Clear-With-intuitive-pictures-O

This question is very similar to
84. Largest Rectangle in Histogram
85. Maximal Rectangle

They are both hard questions, so don't be frustrated if you cannot solve it in the contest.

First think of what we can do with a collection of histograms ? What is the largest rectangle we can form?
image

Unlike 84. Largest Rectangle in Histogram, the pillar in this question can be rearranged !
image

Feel better now? Yes, for each pillar it can centainly form a rectangle with it's right neighbors.
image
So we just iterate every pillar and calculate the maximum rectangle.

Now comes the tricky part for this question, we can view each row with its above as a collection of pillars!
And if the matrix[row][col] is 1 , we add the height of pillar in col by 1, height[row][col] = height[row - 1][col] + 1,
else if matrix[row][col] is 0, we reset the height of pillar in col as 0, height[row][col] = 0, because we can see it as broken pillar and hence useless.

Example
image

Code
In code I just use one dimensional array height[col] to record heights of pillar

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<int> height(n, 0);
		
		// view each row and its above as pillars 
        for(int i = 0; i < m; ++i){
			// calculate heights
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == 0) height[j] = 0;
                else height[j] += 1;
            }
			
			// sort pillars
            vector<int> order_height = height;
            sort(order_height.begin(), order_height.end());
			
			// iterate to get the maxium rectangle
            for(int j = 0; j < n; ++j){
                ans = max(ans, order_height[j] * (n - j));
            }
        }
        return ans;
    }
};
