



1230. Toss Strange Coins
Medium

121

6

Add to List

Share
You have some coins.  The i-th coin has a probability prob[i] of facing heads when tossed.

Return the probability that the number of coins facing heads equals target if you toss every coin exactly once.

 

Example 1:

Input: prob = [0.4], target = 1
Output: 0.40000
Example 2:

Input: prob = [0.5,0.5,0.5,0.5,0.5], target = 0
Output: 0.03125
 

Constraints:

1 <= prob.length <= 1000
0 <= prob[i] <= 1
0 <= target <= prob.length
Answers will be accepted as correct if they are within 10^-5 of the correct answer.



This problem can be solved using a dynamic programming approach.
Our DP array is d[i][j] which answers the question => What is the probability of having j items till i-th coin inclusively?
1.

The base case is when we have a zero target.
This can be computed using the recurrence relation as the cumulative product of prob[i] negations. 
2.
For all other variations of filling d[i][j], we have two options.

i-th coin has a tail
P1 = (proability of having j coins till i) * (probability of having a tail)
i-th coin has a head
P2 = (probability of having j - 1 coins till i) * (probability of having a head)
Therefore, the probability of having j heads till i-th coin inclusively will be

P = P1 + P2;



This problem is similar to Knapsack, either we will take that coin of certain probability and decreaase target by one or we won't take it.
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        vector<vector<double> > d(prob.size() + 1, vector<double>(target + 1, 0));
        d[0][0] = 1.0;
        for (int i = 1; i <= prob.size(); ++i)
            for (int j = 0; j <= target; ++j)
                if (j == 0) d[i][j] = d[i - 1][j] * (1 - prob[i - 1]);
                else  d[i][j] =  d[i - 1][j - 1] * prob[i - 1] + d[i - 1][j] * (1.0 - prob[i - 1]);
        return d[prob.size()][target];
    }
};
Complexity:
Time complexity: O(target * n) => O(n^2), because the target is in range [0,n]
Space complexity: O(n^2).
However, the space complexity might be reduced to O(n)
Hint: for filling results of d[i][j] we only need to have an access to the vector with j-1 coins.
