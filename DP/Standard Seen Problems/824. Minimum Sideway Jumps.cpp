








824. Minimum Sideway Jumps
Medium

151

9

Add to List

Share
There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to 
jump to point n. However, there could be obstacles along the way.

You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i]
at point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.

For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1. To avoid 
obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no 
obstacle on the new lane.

For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.

Note: There will be no obstacles on points 0 and n.

 

Example 1:


Input: obstacles = [0,1,2,3,0]
Output: 2 
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps (red arrows).
Note that the frog can jump over obstacles only when making side jumps (as shown at point 2).
Example 2:


Input: obstacles = [0,1,1,3,3,0]
Output: 0
Explanation: There are no obstacles on lane 2. No side jumps are required.
Example 3:


Input: obstacles = [0,2,1,0,3,0]
Output: 2
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps.
 

Constraints:

obstacles.length == n + 1
1 <= n <= 5 * 105
0 <= obstacles[i] <= 3
obstacles[0] == obstacles[n] == 0



KEY POINTS :

The state of dp[lane][i] will be storing the minimum no. of side moves to be taken to reach n.
If the current state i.e dp[lane][i] is having obstacle , we return with a large value as it is not possible to go through this obstacle .
The lane are taken as { 0 , 1 , 2 } instead of { 1 , 2 , 3 } .
int dp[3][1000000] ;
int n ;
int dfs(vector<int>& obstacles , int lane , int i )
{
    if(i >= n)
        return 0 ;
    if(dp[lane][i] != -1)
        return dp[lane][i] ;
    if(obstacles[i] == lane + 1)
        return 1e9 ;
    int lane2 = (lane+1) % 3 , lane3 = (lane+2) % 3 ;
    dp[lane][i] = dfs(obstacles , lane , i+1) ;
    if(obstacles[i] != lane2 + 1)
        dp[lane][i] = min(dp[lane][i] , dfs(obstacles , lane2 , i+1) + 1) ;
    if(obstacles[i] != lane3 + 1)
        dp[lane][i] = min(dp[lane][i] , dfs(obstacles , lane3 , i+1) + 1) ;
    return dp[lane][i] ;
}

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        n = obstacles.size() ;
        memset(dp , -1 , sizeof(dp)) ;
        return dfs(obstacles , 1 , 0 ) ;
    }
};
