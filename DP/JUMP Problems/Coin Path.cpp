656. Coin Path


Share
Given an array A (index starts at 1) consisting of N integers: A1, A2, ..., AN and an integer B. The integer B denotes that from any place (suppose the index is i) in the array A, you can jump to any one of the place in the array A indexed i+1, i+2, …, i+B if this place can be jumped to. Also, if you step on the index i, you have to pay Ai coins. If Ai is -1, it means you can’t jump to the place indexed i in the array.

Now, you start from the place indexed 1 in the array A, and your aim is to reach the place indexed N using the minimum coins. You need to return the path of indexes (starting from 1 to N) in the array you should take to get to the place indexed N using minimum coins.

If there are multiple paths with the same cost, return the lexicographically smallest such path.

If it's not possible to reach the place indexed N then you need to return an empty array.

Example 1:

Input: [1,2,4,-1,2], 2
Output: [1,3,5]
 

Example 2:

Input: [1,2,4,-1,2], 1
Output: []
 

Note:

Path Pa1, Pa2, ..., Pan is lexicographically smaller than Pb1, Pb2, ..., Pbm, if and only if at the first i where Pai and Pbi differ, Pai < Pbi; when no such i exists, then n < m.
A1 >= 0. A2, ..., AN (if exist) will in the range of [-1, 100].
Length of A is in the range of [1, 1000].
B is in the range of [1, 100].




This is a classic DP problem. dp[k] (starting from k = 0) is the minimum coins from Ak+1 to An, and pos[k] is the next place to jump from Ak+1.

If working backward from dp[n-1] to dp[0], and considering smaller index first, i.e. i+1 to i+B, there is no need to worry about lexicographical order. I argue pos[k] always holds the lexicographically smallest path from k to n-1, i.e. from Ak+1 to An. The prove is as below.

Clearly, when k = n-1, it is true because there is only 1 possible path, which is [n]. When k = i and i < n-1, we search for an index j, which has smallest cost or smallest j if the same cost. If there are >= 2 paths having the same minimum cost, for example,
P = [k+1, j+1, ..., n]
Q = [k+1, m+1, ..., n] (m > j)
The path P with smaller index j is always the lexicographically smaller path.
So the argument is true by induction.

class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        vector<int> ans;
        if (A.empty() || A.back() == -1) return ans;
        int n = A.size();
        vector<int> dp(n, INT_MAX), pos(n, -1);
        dp[n-1] = A[n-1];
        // working backward
        for (int i = n-2; i >= 0; i--) {
            if (A[i] == -1) continue;
            for (int j = i+1; j <= min(i+B, n-1); j++) {
                if (dp[j] == INT_MAX) continue;
                if (A[i]+dp[j] < dp[i]) {
                    dp[i] = A[i]+dp[j];
                    pos[i] = j;
                }
            }
        }
        // cannot jump to An
        if (dp[0] == INT_MAX) return ans;
        int k = 0;
        while (k != -1) {
            ans.push_back(k+1);
            k = pos[k];
        }
        return ans;
    }
};










