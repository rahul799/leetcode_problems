Longest Path in a Graph
Question 468 of 992
You are given a two-dimensional integer list graph representing an adjacency list where graph[i] contains a list of nodes i is connected to. Given that the graph is acyclic and directed, return the length of the longest path in the graph without repeated nodes.

Constraints

n, m ≤ 1,000 where n and m are the number of rows and columns in graph.
Example 1
Input
Visualize
graph =
0

1

2

3

4

5

Output
5
Explanation
We can take the path 0 -> 3 -> 1 -> 2 -> 4 -> 5 with length 5.

Example 2
Input
Visualize
graph =
0

1

2

3

Output
2
Explanation
We can take 2 -> 1 -> 3 with length 2.









// If we let longest_path(node) return the longest path starting at node, then we can get the answer to this question by returning the max of all 
longest_path(node) for every node.

// We can compute longest_path(node) recursively by taking the maximum of all longest_path(neighbor) and adding 1. More formally:

// longest_path(node) = 1 + max(longest_path(neighbor)) for all neighbor of node
// We will slap on some memoization/caching with lru_cache(None) because we might encounter the same node and we dont want to recalculate it every time 
and blow up our time complexity.

// Implementation
// We will use recursion and lru_cache(None) to implement caching

// Time Complexity
// \mathcal{O}(e + v)O(e+v) where e is the number of edges and v is the number of verticies. This is because we visit at most every edge once and every 
vertex once.






int dfs(vector<vector<int>>& graph, int s, vector<int>& dis) {
    if (dis[s] != -1) return dis[s];

    if (graph[s].size() == 0) return dis[s] = 0;

    int ans = 0;
    for (auto v : graph[s]) {
        ans = max(ans, dfs(graph, v, dis));
    }

    return dis[s] = ans + 1;
}
int solve(vector<vector<int>>& graph) {
    int n = graph.size();

    int len = 0;
    vector<int> dis(n, -1);
    for (int i = 0; i < n; i++) {
        dis[i] = dfs(graph, i, dis), len = max(len, dis[i]);
    }
    // for(int i=0;i<n;i++)cout<<dis[i]<<" ";
    return len;
}

