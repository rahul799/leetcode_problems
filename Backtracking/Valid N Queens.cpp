




Valid N Queens



Question 244 of 927
The n queens puzzle asks to place n queens on an n×n chessboard so that no two queens are attacking each other.

Given a two-dimensional integer matrix where 1 represents a queen and 0 represents an empty cell, return whether the board is valid solution to the puzzle.

Example 1
Input
matrix = [
    [1, 0, 0, 0, 0],
    [0, 0, 0, 0, 0],
    [0, 0, 0, 0, 1],
    [0, 0, 0, 0, 0],
    [0, 0, 0, 1, 0]
]
Output
false
Explanation
There are no queens on the 2nd or 4th row.

Example 2
Input
matrix = [
    [0, 0, 0, 1, 0],
    [0, 1, 0, 0, 0],
    [0, 0, 0, 0, 1],
    [0, 0, 1, 0, 0],
    [1, 0, 0, 0, 0]
]
Output
true
Explanation
This is a valid n queens solution.









bool check(vector<vector<int>> matrix, int r, int c) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        if (i != r && matrix[i][c] == 1) return false;
        if (i != c && matrix[r][i] == 1) return false;
    }
    int x = r - c;
    int y = r + c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != r && j != c) {
                if (i - j == x)
                    if (matrix[i][j] == 1) return false;
                if (i + j == y)
                    if (matrix[i][j] == 1) return false;
            }
        }
    }
    return true;
}
bool solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                flag = true;
                if (!check(matrix, i, j)) return false;
                break;
            }
        }
        if (!flag) return false;
    }
    return true;
}
