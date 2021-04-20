


Shortest Absolute Value Distance
You are given a two-dimensional list of integers matrix. You can move up, left, right, down and each move from matrix[a][b] to matrix[c][d] costs abs(matrix[a][b] - matrix[c][d]).

Return the minimum cost to move from the top left corner to the bottom right corner.

Constraints

1 ≤ n * m ≤ 200,000 where n and m are the number of rows and columns in matrix
Example 1
Input
matrix = [
    [1, 100, 1],
    [2, 5, 3],
    [1, 2, 3]
]
Output
4
Explanation
We can move from 1 -> 2 -> 1 -> 2 -> 3.



int solve(vector<vector<int>>& matrix) {
    ios::sync_with_stdio(false);
    int n = (int)matrix.size();
    int m = (int)matrix[0].size();
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
    q.push({0, 0, 0});
    vector<vector<int>> cost(n, vector<int>(m, 2e9));
    cost[0][0] = 0;
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!q.empty()) {
        auto [c, x, y] = q.top();
        q.pop();
        for (auto& [dx, dy] : moves) {
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (cost[nx][ny] > abs(matrix[nx][ny] - matrix[x][y]) + cost[x][y]) {
                    cost[nx][ny] = cost[x][y] + abs(matrix[nx][ny] - matrix[x][y]);
                    q.push({cost[nx][ny], nx, ny});
                }
            }
        }
    }
    return cost[n - 1][m - 1];
}
