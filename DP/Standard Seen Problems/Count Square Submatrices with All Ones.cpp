

1277. Count Square Submatrices with All Ones
Medium

1471

26

Add to List

Share
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1









class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int submatrices_with_all_ones = 0;
        vector<vector<int>> dp(rows, vector<int>(columns, 0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if((i == 0 || j == 0) && matrix[i][j] == 1)
                    dp[i][j] = matrix[i][j];
                else if(matrix[i][j] == 1)
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                submatrices_with_all_ones += dp[i][j]; 
                }
            
           
        }
         return submatrices_with_all_ones;
    }
};


