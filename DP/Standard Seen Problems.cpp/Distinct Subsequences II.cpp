Distinct Subsequences II
Hard

475

17

Add to List

Share
Given a string S, count the number of distinct, non-empty subsequences of S .

Since the result may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: "abc"
Output: 7
Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
Example 2:

Input: "aba"
Output: 6
Explanation: The 6 distinct subsequences are "a", "b", "ab", "ba", "aa" and "aba".
Example 3:

Input: "aaa"
Output: 3
Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
 

 

Note:

S contains only lowercase letters.
1 <= S.length <= 2000





pproach 1: Dynamic Programming
Intuition and Algorithm

Even though the final code for this problem is very short, it is not very intuitive to find the answer. In the solution below, we'll focus on 
finding all subsequences (including empty ones), and subtract the empty subsequence at the end.

Let's try for a dynamic programming solution. In order to not repeat work, our goal is to phrase the current problem in terms of the answer to 
previous problems. A typical idea will be to try to count the number of states dp[k] (distinct subsequences) that use letters
S[0], S[1], ..., S[k].

Naively, for say, S = "abcx", we have dp[k] = dp[k-1] * 2. This is because for dp[2] which counts ("", "a", "b", "c", "ab", "ac", "bc", "abc"), 
dp[3] counts all of those, plus all of those with the x ending, like ("x", "ax", "bx", "cx", "abx", "acx", "bcx", "abcx"). Here's a visualization
for this string.

However, for something like S = "abab", let's play around with it. We have:

dp[0] = 2, as it counts ("", "a")
dp[1] = 4, as it counts ("", "a", "b", "ab");
dp[2] = 7 as it counts ("", "a", "b", "aa", "ab", "ba", "aba");
dp[3] = 12, as it counts ("", "a", "b", "aa", "ab", "ba", "bb", "aab", "aba", "abb", "bab", "abab").
We have that dp[3]countsdp[2], plus("b", "aa", "ab", "ba", "aba")with"b"added to it. Notice that("", "a")are missing from this list, as 
they get double counted. In general, the sequences that resulted from putting"b"the last time (ie."b", "ab"`) will get double counted.
Here's a visualization for a string with repeated letters.

This insight leads to the recurrence:

dp[k] = 2 * dp[k-1] - dp[last[S[k]] - 1]

The number of distinct subsequences ending at S[k], is twice the distinct subsequences counted by dp[k-1] (all of them, plus all of
them with S[k] appended), minus the amount we double counted, which is dp[last[S[k]] - 1].



class Solution {
public:
    int distinctSubseqII(string s) {
        const int N = s.length();
        const int MOD = 1e9 + 7;
        
        vector<int> dp(N+1);
        dp[0] = 1;
        vector<int> last(26, -1);
        
        for(int i = 0; i < N; i++){
            int x = s[i] - 'a';
            dp[i+1] = dp[i] * 2 % MOD;
            if(last[x] >= 0) // if this is the first occurence of ch
                dp[i+1] -= dp[last[x]];
            dp[i+1] %= MOD;
            last[x] = i;
        }
        dp[N]--;
        if(dp[N] < 0) dp[N] += MOD;
        return dp[N];
    }
};












 
