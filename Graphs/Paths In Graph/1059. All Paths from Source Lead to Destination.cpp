Given the edges of a directed graph, and two nodes source and destination of this graph, determine whether or not all paths starting from source eventually end at destination, that is:

At least one path exists from the source node to the destination node
If a path exists from the source node to a node with no outgoing edges, then that node is equal to destination.
The number of possible paths from source to destination is a finite number.
Return true if and only if all roads from source lead to destination.

 

Example 1:



Input: n = 3, edges = [[0,1],[0,2]], source = 0, destination = 2
Output: false
Explanation: It is possible to reach and get stuck on both node 1 and node 2.
Example 2:

Input: n = 4, edges = [[0,1],[0,3],[1,2],[2,1]], source = 0, destination = 3
Output: false
Explanation: We have two possibilities: to end at node 3, or to loop over node 1 and node 2 indefinitely.
Example 3:

Input: n = 4, edges = [[0,1],[0,2],[1,3],[2,3]], source = 0, destination = 3
Output: true
Example 4:



Input: n = 3, edges = [[0,1],[1,1],[1,2]], source = 0, destination = 2
Output: false
Explanation: All paths from the source node end at the destination node, but there are an infinite number of paths, such as 0-1-2, 0-1-1-2, 0-1-1-1-2, 0-1-1-1-1-2, and so on.
Example 5:






For the visited array, -1 means never processed, false is being analyzed, and true is that all routes from that nodes lead to the destination. This is to avoid re-processing portions of the graph.

bool dfs(vector<vector<int>> &al, vector<int> &visited, int i, int dest) {
  if (al[i].empty()) return i == dest;
  if (visited[i] != -1) return visited[i];
  visited[i] = 0;
  for (auto j : al[i])
    if (!dfs(al, visited, j, dest)) return false;
  return visited[i] = true;
}
bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
  vector<vector<int>> al(n);
  vector<int> visited(n, -1);
  for (auto e : edges) al[e[0]].push_back(e[1]);
  return dfs(al, visited, source, destination);
}






Approach 2:

 bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        queue<int> q;
        q.push(source);
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            if(graph[t].empty() && t!=destination)return false;
            for(int x:graph[t])
            {
                if(indegree[x]<0)return false;
                indegree[x]--;
                q.push(x);
            }
        }
        return true;
    }





Input: n = 2, edges = [[0,1],[1,1]], source = 0, destination = 1
Output: false
Explanation: There is infinite self-loop at destination node.
