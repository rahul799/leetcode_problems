

https://binarysearch.com/problems/Bomber-Man


Bomber Man
You are given a two-dimensional integer matrix of 1s and 0s, where a 1 represents a bomb and 0 represents an empty cell. When a bomb explodes, all the spaces along on the same row and column are damaged. Return the number of spaces you can stand in to not get damaged.

Constraints

n * m ≤ 200,000 where n and m are the number of rows and columns in matrix.
Example 1
Input
matrix = [
    [1, 0, 0],
    [0, 1, 0],
    [0, 0, 0]
]
Output
1
Explanation
Only the bottom right cell is safe



int solve(vector<vector<int>>& matrix) {
    unordered_set<int> cols, rows;
    const int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j]) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    // printf("%d %d %d %d", n, m, (int)(rows.size()), (int)(cols.size()));
    return (n - rows.size()) * (m - cols.size());
}
