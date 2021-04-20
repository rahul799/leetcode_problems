

741. Cherry Pickup
Hard

1496

89

Add to List

Share
You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

0 means the cell is empty, so you can pass through,
1 means the cell contains a cherry that you can pick up and pass through, or
-1 means the cell contains a thorn that blocks your way.
Return the maximum number of cherries you can collect by following the rules below:

Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.
 

Example 1:


Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
Output: 5
Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.
Example 2:

Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
Output: 0
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 50
grid[i][j] is -1, 0, or 1.
grid[0][0] != -1
grid[n - 1][n - 1] != -1










Assume [row1][column1] is a grid on the path going from top left corner to bottom right corner, which is steps moves away from bottom right corner and [row2][column2] is a position steps moves coming back from the bottom right corner. we use s, a partially filled 3-D table, to memorize all caculated moves s[row1][column1][row2].

Note: row1+column1 and row2+column2 are always the same. These two grids are actually 2n-2-row1-column1 (2n-2-row2-column2) moves away from bottom right corner.

class Solution {
    int populate(vector<vector<vector<int>>> &s, vector<vector<int>>& g, int r1, int c1, int r2, int n){
        int c2=r1+c1-r2;
        
        // invalid parameters or one of the grids is not reachable
        if (r1>=n || r2>=n || c1>=n || c2>=n || g[r1][c1]==-1 || g[r2][c2]==-1) return -2;
        
        // value already caculated
        if (s[r1][c1][c2]!=-1) return s[r1][c1][c2];
        
        // [r1][c1] and [r2][c2] are both at the bottom right corner 
        if (r1==n-1 && c1==n-1) return g[r1][c1];
        
        // backtracking towards right bottom corner 
        // on all four possible moves
        int d = populate(s,g,r1,c1+1,r2+1,n); 
        d = max(d, populate(s,g,r1+1,c1,r2+1,n));
        d = max(d, populate(s,g,r1,c1+1,r2,n));
        d = max(d, populate(s,g,r1+1,c1,r2,n));
        
        // is [r1][c1] and [r2][c2] a valid combination, or one of the grids is blocked?  
        if (d >= 0) {
            // picking up cherries from both grid(s)
            d += g[r1][c1];
            if(c1 != c2) d += g[r2][c2];
        }
        s[r1][c1][c2] = d;
        return d;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        // s is a partially filled backtracking table
        // s[i][j][k] is the max number of cherries picked 
        // going from [i][j] to the right bottom corner
        // and coming back to [k][i+j-k].
        // s[i][j][k]: -1 -- unchecked; -2 -- invalid move  
        vector<vector<vector<int>>> s(n, vector<vector<int>>(n, vector<int>(n, -1)));  
        int ret = populate(s,grid,0,0,0,n);
        if (ret < 0) return 0;
        return ret;
    }
};
