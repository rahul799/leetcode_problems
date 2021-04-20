

https://binarysearch.com/problems/Island-Shape-Perimeter

Island Shape Perimeter
Given a two-dimensional integer matrix of 1s and 0s where 0 represents empty cell and 1 represents a block that forms a shape, return the perimeter of the shape. There is guaranteed to be exactly one shape, and the shape has no holes in it.

Constraints

1 ≤ n, m ≤ 250 where n and m are the number of rows and columns in matrix
Example 1
Input
matrix = [
    [0, 1, 1],
    [0, 1, 0]
]
Output
8





// You can easily identify a boundary cell.
// For every island cell check all four directions, wherever water there or boundary increment ans.

// Note : Will also work when holes there and multiple islands. (will return total perimeter)

int solve(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) continue;

            if (j == 0 or !matrix[i][j - 1])  // left
                ans++;
            if (j == n - 1 or !matrix[i][j + 1])  // right
                ans++;
            if (i == 0 or !matrix[i - 1][j])  // up
                ans++;
            if (i == m - 1 or !matrix[i + 1][j])  // down
                ans++;
        }
    }

    return ans;
}
