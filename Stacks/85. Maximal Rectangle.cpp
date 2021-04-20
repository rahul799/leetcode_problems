
85. Maximal Rectangle
Hard

2956

71

Add to List

Share
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6



class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int maxarea = 0;
        vector<int> dp(matrix[0].size(), 0);

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {

                // update the state of this row's histogram using the last row's histogram
                // by keeping track of the number of consecutive ones

                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            // update maxarea with the maximum area from this row's histogram
            maxarea = max(maxarea, largestRectangleArea(dp));
        } 
        return maxarea;
    }
    
     // Get the maximum area in a histogram given its heights
    int largestRectangleArea(vector<int>& heights) {
        int h;
        stack<int> st;
        st.push(-1);
        int maxarea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (st.top() != -1 && heights[st.top()] >= heights[i]) {
                h = st.top(); st.pop();
                maxarea = max(maxarea, heights[h] * (i - st.top() - 1));
            }
            st.push(i);
        }
        while (st.top() != -1) {
            h = st.top(); st.pop();
            maxarea = max(maxarea, heights[h] * ((int)heights.size() - st.top() -1));
        }
        return maxarea;
    }
    
};
