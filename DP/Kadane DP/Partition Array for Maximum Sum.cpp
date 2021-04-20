
1043. Partition Array for Maximum Sum
Medium

964

121

Add to List

Share
Given an integer array arr, you should partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length
Accepted


dp[i] record the maximum sum we can get considering A[0] ~ A[i]
To get dp[i], we will try to change k last numbers separately to the maximum of them,
where k = 1 to k = K.




The dynamic programming solution works here because the problem has an optimal substructure and overlapping subproblems as in the following example:

Let A = [9, 10, 2, 5] and K = 3

Let S[n1, n2, ..., ni] be the solution to subarray [n1, n2, ..., ni].
The following are base cases to initialize the memo array:

S[9] = 9 (i.e., memo[0] = 9)
S[9, 10] = 20 (i.e., memo[1] = 20)
S[9, 10, 2] = 30 (i.e., memo[2] = 30)
Here we do the real work, where you need to "loop" through a K-sized window before the new value to be considered, including the new value, which in this case the new value is 5:

S[9, 10, 2, 5] = max(S[9] + S[10, 2, 5], S[9, 10] + S[2, 5], S[9, 10, 2] + S[5]) = 39
The window we "looped" through above is [10, 2, 5].

From the formula above, we see that the overlapping subproblem is in using the solutions from previous solutions stored in the memo, e.g., S[9], S[9, 10], and S[9, 10, 2]. The optimal substructure comes from the fact that the solution to S[9, 10, 2, 5] is solved by using solutions to previously calculated solutions.






class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int k) {
        int n = A.size();
        vector<int> dp(n);
        dp[0] = A[0];
        for(int i = 1; i < n; i++) {
            int mx = A[i];
            int curr = INT_MIN;
            for(int j = 1; j <= k && i - j + 1 >= 0; j++) {
                mx = max(mx, A[i - j + 1]);
                if(i - j + 1 == 0)
                    curr = max(curr, j * mx);
                else
                    curr = max(curr, dp[i - j] + j * mx);
            }
            dp[i] = curr;
        }
        return dp[n - 1];
    }
};






   int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N = A.size();
        vector<int> dp(N);
        for (int i = 0; i < N; ++i) {
            int curMax = 0;
            for (int k = 1; k <= K && i - k + 1 >= 0; ++k) {
                curMax = max(curMax, A[i - k + 1]);
                dp[i] = max(dp[i], (i >= k ? dp[i - k] : 0) + curMax * k);
            }
        }
        return dp[N - 1];
    }
