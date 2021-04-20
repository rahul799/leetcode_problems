

Maximum Dropping Path Sum With Column Distance Cost


https://github.com/ramankgp/Leetcode-Solutions2020/new/master/DP/Tough%20Important




You are given a two-dimensional list of integers matrix. You want to pick a number from each row. For each 
0 ≤ r < n - 1 the cost for picking matrix[r][j] and matrix[r + 1][k] is abs(k - j).

Return the maximum sum possible of the numbers chosen, minus costs.

Constraints

1 ≤ n * m ≤ 200,000 where n and m are the number of rows and columns in matrix
Example 1
Input
matrix = [
    [3, 2, 1, 6],
    [4, 1, 2, 0],
    [1, 5, 2, -2]
]
Output
11
Explanation
Return 11 by picking 3, 4 and 5.

Example 2
Input
matrix = [
    [7, 6, 5, 6],
    [6, 4, 5, 8]
]
Output
14
Explanation
We can take the last 6 in the first row and 8 in the last row.

Example 3
Input
matrix = [
    [2, 1, 3]
]
Output
3
Explanation
We can take 3.

Standard O(n * m * m) solution will give TLE.

dp[i][j] = max(dp[i][j], dp[i-1][k] - abs(j-k) + matrix[i][j]);

So, we will just store maximum cost we can get from row i-1 to calculate the maximum cost to reach matrix[i][j].

For j>=k , look at the above equation in this way
dp[i][j] = max(dp[i][j], (dp[i-1][k]+k) +(matrix[i][j]-j));
For j<=k, look at the above equation in this way
dp[i][j] = max(dp[i][j], (dp[i-1][k]-k) +(matrix[i][j]+j));

All we need to do it, Pre calculate maximum of (dp[i-1][k]+k) and (dp[i-1][k]-k) in left and right.

Implementation
Standard implementation with left and right vectors to store the pre calculation.

Time Complexity
\mathcal{O}(n*m)O(n∗m) - We use another left and right subarray to store the required cost.

Space Complexity
\mathcal{O}(n*m + 2*m)O(n∗m+2∗m) - O(n*m) for dp and O(m) for both left and right subarray.


int solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
    vector<int> left(m, INT_MIN), right(m, INT_MIN);
    for (int i = 0; i < m; i++) {
        dp[0][i] = matrix[0][i];
    }

    for (int i = 0; i < m; i++) {
        if (i > 0) {
            left[i] = max(left[i - 1], dp[0][i] + i);
        } else {
            left[0] = dp[0][0];
        }
        int ri = m - 1 - i;
        if (ri < m - 1) {
            right[ri] = max(right[ri + 1], dp[0][ri] - ri);
        } else {
            right[ri] = dp[0][ri] - ri;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = max({dp[i][j], left[j] + matrix[i][j] - j, right[j] + matrix[i][j] + j});
        }
        for (int j = 0; j < m; j++) {
            left[j] = INT_MIN;
            if (j > 0) {
                left[j] = max(left[j - 1], dp[i][j] + j);
            } else {
                left[0] = dp[i][0];
            }
            int ri = m - 1 - j;
            right[ri] = INT_MIN;
            if (ri < m - 1) {
                right[ri] = max(right[ri + 1], dp[i][ri] - ri);
            } else {
                right[ri] = dp[i][ri] - ri;
            }
        }
    }
    int ans = *max_element(dp[n - 1].begin(), dp[n - 1].end());
    return ans;
}
