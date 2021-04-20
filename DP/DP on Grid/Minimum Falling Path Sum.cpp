931. Minimum Falling Path Sum
Medium

1045

77

Add to List

Share
Given a square array of integers A, we want the minimum sum of a falling path through A.

A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.

 

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12
Explanation: 
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
The falling path with the smallest sum is [1,4,7], so the answer is 12.

 

Constraints:

1 <= A.length == A[0].length <= 100
-100 <= A[i][j] <= 100

This problem has an optimal substructure, meaning that the solutions to subproblems can be used to solve larger instances of 
this problem. This makes dynamic programming an ideal candidate.

Let dp(r, c) be the minimum total weight of a falling path starting at (r, c) and reaching the bottom row.

Then, dp(r, c) = A[r][c] + min(dp(r+1, c-1), dp(r+1, c), dp(r+1, c+1)), and the answer is \min\limits_c \text{dp}(0, c) 
c
min
​	
 dp(0,c).

Algorithm

Usually, we would make an auxillary array dp to cache intermediate values dp(r, c). However, this time we will use A to 
cache these values. Our goal is to transform the values of A into the values of dp.

We process each row, starting with the second last. (The last row is already correct.) We set A[r][c] = min(A[r+1][c-1], 
A[r+1][c], A[r+1][c+1]), handling boundary conditions gracefully.

Let's look at the recursion a little more to get a handle on why it works. For an array like A = [[1,1,1],[5,3,1],[2,3,4]], 
imagine you are at (1, 0) (A[1][0] = 5). You can either go to (2, 0) and get a weight of 2, or (2, 1) and get a weight of 3. 
Since 2 is lower, we say that the minimum total weight at (1, 0) is dp(1, 0) = 5 + 2 (5 for the original A[r][c].)

After visiting (1, 0), (1, 1), and (1, 2), A [which is storing the values of our dp], looks like [[1,1,1],[7,5,4],[2,3,4]].
We do this procedure again by visiting (0, 0), (0, 1), (0, 2). We get A = [[6,5,5],[7,5,4],[2,3,4]], and the final answer
is min(A[0]) = 5


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
    vector<vector<int>> dp(A.size(),vector<int>(A.size(),INT_MAX));
    for(int i=0;i<A.size();i++){
        dp[0][i] = A[0][i];
    }
    for(int i=1;i<A.size();i++){
        for(int j=0;j<A.size();j++){
            if(j>0 and j<A.size()-1){
                dp[i][j] = min(dp[i-1][j-1]+A[i][j],dp[i-1][j]+A[i][j]);
                dp[i][j] = min(dp[i-1][j+1]+A[i][j],dp[i][j]);
            }
            else if(j==0){
                dp[i][j] = min(dp[i-1][j+1]+A[i][j],dp[i-1][j]+A[i][j]);
            }
            else if(j == A.size()-1){
                dp[i][j] = min(dp[i-1][j-1]+A[i][j],dp[i-1][j]+A[i][j]);
            }
        }
    }
    
    int ans = INT_MAX;
    for(auto& x:dp[dp.size()-1]){
            ans = min(ans,x);
    }
    return ans;
    }
};

