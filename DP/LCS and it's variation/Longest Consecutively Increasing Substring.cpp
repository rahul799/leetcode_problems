


Longest Consecutively Increasing Substring




You are given a string s containing lowercase alphabet characters as well as "?". For each "?" you must either delete it or replace it with any lowercase alphabet character.

Return the length of the longest consecutively increasing substring that starts with "a".

Constraints

1 ≤ n ≤ 100,000 where n is the length of s
Example 1
Input
s = "bca???de"
Output
5
Explanation
We can turn s into "bcabcde" and "abcde" is the longest consecutively increasing substring that starts with "a"

Example 2
Input
s = "zyx"
Output
0
Explanation
No substring here starts with "a"
  
  
  
  
  
  

int solve(string s) {
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a' or s[i] == '?') {
            ans = max(ans, 1);
            int totaldels = 0, lastchar = 'a';
            for (int j = i + 1; j < s.length(); j++) {
                if (s[j] == '?') {
                    totaldels += 1;
                } else {
                    if (s[j] <= lastchar or lastchar + totaldels + 1 < s[j]) {
                        break;
                    }
                    lastchar = s[j];
                    totaldels = 0;
                    ans = max(ans, lastchar - 'a' + 1);
                }
                ans = max({ans, 1, lastchar - 'a' + 1 + totaldels});
                if(ans >= 26) break;
            }
        }
    }
    return min(26, ans);
}
