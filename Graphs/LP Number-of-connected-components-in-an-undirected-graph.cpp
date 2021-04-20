323. Number of Connected Components in an Undirected Graph

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an
undirected graph.

Example 1:

Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4 

Output: 2
Example 2:

Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1




There are two ways of solving this question

vector<int> id;
public:
int find(int i) {
    while (i != id[i]) {
        id[i] = id[id[i]]; // compression
        i = id[i];
    }
    return i;
}
void unions(int p, int q) {
    int x = find(p);
    int y = find(q);
    id[x] = y;
}
int countComponents(int n, vector<pair<int, int>>& edges) {
    id.resize(n);
    for (int i = 0; i < n; i++) {
        id[i] = i;
    }
    int count = 0;
    for (const auto& edge: edges) {
        int x = find(edge.first);
        int y = find(edge.second);
        if (x != y) {
            unions(edge.first, edge.second);
            count++;
        }
    }
    return n-count;
}



Approach: The idea is to use a variable count to store the number of connected components and do the following steps:

Initialize all vertices as unvisited.
For all the vertices check if a vertex has not been visited, then perform DFS on that vertex and increment the variable count by 1



The way to solve this question is first build a graph:-
        vector<vector<int>> graph(n);
        int ans=0;                                        //I use an adjacency list u can use whatever u want
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
 After building a graph our main focus is to vist all the neighbours of all the nodes in the graph and more importantly to not visit them multiple
 times.
 We can do this by doing a dfs and a bool matrix which keeps tracks of the visited nodes so that we donot visit them again:-

     void dfs(vector<vector<int>> &graph,vector<bool> &vis,int i)
    {
        if(vis[i])return;
        vis[i]=true;
        for(auto x:graph[i])
            dfs(graph,vis,x);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        int ans=0;
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(graph,vis,i);
            }
        }
        return ans;
    }
    
    
    
    
    
    
    Approach 2 is using union find
