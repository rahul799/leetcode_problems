
Collecting Disappearing Coins
You are given a two-dimensional list of integers matrix where each matrix[r][c] represents the number of coins in that cell. When you pick up coins on matrix[r][c], all the coins on row r - 1 and r + 1 disappear, as well as the coins at the two cells matrix[r][c + 1] and matrix[r][c - 1]. Return the maximum number of coins that you can collect.

    
    https://binarysearch.com/problems/Collecting-Disappearing-Coins



Constraints

n, m ≤ 250 where n and m are the number of rows and columns in matrix
Example 1
Input
matrix = [
    [1, 7, 6, 5],
    [9, 9, 3, 1],
    [4, 8, 1, 2]
]
Output
22
Explanation
We can pick cells with the coins 7, 5, and 8 and 2.



int helper(vector<int>& arr){
        int n = arr.size();
        int dp[n][2] = {0};
         dp[0][0] = arr[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][1] + arr[i];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        int ans1 = max(dp[n - 1][0], dp[n - 1][1]);
        return ans1 ;

}

int solve(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        vector<int> arr(n, 0);
        for(int i = 0; i < n; i++) arr[i] = helper(matrix[i]);
        int ans = helper(arr);
        return ans; 
}





Intuition
This is a DP within a DP problem. Consider the standard DP of finding the maximum sum you can get in an array, if you are not allowed to pick adjacent numbers.

In a given row, the constraint of this problem is identical to that standard DP, since the constraint specifies we can't pick either adjacent number! Thus, \textbf{we calculate the answer for each row independently}we calculate the answer for each row independently. Now, the other part of the constraint is that once we pick a number , we can't pick ANY number in either adjacent row. However, this is still identical to that same standard DP, after we calculate the optimal answer for each row!

Check out the code below. The DP function calculates the standard dp.

Time Complexity: \mathcal{O}(NM)O(NM)
Space Complexity: \mathcal{O}(NM)O(NM)


int best(vector<int>& v) {
    // return the maximum sum of elements given that you can't choose adjacent elements
    int n = v.size();
    // dp[i] is the maximum sum you can get considering exactly the first i elements
    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++) {
        // don't choose element i
        dp[i + 1] = max(dp[i + 1], dp[i]);
        // choose element i
        dp[i + 1] = max(dp[i + 1], v[i] + (i == 0 ? 0 : dp[i - 1]));
    }
    return dp[n];
}

int solve(vector<vector<int>>& matrix) {
    vector<int> rows;
    for (auto& row : matrix) {
        rows.push_back(best(row));
    }
    return best(rows);
}
