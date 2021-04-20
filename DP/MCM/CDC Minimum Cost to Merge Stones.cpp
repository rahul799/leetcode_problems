


1000. Minimum Cost to Merge Stones
Hard

888

57

Add to List

Share
There are N piles of stones arranged in a row.  The i-th pile has stones[i] stones.

A move consists of merging exactly K consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these K piles.

Find the minimum cost to merge all piles of stones into one pile.  If it is impossible, return -1.

 

Example 1:

Input: stones = [3,2,4,1], K = 2
Output: 20
Explanation: 
We start with [3, 2, 4, 1].
We merge [3, 2] for a cost of 5, and we are left with [5, 4, 1].
We merge [4, 1] for a cost of 5, and we are left with [5, 5].
We merge [5, 5] for a cost of 10, and we are left with [10].
The total cost was 20, and this is the minimum possible.
Example 2:

Input: stones = [3,2,4,1], K = 3
Output: -1
Explanation: After any merge operation, there are 2 piles left, and we can't merge anymore.  So the task is impossible.
Example 3:

Input: stones = [3,5,1,2,6], K = 3
Output: 25
Explanation: 
We start with [3, 5, 1, 2, 6].
We merge [5, 1, 2] for a cost of 8, and we are left with [3, 8, 6].
We merge [3, 8, 6] for a cost of 17, and we are left with [17].
The total cost was 25, and this is the minimum possible.
 

Note:

1 <= stones.length <= 30
2 <= K <= 30
1 <= stones[i] <= 100







 int mergeStones(vector<int>& stones, int K) 
    {
      int N = stones.size();
      if ((N-1)%(K-1) > 0) return -1; // validation to merge into a single pile
      
      // partial sum
      int sum[N+1] = {0};
      for (int i = 1; i <= N; i++)
        sum[i] = sum[i-1] + stones[i-1];
      
      // dp[i][j]: the minimum cost needed to merge stones[i] ~ stones[j] 
      // with the left most element stones[i] always involved in merge if possible
      vector<vector<int>> dp(N, vector<int>(N, 0));
      
      for (int L = K; L <= N; L++) // L: length of interval [i,j]
        for (int i = 0, j = i+L-1; j < N; i++, j++) { // each interval [i,j] of length L in [0,N]
          
          dp[i][j] = INT_MAX;          
          
          // when stones[i] is merged, it must be merged with multiple of (K-1) other stones
          for (int k = i; k < j; k += (K-1))
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
          
          // all stones in [i,j] can be merged into one pile
          if ((L-1)%(K-1) == 0)
            dp[i][j] += (sum[j+1] - sum[i]); // add sum in [i,j]
        }
      
      return dp[0][N-1];
    }
