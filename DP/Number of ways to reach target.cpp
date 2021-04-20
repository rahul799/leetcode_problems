You are given an N by M matrix of 0s and 1s. Starting from the top left corner, how many ways are there to reach the bottom right corner? Mod the result by 10 ** 9 + 7.

You can only move right and down. 0 represents an empty space while 1 represents a wall you cannot walk through. The top left corner and bottom right corner will always be 0.

Constraints

n, m ≤ 100 where n and m are the number of rows and columns in matrix.
Example 1
Input
matrix = [
    [0, 0, 1],
    [0, 0, 1],
    [1, 0, 0]
]
Output
2
Explanation
There are two ways to get to the bottom right:

Right, down, down, right
Down, right, down, right
Example 2
Input
matrix = [
    [0, 0, 0],
    [0, 0, 0],
    [0, 0, 0]
]
Output
6
Explanation
There are 6 ways here:

Right, right, down, down
Down, down, right, right
Right, down, right, down
Down, right, down, right
Right, down, down, right
Down, right, right, down







int solve(vector<vector<int>>& matrix) {
    if (matrix[0][0] == 1) return 0;

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 and j == 0) continue;
            if (matrix[i][j] == 0) {
                int t1 = 0;
                int t2 = 0;
                if (i - 1 >= 0) t1 = dp[i - 1][j];
                if (j - 1 >= 0) t2 = dp[i][j - 1];
                dp[i][j] = t1 + t2;
            }
        }
    }

    return dp[n - 1][m - 1] % 1000000007;
}
