1293. Shortest Path in a Grid with Obstacles Elimination
Hard

545

8

Add to List

Share
Given a m * n grid, where each cell is either 0 (empty) or 1 (obstacle). In one step, you can move up, down, left or right from and to an empty cell.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m-1, n-1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

 

Example 1:

Input: 
grid = 
[[0,0,0],
 [1,1,0],
 [0,0,0],
 [0,1,1],
 [0,0,0]], 
k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10. 
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
 

Example 2:

Input: 
grid = 
[[0,1,1],
 [1,1,1],
 [1,0,0]], 
k = 1
Output: -1
Explanation: 
We need to eliminate at least two obstacles to find such a walk.
 

Constraints:

grid.length == m
grid[0].length == n
1 <= m, n <= 40
1 <= k <= m*n
grid[i][j] == 0 or 1
grid[0][0] == grid[m-1][n-1] == 0









class Solution {
public:

	vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
	int shortestPath(vector<vector<int>>& grid, int k) {
		int m = grid.size(), n = grid[0].size();
		queue<vector<int>> q;
		int step = 0;
		vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
		if (grid[0][0] == 1) { 
			q.push({0, 0, 1});
			visited[0][0][1] = true;
		}
		else { 
			q.push({0, 0, 0});
			visited[0][0][0] = true;
		}

		while (!q.empty()) { 
			int l = q.size();
			for (int i = 0; i < l; i++) { 
				vector<int> s = q.front();
				q.pop();
				if (s[2] == k + 1) { 
					continue;
				}

				if (s[0] == m - 1 && s[1] == n - 1) { 
					return step;
				}

				for (vector<int>& dir : dirs) { 
					int new_x = s[0] + dir[0];
					int new_y = s[1] + dir[1];
					//Note: validity, visited
					if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) { 
						if (grid[new_x][new_y] == 0 && !visited[new_x][new_y][s[2]]) { 
							q.push({new_x, new_y, s[2]});
							visited[new_x][new_y][s[2]] = true;
						}
						else if (grid[new_x][new_y] == 1 && !visited[new_x][new_y][s[2] + 1]){ 
							q.push({new_x, new_y, s[2] + 1});
							visited[new_x][new_y][s[2] + 1] = true;
						}
					}
				}
			}
			step++;
		}
		return -1;

	}
};
