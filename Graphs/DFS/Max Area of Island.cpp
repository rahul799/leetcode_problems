695. Max Area of Island

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four
edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.



 
 
 
 class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (grid[i][j] == 1) ans = max(ans, dfs(grid, i, j));
        return ans;
    }
private:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size(), area = 1;
        grid[row][col] = 2;
        vector<int> dir({-1,0,1,0,-1});
        for (int i = 0; i < 4; i++) {
            int r = row+dir[i], c = col+dir[i+1];
            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) 
                area += dfs(grid, r, c);
        }
        return area;
    }
};





class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, area = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int a = 0;
                    computeArea(grid, i, j, a);
                    area = max(area, a);
                }
            }
        }
        return area;
    }
private:
    void computeArea(vector<vector<int>>& grid, int i, int j, int& a) {
        int m = grid.size(), n = grid[0].size();
        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j]) {
            a++;
            grid[i][j] = 0;            
            computeArea(grid, i - 1, j, a);
            computeArea(grid, i + 1, j, a);
            computeArea(grid, i, j - 1, a);
            computeArea(grid, i, j + 1, a);
        }
    }
};



// class Solution {
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size(), ans = 0;
//         for (int i = 0; i < m; i++) 
//             for (int j = 0; j < n; j++) 
//                 if (grid[i][j] == 1) ans = max(ans, dfs(grid, i, j));
//         return ans;
//     }
// private:
//     int dfs(vector<vector<int>>& grid, int row, int col) {
//         int m = grid.size(), n = grid[0].size(), area = 1;
//         grid[row][col] = 2;
//         vector<int> dir({-1,0,1,0,-1});
//         for (int i = 0; i < 4; i++) {
//             int r = row+dir[i], c = col+dir[i+1];
//             if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) 
//                 area += dfs(grid, r, c);
//         }
//         return area;
     }
// };




// class Solution {
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int res = 0;
//         for(int i=0; i<grid.size(); i++){
//             for(int j=0; j<grid[0].size(); j++){
//                 if(grid[i][j] == 0) continue;
//                 res = max(res, find(grid, i, j));
//             }
//         }
//         return res;
//     }
//     int find(vector<vector<int>>& grid, int i, int j){
//         if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == 0) return 0;
//         grid[i][j] = 0;
//         return find(grid, i-1, j)+find(grid, i+1, j)+find(grid, i, j-1)+find(grid, i, j+1)+1;
//     }
// };
