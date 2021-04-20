[LeetCode] Shortest Distance from All Buildings
 

You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.

 

This question gave us the coordinates of some buildings and the coordinates of some obstacles. Let us find a location to minimize the sum of the Manhattan distances to all buildings. At first I thought this question should be considered as the Best Meeting Point question. The difference is that there are obstacles in this question, which makes it infeasible to directly use the Manhattan distance calculation formula, because in some cases, the obstacle completely seals a building, then It should return -1 at this time. So this question can only be solved by the idea of ​​traversing the maze, then this question is the same as the previous Walls and GatesIt’s very similar, but it’s very troublesome to use DFS for this question, because our goal is to build a Distance Map, so the characteristics of BFS make it very suitable for establishing a distance field, and because DFS is a brain search in one direction, it will Facing the problem of updating the distance, the distance field is only established after the recursive function is called. Then we have to traverse the entire distance field again when we accumulate the distance field, which is very inefficient. The main reason is that the DFS search method is not suitable for the distance field, because after BFS traverses a point, it will not change the value of this point, and DFS will repeatedly change the value of the same point. I force the method written by DFS It is impossible to pass the last big set of OJ, so this problem should be solved by BFS honestly, or it needs to be traversed with the help of queue. We will perform a BFS traversal of the whole picture for each building location, and create it every time A distance field of dist, because our BFS traversal needs to mark the location that should be visited, and we don’t want to build a two-dimensional visit matrix, so what should we do? Here is a small trick. When we traverse the first time, both It is to find the position of 0. After the traversal, we assign it to -1, so that in the next round of traversal we will find the position of -1, and then assign them to -2, and so on until all buildings are traversed , And then update the values ​​of dist and sum during the traversal. Note that our dist is a local variable, initialized to grid every time, and the real distance field is accumulated in sum. Since the position of the building is 1 in the grid, so The initialization in dist is also 1, and it needs to be subtracted by adding it to sum. We use the value in sum to update the value of the result res, and finally according to the value of res to see if we want to return -1, see the code as follows:
 
 
 
 NOt completely clear
 
 
 
 class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int res = INT_MAX, buildingCnt = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0)), cnt = dist;
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++buildingCnt;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    int level = 1;
                    while (!q.empty()) {
                        int size = q.size();
                        for (int s = 0; s < size; ++s) {
                            int a = q.front().first, b = q.front().second; q.pop();
                            for (int k = 0; k < dirs.size(); ++k) {
                                int x = a + dirs[k][0], y = b + dirs[k][1];
                                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0 && !visited[x][y]) {
                                    dist[x][y] += level;
                                    ++cnt[x][y];
                                    visited[x][y] = true;
                                    q.push({x, y});
                                }
                            }
                        }
                        ++level;
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && cnt[i][j] == buildingCnt) {
                    res = min(res, dist[i][j]);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};






OPtimised


class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int res = INT_MAX, val = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> sum = grid;
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    res = INT_MAX;
                    vector<vector<int>> dist = grid;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        int a = q.front().first, b = q.front().second; q.pop();
                        for (int k = 0; k < dirs.size(); ++k) {
                            int x = a + dirs[k][0], y = b + dirs[k][1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == val) {
                                --grid[x][y];
                                dist [x] [y] = dist [a] [b] + 1 ;
                                sum [x] [y] + = dist [x] [y] - 1 ;
                                q.push({x, y});
                                res = min(res, sum[x][y]);
                            }
                        }
                    }
                    --val;                    
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
