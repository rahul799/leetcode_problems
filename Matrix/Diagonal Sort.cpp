


https://binarysearch.com/problems/Diagonal-Sort



Diagonal Sort
Question 166 of 978
Given a two-dimensional integer matrix, sort each of the diagonals descending from left to right in ascending order.

Constraints

n, m ≤ 25 where n and m are the rows and columns of matrix
Example 1
Input
matrix = [
    [9, 8, 7],
    [6, 5, 4],
    [3, 2, 1]
]
Output
[
    [1, 4, 7],
    [2, 5, 8],
    [3, 6, 9]
]



unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;

vector<vector<int>> solve(vector<vector<int>>& mat) {
    int Row = mat.size();
    int Col = mat[0].size();

    for (int i = 0; i < Row; ++i) {
        for (int j = 0; j < Col; ++j) {
            m[i - j].push(mat[i][j]);
        }
    }

    for (int i = 0; i < Row; ++i) {
        for (int j = 0; j < Col; ++j) {
            mat[i][j] = m[i - j].top();
            m[i - j].pop();
        }
    }

    return mat;
}
