310. Minimum Height Trees
Medium



https://leetcode.com/problems/minimum-height-trees/




2718

119

Add to List

Share
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between he root and a leaf.

 Suppose a tree has only one long linear path, in that case the minimum height tree's root
would be the middle value of the path when path length is odd or the two middle values of the
path when path length is even. So there can be at most two MHT and the root vlaues would be the 
middle values of the longest path of the tree.
    
Tree: 0-1-2-3-4-5-6, middle values: [2,3] => Path Length Even
Tree: 0-1-2-3-4-5, middle values: [2] => Path Length Odd

Finding longest tree path by running DFS/BFS is quite hectic.

Instead we can find the middle values of the longest path by removing the leaf nodes from the tree
in each step which we implement by running BFS and counting degeree of node.

Longest path always starts with leaf nodes which has degree 1, so initially we can add all degree 1
leaf nodes in to queue and run BFS, while processing a node, we decrease degree of all its neighbour
nodes (as we are removing the current node from the tree) and add neighbours in to queue which has 
degree 1 (leaf node). The nodes which exists at last are the middle nodes of the longest tree path.
    
Example: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]

Push node 0,1,2,5 in to queue and run BFS and for each node, decrease it's neighbour's degree
at last only node 3 and 4 remains and they are the root nodes of MHT.
 
 
 class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        // Base case: only one node
        if(n==1) return vector<int>{0};
        
        // graph adjacency list of nodes
        vector<vector<int>>graph(n);
        
        // degree count of nodes
        vector<int>degree(n,0);
        
        // populate graph adjacency list and degree count of nodes
        for(int i=0;i<edges.size();i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            
            graph[a].push_back(b);
            graph[b].push_back(a);
            
            degree[a]++;
            degree[b]++;
        }
        
        queue<int>Q;
        
        // push degree 1 nodes (leaf nodes) in to queue 
        for(int i=0;i<n;i++)
            if(degree[i]==1)Q.push(i);

        // MHT root nodes
        vector<int>res;
        
        // run BFS until queue is empty 
        while(!Q.empty())
        {
            int n = Q.size();
            
            // clear root nodes 
            res.clear();
            
            // perform level order traverse
            while(n--)
            {
                int node = Q.front();
                Q.pop();
                
                // add current in to root node vector
                res.push_back(node);
                
                // process neighbour nodes
                for(int i=0;i<graph[node].size();i++)
                {
                    // decrease degree of neighbour nodes
                    degree[graph[node][i]]--;
                    
                    // push leaf nodes in to queue
                    if(degree[graph[node][i]]==1)
                    {
                        Q.push(graph[node][i]);
                    }
                }
            }
        }
        
        // root nodes of MHT
        return res;
    }
};
 
 
 
https://leetcode.com/problems/minimum-height-trees/discuss/897095/C%2B%2B-BFS-Solution-Explained

Example 1:


Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
Example 2:


Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]
Example 3:

Input: n = 1, edges = []
Output: [0]
Example 4:

Input: n = 2, edges = [[0,1]]
Output: [0,1]
 

Constraints:

1 <= n <= 2 * 104
edges.length == n - 1
0 <= ai, bi < n
ai != bi
All the pairs (ai, bi) are distinct.
The given input is guaranteed to be a tree and there will be no repeated edges.



class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        
        if (n == 1) {
            res.push_back(0);
            return res;
        }
        if (n == 2) {
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        
        vector<int> t[n];
        vector<int> deg(n);
        
        for (auto &e :edges) {
            t[e[0]].push_back(e[1]);
            t[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }
        
        for (int i=0; i<n; i++) {
            if (deg[i] == 1)
                res.push_back(i);
        }
        
        int remain = n;
        while (remain > 2) {
            remain -= res.size();
            vector<int> queue;
            for (int u: res) {
                for(int v: t[u]){
                    if(--deg[v] == 1)
                        queue.push_back(v);
                }
                t[u].clear();
            }
            res = queue;
        }
        return res;
    }
};
