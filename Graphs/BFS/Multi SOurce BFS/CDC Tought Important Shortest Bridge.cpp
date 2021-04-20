



Shortest Bridge


https://binarysearch.com/problems/Shortest-Bridge





Shortest Bridge
Given a two-dimensional list of integers matrix containing 0s and 1s, 0 represents water and 1 represents land.

An island is a group of connecting 1s in 4 directions that are either surrounded by 0s or by the edges.
Find the shortest bridge that connects two islands.

It is guaranteed that there are two and only two islands.

Constraints

n, m ≤ 250 where n and m re the number of rows and columns in matrix
Example 1
Input
matrix = [
    [0, 1],
    [1, 0]
]
Output
1
Explanation
Either of the two water elements can be used as the bridge.

Example 2
Input
matrix = [
    [1, 0, 0],
    [0, 0, 0],
    [0, 0, 1]
]
Output
3
Explanation
There's six shortest bridges such as [(0, 1), (0, 2), (1, 2)] or [(1, 0), (2, 0), (2, 1)]














void dfs(vector<vector<int>>& matrix, int i, int j, int R, int C) {
    if (i < 0 || i >= R || j < 0 || j >= C || matrix[i][j] != 1) return;
    matrix[i][j] = 2;
    dfs(matrix, i + 1, j, R, C);
    dfs(matrix, i, j + 1, R, C);
    dfs(matrix, i - 1, j, R, C);
    dfs(matrix, i, j - 1, R, C);
}
bool isValid(int i, int j, int R, int C) {
    if (i < 0 || i >= R || j < 0 || j >= C) return false;
    return true;
}
int solve(vector<vector<int>>& matrix) {
    int R = matrix.size();
    int C = matrix[0].size();
    // 2 break statements required to break out of 2 loops
    for (int i = 0; i < R; i++) {
        int f = 0;
        for (int j = 0; j < C; j++) {
            if (matrix[i][j] == 1) {
                f = 1;
                dfs(matrix, i, j, R, C);
                break;
            }
        }
        if (f == 1) break;
    }
    vector<vector<bool>> vis(R, vector<bool>(C, false));
    queue<pair<int, int>> q;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matrix[i][j] == 2) {
                q.emplace(i, j);
            }
        }
    }
    int x[4]{-1, 1, 0, 0};
    int y[4]{0, 0, -1, 1};
    int dis = 0;
    while (!q.empty()) {
        int len = q.size();
        for (int el = 0; el < len; el++) {
            auto [i, j] = q.front();
            q.pop();
            if (matrix[i][j] == 1) return dis - 1;
            if (vis[i][j]) continue;
            vis[i][j] = true;
            for (int k = 0; k < 4; k++) {
                int ni = i + x[k];
                int nj = j + y[k];
                if (isValid(ni, nj, R, C) && (matrix[ni][nj] == 0 || matrix[ni][nj] == 1))
                    q.emplace(ni, nj);
            }
        }
        dis += 1;
    }
    return -1;
}



