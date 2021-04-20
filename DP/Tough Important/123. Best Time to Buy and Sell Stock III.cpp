

123. Best Time to Buy and Sell Stock III

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
Example 4:

Input: prices = [1]
Output: 0


We could do better than the naive \mathcal{O}(N^2)O(N 
2
 ) implementation. Regarding the algorithms of divide-and-conquer, one common technique that we can apply in order to optimize the time complexity is called dynamic
 programming (DP) where we trade less repetitive calculation with some extra space.

 
In dynamic programming algorithms, normally we create an array of one or two dimensions to keep the intermediate optimal results. In this problem though, we would
use two arrays, with one array keeping the results of sequence from left to right and the other array keeping the results of sequence from right to left. For the sake of name,
we could call it bidirectional dynamic programming.
 
 
 
 
 First, we denote a sequence of prices as Prices[i], with index starting from 0 to N-1. Then we define two arrays, namely left_profits[i] and right_profits[i].

As suggested by the name, each element in the left_profits[i] array would hold the maximum profits that one can gain from doing one single transaction on the left subsequence of prices from the index zero to i, (i.e. Prices[0], Prices[1], ... Prices[i]). For instance, for the subsequences of [7, 1, 5], the corresponding left_profits[2] would be 4, which is to buy the price of 1 and sell it at the price of 5.

And each element in the right_profits[i] array would hold the maximum profits that one can gain from doing one single transaction on the right subsequence of the prices from the index i up to N-1, (i.e. Prices[i], Prices[i+1], ... Prices[N-1]). For example, for the right subsequence of [3, 6, 4], the corresponding right_profits[3] would be 3, which is to buy at the price of 3 and then sell it at the price of 6.

Now, if we divide the sequence of prices around the element at the index i, into two subsequences, with left subsequences as Prices[0], Prices[1], ... Prices[i] and 
the right subsequence as Prices[i+1], ... Prices[N-1], then the total maximum profits that we obtain from this division (denoted as max_profits[i]) can be expressed as
follows: \text{max\_profits[i]} = \text{left\_profits[i]} + \text{right\_profits[i+1]}max_profits[i]=left_profits[i]+
 right_profits[i+1]






class Solution {
  public:
  int maxProfit(vector<int>& prices) {
    int length = prices.size();
    if (length <= 1) return 0;

    int leftMin = prices[0];
    int rightMax = prices[length - 1];

    vector<int> leftProfits(length, 0);
    // pad the right DP array with an additional zero for convenience.
    vector<int> rightProfits(length + 1, 0);

    // construct the bidirectional DP array
    for (int l = 1; l < length; ++l) {
      leftProfits[l] = max(leftProfits[l - 1], prices[l] - leftMin);
      leftMin = min(leftMin, prices[l]);

      int r = length - 1 - l;
      rightProfits[r] = max(rightProfits[r + 1], rightMax - prices[r]);
      rightMax = max(rightMax, prices[r]);
    }

    int maxProfit = 0;
    for (int i = 0; i < length; ++i) {
      maxProfit = max(maxProfit, leftProfits[i] + rightProfits[i + 1]);
    }
    return maxProfit;
  }
};


Approach 2:




Algorithm

Overall, we run an iteration over the sequence of prices.

Over the iteration, we calculate 4 variables which correspond to the costs or the profits of each action respectively, as follows:

t1_cost: the minimal cost of buying the stock in transaction #1. The minimal cost to acquire a stock would be the minimal price value that we have seen so far at each step.

t1_profit: the maximal profit of selling the stock in transaction #1. Actually, at the end of the iteration, this value would be the answer for the first problem in the
series, i.e. Best Time to Buy and Sell Stock.

t2_cost: the minimal cost of buying the stock in transaction #2, while taking into account the profit gained from the previous transaction #1. One can consider this as
the cost of reinvestment. Similar with t1_cost, we try to find the lowest price so far, which in addition would be partially compensated by the profits gained from the first
transaction.

t2_profit: the maximal profit of selling the stock in transaction #2. With the help of t2_cost as we prepared so far, we would find out the maximal profits with at most
two transactions at each step





int maxProfit(vector<int>& prices) {
    //It's wrong if you choose the minimum price for buy2 , but you can maximize the left money.
    //
    int buy1 = INT_MIN, sale1 = 0, buy2 = INT_MIN, sale2 = 0;
    for(int i=0; i<prices.size(); i++){                      //the more money left, the happier you will be
        buy1 = max(buy1, -prices[i]);                        //left money after buy1
        sale1 = max(sale1, prices[i] + buy1);                //left money after sale1
        buy2 = max(buy2, sale1 - prices[i]);                 //left money after buy2
        sale2 = max(sale2, prices[i] + buy2);                //left money after sale2
    }
    return sale2;
}













class Solution {
    // divide and concquer => dp
    // check solution 1
public:
  int maxProfit(vector<int>& prices) {
    int t1Cost = INT_MAX, 
        t2Cost = INT_MAX;
    int t1Profit = 0,
        t2Profit = 0;

    for (int price : prices) {
        // the maximum profit if only one transaction is allowed
        t1Cost = min(t1Cost, price);
        t1Profit = max(t1Profit, price - t1Cost);
        // re-invest the gained profit in the second transaction
        t2Cost = min(t2Cost, price - t1Profit);
        t2Profit = max(t2Profit, price - t2Cost);
    }

    return t2Profit;
  }
};
