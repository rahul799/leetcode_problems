


Farthest Point From Water
Question 50 of 977
You are given a matrix matrix of 0s and 1s where 0 represents water and 1 represents land. Find the land with the largest Manhattan distance from water and return this distance. If there is no land or no water in the board, return -1.

Constraints

n, m ≤ 100 where n and m are the number of rows and columns in matrix
Example 1
Input
matrix = [
    [1, 1, 0],
    [1, 1, 0],
    [0, 0, 1]
]
Output
2
Explanation
grid[0][0] has a Manhattan distance of 2 to water.

Example 2
Input
matrix = [
    [1, 1],
    [1, 1]
]
Output
-1
Explanation
There is no water in this grid.

Example 3
Input
matrix = [
    [1, 1, 1, 1],
    [0, 1, 1, 1],
    [0, 0, 1, 0]
]
Output
3
Explanation
Land at grid[0][2] has a Manhattan distance of 3 to nearest water.











int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solve(vector<vector<int>>& a) {
    int m = a.size();
    int n = a[0].size();
    int ans = -1;

    queue<pair<int, int>> qq;
    vector<vector<bool>> vis(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 0) qq.push({i, j}), vis[i][j] = true;

    if (qq.size() == 0 or qq.size() == m * n) return -1;

    while (!qq.empty()) {
        int sz = qq.size();
        while (sz--) {
            int p = qq.front().first, q = qq.front().second;
            qq.pop();

            for (int i = 0; i < 4; i++) {
                int ii = p + dx[i], jj = q + dy[i];
                if (ii < 0 or jj < 0 or ii >= m or jj >= n or vis[ii][jj] or !a[ii][jj]) continue;
                qq.push({ii, jj});
                vis[ii][jj] = true;
            }
        }
        ans++;
    }

    return ans;
}
