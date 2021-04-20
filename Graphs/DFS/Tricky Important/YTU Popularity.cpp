




https://binarysearch.com/problems/Popularity



you have to simple dfs traversal to count the number of children nodes in subtree of any node store that count.
answer for each edge will =v1*(N-V1)
where N=total number of edges +1
v1=represent number of nodes in subtree of any nodes(for each edge consider that node for answer who has minimum number of child nodes)



I then did a DFS traversal of the tree, and used the "children" array to store the number of children of that node, relative to the root 0.

Finally, the answer for each edge was simply C*(N-C), where C is the number of nodes "below" the edge in question. The reason this is correct is because each simple path on a tree is uniquely defined by its start and end nodes. To guarantee that simple path includes our edge, we simply choose a start node on one side of the edge (C choices), and an end node on the other side of the edge (N-C choices).

Popularity
You are given a list of (u, v) edges edges representing a tree — that is, a connected acyclic undirected graph. For each edge, return the total number of unique paths that includes said edge, in the same order as the input list.

Constraints

n ≤ 100,000 where n is the length of edges.
Example 1
Input
edges = [
    [0, 1],
    [1, 2],
    [0, 3]
]
Output
[4, 3, 3]
Explanation
This represents the following tree:

      0
     / \
    1   3
   /
  2
The first edge has 4 paths that include it:

0 -> 1
0 -> 1 -> 2
3 -> 0 -> 1 -> 2
3 -> 0 -> 1
The second edge has 3 paths:

1 -> 2
0 -> 1 -> 2
3 -> 0 -> 1 -> 2
The third edge has 3 paths as well:

0 -> 3
3 -> 0 -> 1
3 -> 0 -> 1 -> 2
Note that the paths are undirected so a -> b is the same as b -> a.





vector<int> ans, cnt;
vector<vector<pair<int, int>>> adj;
int n;

void dfs(int u, int edge_to_parent) {
    cnt[u] = 1;
    for (auto [v, e] : adj[u]) {
        if (e == edge_to_parent) continue;
        dfs(v, e);
        cnt[u] += cnt[v];
    }
    if (edge_to_parent != -1) ans[edge_to_parent] = cnt[u] * (n - cnt[u]);
}

vector<int> solve(vector<vector<int>>& edges) {
    n = edges.size() + 1;
    ans = vector<int>(n - 1);
    adj = vector<vector<pair<int, int>>>(n);
    for (int i = 0; i < n - 1; ++i) {
        int u = edges[i][0], v = edges[i][1];
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    cnt = vector<int>(n);
    dfs(0, -1);
    return ans;
}
