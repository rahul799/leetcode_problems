
https://binarysearch.com/problems/Particular-Paths

Particular Paths
You are given a two-dimensional integer matrix and an integer k. Each cell in the matrix has either a 0 or a 1. You start at the top-left square, and you must get to the bottom right square. In one step, you can only go down, or right.

The score of a path is the sum of the values on the cells on the path. Return the number of paths from the top left square to the bottom right square, with score k.

Return the answer modulo 10^9+7.

Constraints

h, w ≤ 100 where h and w are the height and width of matrix.
k ≤ 100,000
Example 1
Input
matrix = [
    [0, 0, 1],
    [0, 1, 1],
    [0, 1, 0]
]
k = 2
Output
5
Explanation
Here are all the different paths we can take to reach score of 2:

right, right, down, down
right, down, right, down
right, down, down, right
down, right, right, down
down, right, down, right








#define mod 1000000007

int pth(int x, int y, int csum, int n, int m, vector<vector<int>> &mat,
        vector<vector<vector<int>>> &dp) {
    if (x < 0 || y < 0 || x >= n || y >= m || csum < 0) {
        return 0;
    }
    // cout<<x<<" "<<y<<" "<<csum<<endl;
    if (x == n - 1 && y == m - 1) {
        if ((csum - mat[x][y]) == 0) {
            return 1;
        }
        return 0;
    }
    if (dp[x][y][csum] != -1) {
        return dp[x][y][csum];
    }

    return dp[x][y][csum] = ((pth(x + 1, y, csum - mat[x][y], n, m, mat, dp) % mod) +
                             pth(x, y + 1, csum - mat[x][y], n, m, mat, dp) % mod) %
                            mod;
}

int solve(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    if (n == 0) {
        return 0;
    }
    int m = matrix[0].size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
    int ans = pth(0, 0, k, n, m, matrix, dp);
    return ans;
}
