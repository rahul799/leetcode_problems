


323. Number of Connected Components in an Undirected Graph
Medium

1107

35

Add to List

Share
You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.

 

Example 1:


Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
Example 2:


Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1
 

Constraints:

1 <= n <= 2000
1 <= edges.length <= 5000
edges[i].length == 2
0 <= ai <= bi < n
ai != bi
There are no repeated edges.










class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>>graph(n);
        vector<int>visited(n);
        for(auto x: edges){
            graph[x.first].push_back(x.second);
            graph[x.second].push_back(x.first);
        }
        int label = 0;
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            label++;
            DFS(graph, i, visited);
        }
        return label;
    }
    
    void DFS(vector<vector<int>>& graph, int root, vector<int>& visited){
        if(visited[root]) return;
        visited[root] = 1;
        for(auto neigh: graph[root])
            if(!visited[neigh]) DFS(graph, neigh, visited);
    }
};
