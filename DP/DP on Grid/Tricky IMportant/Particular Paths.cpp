Particular Paths
You are given a two-dimensional integer matrix and an integer k. Each cell in the matrix has either a 0 or a 1. You start at the top-left square, 
and you must get to the bottom right square. In one step, you can only go down, or right.

The score of a path is the sum of the values on the cells on the path. Return the number of paths from the top left square to the bottom right
square, with score k.

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




Intuition
DP using dp[i][j][k] that denotes that at position matrix[i][j] there how many of each combination is possible. This is done by storing a defaultdict that stores how many
of score x can be achieved at that position.

Implementation
For each cell dp[i][j], update the dictionary to use the above dp[i-1][j] and to the left cell dp[i][j-1], based on if the cell is a 0 or 1. 0 means it copies it over 
directly (no change to number). 1 means it copies over the values from the previous value (if possible ways to get 1 is 4, possible ways to get to 2 is now 4 since the cell
has a 1).

Time Complexity
\mathcal{O}(n^3)O(n 
3
 ) since it uses the matrix dimensions and is bounded by the number we want to reach k

Space Complexity
\mathcal{O}(n^3)O(n 
3
 ) since it uses the matrix dimensions and is bounded by the number we want to reach k
 
 
 

Intuition
Think of recursion + Memotisation.
Here we have 3 changing states i.e x,y and current sum.

Implementation
Do dfs calls from particular pt.
2.Create 3D DP array which stores the x,y and current sum.
3.Return result.
Time Complexity
\mathcal{O}(n^3)O(n 
3
 ) It will be similar to n^3.May be lesser

Space Complexity
\mathcal{O}(n*m*k)O(n∗m∗k) 3D array to store states(for memotization).

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
