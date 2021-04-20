1245. Tree Diameter
Medium



Share
Given an undirected tree, return its diameter: the number of edges in a longest path in that tree.

The tree is given as an array of edges where edges[i] = [u, v] is a bidirectional edge between nodes u and v.  Each node has labels in the set {0, 1, ..., 
edges.length}.

 

Example 1:



Input: edges = [[0,1],[0,2]]
Output: 2
Explanation: 
A longest path of the tree is the path 1 - 0 - 2.
Example 2:



Input: edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
Output: 4
Explanation: 
A longest path of the tree is the path 3 - 2 - 1 - 4 - 5.
 

Constraints:

0 <= edges.length < 10^4
edges[i][0] != edges[i][1]
0 <= edges[i][j] <= edges.length
The given edges form an undirected tree.





A beginner level problem in graph theory.
Idea: Use 2 BFS.
The first BFS: sStart with a random vertex, say 0, then find the last visited vertex, then it must be a leaf.
The second BFS: start with the leaf we found in the first BFS, then do BFS again, record distances while doing BFS, then simply return the largest element in 
the distances vector.



https://stackoverflow.com/questions/20010472/proof-of-correctness-algorithm-for-diameter-of-a-tree-in-graph-theory




class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(edges.size()+1);
        for (auto l : edges) {
            adj[l[0]].push_back(l[1]);
            adj[l[1]].push_back(l[0]);
        }
        
        queue<int> q;
        q.push(0); 
        int leaf;
        vector<bool> visited(edges.size()+1, false);
        while (!q.empty()) {
            int curr = q.front();  
            q.pop();
            if (visited[curr]) {continue;}
            visited[curr] = true;
            for (int nei : adj[curr]) {
                if (!visited[nei]) q.push(nei);
            }
            if (q.empty()) {
                leaf = curr;
            }
        }
        
        q.push(leaf);
        vector<int> dist(edges.size()+1, -1);
        dist[leaf] = 0;
        while (!q.empty()) {
            int curr = q.front();  q.pop();
            for (int nei : adj[curr]) {
                if (dist[nei] == -1) {
                    q.push(nei);
                    dist[nei] = dist[curr] + 1;
                }
            }
        }
        return *(max_element(dist.begin(), dist.end()));
    }
};






