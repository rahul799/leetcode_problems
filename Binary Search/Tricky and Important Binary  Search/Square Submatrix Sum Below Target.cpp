
Square Submatrix Sum Below Target

You are given a two-dimensional list of non-negative integers matrix and a non-negative integer target. Return the area of the largest square sub-matrix whose sum is less than or equal to target. If there's no such matrix, return 0.

    
    https://binarysearch.com/problems/Square-Submatrix-Sum-Below-Target/editorials/3404696

Constraints

1 ≤ n, m ≤ 250 where n and m are the number of rows and columns in matrix
Example 1
Input
matrix = [
    [3, 2, 1],
    [2, 0, 7],
    [1, 1, 9]
]
target = 10
Output
4
Explanation
This sub-matrix sums to 10:

[2, 1]
[0, 7]





Intuition
here we want to find the largest square in the matrix whose sum is less than or equals to the target. since every element is non negative we can see if the matrix of dimension [n,m][n,m] has this validity than all the inclusive matrix inside this matrix will also hold true. so we can binary search for the answer.

Implementation
we first build prefix sum subarray to get the sum of submatrix in \mathcal{O}(1)O(1) .
now we check for the search space ->
a. the minimum will be that no matrix is valid even of size 11 .
b. maximum square will have the length min(N,M)min(N,M).
Time Complexity
\mathcal{O}(n \cdot m \cdot \log ( min(n,m))O(n⋅m⋅log(min(n,m)) cause the binary search take logarithmic and the validation part is n \cdot mn⋅m

Space Complexity
\mathcal{O}(n \cdot m)O(n⋅m) coz we build a prefix sum subarray of size of the matrix.

int solve(vector<vector<int>>& nums, int target) {
    int n = nums.size(), m = nums[0].size(), s = 0, e = min(n, m);
    vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + nums[i - 1][j - 1];
        }
    }
    auto is_valid = [&](int x) -> bool {
        for (int i = x; i <= n; i++) {
            for (int j = x; j <= m; j++) {
                int cs = pre[i][j] - pre[i][j - x] - pre[i - x][j] + pre[i - x][j - x];
                if (cs <= target) return true;
            }
        }
        return false;
    };
    while (s <= e) {
        int m = s + (e - s) / 2;
        if (is_valid(m)) {
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    return e * e;
}
