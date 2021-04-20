



1168. Optimize Water Distribution in a Village
Hard

401

15

Add to List

Share
There are n houses in a village. We want to supply water for all the houses by building wells and laying pipes.

For each house i, we can either build a well inside it directly with cost wells[i - 1] (note the -1 due to 0-indexing), or pipe in water from another well to it. The costs to lay pipes between houses are given by the array pipes, where each pipes[j] = [house1j, house2j, costj] represents the cost to connect house1j and house2j together using a pipe. Connections are bidirectional.

Return the minimum total cost to supply water to all houses.

 

Example 1:



Input: n = 3, wells = [1,2,2], pipes = [[1,2,1],[2,3,1]]
Output: 3
Explanation: 
The image shows the costs of connecting houses using pipes.
The best strategy is to build a well in the first house with cost 1 and connect the other houses to it with cost 2 so the total cost is 3.
 

Constraints:

1 <= n <= 104
wells.length == n
0 <= wells[i] <= 105
1 <= pipes.length <= 104
pipes[j].length == 3
1 <= house1j, house2j <= n
0 <= costj <= 105
house1j != house2j






class UnionFind {
    public:
    int total_cost = 0;
    vector<int> parents;
    
    UnionFind(int n) {
        parents.resize(n);
        for(int i=0; i < n; ++i) parents[i] = i;
    }
    int find(int i) {
        
        if (i == parents[i])    return i;
        parents[i] = find(parents[i]);
        return parents[i];
    }
    void unite(int i, int j, int cost) {
        
        int pi = find(i);
        int pj = find(j);
        if(pi != pj) {
            parents[pi] = pj;
            total_cost += cost;
        }
        
    }
};

class Solution {
    static bool comp(vector<int> a, vector<int> b) {
        return a[2] < b[2];
    }
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        
        if (n == 0) return 0;
        if (pipes.size() == 0) return accumulate(wells.begin(), wells.end(), 0);
        
        for (int i = 0; i < wells.size(); i++) {
            pipes.push_back({0, i + 1, wells[i]});
        }
        sort(pipes.begin(), pipes.end(), comp);
        UnionFind uf = UnionFind(n + 1);
        for (int i = 0; i < pipes.size(); i++) {
            uf.unite(pipes[i][0], pipes[i][1], pipes[i][2]);
        }
        return uf.total_cost;
    }
};


