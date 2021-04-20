

276. Paint Fence
Medium

903

309

Add to List

Share
You are painting a fence of n posts with k different colors. You must paint the posts following these rules:

Every post must be painted exactly one color.
At most one pair of adjacent fence posts can have the same color.
Given the two integers n and k, return the number of ways you can paint the fence.

 

Example 1:


Input: n = 3, k = 2
Output: 6
Explanation: All the possibilities are shown.
Note that painting all the posts red or all the posts green is invalid because there can only be at most one pair of adjacent posts that are the same color.
Example 2:

Input: n = 1, k = 1
Output: 1
Example 3:

Input: n = 7, k = 2
Output: 42
 

Constraints:

1 <= n <= 50
1 <= k <= 105
The answer is guaranteed to be in the range [0, 231 - 1] for the given n and k.







class Solution {
public:
    int numWays(int n, int k) {
    long long mod = 1000000007;

if(n==0) return 0;
    
    if(n==1) return k;
long long same = k%mod; 
        
  long long diff = (k*(k-1))%mod;

for(long long i=2;i< n; i++){ 
    
    long long prev = diff%mod;

diff = ((same+diff)*(k-1))%mod;

same = prev%mod;

} return (same+diff)%mod;

        
    }
};
