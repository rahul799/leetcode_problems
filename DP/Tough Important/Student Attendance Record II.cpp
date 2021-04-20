552. Student Attendance Record II
Hard

661

126

Add to List

Share
Given a positive integer n, return the number of all possible attendance records with length n, which will be regarded as rewardable. The answer may be very large, return it after mod 109 + 7.

A student attendance record is a string that only contains the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

Example 1:
Input: n = 2
Output: 8 
Explanation:
There are 8 records with length 2 will be regarded as rewardable:
"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" won't be regarded as rewardable owing to more than one absent times. 
Note: The value of n won't exceed 100,000.





// Ends at A
A(n) = L(n - 1) + P(n - 1)
// Ends at L but doesnt contain A
L(n) = P(n - 2) + P(n - 1)
// Ends at L and contains A
AL(n) = A(n - 1) + A(n - 2) + P(n - 1) + P(n - 2)
// Ends at P but doesnt contain A
P(n) = P(n - 1) + L(n - 1)
// Ends at P but doesnt contain A
AP(n) = A(n - 1) + AL(n - 1) + AP(n - 1)
Seed value

P[0] = 1
A[1] = L[1] = P[1] = 1
Implementation

3 has been added before taking the mod to avoid negative mod value

class Solution {
public:
    
    int mod = 1e9+7;
    
    int checkRecord(int n) {
        vector<vector<long long>> dp(3, vector<long long>(5));
        dp[1] = vector<long long>(5, 1);
        dp[0][1] = dp[0][3] = 1;
        dp[1][2] = dp[1][4] = 0;
        for(int i = 2; i <= n; ++i) {
            dp[i % 3][0] = (dp[(i + 2) % 3][1] + dp[(i + 2) % 3][3]) % mod;
            dp[i % 3][1] = (dp[(i + 1) % 3][3] + dp[(i + 2) % 3][3]) % mod;
            dp[i % 3][2] = (dp[(i + 2) % 3][0] + dp[(i + 1) % 3][0] + dp[(i + 2) % 3][4] + dp[(i + 1) % 3][4]) % mod;
            dp[i % 3][3] = (dp[(i + 2) % 3][1] + dp[(i + 2) % 3][3]) % mod;
            dp[i % 3][4] = (dp[(i + 2) % 3][0] + dp[(i + 2) % 3][2] + dp[(i + 2) % 3][4]) % mod;
        }
        long long ans = 0;
        for(int i = 0; i < 5; ++i) {
            cout << dp[n % 3][i] << ' ';
            ans = (ans + dp[n % 3][i]) % mod;
        }
        return ans;
    }
};







dp[i][0]: Studnet presented at i class
dp[i][1]: Student was late at i class
dp[i][2]: Student was late at i-1 and i class

Code
#define LL long long
class Solution {
    LL MOD = 1e9 + 7;
public:
    int checkRecord(int n) {
        vector<vector<LL>> dp(n + 1, vector<LL>(3, 1));
        //There is no absent
        dp[0][0] = 1; dp[0][1] = 1; dp[0][2] = 0;
        for(int i = 1; i <= n; i++){
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
            dp[i][1] = dp[i - 1][0] % MOD;
            dp[i][2] = dp[i - 1][1] % MOD;
        }
    
        //Absent at different position
        LL res = dp[n][0];
        for(int i = 1; i <= n; i++){
            res = (res + dp[i - 1][0] * dp[n - i][0]) % MOD;
        }
        return res;
    }
};
