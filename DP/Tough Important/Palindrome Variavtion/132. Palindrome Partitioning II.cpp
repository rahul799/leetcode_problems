

https://leetcode.com/problems/palindrome-partitioning-ii/discuss/42212/Two-C%2B%2B-versions-given-(one-DP-28ms-one-Manancher-like-algorithm-10-ms)



132. Palindrome Partitioning II
Hard

1457

41

Add to List

Share
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1


One typical solution is DP based. Such solution first constructs a two-dimensional bool array isPalin to indicate whether the sub-string s[i..j] is palindrome. 
To get such array, we need O(N^2) time complexity. Moreover, to get the minimum cuts, we need another array minCuts to do DP and minCuts[i] saves the minimum cuts found for the sub-string s[0..i-1]. minCuts[i] is initialized to i-1, which is the maximum cuts needed (cuts the string into one-letter characters) and minCuts[0] initially sets to -1, which is needed in the case that s[0..i-1] is a palindrome. When we construct isPalin array, we update minCuts everytime we found a palindrome sub-string, i.e. if s[i..j] is a palindrome, then minCuts[j+1] will be updated to the minimum of the current minCuts[j+1] and minCut[i]+1(i.e. cut s[0..j] into s[0,i-1] and s[i,j]). At last, we return minCuts[N].
So the complexity is O(N^2). However, it can be further improved since as described above, we only update minCuts when we find a palindrome substring, while the
DP algorithm spends lots of time to calculate isPalin, most of which is false (i.e. not a palindrome substring). If we can reduce such unnecessary calculation,
then we can speed up the algorithm. This can be achieved with a Manancher-like solution, which is also given
as following.

 
 
 
 
 A typical dp problem:
For each position i, incrementally find palindrome of length 1,3,5,..., then, of length 2,4,6. Suppose the start index of the found palindrome is idx_s and the end index of the palindrome is idx_e, update the dp table as the follow formula:
dp[idx_e] = min(dp[idx_e], dp[idx_s-1] + 1)

Wait a min, how about idx_s equal to 0? Seems like we should and some kind of special case test. Actually, this can be avoided by a sentinel trick. Refer to code for details.

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = -1;       //act as a sentinel
        for(int i = 0; i < n; i++){
	//palindrome of length 1,3,5...
            for(int len = 0; i-len >= 0 && i+len < n && s[i-len] == s[i+len]; len++)
                dp[i+len+1] = min(dp[i+len+1], dp[i-len]+1);
	//palindrome of lenght 2,4,6...
            for(int len = 0; i-len >= 0 && i+len+1 < n && s[i-len] == s[i+len+1]; len++)
                dp[i+len+2] = min(dp[i+len+2], dp[i-len]+1);
        }
        return dp[n];
    }
};





/ DP solution
    class Solution {
    public:
        int minCut(string s) {
            const int N = s.size();
            if(N<=1) return 0;
            int i,j;
            bool isPalin[N][N];
            fill_n(&isPalin[0][0], N*N, false);
            int minCuts[N+1];
            for(i=0; i<=N; ++i) minCuts[i] = i-1;
            
            for(j=1; j<N; ++j)
            {
                for(i=j; i>=0; --i)
                {
                    if( (s[i] == s[j]) && ( ( j-i < 2 ) || isPalin[i+1][j-1] ) )
                    {
                        isPalin[i][j] = true;
                        minCuts[j+1] = min(minCuts[j+1], 1 + minCuts[i]);    
                    }
                }
            }
            return minCuts[N];
            
        }
    };
The Manancher-like solution scan the array from left to right (for i loop) and only check those sub-strings centered at s[i]; once a non-palindrome string is found, it will stop and move to i+1. Same as the DP solution, minCUTS[i] is used to save the minimum cuts for s[0:i-1]. For each i, we do two for loops (for j loop) to check if the substrings s[i-j .. i+j] (odd-length substring) and s[i-j-1.. i+j] (even-length substring) are palindrome. By increasing j from 0, we can find all the palindrome sub-strings centered at i and update minCUTS accordingly. Once we meet one non-palindrome sub-string, we stop for-j loop since we know there no further palindrome substring centered at i. This helps us avoid unnecessary palindrome substring checks, as we did in the DP algorithm. Therefore, this version is faster.

//Manancher-like solution
class Solution {
public:
    int minCut(string s) {
        const int N = s.size();
        if(N<=1) return 0;
        
        int i, j, minCUTS[N+1];
        for(i=0; i<=N; ++i) minCUTS[i] = i-1;
        
        for(i=1;i<N;i++)
        {
            for(j=0;(i-j)>=0 && (i+j)<N && s[i-j]== s[i+j]; ++j) // odd-length substrings 
                minCUTS[i+j+1] = min(minCUTS[i+j+1], 1 + minCUTS[i-j]);

            for(j=0;(i-j-1)>=0 && (i+j)<N && s[i-j-1]== s[i+j]; ++j) // even-length substrings
                minCUTS[i+j+1] = min(minCUTS[i+j+1], 1 + minCUTS[i-j-1]);
        }
        return minCUTS[N];
    }
};



