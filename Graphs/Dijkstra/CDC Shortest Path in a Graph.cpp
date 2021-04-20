




Shortest Path in a Graph
You are given a two-dimensional list of integers edges which represents a directed, weighted graph. Each element in edges contains [u, v, w] meaning that there is an edge from node u to node v which costs positive weight w. You are also given integers start and end.

Return the cost of the shortest path from start to end. If there is no path between the two nodes, return -1.

Constraints

1 ≤ n ≤ 100,000 where n is the length of edges
Example 1
Input
edges = [
    [0, 1, 3],
    [1, 2, 2],
    [0, 2, 9]
]
start = 0
end = 2
Output
5
Explanation
We can go 0 to 1 for cost of 3 and then 1 to 2 for cost of 2.







int solve(vector<vector<int>>& edges, int start, int end) {
    unordered_map<int, vector<pair<int, int>>> adj;
    unordered_map<int, int> dist;
    for (auto e : edges) {
        adj[e[0]].push_back({e[1], e[2]});
    }
    dist[start] = 0;
    set<pair<int, int>> s;
    s.insert({0, start});
    while (!s.empty()) {
        auto [dis, el] = *s.begin();
        if (el == end) return dis;
        s.erase(s.begin());
        for (auto [nbr, ew] : adj[el]) {
            if (dist.count(nbr) == 0 or dis + ew < dist[nbr]) {
                if (s.find({dist[nbr], nbr}) != s.end()) {
                    s.erase({dist[nbr], nbr});
                }
                dist[nbr] = dis + ew;
                s.insert({dist[nbr], nbr});
            }
        }
    }
    return -1;
}
