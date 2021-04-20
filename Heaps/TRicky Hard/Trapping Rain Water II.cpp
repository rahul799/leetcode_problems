

https://leetcode.com/problems/trapping-rain-water-ii/


407. Trapping Rain Water II
Hard

1731

37

Add to List

Share
Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.


The above image represents the elevation map [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.

 



After the rain, water is trapped between the blocks. The total volume of water trapped is 4.

 

Constraints:

1 <= m, n <= 110
0 <= heightMap[i][j] <= 20000




class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
     int m = heightMap.size();
     int n = heightMap.front().size();
    // We need min-heap.
    priority_queue<
      pair<int, pair<int, int>>, 
      vector<pair<int, pair<int, int>>>, 
      greater<pair<int, pair<int, int>>>> q;

    // visited matrix.
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j)
        if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
          q.push({heightMap[i][j], {i, j}}), visited[i][j] = true;
    
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int ans = 0;    
    while (!q.empty()) {
      auto t = q.top(); q.pop();
      auto h = t.first;
      auto [y, x] = t.second;

      for ( auto& d : dir) {
        auto ny = y + d[0];
        auto nx = x + d[1];
        if ((ny >= 0 && ny < m && nx >= 0 && nx < n) && !visited[ny][nx]) {
          if (heightMap[ny][nx] < heightMap[y][x]) {
            ans += (heightMap[y][x] - heightMap[ny][nx]);         
            heightMap[ny][nx] = heightMap[y][x];
          }
          q.push({heightMap[ny][nx], {ny, nx}});
          visited[ny][nx] = 1;
        }
      }
    }
    return ans;
  }
};
