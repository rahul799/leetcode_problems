


https://leetcode.com/problems/numbers-at-most-n-given-digit-set/

902. Numbers At Most N Given Digit Set
Hard

484

68

Add to List

Share
Given an array of digits which is sorted in non-decreasing order. You can write numbers using each digits[i] as many times as we want. For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.

Return the number of positive integers that can be generated that are less than or equal to a given integer n.

 

Example 1:

Input: digits = ["1","3","5","7"], n = 100
Output: 20
Explanation: 
The 20 numbers that can be written are:
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
Example 2:

Input: digits = ["1","4","9"], n = 1000000000
Output: 29523
Explanation: 
We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
In total, this is 29523 integers that can be written using the digits array.
Example 3:

Input: digits = ["7"], n = 8
Output: 1
 

Constraints:

1 <= digits.length <= 9
digits[i].length == 1
digits[i] is a digit from '1' to '9'.
All the values in digits are unique.
digits is sorted in non-decreasing order.
1 <= n <= 109









// Time and Space - O(log10(N))
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        
        int ans = 0, n=D.size();
        
        // No. of digits in N
        int len = (int)(log10(N) + 1);
        
        // Convert N into its digits
        string digits = to_string(N); 
        
        // Count all possible integers having less digits than N
        for (int i=1, cnt=n; i<len; i++) {
            ans += cnt;
            cnt *= n;
        }
        
        // Count all possible integers having digits = digits in N
        // Using DP
        vector<vector<int>> dp(len, vector<int>(2, -1));
        ans += helper(0, 1, D, digits, dp);
        
        return ans;
    }
    
    int helper(int idx, int limit, vector<string>& D, string& digits, vector<vector<int>>& dp) {
        
        // Base case
        if (idx == digits.size()) return 1;
        
        // DP lookUp
        if (dp[idx][limit] != -1) return dp[idx][limit];
        
        int ans = 0;
        // Recursion
        if (limit) {
            for (int i=0; i<D.size() && D[i][0] <= digits[idx]; i++) {
                
                if (D[i][0] < digits[idx])
                    ans += helper(idx+1, 0, D, digits, dp);
                else
                    ans += helper(idx+1, 1, D, digits, dp);
            }
        }
        else {
            ans += D.size() * helper(idx+1, 0, D, digits, dp);
        }
        
        // Memoization
        return dp[idx][limit] = ans;
    }
};




class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        
        string s = to_string(n);
        
       int  numLen = s.size();
        int result = 0;
        
        for(int  i = 1; i < numLen; ++i )
            result += pow(digits.size(), i);
        
        for(int i = 0; i < numLen; i++){
            bool hasSameNum = false;
            for( string &d : digits ){
                if(d[0] < s[i])
                    result +=  pow(digits.size(), numLen - i - 1);
                else if ( d[0] == s[i]) hasSameNum = true;
            }
            if (!hasSameNum) return result;
        }
        
        return result + 1;
    }
};


