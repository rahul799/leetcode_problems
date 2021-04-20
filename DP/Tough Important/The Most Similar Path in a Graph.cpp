


1548. The Most Similar Path in a Graph
Hard

125

64

Add to List

Share
We have n cities and m bi-directional roads where roads[i] = [ai, bi] connects city ai with city bi. Each city has a name consisting of exactly 3 upper-case English letters given in the string array names. Starting at any city x, you can reach any city y where y != x (i.e. the cities and the roads are forming an undirected connected graph).

You will be given a string array targetPath. You should find a path in the graph of the same length and with the minimum edit distance to targetPath.

You need to return the order of the nodes in the path with the minimum edit distance, The path should be of the same length of targetPath and should be valid (i.e. there should be a direct road between ans[i] and ans[i + 1]). If there are multiple answers return any one of them.

The edit distance is defined as follows:



Follow-up: If each node can be visited only once in the path, What should you change in your solution?

 

Example 1:


Input: n = 5, roads = [[0,2],[0,3],[1,2],[1,3],[1,4],[2,4]], names = ["ATL","PEK","LAX","DXB","HND"], targetPath = ["ATL","DXB","HND","LAX"]
Output: [0,2,4,2]
Explanation: [0,2,4,2], [0,3,0,2] and [0,3,1,2] are accepted answers.
[0,2,4,2] is equivalent to ["ATL","LAX","HND","LAX"] which has edit distance = 1 with targetPath.
[0,3,0,2] is equivalent to ["ATL","DXB","ATL","LAX"] which has edit distance = 1 with targetPath.
[0,3,1,2] is equivalent to ["ATL","DXB","PEK","LAX"] which has edit distance = 1 with targetPath.
Example 2:


Input: n = 4, roads = [[1,0],[2,0],[3,0],[2,1],[3,1],[3,2]], names = ["ATL","PEK","LAX","DXB"], targetPath = ["ABC","DEF","GHI","JKL","MNO","PQR","STU","VWX"]
Output: [0,1,0,1,0,1,0,1]
Explanation: Any path in this graph has edit distance = 8 with targetPath.
Example 3:



Input: n = 6, roads = [[0,1],[1,2],[2,3],[3,4],[4,5]], names = ["ATL","PEK","LAX","ATL","DXB","HND"], targetPath = ["ATL","DXB","HND","DXB","ATL","LAX","PEK"]
Output: [3,4,5,4,3,2,1]
Explanation: [3,4,5,4,3,2,1] is the only path with edit distance = 0 with targetPath.
It's equivalent to ["ATL","DXB","HND","DXB","ATL","LAX","PEK"]
 

Constraints:

2 <= n <= 100
m == roads.length
n - 1 <= m <= (n * (n - 1) / 2)
0 <= ai, bi <= n - 1
ai != bi 
The graph is guaranteed to be connected and each pair of nodes may have at most one direct road.
names.length == n
names[i].length == 3
names[i] consists of upper-case English letters.
There can be two cities with the same name.
1 <= targetPath.length <= 100
targetPath[i].length == 3
targetPath[i] consists of upper-case English letters.





class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        
        vector<vector<int>> adj(n);
        int total_t = targetPath.size();
        for (vector<int> road: roads) {
            int u = road[0];
            int v = road[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        vector<vector<int>> dp(n, vector<int>(targetPath.size(), INT_MAX));
        vector<vector<int>> parent(n, vector<int>(targetPath.size(), INT_MAX));

        for (int u = 0; u < n; u++) {
            string city = targetPath[0];
            dp[u][0] = names[u] == city ? 0 : 1;
        }
        for (int t = 1; t < total_t; t++) {
            for (int u = 0; u < n; u++) {
                string city = targetPath[t];
                int cost =  names[u] == city ? 0 : 1;
                int min_cost = INT_MAX;

                for (int neighbor : adj[u]) {
                    int curr_total_cost = dp[neighbor][t-1] + cost;
                    if (curr_total_cost < min_cost) {
                        parent[u][t] = neighbor;
                        min_cost = curr_total_cost;
                    }
                }
                dp[u][t] = min_cost;
            }
        }
        vector<int> ans(total_t);
        int final_min_cost = INT_MAX;
        int last = -1;
        for (int u = 0; u < n; u++) {
            if (dp[u][total_t-1] < final_min_cost) {
                last = u;
                final_min_cost = dp[u][total_t-1];
            }
        }

        for (int t = total_t - 1; t >=0 ; t--) {
            ans[t] = last;
            last = parent[last][t];
        }
        return ans;
        
    }
};
