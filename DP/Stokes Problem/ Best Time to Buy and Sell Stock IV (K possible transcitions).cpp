188. Best Time to Buy and Sell Stock IV

Say you have an array for which the i-th element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
   
   
   
 
 class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        
        if(n<=1 || k==0)
        return 0;
       
        if(k>=n)
        {
            int ans=0;
            for(int i=0;i<n-1;i++)
                if(prices[i+1]>prices[i])
                    ans+=prices[i+1]-prices[i];
            
            return ans;
        }
        
        int a[k+1][n], maxDiff;
        for(int i=0;i<=k;i++)
        {
            maxDiff=-prices[0];
            for(int j=0;j<n;j++)
            {
               if(i==0||j==0)
               a[i][j]=0;
               else
               {
                 a[i][j]=max(a[i][j-1],prices[j]+maxDiff);
                 maxDiff=max(maxDiff,a[i-1][j]-prices[j]);
               }
            }
        }
        return a[k][n-1];
    }
};
