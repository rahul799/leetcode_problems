



We can use DFS to detect cycle in an undirected graph in O(V+E) time. We do a DFS traversal of the given graph. For every visited vertex ‘v’, 
if there is an adjacent ‘u’ such that u is already visited and u is not parent of v, then there is a cycle in graph. If we don’t find such an adjacent 
for any vertex, we say that there is no cycle. The assumption of this approach is that there are no parallel edges between any two vertices.




Approach:

Method 1: DFS
Like directed graphs, we can use DFS to detect cycle in an undirected graph in O(A+M) time.
We do a DFS traversal of the given graph. For every visited vertex ‘v’, if there is an adjacent ‘u’ such that u is already visited and u is not parent of v, then there is
a cycle in graph.
If we don’t find such an adjacent for any vertex, we say that there is no cycle.
The assumption of this approach is that there are no parallel edges between any two vertices


Method 2: Union-Find
We can keep track of the subsets in a 1D array, let’s call it parent[].
For each edge, make subsets using both the vertices of the edge. If both the vertices are in the same subset, a cycle is found.
Initially, all slots of parent array are initialized to -1 (means there is only one item in every subset).
Time Complexity: O(MlogA)




int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int> > adj(A+1);
    for(int i=0; i<B.size(); i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    
    vector<bool> vis(A+1, 0);
    for(int i=1; i<=A; i++){
        if(vis[i]==0){
            vector<bool> check(A+1,0);
            queue<int> q;
            q.push(i);
            // check[i]=1;
            while(!q.empty()){
                int x = q.front();
                q.pop();
                if(check[x]==1) return 1;
                check[x]=1;
                vis[x]=1;
                for(int j=0; j<adj[x].size(); j++){
                    if(check[adj[x][j]]==0){
                        q.push(adj[x][j]);
                    }
                }
            }
            
        }
    }
    
    return 0;
}




def cycUtil(graph, visited, parent,v):
  visited.append(v)
 
  
  if v in graph:
    for n in graph[v]: 
      
      if n not in visited:
        retval = cycUtil(graph, visited, v,n)
        if retval:
          return True
      else:
        if n != parent:
          return True

  return False
  

def isCyclic(graph, V):
  visited = []
  #recStk = []
  parent = -1
  
  for v in V:
    if v not in visited:
      retval = cycUtil(graph, visited, parent,v)
      if retval:
        return True
  return False


graph = {0:[1,2,3], 3:[2,0], 2:[0,3]}
V = [0,1,2,3]
print(isCyclic(graph, V))
