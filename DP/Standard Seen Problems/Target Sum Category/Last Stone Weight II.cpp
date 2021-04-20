1049. Last Stone Weight II
Medium

1058

41

Add to List

Share
We have a collection of rocks, each rock has a positive integer weight.

Each turn, we choose any two rocks and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the smallest possible weight of this stone (the weight is 0 if there are no stones left.)

 

Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We can combine 2 and 4 to get 2 so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1 so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0 so the array converts to [1] then that's the optimal value.
 

Note:

1 <= stones.length <= 30
1 <= stones[i] <= 100
Accepted





dp[i][j]   = {true if some subset from 1st to j'th has a sum equal to sum i, false otherwise}
    i ranges from (sum of all elements) {1..n}
    j ranges from  {1..n}
              
              

// divide into subsets having minimum difference between them

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
       int n = stones.size();
        int sum=0,main;
        for(auto a:stones)
            sum+=a;
        int m=sum;
        sum=sum/2;
        int dp[n+1][sum+1];
        memset(dp,false,sizeof dp);
        
         for(int i=0;i<=sum;i++)
            dp[0][i]=false;
        
        for(int i=0;i<=n;i++)
            dp[i][0]=true;
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j>=stones[i-1])
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-stones[i-1]];
                else 
                    dp[i][j]=dp[i-1][j];
            }
        }
        
        for(int i=sum;i>0;i--)
            if(dp[n][i])
            {   main=i;
                break;
            }
        return abs(m-2*main);
    }
};









class Solution {
   public:
   int lastStoneWeightII(vector<int>& stones) {
      int n = stones.size();
      int total = 0;
      for(int i = 0; i < n; i++){
         total += stones[i];
      }
      int req = total / 2;
      vector <bool> dp(req + 1, false);
      dp[0] = true;
      int reach = 0;
      for(int i = 0; i < n; i++){
         for(int j = req; j - stones[i] >= 0; j--){
            dp[j] = dp[j] || dp[j - stones[i]];
            if(dp[j]) reach = max(reach, j);
         }
      }
      return total - (2 * reach);
   }
};
