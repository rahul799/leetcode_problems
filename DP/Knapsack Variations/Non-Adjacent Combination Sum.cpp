
You are given a list of positive integers nums and an integer k. Return whether there exists a combination of integers in nums such that their sum is k and none of those elements are adjacent in the original list.

        
 https://binarysearch.com/room/Weekly-Contest-34-aDD9ZHbeO9?questionsetIndex=2


Constraints

n * k ≤ 100,000 where n is the length of nums
Example 1
Input

nums = [1, 2, 2, 3]
k = 4
Output

true
Explanation

We can pick [1, 3] since they are non-adjacent and sums to 4

Example 2
Input

nums = [1, 3, 1]
k = 4
Output

false
Explanation

We can't pick [1, 3] or [3, 1] since they are adjacent.




bool solve(vector<int>& nums, int K) {
        int N = nums.size();
        
        bool dp [N+2][K +1];
        dp[0][0] = true;
        dp[1][0] = true;
        for(int i = 2; i <= N +1; i++ ){
                int n = nums[i - 2];
        for(int j = 0; j < min(n, K +1); j++){
        dp[i][j] = dp[i-1][j];
                }
        for(int j = n; j <= K; j++){
                dp[i][j] = dp[i - 1][j] || dp[i - 2][j - n];
        }
        
                
                
        }
        return dp[N + 1][K];
        }
    









