Peak Heights 🦖
Question 818 of 907
You are given a two-dimensional integer matrix containing 0s and 1s where 0 represents water and 1 represents land. Return a new matrix of the same dimensions where we increase the height of every land cell as much as possible given that:

The height of any water cell stays 0
Any cell can differ by at most 1 unit of height between neighboring cells (up, down, left, right)
You can assume there is at least one water cell.

Constraints

n, m ≤ 250 where n and m are the number of rows and columns in matrix
Example 1
Input
matrix = [
    [0, 1, 0],
    [1, 1, 1],
    [1, 1, 1]
]
Output
[
    [0, 1, 0],
    [1, 2, 1],
    [2, 3, 2]
]









int isValid(int x, int y, int n, int m) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    return 1;
}
vector<vector<int>> solve(vector<vector<int>>& mat) {
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 0) {
                q.push({i, j});
                vis[i][j] = 0;
            }
        }
    }
    int val = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            auto curr = q.front();
            q.pop();
            if (vis[curr.first][curr.second]) continue;
            vis[curr.first][curr.second] = 1;
            mat[curr.first][curr.second] = val;
            for (int i = 0; i < 4; ++i) {
                int nx = curr.first + dx[i];
                int ny = curr.second + dy[i];
                if (isValid(nx, ny, n, m) && !vis[nx][ny]) {
                    q.push({nx, ny});
                }
            }
        }
        val++;
    }
    return mat;
}


