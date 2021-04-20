Longest Path in a Directed Acyclic Graph
Difficulty Level : Hard
 Last Updated : 02 Mar, 2021
 
 
 https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/
 
 https://ideone.com/3coiqm
 
 
Given a Weighted Directed Acyclic Graph (DAG) and a source vertex s in it, find the longest distances from s to all other vertices in the given graph.
The longest path problem for a general graph is not as easy as the shortest path problem because the longest path problem doesn’t have optimal substructure property. In fact, the Longest Path problem is NP-Hard for a general graph. However, the longest path problem has a linear time solution for directed acyclic graphs. The idea is similar to linear time solution for shortest path in a directed acyclic graph., we use Topological Sorting. 
We initialize distances to all vertices as minus infinite and distance to source as 0, then we find a topological sorting of the graph. Topological Sorting of a graph represents a linear ordering of the graph (See below, figure (b) is a linear representation of figure (a) ). Once we have topological order (or linear representation), we one by one process all vertices in topological order. For every vertex being processed, we update distances of its adjacent using distance of current vertex.
Following figure shows step by step process of finding longest paths.
 

LongestPath

Following is complete algorithm for finding longest distances. 
1) Initialize dist[] = {NINF, NINF, ….} and dist[s] = 0 where s is the source vertex. Here NINF means negative infinite. 
2) Create a toplogical order of all vertices. 
3) Do following for every vertex u in topological order. 
………..Do following for every adjacent vertex v of u 
………………if (dist[v] < dist[u] + weight(u, v)) 
………………………dist[v] = dist[u] + weight(u, v) 
  
  
  
  
  
  #include<bits/stdc++.h>
#define int             long long int
#define pb              push_back
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define w(x)            int x; cin>>x; while(x--)
using namespace std;
 
 
vector<int> order;
 
void topo(int src,vector<int> &vis,vector<vector<pair<int,int> > > g){
    vis[src] = 1;
    for(auto x:g[src]){
        if(!vis[x.first])
            topo(x.first,vis,g);
    }
    order.push_back(src);
}
 
 
int32_t main() {
 
    int v,e;
    cin>>v>>e;
 
    int src;
    cin>>src;
 
    vector<vector<pair<int,int> > > g(v);
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
    }
 
    vector<int> vis(v,0);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            topo(i,vis,g);                    
        }                                  
    }
    vector<int> dist(v);
    for(int i=0;i<v;i++) dist[i] = INT_MIN;
    dist[src] = 0;
    for(int i=v-1;i>=0;i--){
        if(dist[order[i]]!=INT_MIN){
            for(auto x:g[order[i]]){
                int v = dist[x.first];
                int w = x.second;
                int u = dist[order[i]];
                if(u + w > v)
                    dist[x.first] = u + w;
            }
        }
    }
    for(int i=0;i<v;i++){
        if(i!=src and dist[i]!=INT_MIN){
            cout<<src<<" -> "<<i<<" = "<<dist[i]<<endl;
        }
    }
 
    return 0;
 
}
 
