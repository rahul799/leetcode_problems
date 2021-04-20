

Number of Monotonically Increasing Lists
You are given integers n and k. Return the number of distinct lists such that for each list:

There are k positive numbers whose sum is n
Every number is greater than or equal to the number on its left
Mod the result by 10 ** 9 + 7.

Constraints

1 ≤ n * k ≤ 200,000
Example 1
Input
n = 8
k = 4
Output
5
Explanation
We can have the following lists:

[1,1,1,5]
[1,1,2,4]
[1,1,3,3]
[1,2,2,3]
[2,2,2,2]
Note that in each list every number is greater than or equal to the number on its left. Each list has length of 4 and sums to 8.






https://binarysearch.com/contest/Weekly-Contest-48-MOI3ENhAxJ/editorials/3902206?questionsetIndex=3






Intuition
Due to the non-decreasing constraint, we can re-write the list like this:

[a,a+x_{k-1},a+x_{k-1}+x_{k-2},\dots,a+\sum_{i=k-1}^{1}{x_i}][a,a+x 
k−1
​	
 

This is a \textbf{Linear diophantine equation}Linear diophantine equation, and there is a very well known dynamic programming solution for this.

Implementation
Define a dp[i][j] representing processing the first i coefficients of the linear diophantine equation and achieving a target sum of exactly j. For the purposes of the dp, we only care about how many x_ix 
i
​	
 s we use.

The base case is dp[0][0]=1.

There are two transitions.

Case 1: Don't use any x_ix 
i
​	
 s. This is equal to dp[i-1][j].

Case 2: If possible, use an x_ix 
i
​	
 . The coefficient in front of x_ix 
i
​	
  is simply i, so this is equal to dp[i][j-i].

Remember to MOD by 10^9+710 
9
 +7 at every step.

Time Complexity
\mathcal{O}(nk)O(nk) for doing the linear diophantine dp.

Space Complexity
\mathcal{O}(nk)O(nk) for storing the dp array in memory.

import java.util.*;

class Solution {
    public int solve(int n, int k) {
        if (n < k)
            return 0;
        n -= k;

        long[][] dp = new long[k + 1][n + 1];
        dp[0][0] = 1L;
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j <= n; j++) {
                // case 1
                dp[i][j] = dp[i - 1][j];

                // case 2
                if (j >= i)
                    dp[i][j] += dp[i][j - i];

                dp[i][j] %= 1000000007;
            }
        }
        return (int) dp[k][n];
    }
}






