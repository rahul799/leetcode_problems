


1615. Maximal Network Rank
Medium

161

27

Add to List

Share
There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.

The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.

The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.

Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.

 

Example 1:



Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
Output: 4
Explanation: The network rank of cities 0 and 1 is 4 as there are 4 roads that are connected to either 0 or 1. The road between 0 and 1 is only counted once.
Example 2:



Input: n = 5, roads = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
Output: 5
Explanation: There are 5 roads that are connected to cities 1 or 2.
Example 3:

Input: n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
Output: 5
Explanation: The network rank of 2 and 5 is 5. Notice that all the cities do not have to be connected.
 

Constraints:

2 <= n <= 100
0 <= roads.length <= n * (n - 1) / 2
roads[i].length == 2
0 <= ai, bi <= n-1
ai != bi
Each pair of cities has at most one road connecting them.



Brief Explanation

Build the graph (adjacency list).
Compute network rank of all pairs of cities.
Simply compute the sum of neighbors (connected cities) of both cities.
Decrement 1 from the computed sum if the cities under consideration are connected to each other.
(Otherwise the road between those 2 cities will be double counted)
Update the maximal network rank if the network rank computed is greater than the current value.
Note:
Used unordered_set in the graph to track neighbors (connected cities) in order to speed up the look up.
(Required to check if the 2 cities under consideration are connected or not)

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> graph(n);
        
        // Building the graph (adjacency list). 
        for (const auto& road: roads) {
            graph[road[0]].insert(road[1]);
            graph[road[1]].insert(road[0]);
        }
        
        int maximal = 0;
        for(int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Sum of neighbors (connected cities) of both cities. 
                int network_rank = graph[i].size() + graph[j].size();
                
                // Reduce the rank by 1 in case the cities are connected to each other.
                if (graph[j].count(i)) {
                    --network_rank;
                }
                
                // Maximal network rank is the maximum network rank possible.
                maximal = max(maximal, network_rank);
            }
            
        }
        return maximal;
    }
};
