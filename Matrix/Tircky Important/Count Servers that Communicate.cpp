

1267. Count Servers that Communicate
Medium

525

50

Add to List

Share
You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

 

Example 1:



Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.
Example 2:



Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.
Example 3:



Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m <= 250
1 <= n <= 250
grid[i][j] == 0 or 1
  
  



https://leetcode.com/problems/count-servers-that-communicate/



class Solution {
public:
    int countServers(vector<vector<int>>& grid) 
    {
        vector<int> rows(grid.size(),0),columns(grid[0].size(),0);	//Stores count of servers in rows and colums
        for(int i=0;i<grid.size();i++)						//Fill the count vectors
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j])
                    rows[i]++,columns[j]++;
        int result=0;
        for(int i=0;i<grid.size();i++)			//Traverse the grid to get result count
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]&&(columns[j]>1||rows[i]>1))	//Check if there are any other server except the current one in it's corresponding row or column.
                    result++;
        return result;
    }
};
