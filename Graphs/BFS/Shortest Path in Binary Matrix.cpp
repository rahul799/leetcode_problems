1091. Shortest Path in Binary Matrix

Share
In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.









class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return -1;
        if (grid[0][0] == 1 || grid.back().back() == 1) return -1;

        vector<vector<int>> dirs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}});
        queue<vector<int>> q;
        q.push(vector<int>({0, 0, 1}));
        grid[0][0] = 2;
        while (!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            int s   = q.front()[2];
            q.pop();

            if (x == grid.size() - 1 && y == grid[0].size() - 1) {
                return s;
            }
            for (auto &dir : dirs) {
                int i = x + dir[0], j = y + dir[1];
                if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] != 0)
                    continue;
                q.push(vector<int>({i, j, s + 1}));
                grid[i][j] = 2;
            }
        }
        return -1;
    }
};














/ class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int M = grid.size();
//         int N = grid[0].size();
        
//         if(grid[0][0] !=0 || grid[M-1][N-1] != 0)
//             return -1;
//         queue<pair<int, int>> points;
//         points.push({0,0});
//         grid[0][0] = 1;
//         while(!points.empty()){
//             pair<int, int> currentCell = points.front();
//             points.pop();
//             if(currentCell == make_pair(M-1, N-1)){
//                 return grid[M-1][N-1];
//             }
//             pair<int, int> directions[8] = {{0,1}, {0, -1}, {1, 0}, {1, 1}, {1, -1}, {-1, 0},
//                                             {-1, -1}, {-1, 1}};
//             for( auto direction: directions){
//                 int x = currentCell.first + direction.first;
//                 int y = currentCell.second + direction.second;
//                 if(x >=0 && x < grid.size() && y >=0 && y < grid[0].size() && grid[x][y] == 0){
//                     points.push({x, y});
//                     grid[x][y] = grid[currentCell.first][currentCell.second] + 1;
//                 }
                
//             }
            
            
//         }
//         return -1;
        
//     }   
    
// };

