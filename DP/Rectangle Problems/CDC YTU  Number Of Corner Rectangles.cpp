






https://leetcode.com/problems/number-of-corner-rectangles/discuss/188581/Google-follow-up-question.-A-general-case-solution.

750. Number Of Corner Rectangles
Medium

511

78

Add to List

Share
Given a grid where each entry is only 0 or 1, find the number of corner rectangles.

A corner rectangle is 4 distinct 1s on the grid that form an axis-aligned rectangle. Note that only the corners need to have the value 1. Also, all four 1s used must be distinct.

 

Example 1:

Input: grid = 
[[1, 0, 0, 1, 0],
 [0, 0, 1, 0, 1],
 [0, 0, 0, 1, 0],
 [1, 0, 1, 0, 1]]
Output: 1
Explanation: There is only one corner rectangle, with corners grid[1][2], grid[1][4], grid[3][2], grid[3][4].
 

Example 2:

Input: grid = 
[[1, 1, 1],
 [1, 1, 1],
 [1, 1, 1]]
Output: 9
Explanation: There are four 2x2 rectangles, four 2x3 and 3x2 rectangles, and one 3x3 rectangle.
 

Example 3:

Input: grid = 
[[1, 1, 1, 1]]
Output: 0
Explanation: Rectangles must have four distinct corners.
 

Note:

The number of rows and columns of grid will each be in the range [1, 200].
Each grid[i][j] will be either 0 or 1.
The number of 1s in the grid will be at most 6000.
 



class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<unordered_map<int,int>>> dp(col, vector<unordered_map<int,int>> (col, unordered_map<int,int>()));
        unordered_map<int, int> appeared_num;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                for(int q = j + 1; q < col; ++q) {                    
                    if(grid[i][j] == grid[i][q]) {
                        int num = grid[i][q];
                        auto & m = dp[j][q];
                        if(m.count(num))
                            m[num]++;
                        else
                            m[num] = 0;
                        appeared_num[num] += m[num];
                    }
  
                }
            }
        }
        // for(auto& n: appeared_num){
        //     cout << n.first << ":" << n.second << endl;
        // }
        return appeared_num[1];
    }
};
