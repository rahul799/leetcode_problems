Probability of getting more heads than tails when N biased coins are tossed
Difficulty Level : Hard
 Last Updated : 15 Jul, 2019
Given an array p[] of odd length N where p[i] denotes the probability of getting a head on the ith coin. As the coins are biased, the probability of getting a head is not always equal to 0.5. The task is to find the probability of getting heads more number of times than tails.

Examples:

Input: p[] = {0.3, 0.4, 0.7}
Output: 0.442
Probability for a tail = (1 – Probability for a head)
For heads greater than tails, there are 4 possibilities:
P({head, head, tail}) = 0.3 x 0.4 x (1 – 0.7) = 0.036
P({tail, head, head}) = (1 – 0.3) x 0.4 x 0.7 = 0.196
P({head, tail, head}) = 0.3 x (1 – 0.4) x 0.7= 0.126
P({head, head, head}) = 0.3 x 0.4 x 0.7 = 0.084
Adding the above probabilities
0.036 + 0.196 + 0.126 + 0.084 = 0.442

Input: p[] = {0.3, 0.5, 0.2, 0.6, 0.9}
Output: 0.495

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Naive approach: The naive approach would be creating all the 2n possibilities of heads and tails. Then calculating the probabilities for different permutations and adding them when the number of heads are greater than the number of tails just like the example explanation. This would give TLE when n is large.



Efficient approach: The idea is to use dynamic programming. Let’s assume dp[i][j] to be the probability of getting j heads with first i coins. To get j heads at the ith position, there are two possibilities:

If number of heads till (i – 1) coins is equal to j then a tail comes at ith.
If number of heads till (i – 1) coins is equal to (j – 1) then a head comes at ith position
Hence, it can be broken into its subproblems as follows:

dp[i][j] = dp[i – 1][j] * (1 – p[i]) + dp[i – 1][j – 1] * p[i]

Below is the implementation of the above approach:
C++
filter_none
edit
play_arrow

brightness_4
// C++ implementation of the above approach 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to return the probability when 
// number of heads is greater than the number of tails 
double Probability(double p[], int n) 
{ 
  
    // Declaring the DP table 
    double dp[n + 1][n + 1]; 
    memset(dp, 0.0, sizeof(dp)); 
  
    // Base case 
    dp[0][0] = 1.0; 
  
    // Iterating for every coin 
    for (int i = 1; i <= n; i += 1) { 
  
        // j represents the numbers of heads 
        for (int j = 0; j <= i; j += 1) { 
  
            // If number of heads is equal to zero 
            // there there is only one possiblity 
            if (j == 0) 
                dp[i][j] = dp[i - 1][j] 
                           * (1.0 - p[i]); 
            else
                dp[i][j] = dp[i - 1][j] 
                               * (1.0 - p[i]) 
                           + dp[i - 1][j - 1] * p[i]; 
        } 
    } 
  
    double ans = 0.0; 
  
    // When the number of heads is greater than (n+1)/2 
    // it means that heads are greater than tails as 
    // no of tails + no of heads is equal to n for 
    // any permuation of heads and tails 
    for (int i = (n + 1) / 2; i <= n; i += 1) 
        ans += dp[n][i]; 
  
    return ans; 
} 
  
// Driver Code 
int main() 
{ 
    // 1 based indexing 
    double p[] = { 0.0, 0.3, 0.4, 0.7 }; 
  
    // Number of coins 
    int n = sizeof(p) / sizeof(p[0]) - 1; 
  
    // Function call 
    cout << Probability(p, n); 
  
    return 0; 
} 
