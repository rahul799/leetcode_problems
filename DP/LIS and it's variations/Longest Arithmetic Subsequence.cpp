


Longest Arithmetic Subsequence




Given a list of integers nums, return the length of the longest arithmetic subsequence.

A sequence B[i] is defined as an arithmetic sequence if B[i+1] - B[i] have the same value for every 0 ≤ i < len(B) - 1.
For example, [1, 5, 9, 13, 17] is the longest arithmetic subsequence of [-30, 1, 10, 5, 9, -20, 13, 17].

Constraints

n ≤ 1,000 where n is the length of nums
Example 1
Input
nums = [1, 3, 5, 7, 9]
Output
5
Explanation
The whole array is arithmetic since the difference between each consecutive element is 2.

Example 2
Input
nums = [1, 3, 6, 7, 5, 8, 9]
Output
4
Explanation
[6, 7, 8, 9] is the longest arithmetic subsequence.



int solve(vector<int>& arr) {
          if(arr.size() <= 1)
        return arr.size();
        
        int max_len = 0;
        // dp(i): dict of (diff, length) for ith index 
        vector<unordered_map<int, int>> dp(arr.size());

        for(int i = 1; i < arr.size(); i++)
            // check with the previous terms the if there is a series
            // with diff (a[i] - a[j])
            for(int j = 0; j < i; j++) {
                int diff = (arr[i] - arr[j]);
                // check if there is an AP ending before ith term
                // with the same diff and include the current term
                int max_ap_len = 1 + (dp[j].count(diff) ? dp[j][diff] : 0);
                // max length AP found ending with current ith term so far,
                // if this is the first time then it makes the length 2 using {a[i], a[j]}
                int max_len_ending_here = dp[i].count(diff) ? dp[i][diff] : 2;

                dp[i][diff] = max(max_len_ending_here, max_ap_len);
                max_len = max(max_len, dp[i][diff]);
            } 
        return max_len;
    
}

 
      
    
