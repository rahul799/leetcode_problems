


https://binarysearch.com/problems/Intersection-of-Two-Maps



Intersection of Two Maps
You are given two-dimensional lists of integers a and b, both of which contains 0s and 1s. A 1 represents land and 0 represents water, so an island is a group of 1s that are neighboring whose perimeter is surrounded by water.

Return the number of islands that exist in both a and b at the exact same coordinates.

Constraints

1 ≤ n * m ≤ 200,000 where n and m are the number of rows and columns in a and b
Example 1
Input
a = [
    [1, 0, 1],
    [1, 0, 0],
    [1, 0, 0]
]
b = [
    [1, 0, 0],
    [1, 0, 1],
    [1, 0, 0]
]
Output
1
Explanation
The top left island is shared in both a and b.

Example 2
Input
a = [
    [1, 1, 1],
    [1, 1, 1],
    [1, 1, 1]
]
b = [
    [1, 1, 0],
    [1, 0, 1],
    [1, 0, 0]
]
Output
0









void find(vector<vector<int>>& a, vector<vector<int>>& b, int i, int j, bool& mark) {
    if (i < 0 || j < 0 || i >= a.size() || j >= a[0].size() || (a[i][j] == 0 && b[i][j] == 0)) {
        return;
    }
    if (a[i][j] != b[i][j]) {
        mark = false;
    }
    a[i][j] = 0;
    b[i][j] = 0;
    find(a, b, i - 1, j, mark);
    find(a, b, i + 1, j, mark);
    find(a, b, i, j - 1, mark);
    find(a, b, i, j + 1, mark);
}
int solve(vector<vector<int>>& a, vector<vector<int>>& b) {
    int n = a.size();
    int m = a[0].size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1 && b[i][j] == 1) {
                bool mark = true;
                find(a, b, i, j, mark);
                if (mark) {
                    count++;
                }
            }
        }
    }
    return count;
}
