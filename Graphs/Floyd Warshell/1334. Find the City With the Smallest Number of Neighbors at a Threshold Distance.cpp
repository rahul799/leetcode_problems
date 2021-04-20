1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
Medium

375

26

Add to List

Share
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.


Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.

1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; ++i) dp[i][i] = 0;
        for (const auto &e : edges) {
            dp[e[0]][e[1]] = e[2];
            dp[e[1]][e[0]] = e[2];
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dp[i][j] > dp[i][k] + dp[k][j]) dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
        auto m = INT_MAX, res = -1;
        for (int i = n - 1; i >= 0; --i) {
            auto cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (dp[i][j] <= distanceThreshold) ++cnt;
            }
            if (cnt < m) {
                m = cnt;
                res = i;
            }
        }
        return res;
    }
};
