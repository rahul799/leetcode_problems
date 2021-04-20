
https://binarysearch.com/room/Weekly-Contest-31-Z6peqEgSi3?questionsetIndex=2

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




Let f(i, j)f(i,j) be the minimum distance from the entry in row ii, column jj to any water square. We claim that the answer is exactly equal to the ff matrix.

This matrix is clearly a valid matrix - the first condition is clearly satisfied, and the second condition is satisfied because in such a distance matrix, two adjacent squares cannot differ in value by more than 11, otherwise you could find a closer shortest path.

It remains to prove there is no better matrix, but by definition, if you start at a water cell and trace the shortest path to any given square, that establishes an upper bound on the value in that square per the second condition where adjacent squares can only differ in value by at most 1. Therefore, the aforementioned distance matrix realizes the maximum possible values in each square.

Computing ff can be done with a multisource BFS from each water cell. This takes \mathcal{O}(MN)O(MN) time and space.



vector<vector<int>> solve(vector<vector<int>>& g) {
    int r = g.size();
    int c = g[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            if (g[i][j] == 0) {
                q.emplace(i, j);
            } else {
                g[i][j] = 1e9;
            }
        }
    while (q.size()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        int dx[4]{-1, 0, 1, 0};
        int dy[4]{0, -1, 0, 1};
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && g[nx][ny] > 1 + g[x][y]) {
                g[nx][ny] = 1 + g[x][y];
                q.emplace(nx, ny);
            }
        }
    }
    return g;
}
