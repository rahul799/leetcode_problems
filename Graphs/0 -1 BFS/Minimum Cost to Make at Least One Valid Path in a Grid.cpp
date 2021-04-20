
https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/






1368. Minimum Cost to Make at Least One Valid Path in a Grid
Hard

407

5

Add to List

Share
Given a m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:
1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
Notice that there could be some invalid signs on the cells of the grid which points outside the grid.

You will initially start at the upper left cell (0,0). A valid path in the grid is a path which starts from the upper left cell (0,0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path doesn't have to be the shortest.

You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

Return the minimum cost to make the grid have at least one valid path.

 

Example 1:


Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
Output: 3
Explanation: You will start at point (0, 0).
The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
The total cost = 3.
Example 2:


Input: grid = [[1,1,3],[3,2,2],[1,1,4]]
Output: 0
Explanation: You can follow the path from (0, 0) to (2, 2).
Example 3:


Input: grid = [[1,2],[4,3]]
Output: 1
Example 4:

Input: grid = [[2,2,2],[2,2,2]]
Output: 3
Example 5:

Input: grid = [[4]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100



https://www.youtube.com/watch?v=dshUKuVLqaA&ab_channel=LearnCompetitiveProgrammingwithCodeChef


If, for example, our current cell arrow is "->" but we want to move to the cell below, then we incur 1 cost. This means that, there is an edge with cost 1 between the 2 cells.
If we move to the adjacent cell along the direction of arrow, we do not incur cost.


So, our problem becomes: find the shortest path from the source (0,0) to the target (m-1,n-1), on the graph where edge weight is either 0 or 1.


This is a special graph, and we can use 0-1 BFS to solve. O(N). See this: https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/


If we use Dijkstra's algorithm, the complexity is not optimal: O(NlogN).




WHen we have an edge of weight 0, we will push front in deque where as when we have an edge of weight 1 : we will pop back


class Solution {
public:
    int m, n;
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();    n = grid[0].size();
        
        if(grid.size()==1 && grid[0].size()==1) return 0;
        vector<vector<int>> mark(m, vector<int>(n, 0));
        deque<vector<int>> deq;
        deq.push_back({0,0,0});
        int row[4] = {0,0,1,-1};
        int col[4] = {1,-1,0,0};
        
        
        while(!deq.empty()){
            auto cur = deq.front();
            deq.pop_front();
            mark[cur[0]][cur[1]] = 1;
            if(cur[0]==m-1 && cur[1]==n-1)
                return cur[2];
            int dir = grid[cur[0]][cur[1]]-1;
            for(int i=0; i<4; i++){
                int r = row[i] + cur[0];
                int c = col[i] + cur[1];
                if(valid(r,c) && !mark[r][c])
                    if(r == row[dir] + cur[0] && c == col[dir] + cur[1])
                        deq.push_front({r,c,cur[2]});
                    else
                        deq.push_back({r,c,cur[2]+1});
            }

        }return -1;
        
    }
    
    bool valid(int r, int c){
        return r>=0 && r<m && c>=0 && c<n;
    }
};
