309. Best Time to Buy and Sell Stock with Cooldown
Medium

2698

88

Add to List

Share
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]







int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 2)
            return 0;
        vector<int> buy(len),sell(len);
        buy[0] = -prices[0];
        buy[1] = max(buy[0],-prices[1]);
        sell[1] = max(0,prices[1]-prices[0]);
        for(int i=2;i<len;++i){
            buy[i] = max(buy[i-1],sell[i-2]-prices[i]);
            sell[i] = max(buy[i-1]+prices[i],sell[i-1]);
        }
        return sell[len-1];
    }







class Solution {
public:
   int maxProfit(vector<int>& prices) {
    int sold = 0, hold = INT_MIN, rest = 0;
    for (int i=0; i<prices.size(); ++i)
    {
        int prvSold = sold;
        sold = hold + prices[i];
        hold = max(hold, rest-prices[i]);
        rest = max(rest, prvSold);
    }
    return max(sold, rest);
}
};



 
