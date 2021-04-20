



959. Regions Cut By Slashes
Medium

1265

241

Add to List

Share
In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.

(Note that backslash characters are escaped, so a \ is represented as "\\".)

Return the number of regions.

 

Example 1:

Input:
[
  " /",
  "/ "
]
Output: 2
Explanation: The 2x2 grid is as follows:

Example 2:

Input:
[
  " /",
  "  "
]
Output: 1
Explanation: The 2x2 grid is as follows:

Example 3:

Input:
[
  "\\/",
  "/\\"
]
Output: 4
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
The 2x2 grid is as follows:

Example 4:

Input:
[
  "/\\",
  "\\/"
]
Output: 5
Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
The 2x2 grid is as follows:

Example 5:

Input:
[
  "//",
  "/ "
]
Output: 3
Explanation: The 2x2 grid is as follows:

 

Note:

1 <= grid.length == grid[0].length <= 30
grid[i][j] is either '/', '\', or ' '.
  
  
  
  




https://leetcode.com/problems/regions-cut-by-slashes/discuss/205674/C%2B%2B-with-picture-DFS-on-upscaled-grid


We can upscale the input grid to [n * 3][n * 3] grid and draw "lines" there. Then, we can paint empty regions using DFS and count them. 
  Picture below says it all. Note that [n * 2][n * 2] grid does not work as "lines" are too thick to identify empty areas correctly.
  
  
  
  
959. Regions Cut By Slashes
Medium

1265

241

Add to List

Share
In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.

(Note that backslash characters are escaped, so a \ is represented as "\\".)

Return the number of regions.

 

Example 1:

Input:
[
  " /",
  "/ "
]
Output: 2
Explanation: The 2x2 grid is as follows:

Example 2:

Input:
[
  " /",
  "  "
]
Output: 1
Explanation: The 2x2 grid is as follows:

Example 3:

Input:
[
  "\\/",
  "/\\"
]
Output: 4
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
The 2x2 grid is as follows:

Example 4:

Input:
[
  "/\\",
  "\\/"
]
Output: 5
Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
The 2x2 grid is as follows:

Example 5:

Input:
[
  "//",
  "/ "
]
Output: 3
Explanation: The 2x2 grid is as follows:

 

Note:

1 <= grid.length == grid[0].length <= 30
grid[i][j] is either '/', '\', or ' '.


class Solution {
public:
    void dfs(vector<vector<int>>& g, int i, int j) {
  if (i >= 0 && j >= 0 && i < g.size() && j < g.size() && g[i][j] == 0) {
    g[i][j] = 1;
      
    dfs(g, i - 1, j), dfs(g, i + 1, j), dfs(g, i, j - 1), dfs(g, i, j + 1);
  }
}
int regionsBySlashes(vector<string>& grid, int regions = 0) {
  vector<vector<int>> g(grid.size() * 3, vector<int>(grid.size() * 3, 0));
  for (auto i = 0; i < grid.size(); ++i)
    for (auto j = 0; j < grid.size(); ++j) {
      if (grid[i][j] == '/') g[i * 3][j * 3 + 2] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3] = 1;
      if (grid[i][j] == '\\') g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1;
    }
  for (auto i = 0; i < g.size(); ++i)
    for (auto j = 0; j < g.size(); ++j) if (g[i][j] == 0) dfs(g, i, j), ++regions;
  return regions;
}
};

