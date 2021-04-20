

Social Distancing 2
You are given a two-dimensional integer matrix containing either a 0 or a 1. A 0 signifies an empty space, and a 1 signifies a square with a person. A distance between two squares is defined as the maximum between the difference in x coordinates and the difference in y coordinates.

The grid is considered safe with a factor k if there is an empty square such that the distance from the square to each person in the grid, and each side of the grid is all greater or equal to k.

Return the maximum value of factor k for which you can be safe.

Constraints

n, m ≤ 1,000
All of the outermost squares are guaranteed to be 1.
Example 1
Input
matrix = [
    [1, 1, 1],
    [1, 0, 1],
    [1, 1, 1]
]
Output
1
Explanation
In the middle empty cell the distance from the square to each person in the grid is at least 1.

Example 2
Input
matrix = [
    [1, 1, 1, 1, 1, 1],
    [1, 1, 0, 0, 1, 1],
    [1, 0, 0, 0, 0, 1],
    [1, 1, 0, 0, 0, 1],
    [1, 1, 1, 1, 1, 1]
]
Output
1



int solve(vector<vector<int>>& matrix) {
    queue<vector<int>> q;
    int n = matrix.size();
    int m = matrix[0].size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j]) {
                q.push({i, j});
            } else {
                count++;
            }
        }
    }
    if (count == 0) {
        return 0;
    }
    int t = 0;
    int dir[8][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int x = q.front()[0];
            int y = q.front()[1];
            q.pop();
            for (int k = 0; k < 8; k++) {
                int nx = x + dir[k][0];
                int ny = y + dir[k][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] == 0) {
                    matrix[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        if (q.size()) {
            t++;
        }
    }
    return t;
}
