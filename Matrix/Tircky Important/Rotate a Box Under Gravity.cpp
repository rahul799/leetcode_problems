Rotate a Box Under Gravity
You are given a two-dimensional list of strings matrix. Each element in matrix contains one of the following:

".", which means that the cell is empty.
"*", which means that the cell contains an obstacle.
"#", which means that the cell contains a small box.
You decide to rotate the matrix clockwise 90 degrees to see how the small boxes will fall under gravity. After rotating, each small box falls down until it lands on an obstacle, another small box, or the bottom of the big box. The obstacle does not fall under gravity.

Return the state of matrix after rotating it 90 degrees clockwise.

Constraints

0 ≤ n * m ≤ 100,000 where n is the number of rows and columns in matrix
Example 1
Input
matrix = [
    ["#", "#", ".", ".", ".", ".", "."],
    ["#", "#", "#", ".", ".", ".", "."],
    ["#", "#", "#", ".", ".", "#", "."]
]
Output
[
    [".", ".", "."],
    [".", ".", "."],
    [".", ".", "."],
    ["#", ".", "."],
    ["#", "#", "."],
    ["#", "#", "#"],
    ["#", "#", "#"]
]
Example 2
Input
matrix = [
    ["#", "*", "."],
    ["*", ".", "."],
    ["#", "#", "."],
    [".", ".", "."]
]
Output
[
    [".", ".", "*", "#"],
    [".", "#", ".", "*"],
    [".", "#", ".", "."]
]







Intuition
We know that maximum # can go to last cell of the particular row, so take the last cell as m-1 and when we found a # we just put that # to the last cell empty cell and when we found the * which means we can only move are # to (*)start^th index -1 so we do it like this in a greedy manner.

Implementation
N means no of rows
m means no of columns
down means that last cell upto which our # can move and that down is change to *(start)^th index-1 when we found a *

Time Complexity
\mathcal{O}(n^2)O(n 
2
 ) for running in a loop which cost n*m time

Space Complexity
\mathcal{O}(n^2)O(n 
2
 ) I have taken another matrix due to which it takes n^2 space

vector<vector<string>> solve(vector<vector<string>>& matrix) {
    int n, m;
    n = matrix.size();
    m = matrix[0].size();
    int i, j;
    for (i = 0; i < n; i++) {
        int down = m - 1;
        for (j = m - 1; j >= 0; j--) {
            if (matrix[i][j] == "#") {
                matrix[i][j] = ".";
                matrix[i][down] = "#";
                down--;
            } else if (matrix[i][j] == "*")
                down = j - 1;
        }
    }
    vector<vector<string>> dp(m, vector<string>(n));

    int k = 0;
    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i < m; i++) {
            dp[i][j] = matrix[k][i];
        }
        k++;
    }
    return dp;
}
