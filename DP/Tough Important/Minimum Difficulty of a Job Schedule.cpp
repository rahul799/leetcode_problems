



1335. Minimum Difficulty of a Job Schedule
Hard

427

41


https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/discuss/612228/C%2B%2B-Bottom-Up-DP-O(n2)-Space-With-Comments




Add to List

Share
You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the i-th job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done in that day.

Given an array of integers jobDifficulty and an integer d. The difficulty of the i-th job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.

 
 
 
 My thought process for the question :
Prerequisite:
For each i (0 <= i < n) all previous tasks need to completed.

The question can be framed into another statement which might be more intuitive
Partition the array into d contiguous subsets such that sum of maximum of each subset is minimum.

I defined the state function as the minimum sum of partitioning array ending at index i into x subsets
for all  0 <= i < n and 0 <= x < d
State function: S(i, d) (Definition given above)
Some edges cases : 
If number of jobs is less that d then return -1 since partitioning is not possible
If d == 1 then return max element in array
if no of jobs == d then return sum of array

Example :

6 5 4 3 2 1.
If we are at index 3 and d = 2
then the subproblem is partitioning 6 5 4 3 into 2 subsets such that sum of maximum of subsets is minimum.
6 5 4 3 in d = 2 depends on min of :

6 5 4 in 1 + 3 in 1 -> subproblem 1
65 in 1 + 43 in 1 -> subproblem 2
6 in 1 + 543 in 1 -> subproblem 3

It should be noted that ( 43 in 1 ) can be calulated by looping back from 3 and taking max.
2D matrix for more clarification :
    6  4  5  3  2  1
1   6  6  6  6  6  6
2  -1  10 10 9  8  7






Example 1:


Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7 
Example 2:

Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.
Example 3:

Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.
Example 4:

Input: jobDifficulty = [7,1,7,1,7,1], d = 3
Output: 15
Example 5:

Input: jobDifficulty = [11,111,22,222,33,333,44,444], d = 6
Output: 843
 

Constraints:

1 <= jobDifficulty.length <= 300
0 <= jobDifficulty[i] <= 1000
1 <= d <= 10
Accepted

Easy to understand

 #define INF 10000000

class Solution {
public:
    
     int dp[301][11];
    int dfs(int idx, int d, vector<int>&jobDifficulty, int n){
        
        if(idx == n && d == 0 ) return 0;
        
        if(idx == n || d == 0 || n-idx<d ) return INF;
        
        if(dp[idx][d] != -1) return dp[idx][d];
        
        int ans = INF, maxEle = -INF;
        
        for(int j = idx ; j < n; j++){
            
            maxEle = max(maxEle, jobDifficulty[j]);
            ans = min(ans, maxEle + dfs( j + 1, d -1, jobDifficulty, n));
        }
        
        dp[idx][d] = ans;
        
        return ans;
    }
        
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        if(n < d) return -1;
        memset(dp, -1, sizeof(dp));
        
        int ans = dfs(0, d, jobDifficulty, n);
       return ans;
        
        
    }
};





int minDifficulty(vector<int>& A, int D) {
        int n = A.size(), inf = 1e9, maxd;
        if (n < D) return -1;
        vector<int> dp(n + 1, 1e9);
        dp[n] = 0;
        for (int d = 1; d <= D; ++d) {
            for (int i = 0; i <= n - d; ++i) {
                maxd = 0, dp[i] = inf;
                for (int j = i; j <= n - d; ++j) {
                    maxd = max(maxd, A[j]);
                    dp[i] = min(dp[i], maxd + dp[j + 1]);
                }
            }
        }
        return dp[0];
    }



class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size() < d){ return -1; }
        if(jobDifficulty.size() == d){ return accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0); }
        if(d == 1){ return *max_element(jobDifficulty.begin(), jobDifficulty.end()); }
        vector<vector<int>> dp(d, vector<int>(jobDifficulty.size(), -1));
        int maxEl = -1;
        
        for(int i = 0; i < jobDifficulty.size(); i++){
            maxEl = max(maxEl, jobDifficulty[i]);
            dp[0][i] = maxEl;
        }
        
        for(int i = 1; i < d; i++){
            for(int j = i; j < dp[0].size(); j++){
                dp[i][j] = INT_MAX - 2000;
                int maxDiff = jobDifficulty[j];
                for(int r = j; r >= i; r--){
                    maxDiff = max(maxDiff, jobDifficulty[r]);
                    dp[i][j] = min(dp[i - 1][r - 1] + maxDiff, dp[i][j]);
                }
            }
        }
        return dp[d - 1][dp[0].size() - 1];
    }
};
