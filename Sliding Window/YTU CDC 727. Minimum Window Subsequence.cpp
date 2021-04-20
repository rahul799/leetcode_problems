
https://anshika-bhargava0202.medium.com/leetcode-727-minimum-window-subsequence-21c40baff689#:~:text=Question%20%3A,return%20the%20empty%20string%20%22%22%20.

727. Minimum Window Subsequence
Hard

923

57

Add to List

Share
Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:

Input: 
S = "abcdebdde", T = "bde"
Output: "bcde"
Explanation: 
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of T in the window must occur in order.
 

Note:

All the strings in the input will only contain lowercase letters.
The length of S will be in the range [1, 20000].
The length of T will be in the range [1, 100]













string minWindow(string S, string T) {
        int s = S.size();
        int t = T.size();
        vector<vector<int>> dp(s, vector<int>(t, -1));
        for(int i = 0; i < s; i++) {
            if(S[i] == T[0]) {
                dp[i][0] = i;
            } else {
                if(i != 0) {
                    dp[i][0] = dp[i-1][0];
                }
            }
        }
        for(int i = 1; i < s; i++) {
            for(int j = 1; j < t; j++) {
                if(S[i] == T[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int begin = -1, length = INT_MAX;
        for(int i = 0; i < s; i++) {
            int index = dp[i][t-1];
            if(index != -1) {
                int curLength = i - index + 1;
                if(curLength < length) {
                    begin = index;
                    length = curLength;
                }
            }
        }
        if(begin == -1)
            return "";
        return S.substr(begin, length);
    }


class Solution {
public:

string minWindow(string s, string t) {
   string res = "";
   int i =0 ;
   int j = 0;
    int left = 0, right= 0;
  int len = INT_MAX;

  if(s.find(t) != std::string::npos)
    return t;
 while(j<s.size()){
   if(t[i] == s[j]){
    
     if(i == t.size()-1){
       right = j;
       /*Find smallest subsequence by traversing same substring front and back. Either you get smaller substring in traversing    reverse or same as obtained in forward traversal*/
        while(i>=0){
         if(s[j] == t[i]) i--;
           j--;
       }
      j++;
       if((right-j+1)<len){
         len = (right-j+1);
         res = s.substr(j,len);
       }
     }         
     
     i++;
   }
   j++;
   
 }
  return res;
}
};



// or substring S[0, i] and T[0, j], 
// dp[i][j] is starting index k of the shortest postfix of S[0, i], such that T[0, j] is a subsequence of S[k, i]. 
// Here T[0] = S[k], T[j] = S[i]. Otherwise, dp[i][j] = -1.

// The goal is the substring with length of min(i-dp[i][n-1]) for all i < m,  where m is S.size() and n is T.size() 
// Initial condition: dp[i][0] = i if S[i] = T[0], else -1
// Equations: If S[i] = T[j], dp[i][j] = max(dp[k][j-1]) for all k < i; else dp[i][j] = -1;      
// O(mn) space 82 ms

class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < m; i++) 
            if (S[i] == T[0]) dp[0][i] = i;
        for (int j = 1; j < n; j++) {
            int k = -1;
            for (int i = 0; i < m; i++) {
                if (k != -1 && S[i] == T[j]) dp[j][i] = k;
                if (dp[j-1][i] != -1) k = dp[j-1][i];
            }
        }
        int st = -1, len = INT_MAX;
        for (int i = 0; i < m; i++) {
            if (dp[n-1][i] != -1 && i-dp[n-1][i]+1 < len) {
                st = dp[n-1][i];
                len = i-dp[n-1][i]+1;
            }    
        }
        return st == -1? "":S.substr(st, len);
    }
};
