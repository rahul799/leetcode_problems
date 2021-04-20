Given a 2D integer matrix A of size N x N find a B x B submatrix where B<= N and B>= 1, such that sum of all the elements in submatrix is maximum.






----------------------xxxxxx DP SOLUTION xxxxxxx-------------------------


 public int solve(int[][] A, int B) {
      
      int row = A.length;
      int col = A[0].length;
      int maxsum = Integer.MIN_VALUE;
      int[][] dp = new int[row+1][col+1];
      
      
      for(int i=1;i<dp.length;i++){
          for(int j=1;j<dp[0].length;j++){
          
        // dp table is basically calucalting the sum matrix
            dp[i][j] =  A[i-1][j-1]+ dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
          }
      }
      
    // This is to calculate the maximum Sum
      for(int i=1;i<dp.length;i++){
          for(int j=1;j<dp[0].length;j++){
            //3X3
            int sum =  Integer.MIN_VALUE;
            if(i-B>=0 && j-B>=0){
          // since the diagonal element was subtracted twice
                sum = dp[i][j] - dp[i-B][j]-dp[i][j-B]+ dp[i-B][j-B];
                maxsum = Math.max(sum,maxsum);
            }
          }
      }
      return maxsum;
    }
