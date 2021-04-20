

63. Unique Paths II
Medium

2490

287

Add to List

Share
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.









class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;
        for(int i = 1 ; i <= m ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m][n];
    }
};







	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int numRows = obstacleGrid.size();
        int numCols = obstacleGrid[0].size();
        obstacleGrid[0][0] = 1;
        // For ease of logic, fill out the first row and column first.
        for (int column = 1; column < numCols; ++column) {
            if (obstacleGrid[0][column] == 1) {
                obstacleGrid[0][column] = 0;
            } else {
                obstacleGrid[0][column] = obstacleGrid[0][column - 1];
            }
        }
        for (int row = 1; row < numRows; ++row) {
            if (obstacleGrid[row][0] == 1) {
                obstacleGrid[row][0] = 0;
            } else {
                obstacleGrid[row][0] = obstacleGrid[row -1][0];
            }
        }
        for (int row = 1; row < numRows; ++row) {
            for (int col = 1; col < numCols; ++col) {
                if (obstacleGrid[row][col] == 1) {
                    obstacleGrid[row][col] = 0;
                } else {
                    obstacleGrid[row][col] =
                            obstacleGrid[row - 1][col] + obstacleGrid[row][col - 1];
                }
            }
        }
        return obstacleGrid[numRows - 1][numCols - 1];        
    }
