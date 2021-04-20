

1192. Critical Connections in a Network
Hard

2072

109

Add to List

Share
There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection
between servers a and b. Any server can reach any other server directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:



Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
 

Constraints:

1 <= n <= 10^5
n-1 <= connections.length <= 10^5
connections[i][0] != connections[i][1]
There are no repeated connections.



Importance of the rank

We can detect a cycle simply by checking if a rank has already been assigned to some neighbor or not (except for the parent of course, which we can handle separately). 
 So when we detect a cycle, we can discard the current edge since that edge cannot be a critical connection. In our example graph above, we can discard edge E-B. However, 
how do we discard edges B-D and D-E? The mere presence of a cycle in a subgraph doesn't guarantee that an ancestral edge/node will also be a part of the cycle.

What we need is the minimum rank that a cycle includes. We need our traversal function to return this information so that the previous callers can use it to identify if 
 an edge has to be discarded or not.

Let's see how this information might be helpful with the help of our previous graph.

Importance of rank

Figure 4. Showcasing the importance of rank.

We know that only the current level knows of the presence of a cycle. To make the upper levels (of recursion) make aware of this cycle, and also to help them discard 
necessary edges, we return the minimum rank that our traversal finds. During a step of recursion from node u to its neighbor v, if DFS returns something smaller than or 
equal to rank of u, then u knows its neighbor v is a part of a cycle spanning back to u or some other node higher up in the recursion tree i.e. an ancestor node. Thus,
we can safely discard edge u-v because it is part of a cycle.

Algorithm

Let's define a function called dfs that takes in the node and the discoveryRank to be assigned to this node.

The first step is to build the graph itself. For that, we will be using an adjacency list structure.

Since our algorithm involves discarding edges, we need some efficient data structure that will allow us to do this operation in O(1)O(1) time. We'll convert the list of 
 edges into a dictionary for that.

For our algorithm, we'll name our graph as graph and our connections dictionary as connDict. The graph here is a dictionary of lists (i.e. it's an adjacency list).

Additionally, we need an array to keep track of the rank of our nodes. That's also something we define in the main function criticalConnections along with all the 
 things explained above.

Inside our function dfs:

We check if the node already has a rank assigned; if so, we return that value.

Else, we assign the rank of this node i.e. rank[node] to the discoveryRank.

We iterate over all the neighbors of the node and for each of them, we make a recursive call and we obtain the recursiveRank as the return value and do two things 
using this value.

If this recursiveRank is less than the current discoveryRank, that implies this edge is a part of a cycle and can be discarded.
Second, we record the minimum rank till now from amongst all the neighbors. Let's name this minRank. This is the value we return at the end of the function.
Note that we don't make a recursive call to the parent node. We detect parent nodes by checking if the rank of the neighboring node is discoveryRank - 1

Return the minRank.

We call the dfs function using the node 0 and rank 0 and once our search function completes, we convert the remaining edges from connDict to a list and return that as the result.
 
 
 
 
 
Condition of Bridge: If there is no back edge from aa  subgraph to it's parent or any of it's anscestor



class Solution {
public:
    struct vertex{
        int time, lowpoint;
    };
    vector<vertex>visited;
    unordered_map<int, vector<int> > graph;
    int timestamp = 1;
    vector<vector<int>> ans;
 
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        visited.resize(n);
        //prepare the graph
        for(auto edge: connections){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        //cover the case of multiple disconnected components
        for(int i=0; i<n;i++)
            if(visited[i].time == 0)
                dfs(i, -1);
        return ans;
    }
    
    void dfs(int v, int parent){
        visited[v].time = timestamp;
        visited[v].lowpoint = timestamp;
        timestamp++;
        for (auto neigh: graph[v]) {
            if (neigh == parent) //ignore the parent of current node
                continue;
            if (visited[neigh].time == 0) //dfs the neighbors
                dfs(neigh, v);
            // this is the most important part
            // 1. Save the current node's "minimum rank" reachable (Why? See explanation in the article)
            // 2. If neighbor's rank is less than the discover time of current node, add the edge as a critical connection
            visited[v].lowpoint = min(visited[v].lowpoint, visited[neigh].lowpoint);
            
           //  If low value at any of the neighbour is greater than the discovery time, then in that case we say that there is a no back edge,  bridge at that point.
            if(visited[neigh].lowpoint > visited[v].time){
                ans.push_back({v, neigh});
            }
        }
    }
};














class Solution {
    unordered_map<int,vector<int>> adj; //Adj list
    void DFS(int u,vector<int>& disc,vector<int>& low,vector<int>& parent,vector<vector<int>>& bridges)
    {
        static int time = 0;    //timestamp
        disc[u] = low[u] = time;
        time +=1;
        
        for(int v: adj[u])
        {
            if(disc[v]==-1) //If v is not visited
            {
                parent[v] = u;
                DFS(v,disc,low,parent,bridges);
                low[u] = min(low[u],low[v]);
                
                if(low[v] > disc[u])
                    bridges.push_back(vector<int>({u,v}));
            }
            else if(v!=parent[u])   //Check for back edge
                low[u] = min(low[u],disc[v]);
        }
    }
    void findBridges_Tarjan(int V,vector<vector<int>>& bridges)
    {
        vector<int> disc(V,-1),low(V,-1),parent(V,-1);
        //Apply DFS for each component
        for(int i=0;i<V;++i)
            if(disc[i]==-1)
                DFS(i,disc,low,parent,bridges);
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(int i=0;i<connections.size();++i)   //Make Adj list
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<vector<int>> bridges; //Store all the bridges as pairs
        findBridges_Tarjan(n,bridges);
        return bridges;
    }
};
