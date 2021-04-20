91. Decode Ways

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).



class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0|| s[0] == '0') return 0;
        vector<int> dp(n+1, 0);
        //start w dp[0] = 1 , since number has to start w >=1 && <=9
        dp[0] = 1;
      // this is done to cope up with the logic of for loop  
        dp[1] = dp[0];
        for(int i = 2; i <= n; i++ ){
            // obserbve here it will be greater than zero
            if(s[i - 1] - '0' > 0 && s[i -1] - '0' <= 9){
                dp[i] += dp[i-1];
            }
            int num = (s[i - 2] - '0') * 10 + s[i - 1] - '0' ;
            if(num >= 10 && num <= 26){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
        
    }
};
