https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/794761/All-Variants-of-%22Best-Time-to-Buy-and-Sell-Stock%22-problems





Atmost 1 Transaction - Kadane's algorithm
 public int maxProfit(int[] prices) {
        int maxEndingHere = 0;
		int maxSoFar = 0;
		for (int i = 1; i < prices.length; i++) {
			maxEndingHere = Math.max(0, maxEndingHere+prices[i] - prices[i - 1]);
			maxSoFar = Math.max(maxSoFar, maxEndingHere);
		}
		return maxSoFar;
    }
Time : O(n)
Space: O(1)

2. Infinite Transactions
If you have increase in price compared to previous price, add it to profit

 public int maxProfit(int[] prices) {
        int profit = 0;
		for (int i = 0; i < prices.length - 1; i++) {
			if (prices[i + 1] > prices[i]) {
				profit += prices[i+1] - prices[i];
			}
		}
		return profit;
    }
    
    
    
    
    

DP: 
dp[i][j] = Max(dp[i][j-1],prices[j]-prices[m]+dp[i-1][m])
m = 0..j-1

dp[i][j-1]                     -> if you are not making a transaction on day j
prices[j]-prices[m]+dp[i-1][m] -> if you are making a transaction on day j, find the m th day to buy the stock 
i = no of transactions
j = prices.length

Time: O(k * n * n) 
Space: O(k * n) 
k = K transactions
n = prices.length




Optimized DP

maxDiff = Max(maxDiff,dp[i-1][j-1] - prices[j-1])
dp[i][j] = Max(dp[i][j-1],prices[j]+maxDiff)

dp[i][j-1]                     -> if you are not making a transaction on day j
prices[j]-prices[m]+dp[i-1][m] -> if you are making a transaction on day j, compute the maxDiff from 0 ..j-1. In other words, we are reusing the maxDiff computed 
before. This reduces O(n) time complexity 

Time: O(k * n) 
Space: O(k * n) 
k = K transactions
n = prices.length
Best Time to Buy and Sell Stock III : Atmost 2 transactions

 public int maxProfit(int[] prices) {
       if(prices.length ==0)
            return 0;
       int k=2;
       int dp[][] = new int[k + 1][prices.length];
		for (int i = 1; i < dp.length; i++) {
			int maxDiff = -prices[0];
			for (int j = 1; j < dp[0].length; j++) {
				maxDiff = Math.max(maxDiff, dp[i - 1][j - 1] - prices[j - 1]);
				dp[i][j] = Math.max(dp[i][j - 1], prices[j] + maxDiff);
			}
		}
		return dp[k][prices.length - 1];
    }
Time: O(k * n)
Space: O(k * n)
k = K transactions
n = prices.length







Best Time to Buy and Sell Stock IV :

	public int maxProfit(int k, int[] prices) {
		if (k >= prices.length / 2)
			return maxProfit(prices); // This is to avoid Memory Limit Exceeded for one of the test cases. In other words, you can make infinite transactions. Using variant 2 logic. 
		int dp[][] = new int[k + 1][prices.length];
		for (int i = 1; i < dp.length; i++) {
			int maxDiff = -prices[0];
			for (int j = 1; j < dp[0].length; j++) {
				maxDiff = Math.max(maxDiff, dp[i - 1][j - 1] - prices[j - 1]);
				dp[i][j] = Math.max(dp[i][j - 1], prices[j] + maxDiff);
			}
		}
		return dp[k][prices.length - 1];
	}

	private int maxProfit(int[] prices) {
        int profit = 0;
		for (int i = 0; i < prices.length - 1; i++) {
			if (prices[i + 1] > prices[i]) {
				profit += prices[i+1] - prices[i];
			}
		}
		return profit;
    }
Time: O(k * n)
Space: O(k * n)
k = K transactions
n = prices.length



