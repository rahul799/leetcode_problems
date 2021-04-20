








Graph Weight Queries
Question 731 of 906
You are given two two-dimensional list of integers edges and queries.

edges represents an undirected graph and each element is in the form [x, y, w] meaning that vertices x and y are connected with edge weight w.

queries is also in the form [x, y, w] and represents the question of does there exist a path between x and y such that each edge in it have weight of at most w.

Return the number of queries that are true.

Constraints

n ≤ 100,000 where n is the length of edges
m ≤ 100,000 where m is the length of queries
Example 1
Input
edges = [
    [0, 1, 5],
    [1, 2, 6],
    [2, 3, 7],
    [0, 3, 4]
]
queries = [
    [0, 3, 5],
    [1, 0, 3]
]
Output
1
Explanation
We can go from 0 to 3 by following this path [0, 3] and the edge's weight is at most 5. There's no path from 1 to 0 where each edge weight is at most 4




Short solution using Union-Find algorithm.
The main idea is to sort the edges and queries by weights then join nodes and check if the nodes are connected i.e. have the same parent node in disjoint-sets.

Implementation



At first edges and queries are sorted by its weights.
In the very beginning all nodes are disconnected. Then starting from edges with smallest weight the nodes are connected (Union) while the weight of edge 
is less or equal to the weight in the current query.
If the nodes have the same parent node for the current query then the query is counted.

Time Complexity
\mathcal{O}(n log(n) + m log(m))O(nlog(n)+mlog(m)) - since inverse Ackermann function is very slow growing so complexity is determined by the sorting edges 
and queries

Space Complexity
\mathcal{O}(n)O(n) - space used for Union-Find: parents and ranks




int Find(vector<int>& p, int i) {
    if (p[i] != i) p[i] = Find(p, p[i]);
    return p[i];
}

void Union(vector<int>& p, int i, int j, vector<int>& r) {
    int s = Find(p, i), t = Find(p, j);
    if (s == t) return;
    if (r[s] < r[t])
        p[s] = t;
    else {
        p[t] = s;
        if (r[s] == r[t]) r[s]++;
    }
}

int solve(vector<vector<int>>& E, vector<vector<int>>& Q) {
    sort(E.begin(), E.end(), [](auto& x, auto& y) { return x[2] < y[2]; });
    sort(Q.begin(), Q.end(), [](auto& x, auto& y) { return x[2] < y[2]; });
    int res = 0, k = 0, m = E.size(), n = Q.size();
    for (auto& e : E) k = max(k, max(e[0], e[1]));
    vector<int> p(k + 1), r(k + 1);
    for (int i = 0; i <= k; i++) p[i] = i;
    for (int i = 0, j = 0; j < n; j++) {
        for (; i < m && E[i][2] <= Q[j][2]; i++) Union(p, E[i][0], E[i][1], r);
        if (Find(p, Q[j][0]) == Find(p, Q[j][1])) res++;
    }
    return res;
}
