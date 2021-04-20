920. Number of Music Playlists
Hard

489

49

Add to List

Share
Your music player contains N different songs and she wants to listen to L (not necessarily different) songs during your trip.  You create a playlist so that:

Every song is played at least once
A song can only be played again only if K other songs have been played
Return the number of possible playlists.  As the answer can be very large, return it modulo 10^9 + 7.

 

Example 1:

Input: N = 3, L = 3, K = 1
Output: 6
Explanation: There are 6 possible playlists. [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].
Example 2:

Input: N = 2, L = 3, K = 0
Output: 6
Explanation: There are 6 possible playlists. [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], [1, 2, 2]
Example 3:

Input: N = 2, L = 3, K = 1
Output: 2
Explanation: There are 2 possible playlists. [1, 2, 1], [2, 1, 2]
 

Note:

0 <= K < N <= L <= 100


static const int mod = 1000000007;

class Solution {
public:
    long long int memo[101][101];
    long long int dp(int N, int L, int K){
        
        
        if(N==0 && L!=0 || N!=0 && L==0){
            return 0;
        }
        
        else if(N==0 && L==0){
            return 1;
        }
        
        if(memo[N][L]!=-1){
            return memo[N][L];
        }
       // int ans = (dp(N-1,L-1,K)*N) + ((dp(N,L-1,K)*max(0,N-K));
        long long int ans = ((((dp(N-1,L-1,K)% mod)*N)% mod) + ((dp(N,L-1,K)% mod)*(max(0,N-K))% mod));
        ans%= mod;
        memo[N][L] = ans;
        return ans;
    }
    int numMusicPlaylists(int N, int L, int K) {
       
        memset(memo,-1,sizeof(memo));
        return dp(N,L,K);
        
        
        
    }
};
