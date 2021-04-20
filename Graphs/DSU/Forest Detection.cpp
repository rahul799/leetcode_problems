https://binarysearch.com/problems/Forest-Detection


Forest Detection
You are given a list of lists edges representing an undirected graph. Each list contains (u, v) which means there is an undirected edge between nodes u and v. Return whether the graph is a collection of trees.

Constraints

n ≤ 100,000 where n is the length of edges
Example 1
Input
Visualize
edges =
0

1

2

3

4

5

Output
true
Explanation
The first two edges form one tree and the last two edges form another tree.

Example 2
Input
Visualize
edges =
0

1

2

Output
false
Explanation
This graph forms a cycle which is not a tree.




Intuition
The idea is to use dfs and check whether there is a loop (visiting a visited node).

Anyway, if we revisit the parent node of a node, then there is no problem. The default parent node has been set as -1.

Have a look at the below code!

vector<bool> visited;
vector<vector<int>> adj;

bool dfs(int child, int parent = -1) {
    visited[child] = true;
    for (int u : adj[child])
        if (u == parent)
            continue;
        else if (visited[u])
            return false;
        else if (not dfs(u, child))
            return false;
    return true;
}

bool solve(vector<vector<int>>& edges) {
    int N = edges.size() + 4;

    visited.resize(N, false);
    adj.resize(N);

    for (vector<int> edge : edges) adj[edge[0]].push_back(edge[1]), adj[edge[1]].push_back(edge[0]);

    for (int i = 0; i < N; i++)
        if (not visited[i])
            if (dfs(i) == false) {
                return false;
            }

    return true;
}









const int MXN = 100005;
int par[MXN];
bool flag = true;

void setup(int n) {
    for (int i = 0; i < n; i++) par[i] = i;
}

int parent(int a) {
    if (par[a] == a) return a;
    return par[a] = parent(par[a]);
}

void conn(int a, int b) {
    a = parent(a);
    b = parent(b);
    if (a == b) {
        flag = false;
        return;
    }
    par[a] = b;
}

bool solve(vector<vector<int>>& edges) {
    int f = edges.size();
    setup(f + 10);
    flag = true;
    for (auto x : edges) {
        conn(x[0], x[1]);
    }
    return flag;
}
