Enclosed Islands
Question 893 of 1000
You are given a two-dimensional integer matrix of 1s and 0s. A 1 represents land and 0 represents water. From any land cell you can move up, down, left or right to another land cell or go off the matrix.

Return the number of land cells from which we cannot go off the matrix.

Constraints

n, m ≤ 250 where n and m are the number of rows and columns in matrix
Example 1
Input
matrix = [
    [0, 0, 0, 1],
    [0, 1, 1, 0],
    [0, 1, 1, 0],
    [0, 0, 0, 0]
]
Output
4
Explanation
There's 4 land squares in the middle from which we cannot walk off the matri



vector<int> dirX{0, 1, 0, -1};
vector<int> dirY{1, 0, -1, 0};


void dfs(vector<vector<int>>& matrix, int i, int j) {
    int n = matrix.size(), m = matrix[0].size();
    matrix[i][j] = 0;
    for (int k = 0; k < 4; ++k) {
        int x = i + dirX[k];
        int y = j + dirY[k];
        if (x >= 0 and x < n and y >= 0 and y < m and matrix[x][y] == 1) {
            dfs(matrix, x, y);
        }
    }
}
int solve(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == n - 1 or j == m - 1 or i == 0 or j == 0) {
                if (matrix[i][j] == 1) dfs(matrix, i, j);
            }
        }
    }
    int count = 0;
     for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
     count += matrix[i][j];
        }
     }
    return count;
}
