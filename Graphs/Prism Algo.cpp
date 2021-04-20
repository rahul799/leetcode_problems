1135. Connecting Cities With Minimum Cost

There are N cities numbered from 1 to N.

You are given connections, where each connections[i] = [city1, city2, cost] represents the cost to connect city1 and city2 together.  (A connection is bidirectional: 
connecting city1 and city2 is the same as connecting city2 and city1.)

Return the minimum cost so that for every pair of cities, there exists a path of connections (possibly of length 1) that connects those two cities together.  
The cost is the sum of the connection costs used. If the task is impossible, return -1.

 

Example 1:



Input: N = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
Output: 6
Explanation: 
Choosing any 2 edges will connect all cities so we choose the minimum 2.
Example 2:



Input: N = 4, connections = [[1,2,3],[3,4,4]]
Output: -1
Explanation: 
There is no way to connect all cities even if all edges are used.








Prim's Algorithm
Time complexity O((E+N)logN) where E is the number of edges.
Prim's algorithm is very similar to Dijkstra algorithm.
The only difference is that instead of keeping a list of minimum total distance and updating it with
dist[v] = min(dist[v], weight(u,v) + dist[u]);
we keep a list of minimum cost for the current node and update it with
minCost[v] = min(minCost[v], cost(u,v));
to find the light edge(edge that add one more node to the tree with minimum cost) in the priority queue.

typedef pair<int,int> pii;
class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        vector<vector<pii>> mp(N+1);
        vector<bool> visited(N+1, false);
        vector<int> minCost(N+1, INT_MAX);
        for (auto& edge : connections) {
            mp[edge[0]].push_back({edge[2], edge[1]});
            mp[edge[1]].push_back({edge[2], edge[0]});
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0,1});
        int numVisited = 0, res = 0;
        while (numVisited < N && !pq.empty()) {
            int cost = pq.top().first, city = pq.top().second;
            pq.pop();
            if (visited[city]) continue;
            visited[city] = true;
            numVisited++;
            res += cost;
            for (auto& n : mp[city]) {
                cost = n.first;
                city = n.second;
                if (!visited[city] && cost < minCost[city]) {
                    minCost[city] = cost;
                    pq.push({cost, city});
                }
            }
        }
        return numVisited == N ? res : -1;
    }
};
