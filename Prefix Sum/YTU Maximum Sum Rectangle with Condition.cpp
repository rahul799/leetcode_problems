

Maximum Sum Rectangle with Condition
Given a two-dimensional integer matrix matrix and an integer k, return the largest sum of a rectangle ≤ k.

Constraints

n, m ≤ 100 where n and m are the number of rows and columns in matrix.
Example 1
Input
matrix = [
    [2, -2],
    [3, 2]
]
k = 6
Output
5



Intuition




Since the constraints are n,m <= 100 then n^4 solution will pass the time limit.
Therefore, we need to find the range query for the sum for given 2D matrix.
This can be implemented by keeping a pre[i][j] matrix where pre[i][j] is sum of all values till [i][j] index.
Implementation
Construct the preprocessing matrix to store the range summation -> O(n^2)
Then iterate over every possible end points of rectangle. (opposite corners -> O(n^4) ).



Time Complexity
\mathcal{O}(n^4)O(n 
4
 ) Since we are iterating over all possible points.

Space Complexity
\mathcal{O}(n^2)O(n 
2
 ) To maintain the preprocessing of the summation of till index i, j

vector<vector<int>> pre;

int get(int x1, int y1, int x2, int y2) {
    int val1 = (y1 - 1 >= 0) ? pre[x2][y1 - 1] : 0;
    int val2 = (x1 - 1 >= 0) ? pre[x1 - 1][y2] : 0;
    int val3 = (x1 - 1 >= 0 && y1 - 1 >= 0) ? pre[x1 - 1][y1 - 1] : 0;
    return pre[x2][y2] - val1 - (val2 - val3);
}

int solve(vector<vector<int>>& matrix, int limit) {
    int n = matrix.size();
    int m = matrix[0].size();
    pre.assign(n, vector<int>(m, 0));
    for (int i = 0; i < m; ++i) {
        if (i == 0)
            pre[0][i] = matrix[0][i];
        else
            pre[0][i] = pre[0][i - 1] + matrix[0][i];
    }
    for (int i = 1; i < n; ++i) pre[i][0] = pre[i - 1][0] + matrix[i][0];
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            pre[i][j] = matrix[i][j] + pre[i - 1][j] - pre[i - 1][j - 1] + pre[i][j - 1];
        }
    }
    int res = INT_MIN;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int val = INT_MIN;
            for (int k = i; k < n; ++k) {
                for (int l = j; l < m; ++l) {
                    int temp = get(i, j, k, l);
                    if (temp <= limit) val = max(val, temp);
                }
            }
            res = max(res, val);
        }
    }
    return res;
}
