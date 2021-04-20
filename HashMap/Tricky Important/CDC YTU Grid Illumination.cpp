


1001. Grid Illumination
Hard

253

72

Add to List

Share
You are given a grid of size N x N, and each cell of this grid has a lamp that is initially turned off.

You are also given an array of lamp positions lamps, where lamps[i] = [rowi, coli] indicates that the lamp at grid[rowi][coli] is turned on. When a lamp is turned on, it illuminates its cell and all other cells in the same row, column, or diagonal.

Finally, you are given a query array queries, where queries[i] = [rowi, coli]. For the ith query, determine whether grid[rowi][coli] is illuminated or not. After answering the ith query, turn off the lamp at grid[rowi][coli] and its 8 adjacent lamps if they exist. A lamp is adjacent if its cell shares either a side or corner with grid[rowi][coli].

Return an array of integers ans, where ans[i] should be 1 if the lamp in the ith query was illuminated, or 0 if the lamp was not.

 

Example 1:


Input: N = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
Output: [1,0]
Explanation: We have the initial grid with all lamps turned off. In the above picture we see the grid after turning on the lamp at grid[0][0] then turning on the lamp at grid[4][4].
The 0th query asks if the lamp at grid[1][1] is illuminated or not (the blue square). It is illuminated, so set ans[0] = 1. Then, we turn off all lamps in the red square.

The 1st query asks if the lamp at grid[1][0] is illuminated or not (the blue square). It is not illuminated, so set ans[1] = 0. Then, we turn off all lamps in the red rectangle.

Example 2:

Input: N = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,1]]
Output: [1,1]
Example 3:

Input: N = 5, lamps = [[0,0],[0,4]], queries = [[0,4],[0,1],[1,4]]
Output: [1,1,0]
 

Constraints:

1 <= N <= 109
0 <= lamps.length <= 20000
lamps[i].length == 2
0 <= lamps[i][j] < N
0 <= queries.length <= 20000
queries[i].length == 2
0 <= queries[i][j] < N








class Solution {
public:
vector gridIllumination(int N, vector<vector>& lamps, vector<vector>& q) {
vector ans;
if(N==0)
return ans;
set<pair<int,int>> s;
unordered_map<int,int> x;
unordered_map<int,int> y;
unordered_map<int,int> xplusy;
unordered_map<int,int> xminusy;

    for(int i=0;i<lamps.size();i++)
    {
        x[lamps[i][0]]++;      // storing count of x
        y[lamps[i][1]]++;     // storing count of y
        xplusy[(lamps[i][0]+lamps[i][1])]++;     // storing x+y  (to take care of anti-diag)
        xminusy[(lamps[i][0]-lamps[i][1])]++;   // storing x+y (to take care of diagonal)
        s.insert(make_pair(lamps[i][0],lamps[i][1]));     // storing lamp to do O(1) check later on
    }
    
    for(int i=0;i<q.size();i++)
    {
        if(x[q[i][0]]>0 || y[q[i][1]]>0 || xplusy[(q[i][0]+q[i][1])]>0 || xminusy[(q[i][0]-q[i][1])]>0)
        {
            ans.push_back(1);
            int X = q[i][0];
            int Y = q[i][1];
            for(int j=-1;j<=1;j++)
            {
                for(int k=-1;k<=1;k++)
                {
                    if(X+j>=0 && X+j<N && Y+k>=0 && Y+k<N && s.find(make_pair(X+j,Y+k))!=s.end())
                    {
                        s.erase(make_pair(X+j,Y+k));
                        x[X+j]--;
                        y[Y+k]--;
                        xplusy[(X+j+Y+k)]--;
                        xminusy[(X+j-Y-k)]--;
                    }
                }
            }
        }
        else
            ans.push_back(0);
    }
    return ans;
}
};
