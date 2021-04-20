Distributed Systems
A network consists of nodes labeled 0 to n. You are given n and a list of edges (a, b, t) of an undirected graph, describing the time t it takes for a message to be sent from node a to node b (or vice versa). Whenever a node receives a message, it immediately passes the message on to a neighboring node.

Assuming all nodes are connected, determine how long it will take for every node to receive a message that begins at node 0.

Example 1
Input
n = 3
edges = [
    [0, 1, 2],
    [1, 2, 3],
    [2, 3, 1]
]
Output
6
Explanation
Node 3 receives the message from 0 -> 1 -> 2 -> 3 which takes 2 + 3 + 1 = 6 time.

Example 2
Input
n = 3
edges = [
    [0, 1, 2],
    [0, 2, 3],
    [0, 3, 5]
]
Output
5
Explanation
0 emits the message to all nodes, but node 3 gets it last at time = 5.





vector<int> dist;
vector<vector<pair<int, int>>> adj;
void daijkstras(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, start});
    dist[0] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        int u_d = q.top().first;
        q.pop();
        if (dist[u] != u_d) continue;
        for (pair<int, int> v : adj[u]) {
            int to = v.first;
            int edge = v.second;
            if (dist[u] + edge < dist[to]) {
                dist[to] = dist[u] + edge;
                q.push({dist[to], to});
            }
        }
    }
}

int solve(int n, vector<vector<int>>& edges) {
    adj.assign(n + 1, vector<pair<int, int>>());
    dist.assign(n + 1, INT_MAX);
    for (int i = 0; i < edges.size(); ++i) {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    daijkstras(0);
    int res = 0;
    for (int i : dist) res = max(res, i);
    return res;
}
