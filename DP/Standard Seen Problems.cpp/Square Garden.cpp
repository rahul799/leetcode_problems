Square Garden

https://github.com/ramankgp/Leetcode-Solutions2020/edit/master/DP/Standard%20Seen%20Problems.cpp/Square%20Garden.cpp


Given a two-dimensional list of integers matrix containing 1s and 0s, return the total number of square submatrices with all 1 s.

Constraints

n, m ≤ 250 where n and m are the number of rows and columns in matrix.
Example 1
Input

matrix = [
    [1, 1, 0],
    [1, 1, 0]
]
Output

5
Explanation

There's 4 of 1 × 1 squares and 1 2 × 2 square.



int solution(vector<vector<int>>& mat) {
        int ans = 0;

        int row = mat.size() - 1;
        int col = mat[0].size() - 1;

        for (int i = col; i >= 0; i--) ans += mat[row][i];

        for (int i = row - 1; i >= 0; i--) ans += mat[i][col];

        for (int r = row - 1; r >= 0; r--) {
            for (int c = col - 1; c >= 0; c--) {
                int right = mat[r][c + 1];
                int down = mat[r + 1][c];
                int downright = mat[r + 1][c + 1];
                if (mat[r][c] == 1) {
                    mat[r][c] += min(downright, min(right, down));
                    ans += mat[r][c];
                }
            }
        }
        return ans;
    }







int solve(vector<vector<int>>& matrix) {
        
        return solution(matrix);
    
    
    
}




