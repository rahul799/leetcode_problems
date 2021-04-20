The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.





class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r=dungeon.size();
        int c=dungeon[0].size();
        vector<vector<int>> dp(r,vector<int>(c));
        
        for(int i=r-1;i>=0;--i)
        {
            for(int j=c-1;j>=0;--j)
            {
                if(i==r-1 && j==c-1)    //Bottom-Right cell (Princess Cell)
                    dp[i][j] = min(0,dungeon[i][j]);
                else if(i==r-1)   //last row
                    dp[i][j] = min(0,dungeon[i][j]+dp[i][j+1]);
                else if(j==c-1)   //last col       
                    dp[i][j] = min(0,dungeon[i][j]+dp[i+1][j]);
                else
                    dp[i][j] = min(0,dungeon[i][j]+max(dp[i][j+1],dp[i+1][j]));
            }
        }
        return abs(dp[0][0])+1;
    }
};
