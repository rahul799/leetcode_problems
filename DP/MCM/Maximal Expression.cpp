https://binarysearch.com/problems/Maximal-Expression/editorials/860825

Given a list of integers nums, return the maximal value that can be made by adding any binary operators +, -, and * between the numbers in nums as well 
as insert 
any valid brackets.



class Solution {
    public int solve(int[] nums) {
        int N = nums.length;
        int[][][] dp = new int[N][N][2];
        for (int i = 0; i < N; i++) {
            dp[i][i][0] = nums[i];
            dp[i][i][1] = nums[i];
        }
        for (int size = 2; size <= N; size++) {
            for (int i = 0; i <= N - size; i++) {
                int j = i + size - 1;
                dp[i][j][0] = Integer.MAX_VALUE;
                dp[i][j][1] = Integer.MIN_VALUE;
                for (int k = i; k < j; k++) {
                    // combine with addition
                    dp[i][j][0] = Math.min(dp[i][j][0], dp[i][k][0] + dp[k + 1][j][0]);
                    dp[i][j][1] = Math.max(dp[i][j][1], dp[i][k][1] + dp[k + 1][j][1]);
                    // combine with subtraction
                    dp[i][j][0] = Math.min(dp[i][j][0], dp[i][k][0] - dp[k + 1][j][1]);
                    dp[i][j][1] = Math.max(dp[i][j][1], dp[i][k][1] - dp[k + 1][j][0]);
                    // combine with multiplication
                    dp[i][j][0] = Math.min(dp[i][j][0],
                        Math.min(dp[i][k][0] * dp[k + 1][j][1], dp[i][k][1] * dp[k + 1][j][0]));
                    dp[i][j][1] = Math.max(dp[i][j][1],
                        Math.max(dp[i][k][0] * dp[k + 1][j][0], dp[i][k][1] * dp[k + 1][j][1]));
                }
            }
        }
        return dp[0][N - 1][1];
    }
}
