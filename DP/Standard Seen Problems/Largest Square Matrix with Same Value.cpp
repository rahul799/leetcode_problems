Largest Square Matrix with Same Value
Given a two-dimensional list of integers matrix, find the largest k × k submatrix such that all of its elements are the same value, and return the k.

Constraints

n, m ≤ 250 where n and m are the number of rows and columns in matrix.
Example 1
Input
matrix = [
    [1, 1, 3],
    [1, 1, 3],
    [5, 5, 5]
]
Output
2
Explanation
There's a 2 × 2 square of 1s on the top left.



int solve(vector<vector<int>>& matrix) {
    
}


int solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int dp[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 1;
            }
        }
    }
    int res = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == matrix[i - 1][j] && matrix[i][j] == matrix[i][j - 1] &&
                matrix[i][j] == matrix[i - 1][j - 1]) {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));

            } else
                dp[i][j] = 1;

            res = max(res, dp[i][j]);
        }
    }

    return res;
}
