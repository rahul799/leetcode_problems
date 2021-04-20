



https://www.youtube.com/watch?v=oZYMOJHWI9w&ab_channel=CodeLibrary


Find if there is a path of more than k length from a source
Difficulty Level : Medium
Last Updated : 05 Mar, 2021
Given a graph, a source vertex in the graph and a number k, find if there is a simple path (without any cycle) starting from given source and ending at any other vertex. 
 

Example:
Input  : Source s = 0, k = 58
Output : True
There exists a simple path 0 -> 7 -> 1
-> 2 -> 8 -> 6 -> 5 -> 3 -> 4
Which has a total distance of 60 km which
is more than 58.

Input  : Source s = 0, k = 62
Output : False

In the above graph, the longest simple
path has distance 61 (0 -> 7 -> 1-> 2
 -> 3 -> 4 -> 5-> 6 -> 8, so output 
should be false for any input greater 
than 61.




#include<bits/stdc++.h>
#define int             long long int
#define pb              push_back
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define w(x)            int x; cin>>x; while(x--)
using namespace std;
 
 
 
 
 
bool solve(int src,int k,vector<pair<int,int> > g[],vector<bool> &vis){
    vis[src] = true;
    if(k<=0) return true;
 
    for(auto x:g[src]){
        int u = x.first;
        int w = x.second;
        if(vis[u]==true) 
            continue;
        if(w>=k) 
            return true;
 
        if(solve(u,k-w,g,vis))
            return true;
 
    }
    vis[src] = false;
    return false;
}
 
int32_t main() {
 
    int v,e;
    cin>>v>>e;
    int k;
    cin>>k;
    vector<pair<int,int> > g[v+1];
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    vector<bool> vis(v+1,false);
    cout<<solve(1,k,g,vis);  
 
 
    return 0;
}
 
 
 
