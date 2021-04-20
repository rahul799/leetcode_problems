1235. Maximum Profit in Job Scheduling
https://cses.fi/paste/805b5307d53e55f0ab73c/


class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs; // {start time, end time, profit}
        for (int i = 0; i < startTime.size(); i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[1] < v2[1];
        });

        int n = jobs.size();
        vector<int> dp(n, 0);
        
        dp[0] = jobs[0][2];
        for (int i = 1; i < n; i++){
            // take jobs[i]
            int takeCurr = jobs[i][2];
            int idx = lastSmallerOrEqual(jobs, i, jobs[i][0]);
            if (jobs[idx][1] <= jobs[i][0])
                takeCurr += dp[idx];
            
            // no take jobs[i]
            int noTakeCurr = dp[i - 1];
            
            dp[i] = max(takeCurr, noTakeCurr);
        } 
        return dp[n - 1];
    }
    
    int lastSmallerOrEqual(const vector<vector<int>>& jobs, int idx, int start_time){
        int left = 0, right = idx - 1;
        while(left < right){
            int mid = left + (right - left + 1) / 2;
            if (jobs[mid][1] <= start_time)
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};
Share
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime , endTime and profit arrays, you need to output the maximum profit you can take such that there are no 2 jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

 

Example 1:



Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:




Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.1235. Maximum Profit in Job Scheduling
Hard

621

8

Add to List

Share
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime , endTime and profit arrays, you need to output the maximum profit you can take such that there are no 2 jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

 

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:




Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.




IMplementation 1:

A is start B is end, C is profit

class Solution {
public:
    
    int go(int index, vector<int>& A, vector<int>& B, vector<int>& C, vector<int> &dp){
        int n = A.size();
		// if index is the last possible valid index then return the profit for selecting this job
        if(index == n-1) return C[index];
		// check if max profit for this index has been previously calculated, if yes return it
        if(dp[index] != -1)return dp[index];
		// find the next possible job that can be undertaken after this job
        auto y = lower_bound(A.begin()+index, A.end(), B[index]);
        int x, z; // x for undertaking the job, z for not undertaking the job
        if(y == A.end()){
			// if no job can be undertaken after this, x = the profit gained from this job
             x = C[index];
        }else{
			// else x = profit gained from this job + max profit from the job which can be taken next
            x = C[index] + go(y-A.begin(), A, B, C, dp);
        }
		// z = max profit by skipping this job and taking the next available job
        z = go(index +1, A, B, C, dp);
		// answer would be the max(x,z) to maximize profit and would be stored in dp[index]
        dp[index] = max(x, z);
        return max(x, z);
    }
    
    static bool comp(vector<int> &A, vector<int> &B){
        if(A[0] == B[0]){
            if(A[1] == B[1]){
                return A[2] > B[2];
            }
            return A[1] < B[1];
        }
        return A[0] < B[0];
    }
    
    int jobScheduling(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
		// sort the jobs according to their start times
        vector<vector<int>> AA;
        for(auto i = 0; i<n; i++){
            AA.push_back({A[i], B[i], C[i]});
        }
        sort(AA.begin(), AA.end(), comp);
        A.clear();
        B.clear();
        C.clear();
		// fill A, B, C back again 
        for(auto &a: AA){
            A.push_back(a[0]);
            B.push_back(a[1]);
            C.push_back(a[2]);
        }
		// initialise dp vector
        vector<int> dp(n, -1);
        return go(0, A, B, C, dp);
    }
};



class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs; // {start time, end time, profit}
        for (int i = 0; i < startTime.size(); i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[1] < v2[1];
        });

        int n = jobs.size();
        vector<int> dp(n, 0);
        
        dp[0] = jobs[0][2];
        for (int i = 1; i < n; i++){
            // take jobs[i]
            int takeCurr = jobs[i][2];
            int idx = lastSmallerOrEqual(jobs, i, jobs[i][0]);
            if (jobs[idx][1] <= jobs[i][0])
                takeCurr += dp[idx];
            
            // no take jobs[i]
            int noTakeCurr = dp[i - 1];
            
            dp[i] = max(takeCurr, noTakeCurr);
        } 
        return dp[n - 1];
    }
    
    int lastSmallerOrEqual(const vector<vector<int>>& jobs, int idx, int start_time){
        int left = 0, right = idx - 1;
        while(left < right){
            int mid = left + (right - left + 1) / 2;
            if (jobs[mid][1] <= start_time)
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};
