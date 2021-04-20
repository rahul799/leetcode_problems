
44. Wildcard Matching

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
	
	
https://procoderforu.com/wildcard-pattern-matching/


We encounter a ‘?’ in the pattern. Since ‘?’ (P[i]) can be matched with only a single character (S[j]) of text , P[1…i] will match with S[1…j] if and only if P[1…i-1] matches with S[1…j-1]. In the language of algorithms, we can say:
match(i, j) = match(i-1, j-1) if P[i] == '?'
We do not encounter any special character in the pattern. In that case, P[1…i] will match with S[1…j] if and only if P[1…i-1] matches with S[1…j-1] and P[i] matches with S[j]. Formally, we can write it as:
match(i, j) = match(i-1, j-1) && P[i]==S[j]  if P[i] not in {'?', '*'}
We encounter a ‘*’ in the pattern. Now, there can further be 2 possibilities:
We match empty sequence with ‘*’. In that case, P[1…i] will match with S[1…j] if and only if P[1…i-1] matches with S[1…j].
We match ‘*’ with S[j]. In that case, P[1…i] will match with S[1…j] if and only if P[1…i] matches with S[1…j-1]. You can appreciate the fact that ‘*’ unlike ‘?’ can be used again for a continuous sequence.
If any one of the above 2 cases returns true, then, match(i, j) will also return true. Formally speaking,

match(i, j) = match(i-1, j) || match(i, j-1) if P[i] == '*'
	
	
	
	
	
	
	

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.


	
	
	
	
Let's briefly summarize the idea of DP. We define the state P[i][j] to be whether s[0..i) matches p[0..j). The state equations are as follows:

P[i][j] = P[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?'), if p[j - 1] != '*';
P[i][j] = P[i][j - 1] || P[i - 1][j], if p[j - 1] == '*'.
	
	
	
	
	
	
	
	class Solution {
public:
    bool isMatch(string s, string p) {
        vector<int> pattern(p.size() + 1, 0);
        vector<vector<int>> dp(s.size() + 1, pattern);
        
        dp[0][0] = true;
        for(int j = 1; j < p.size() + 1; ++j){
            if(p[j-1] == '*') dp[0][j] = dp[0][j-1];    
        }
        
        for(int i = 1; i < s.size() + 1; ++i){
            for(int j = 1; j < p.size() + 1; ++j){
                int s_index = i-1;
                int p_index = j-1;
                if(s[s_index] == p[p_index] || p[p_index] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                if(p[p_index] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
	
	
	
	
	
	
	
	
	
// OPTIMISED CODE

class Solution {
 public:
  bool isMatch(string s, string p) {
    const int m = s.length();
    const int n = p.length();

    // dp[i][j] := true if s[0..i) matches p[0..j)
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
    dp[0][0] = true;

      
      
      
    auto isMatch = [](char c1, char c2) { return c1 == c2 || c2 == '?'; };

    for (int i = 0; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (p[j - 1] == '*') {
          const bool matchEmpty = dp[i][j - 1];
          const bool matchNew = i && dp[i - 1][j];
          dp[i][j] = matchEmpty || matchNew;
        } else {
          dp[i][j] = i && isMatch(s[i - 1], p[j - 1]) && dp[i - 1][j - 1];
        }

    return dp[m][n];
  }
};

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

string S, P;
bool dp[MAX][MAX], computed[MAX][MAX];

bool match(int i, int j)
{
    if (i==0 && j==0) return true;
    
    if (i==0) return false;

    if (j==0 && P[i-1] != '*') return false;

    if (computed[i][j]) return dp[i][j];
    
    computed[i][j] = true;

    if (j==0 && P[i-1]=='*') return dp[i][j] = match(i-1, j);

    if (P[i-1]=='?') return dp[i][j] = match(i-1, j-1);

    if (P[i-1]!='?' && P[i-1]!='*')
        return dp[i][j] = match(i-1, j-1) && P[i-1] == S[j-1];

    return dp[i][j] = match(i-1, j) || match(i, j-1);
}

int main()
{
    memset(computed, false, sizeof(computed));
    
    S = "baaabab", P = "**a*****ab";

    cout << match(P.length(), S.length()) << endl;
    
    // output is 1 (true)
    
}







class Solution {
public:
    bool isMatch(string s, string p) {
	int m=s.size(), n=p.size();
      bool dp[m+1][n+1];  
        for(int i = 0;i<=m;i++) {
            for(int j = 0;j<=n;j++) {
                dp[i][j] = false;
            }
        }
	dp[0][0] = true;
	for (int i=1; i<=m; i++) {
		dp[i][0] = false;
	}
	for(int j=1; j<=n; j++) {
		if(p[j-1]=='*'){
			dp[0][j] = true;
		} else {
			break;
		}
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			if (p[j-1]!='*') {
				dp[i][j] = dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='?');
			} else {
				dp[i][j] = dp[i-1][j] || dp[i][j-1];
			}
		}
	}
	return dp[m][n];
}          
        };
