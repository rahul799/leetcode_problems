1434. Number of Ways to Wear Different Hats to Each Other
Hard



https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/



359

4

Add to List

Share
There are n people and 40 types of hats labeled from 1 to 40.

Given a list of list of integers hats, where hats[i] is a list of all hats preferred by the i-th person.

Return the number of ways that the n people wear different hats to each other.

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: hats = [[3,4],[4,5],[5]]
Output: 1
Explanation: There is only one way to choose hats given the conditions. 
First person choose hat 3, Second person choose hat 4 and last one hat 5.
Example 2:

Input: hats = [[3,5,1],[3,5]]
Output: 4
Explanation: There are 4 ways to choose hats
(3,5), (5,3), (1,3) and (1,5)
Example 3:

Input: hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
Output: 24
Explanation: Each person can choose hats labeled from 1 to 4.
Number of Permutations of (1,2,3,4) = 24.
Example 4:

Input: hats = [[1,2,3],[2,3,5,6],[1,3,7,9],[1,8,9],[2,5,7]]
Output: 111
 

Constraints:

n == hats.length
1 <= n <= 10
1 <= hats[i].length <= 40
1 <= hats[i][j] <= 40
hats[i] contains a list of unique integer






      (b) by using hat h for one person from subset s
                // and other h-1 hats for the rest of the subset.
                // possible only if (b.1) person p likes h, and 
                



        // First index is a hat, second is a subset of people.
        //
        // dp[h][subset] = #ways of making sure each person from
        // |subset| has a hat from 1, 2, ... h (compatible to
        // their wishes).
        //
        // NOTE: one can reduce the space complexity by keeping
        // only the last two rows, but current implementation is
        // easier to understand.
        
        
        
        
        


class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        
    }
};


class Solution {
public:
    int N;
    vector<int> hat_by[41];
    int dp[41][(1 << 11)];
    const int MOD = 1e9 + 7;
    
    int solve(int hat, int mask) {
        int count = __builtin_popcount(mask);
        
        if(count == N)
            return 1;
        
        if(hat > 40)
            return 0;
        
        if(dp[hat][mask] != -1)
            return dp[hat][mask];
        
        long long result = 0;
        
        for(int person : hat_by[hat]) {
            person--;
            
            if(!(mask & (1 << person))) {
                int new_mask = mask | (1 << person);
                result += solve(hat + 1, new_mask);
                result %= MOD;
            }
        }
        
        result += solve(hat + 1, mask);
        result %= MOD;
        
        return dp[hat][mask] = (int)result;
    }
    
    int numberWays(vector<vector<int>>& hats) {
        memset(dp, -1, sizeof(dp));
        
        N = hats.size();
        
        for(int i = 0; i < N; i++) {
            for(auto x : hats[i]) {
                hat_by[x].push_back(i+1);
            }
        }
        
        int answer = solve(1, 0);
        
        return answer;
    }
};
