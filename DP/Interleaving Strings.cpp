


97. Interleaving String


Share
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true


    
 Watch the solution to understand how the one d approach works :

https://leetcode.com/problems/interleaving-string/solution/





Approach 3: Using 2D Dynamic Programming
Algorithm

The recursive approach discussed in above solution included a character from one of the strings s1s1 or s2s2 in the resultant
interleaved string and called a recursive function to check whether the remaining portions of s1s1 and s2s2 can be interleaved 
to form the remaining portion of s3s3. In the current approach, we look at the same problem the other way around. Here, we
include one character from s1s1 or s2s2 and check whether the resultant string formed so far by one particular interleaving 
of the the current prefix of s1s1 and s2s2 form a prefix of s3s3.

Thus, this approach relies on the fact that the in order to determine whether a substring of s3s3(upto index kk), can be 
formed by interleaving strings s1s1 and s2s2 upto indices ii and jj respectively, solely depends on the characters of s1s1
and s2s2 upto indices ii and jj only and not on the characters coming afterwards.

To implement this method, we'll make use of a 2D boolean array dpdp. In this array dp[i][j]dp[i][j] implies if it is possible 
    to obtain a substring of length (i+j+2)(i+j+2) which is a prefix of s3s3 by some interleaving of prefixes of strings s1s1 
    and s2s2 having lengths (i+1)(i+1) and (j+1)(j+1) respectively. For filling in the entry of dp[i][j]dp[i][j], we need to
    consider two cases:

The character just included i.e. either at i^{th}i 
th
  index of s1s1 or at j^{th}j 
th
  index of s2s2 doesn't match the character at k^{th}k 
th
  index of s3s3, where k=i+j+1k=i+j+1. In this case, the resultant string formed using some interleaving of prefixes of s1s1 and s2s2 can never result in a prefix of length k+1k+1 in s3s3. Thus, we enter FalseFalse at the character dp[i][j]dp[i][j].

The character just included i.e. either at i^{th}ith
  index of s1s1 or at j^{th}jth
  index of s2s2 matches the character at k^{th}k th
  index of s3s3, where k=i+j+1k=i+j+1. Now, if the character just included(say xx) which matches the character at k^{th}k th
  index of s3s3, is the character at i^{th}i th
  index of s1s1, we need to keep xx at the last position in the resultant interleaved string formed so far. Thus, in order to use string s1s1 and s2s2 upto indices ii and jj to form a resultant string of length (i+j+2)(i+j+2) which is a prefix of s3s3, we need to ensure that the strings s1s1 and s2s2 upto indices (i-1)(i−1) and jj respectively obey the same property.

Similarly, if we just included the j^{th}j th
  character of s2s2, which matches with the k^{th}kth
  character of s3s3, we need to ensure that the strings s1s1 and s2s2 upto indices ii and (j-1)(j−1) also obey the same property to enter a truetrue at dp[i][j]dp[i][j].

This can be made clear with the following example:

s1="aabcc"
s2="dbbca"
s3="aadbbcbcac"

Approach 4: Using 1D Dynamic Programming
Algorithm

This approach is the same as the previous approach except that we have used only 1D dpdp array to store the results of the
prefixes of the strings processed so far. Instead of maintaining a 2D array, we can maintain a 1D array only and update the 
array's element dp[i]dp[i] when needed using dp[i-1]dp[i−1] and the previous value of dp[i]dp[i].

class Solution {
public:
    
    
 bool isInterleave(string s1, string s2, string s3) {
    
    if(s3.length() != s1.length() + s2.length())
        return false;
    
    bool table[s1.length()+1][s2.length()+1];
    
    for(int i=0; i<s1.length()+1; i++)
        for(int j=0; j< s2.length()+1; j++){
            if(i==0 && j==0)
                table[i][j] = true;
            else if(i == 0)
                table[i][j] = ( table[i][j-1] && s2[j-1] == s3[i+j-1]);
            else if(j == 0)
                table[i][j] = ( table[i-1][j] && s1[i-1] == s3[i+j-1]);
            else
                table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
        }
        
    return table[s1.length()][s2.length()];
}


};


