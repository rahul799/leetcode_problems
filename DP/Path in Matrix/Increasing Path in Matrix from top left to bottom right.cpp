

Problem Description

Given a 2D integer matrix A of size N x M.

From A[i][j] you can move to A[i+1][j], if A[i+1][j] > A[i][j], or can move to A[i][j+1] if A[i][j+1] > A[i][j].

The task is to find and output the longest path length if we start from (0, 0).

NOTE:

If there doesn't exist a path return -1.

 public int solve(int[][] A) {
       
       int[][]dp = new int[A.length][A[0].length];
       dp[0][0] = 1;
       
       for(int i=1;i<A[0].length;i++){
           if(A[0][i]>A[0][i-1]){
               dp[0][i] = dp[0][i-1]+1;
           }else{
               break;
           }
       }
       for(int i=1;i<A.length;i++){
           if(A[i][0]>A[i-1][0]){
               dp[i][0] = dp[i-1][0]+1;
           }else{
               break;
           }
       }
       
       for(int i=1;i<A.length;i++){
           for(int j=1;j<A[0].length;j++){
               if(A[i][j]>A[i-1][j] && dp[i-1][j]!=0){
    
                   dp[i][j] = dp[i-1][j]+1;
               }
               
               if(A[i][j]>A[i][j-1] && dp[i][j-1]!=0){
                   dp[i][j] = Math.max(dp[i][j-1]+1,dp[i][j]);
                   
               }
           }
       }
       
       int n = A.length-1;
       int m = A[0].length-1;
       
       if(dp[n][m]==0)return -1;
       else return dp[n][m];
    
       
    }
  
