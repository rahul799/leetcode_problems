

Maximum Product Path in Matrix


https://binarysearch.com/problems/Maximum-Product-Path-in-Matrix


You are given a two-dimensional list of integers matrix. You are currently at the top left corner and want to move to the bottom right corner. In each move, you can move down or right.

Return the maximum product of the cells visited by going to the bottom right cell. If the result is negative, return -1. Otherwise, mod the result by 10 ** 9 + 7.

Constraints

1 ≤ n, m ≤ 20 where n and m are the number of rows and columns in matrix
-2 ≤ matrix[r][c] ≤ 2
Example 1
Input
matrix = [
    [2, 1, -2],
    [-1, -1, -2],
    [1, 1, 1]
]
Output
8
Explanation
We can take the following path: [2, 1, -2, -2, 1].

This problem has a classical DP structure, in which we go from the top left of the matrix to the bottom right, and try
to find some optimal value. In this case, the optimal value of the current position is only related to its left neighbor 
and top neighbor, since we can only go down or go right.

Now consider the maximum product part. Since there are both positive and non-positive values, it seems that we would
have to consider several situations. But in fact, we only need to store the minimum product lolo and the maximum product 
hihi of each position. Why? Suppose we choose a value xx from (lo, hi)(lo,hi), which means it is neither the minimum nor 
the maximum. Then if the current value is positive, choosing hihi will always be better. If the current value is non-positive, 
choosing lolo will not be worse. So we only need to keep the minimum and the maximum of each position during the dynamic 
programming.

Implementation
Be careful that the top left position needs to be handled separately.

Time Complexity
The time complexity is \mathcal{O}(nm)O(nm), since we enumerate each position of the matrix.

Space Complexity
The space complexity is \mathcal{O}(nm)O(nm), since we need to store the maximum and minimum value for every 
position. This can be further optimized to \mathcal{O}(\min(n,m))O(min(n,m)) with a rolling array.




typedef long long ll;

int solve(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<pair<ll, ll>>> f(n, vector<pair<ll, ll>>(m));
    f[0][0] = {matrix[0][0], matrix[0][0]};
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            ll lo = LLONG_MAX, hi = LLONG_MIN;
            if (i > 0) {
                lo = min(lo,
                         min(f[i - 1][j].first * matrix[i][j], f[i - 1][j].second * matrix[i][j]));
                hi = max(hi,
                         max(f[i - 1][j].first * matrix[i][j], f[i - 1][j].second * matrix[i][j]));
            }
            if (j > 0) {
                lo = min(lo,
                         min(f[i][j - 1].first * matrix[i][j], f[i][j - 1].second * matrix[i][j]));
                hi = max(hi,
                         max(f[i][j - 1].first * matrix[i][j], f[i][j - 1].second * matrix[i][j]));
            }
            if (i || j) f[i][j] = {lo, hi};
        }
    return f[n - 1][m - 1].second >= 0 ? f[n - 1][m - 1].second % 1000000007 : -1;
}

