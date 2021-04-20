Tag Game in a Tree
You are given a two-dimensional list of integers edges representing a tree, where each element is of the form [x, y] meaning there's an undirected edge between 
x and y. You are also given integers u and v.

You are currently at node u, and your opponent is at node v. In the first round, you move, then in the next round your opponent moves, and then you move, and so on.
Your opponent can choose to not make a move in a round. Return the minimum number of rounds it takes for you to catch your opponent, given that you both play optimally.

Constraints

n ≤ 100,000 where n is the length of edges
Example 1
Input
edges = [
    [0, 1],
    [1, 2]
]
u = 0
v = 2
Output
3
Explanation
First, you move from node 0 to 1. Then your opponent stays in the current node. And then you move to node 2.






Intuition
Intuition: If you are catching someone, you will never "wait" and always catch. And the other person calculates if he can reach a point before you and try to be farthest as 
possible. But at the end you will catch him.

Solution Approach:
From u and v, find the time required to reach all the nodes in the graph. let them dist1, dist2. Can be simply done by DFS as the given graph is a tree.
For any 'node' in the graph, if dist1[node]+1>dist[node] ; that means you cannot reach 'node' before other person, so you have to travel at least dist1[node] distance.
and ans will be maximum of all nodes dist1[node]*2-1 with dist1[node]+1>dist[node] .

void dfs(int s, vector<vector<int>> &graph, vector<int> &dist, vector<int> &vis) {
    vis[s] = 1;
    for (auto v : graph[s]) {
        if (!vis[v]) {
            dist[v] = dist[s] + 1;
            dfs(v, graph, dist, vis);
        }
    }
}
int solve(vector<vector<int>> &edges, int u, int v) {
    int n = edges.size() + 1;
    vector<vector<int>> graph(n);
    for (auto e : edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    vector<int> dist1(n), dist2(n);

    vector<int> vis1(n, 0);
    dist1[u] = 0;
    dfs(u, graph, dist1, vis1);
    vector<int> vis2(n, 0);
    dist2[v] = 0;
    dfs(v, graph, dist2, vis2);

    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (dist1[i] > dist2[i] + 1) ans = max(ans, 2 * dist1[i] - 1);
    }
    return ans;
}
