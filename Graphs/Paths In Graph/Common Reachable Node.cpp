Common Reachable Node




https://binarysearch.com/room/Weekly-Contest-38-CNs3hGBp9j?questionsetIndex=1



You are given a two-dimensional list of integers edges representing a directed graph and integers a and b. Each element in edges contains [u, v] meaning there's an edge from u to v.

Return whether there's some node c such that we can go from c to a and c to b.

Constraints

n ≤ 100,000 where n is the length of edges
Example 1
Input
Visualize
edges =

a = 2
b = 3
Output
true
Explanation
We can reach 2 and 3 from 0

Example 2
Input
Visualize
edges =


a = 2
b = 4
Output
false
Explanation
2 and 4 are on different connected components.

Example 3
Input
Visualize
edges =
0

a = 0
b = 0
Output
true




If for node a and node b, we define path_a and path_b as the paths starting from both node a and node b and traversing parent by parent until we reach some root, then we can get our answer by determining if path_a and path_b have a common node.

Thus, we first construct a graph of reversed edges, i.e edge from child to parent, and compute path_a and path_b using Depth First Search.

Finally, we simply iterate through one of the paths and check if any of the nodes is also in the other path.

Implementation
We use Depth First Search, and have each path_a and path_b as a set, since we don't care about the order.

Time Complexity
\mathcal{O}(N)O(N) We visit each node a





Intuition
If there is a node C that reaches both A and B then A and B should also reach C on transposing the graph(i.e edges)

Implementation
Transpose the graph
DFS from node A store it in map
DFS from node B while doing this see if we find a node that is already traversed by node A
Time Complexity
\mathcal{O}(V + E)O(V+E) as we are using dfs which can like in worst case traverse the whole graph

Space Complexity
\mathcal{O}(V)O(V) for adjacency list, visited array and map

vector<int> adj[100001];
vector<bool> vis(100001, false);
unordered_map<int, int> mp;
bool flag;
void dfs(int curr) {
    vis[curr] = true;
    mp[curr]++;
    if(mp[curr] > 1) {    
        flag = true;
        return;
    }
    for(int node : adj[curr]) 
        if(!vis[node])
            dfs(node);
}
bool solve(vector<vector<int>>& edges, int a, int b) {
    int n = edges.size() + 1;
    if(a == b)
        return true;
    for(int i = 0; i < n; i++)
        adj[i].clear();
    for(int i = 0; i < n - 1; i++) {
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    mp.clear();
    flag = false;
    for(int i = 0; i < n; i++)
        vis[i] = false;
    dfs(a);
    for(int i = 0; i < n; i++)
        vis[i] = false;
    dfs(b);
    return flag;
}








/









