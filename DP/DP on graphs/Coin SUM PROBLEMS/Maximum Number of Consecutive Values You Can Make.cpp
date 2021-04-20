1798. Maximum Number of Consecutive Values You Can Make
Medium


https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/


114

17

Add to List

Share
You are given an integer array coins of length n which represents the n coins that you own. The value of the ith coin is coins[i]. You can make some value x if you can choose some of your n coins such that their values sum up to x.

Return the maximum number of consecutive integer values that you can make with your coins starting from and including 0.

Note that you may have multiple coins of the same value.

 

Example 1:

Input: coins = [1,3]
Output: 2
Explanation: You can make the following values:
- 0: take []
- 1: take [1]
You can make 2 consecutive integer values starting from 0.
Example 2:

Input: coins = [1,1,1,4]
Output: 8
Explanation: You can make the following values:
- 0: take []
- 1: take [1]
- 2: take [1,1]
- 3: take [1,1,1]
- 4: take [4]
- 5: take [4,1]
- 6: take [4,1,1]
- 7: take [4,1,1,1]
You can make 8 consecutive integer values starting from 0.
Example 3:

Input: nums = [1,4,10,3,1]
Output: 20
 

Constraints:

coins.length == n
1 <= n <= 4 * 104
1 <= coins[i] <= 4 * 104


  
  

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        // support variables
        int res = 1;
        // preparing coins
        sort(begin(coins), end(coins));
        for (int coin: coins) {
            // checking if we could have reached coin without gaps
            if (res >= coin) res += coin;
            else break;
        }
        return res;
    }
};
