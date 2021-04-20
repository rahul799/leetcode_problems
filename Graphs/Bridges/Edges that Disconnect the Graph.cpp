
https://binarysearch.com/problems/Edges-that-Disconnect-the-Graph




Edges that Disconnect the Graph



You are given an undirected graph represented as an adjacency list, where graph[i] represents node i's neighbors.

Return the number of possible edges that, if removed, causes the graph to become disconnected.

Constraints

0 ≤ n, m ≤ 250 where n and m are the number of rows and columns in graph.
Example 1
Input
Visualize


Output
3
Explanation
The bridges are [0, 5], [0, 1], and [3, 4].







Yet to understand





int dfs(vector<vector<int>> &graph, int src, int parent, int &current_id, vector<bool> &visit,
        vector<int> &low_link, vector<int> &id) {
    visit[src] = true;
    low_link[src] = current_id;
    id[src] = current_id;
    current_id += 1;
    int ans = 0;
    for (auto child : graph[src]) {
        if (child == parent) continue;
        if (visit[child] == false) {
            ans += dfs(graph, child, src, current_id, visit, low_link, id);
            low_link[src] = min(low_link[src], low_link[child]);
            if (id[src] < low_link[child]) {
                ans++;
            }
        } else {
            low_link[src] = min(low_link[src], id[child]);
        }
    }
    return ans;
}

int solve(vector<vector<int>> &graph) {
    vector<int> low_link(graph.size(), 0);
    vector<int> id(graph.size(), 0);
    vector<bool> visit(graph.size(), false);
    int current_id = 0;
    return dfs(graph, 0, -1, current_id, visit, low_link, id);
}
