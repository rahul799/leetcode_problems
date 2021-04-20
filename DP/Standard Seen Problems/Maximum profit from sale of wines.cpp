Maximum profit from sale of wines

https://www.youtube.com/watch?v=f4jUEEzjEJw&ab_channel=TECHDOSE
Difficulty Level : Medium
 Last Updated : 03 Oct, 2019
Given n wines in a row, with integers denoting the cost of each wine respectively. Each year you can sale the first or the last wine in the row. However, the price of wines increases over time. Let the initial profits from the wines be P1, P2, P3…Pn. On the Yth year,
the profit from the ith wine will be Y*Pi. For each year, your task is to print “beg” or “end” denoting whether first or
last wine should be sold. Also, calculate the maximum profit from all the wines.

Examples :

Input: Price of wines: 2 4 6 2 5
Output: beg end end beg beg 
         64
Explanation :

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Approach : It is a standard Dynamic Programming problem. It initially looks like a greedy problem in which we should sell the cheaper of the wines each year but the example case (year 2) clearly proves the approach is wrong. Sometimes we need to sell an expensive wine earlier to save relatively costly wines for later years (Here, if 4 was sold in the 2nd year, in the 4th year we had to sell 2 which would be waste of a heavy coefficient).

The second problem is to “store the strategy” to obtain the calculated price which has a fairly standard method that can 
be used in other problems as well. The idea is to store the optimal action for each state and use that to navigate through
the optimal states starting from the initial state.




// Program to calculate maximum price of wines 
#include <bits/stdc++.h> 
using namespace std; 

#define N 1000 

int dp[N][N]; 

// This array stores the "optimal action" 
// for each state i, j 
int sell[N][N]; 

// Function to maximize profit 
int maxProfit(int price[], int begin, 
				int end, int n) { 
	if (dp[begin][end] != -1) 
		return dp[begin][end]; 

	int year = n - (end - begin); 

	if (begin == end) 
		return year * price[begin];	 

	// x = maximum profit on selling the 
	// wine from the front this year 
	int x = price[begin] * year + 
			maxProfit(price, begin + 1, end, n); 

	// y = maximum profit on selling the 
	// wine from the end this year 
	int y = price[end] * year + 
			maxProfit(price, begin, end - 1, n); 

	int ans = max(x, y); 
	dp[begin][end] = ans; 

	if (x >= y) 
		sell[begin][end] = 0; 
	else
		sell[begin][end] = 1; 

	return ans; 
} 

// Util Function to calculate maxProfit 
int maxProfit(int price[], int n) { 
	// reseting the dp table 
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			dp[i][j] = -1; 

	int ans = maxProfitUtil(price, 0, n - 1, n); 

	int i = 0, j = n - 1; 

	while (i <= j) { 
		// sell[i][j]=0 implies selling the 
		// wine from beginning will be more 
		// profitable in the long run 
		if (sell[i][j] == 0) { 
			cout << "beg "; 
			i++; 
		} else { 
			cout << "end "; 
			j--; 
		} 
	} 

	cout << endl; 

	return ans; 
} 

// Driver code 
int main() { 
	// Price array 
	int price[] = { 2, 4, 6, 2, 5 }; 

	int n = sizeof(price) / sizeof(price[0]); 

	int ans = maxProfit(price, n); 

	cout << ans << endl; 

	return 0; 
} 
