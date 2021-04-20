
Condo Developers
You are given a two-dimensional integer matrix, where matrix[r][c] represents the height of a condominium in a city.

The west-east skyline can be seen by taking the maximum of each row in the matrix. Similarly, the north-south skyline can be seen by taking the maximum of each column.

Return a new matrix where each condominium's height is increased to the maximum possible height while keeping the same west-east and north-south skyline.

Constraints

n, m ≤ 250 where n and m are the number of rows and columns in matrix
Example 1
Input
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
Output
[
    [3, 3, 3],
    [6, 6, 6],
    [7, 8, 9]
]
Explanation
The west-east skyline is [3, 6, 9] and north-south skyline is [7, 8, 9]. We can increase everything in the first row to 3 and everything in the second 
row to 6 without changing the skylines.

Example 2
Input
matrix = [
    [4, 4, 3],
    [5, 5, 3],
    [7, 8, 3]
]
Output
[
    [4, 4, 3],
    [5, 5, 3],
    [7, 8, 3]
]
Explanation
The west-east skyline is [4, 5, 8] and north-south skyline is [7, 8, 3]. We can't increase any condominium's height without changing the skyline,
so we return the same matrix.




Intuition
Let n and m be the dimensions of the matrix, where n is the number of rows and m is the number of columns. Then, each element in the matrix is
the minimum of the maximum of the values in its own row and column. Formally, matrix[r][c] should be updated to
min(max(matrix[r][i]), max(matrix[j][c])) for all 1 \leq j \leq n1≤j≤n and 1 \leq i \leq m1≤i≤m.

Implementation
Iterates through all elements, and does what I said above.

Time Complexity
\mathcal{O}(n)O(n) where n is the number of rows and m is the number of columns.

Space Complexity
\mathcal{O}(n)O(n) Just a two-dimensional array, with n rows and m columns.


  
  


vector<vector<int>> solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> mxRow(n, 0);
    vector<int> mxCol(m, 0);

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            mxRow[j] = max(mxRow[j], matrix[j][i]);
            mxCol[i] = max(mxCol[i], matrix[j][i]);
        }
    }

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            matrix[j][i] = min(mxRow[j], mxCol[i]);
        }
    }

    return matrix;
}
