


1349. Maximum Students Taking Exam
Hard

361

10

Add to List

Share
Given a m * n matrix seats  that represent seats distributions in a classroom. If a seat is broken, it is denoted by '#' character otherwise it is denoted by a '.' character.

Students can see the answers of those sitting next to the left, right, upper left and upper right, but he cannot see the answers of the student sitting directly in front or behind him. Return the maximum number of students that can take the exam together without any cheating being possible..

Students must be placed in seats in good condition.

 
https://leetcode.com/problems/maximum-students-taking-exam/discuss/?currentPage=1&orderBy=most_votes&query=


Example 1:


Input: seats = [["#",".","#","#",".","#"],
                [".","#","#","#","#","."],
                ["#",".","#","#",".","#"]]
Output: 4
Explanation: Teacher can place 4 students in available seats so they don't cheat on the exam. 
Example 2:

Input: seats = [[".","#"],
                ["#","#"],
                ["#","."],
                ["#","#"],
                [".","#"]]
Output: 3
Explanation: Place all students in available seats. 

Example 3:

Input: seats = [["#",".",".",".","#"],
                [".","#",".","#","."],
                [".",".","#",".","."],
                [".","#",".","#","."],
                ["#",".",".",".","#"]]
Output: 10
Explanation: Place students in available seats in column 1, 3 and 5.
 

Constraints:

seats contains only characters '.' and'#'.
m == seats.length
n == seats[i].length
1 <= m <= 8
1 <= n <= 8


Yet to understand

We can do the dp row by row, we start from row 1 until row n.
dp[i][mask] represents that, we are now at row i and the state of this row is mask.

Now, state conversion is: We consider every possible state of the last row, and check if the state conversion is legal (that is, there will be no cheating). Hence we have:

dp[i][mask] = max(dp[i][mask], dp[i-1][premask] + __builtin_popcount(mask));
where mask and premask are both legal, and these two rows together will have no cheating.

Note: __builtin_popcount() count the number of 1-bits in the mask.

Code:

class Solution {
public:
    int n,m;
    int ans = 0;
    int dp[9][(1<<8)+2];  //dp[i][mask]: we are in row i(i is from [1,9]), state is mask
    int avail[9];  //avail[i] is the mask representing available seats in row i
        
    int maxStudents(vector<vector<char>>& seats) {
        n = seats.size(); m = seats[0].size();
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                if (seats[i-1][j] == '.') {
                    avail[i] |= (1<<j);
                }
            }
        }
        
        for (int mask = 0; mask < (1<<m); mask++) {
            dp[0][mask] = 0;  //initialize all illegal states with 0
        }
        
        for (int i = 1; i <= n; i++) {  //now we are at row i
            for (int premask = 0; premask < (1<<m); premask++) {
                if (dp[i-1][premask] == -1) continue;
                for (int mask = 0; mask < (1<<m); mask++) {
                    if ((mask & avail[i]) != mask) continue;
                    if (mask&(mask>>1)) continue;  //if there is adjacent 1
                    
                    /*checking this row and last row*/
                    if (mask&(premask<<1) || mask&(premask>>1)) continue;
                    dp[i][mask] = max(dp[i][mask], dp[i-1][premask] + __builtin_popcount(mask));
                }
            }
        }
        
        for (int mask = 0; mask < (1<<m); mask++) {
            ans = max(ans, dp[n][mask]);
        }
        return ans;
    }
};
