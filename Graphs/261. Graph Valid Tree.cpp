261. Graph Valid Tree


Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true
Example 2:

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false



   
   
   
 if number of edges are not equal to number of vertex minus 1, then return false;
check if the graph just have one connected component, if yes, return true;




class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
// if they have cycle, the edge must not be n-1
        if(edges.size() != n - 1)
        return false;
        int component=0;
        vector<int>v[n];
        vector<bool>visited(n,false);
 
        for(auto edge:edges){
            v[edge.first].push_back(edge.second);
            v[edge.second].push_back(edge.first);
        }
        
// count component
        for(int i=0;i<n;++i){
            if(!visited[i]){
                ++component;
                DFS(v,visited,i);
            }
        }
     
        return component==1;  
    }  
    void DFS(vector<int>v[],vector<bool>&visited,int indx){
        if(visited[indx])
        return;
        visited[indx]=true;
        for(int j=0;j<v[indx].size();++j){
            DFS(v,visited,v[indx][j]);
        }
    }
};




   Using BFS
   
   
   class Solution {
 public:
  bool validTree(int n, vector<vector<int>>& edges) {
    if (n == 0 || edges.size() != n - 1)
      return false;

    vector<vector<int>> graph(n);
    queue<int> q{{0}};
    unordered_set<int> seen{{0}};

    for (const vector<int> edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    while (!q.empty()) {
      const int node = q.front();
      q.pop();
      for (const int neighbor : graph[node])
        if (!seen.count(neighbor)) {
          q.push(neighbor);
          seen.insert(neighbor);
        }
    }

    return seen.size() == n;
  }
};




class UF {
 public:
  UF(int n) : size(n), rank(n), parent(n) {
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  void union_(int u, int v) {
    const int pu = find(u);
    const int pv = find(v);
    if (pu == pv)
      return;

    --size;
    if (rank[pu] < rank[pv])
      parent[pu] = pv;
    else if (rank[pv] < rank[pu])
      parent[pv] = pu;
    else {
      parent[pu] = pv;
      ++rank[pv];
    }
  }

  int getSize() {
    return size;
  }

 private:
  int size;
  vector<int> rank;
  vector<int> parent;

  int find(int u) {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }
};

class Solution {
 public:
  bool validTree(int n, vector<vector<int>>& edges) {
    if (n == 0 || edges.size() != n - 1)
      return false;

    UF uf(n);

    for (const vector<int>& edge : edges)
      uf.union_(edge[0], edge[1]);

    return uf.getSize() == 1;
  }
};





   class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    vector<int> parent;
    void connect(int a, int b){
        int x=find(a);
        int y=find(b);
        if(x!=y){
            parent[y]=x;
        }
    }
    int find(int x){
        int j=x;
        while(j!=parent[j]) j=parent[j];
        int tmp;
        // paht compress
        while(x!=parent[x]){
            tmp=parent[x];
            parent[x]=j;
            x=parent[x];
        }
        return j;
    }
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
         parent.resize(n+1);
         for(int i=1;i<=n;i++) parent[i]=i;
         for(int i=0;i<edges.size();i++){
             int x=edges[i][0];
             int y=edges[i][1];
             if(find(x)!=find(y)) connect(x,y);
             else return false;
         }
         return edges.size()==n-1;
    }
};





Approach 2: using dfs


class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> edgelists(n);
    for(auto i:edges)
    {
        edgelists[i.first].push_back(i.second);
        edgelists[i.second].push_back(i.first);
    }
    vector<bool> visited(n,false);
    if(hascycle(edgelists,visited,0,-1)) return false;
    for(auto i:visited)
        if(!i) return false;
    return true;
    }
    
    bool hascycle(vector<vector<int>> &edgelists,vector<bool> &visited,int cur,int parent)
    {
        if(visited[cur]) return true;
        visited[cur]=true;
        for(auto kid:edgelists[cur])
            if(kid!=parent&&hascycle(edgelists,visited,kid,cur))
                return true;
        return false;
    }
};
