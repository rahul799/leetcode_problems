886. Possible Bipartition
Medium

1135

32

Add to List

Share
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Constraints:

1 <= N <= 2000
0 <= dislikes.length <= 10000
dislikes[i].length == 2
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j]










class Solution {
private:
    bool isBipartite(int src,  vector<vector<int>>& AdjList, vector<bool>& vis, vector<int>& color) {
        queue<int> q;        
        q.push(src);
        color[src] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (const auto& v : AdjList[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                    color[v] = 1 - color[u];
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
        return true;
    }
    
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> AdjList(N);
        vector<bool> vis(N);
        vector<int> color(N);
        for (const auto& edge : dislikes) {
            AdjList[edge[0] - 1].push_back(edge[1] - 1);
            AdjList[edge[1] - 1].push_back(edge[0] - 1);
        }
        for (int i = 0; i < N; ++i) {
            if (!vis[i] && !isBipartite(i, AdjList, vis, color)) {
                return false;
            }
        }
        return true;
    }
};
