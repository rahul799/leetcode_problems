Longest Increasing Path in a Matrix
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:


Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1
  
  
  
  
  

class Solution {
public:
    bool is_valid(int i, int j, int n, int m){
        if(i<0||j<0||i>=n||j>=m)return 0;
        return 1;
    }
    int lip(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int n, int m){
         int row[4]={0,0,1,-1};
         int col[4]={-1,1,0,0};
        if(dp[i][j]!=-1)return dp[i][j];
        dp[i][j]=1;
        for(int k=0;k<4;k++){
            if(is_valid(i+row[k],j+col[k],n,m)&& matrix[i+row[k]][j+col[k]]>matrix[i][j])
                dp[i][j]=max(dp[i][j],1+lip(matrix,dp,i+row[k],j+col[k],n,m));
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),ans=0;
        if(n==0)return 0;
        int m=matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans, lip(matrix,dp,i,j,n,m));
            }
        }
       return ans;
    }
};
