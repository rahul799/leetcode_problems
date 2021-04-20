Chain of Blocks


https://binarysearch.com/problems/Chain-of-Blocks


You are given a list blocks where each block contains two integers [start, end] where start < end. You can join two blocks if the end of one is equal to the start of another. Return the length of the longest chain of blocks.

Constraints

0 ≤ n ≤ 100,000 where n is the length of blocks.
Example 1
Input
blocks = [
    [3, 4],
    [4, 5],
    [3, 7],
    [0, 1],
    [1, 3]
]
Output
4
Explanation
We can form the following chain: [0, 1], [1, 3], [3, 4], [4, 5]




        static bool comp(vector<int>& A,vector<int>& B){
        return A[1]<B[1];
    }
    int solve(vector<vector<int>>& blocks) {
        unordered_map<int,int> dp;
        int ans=0;
        sort(blocks.begin(),blocks.end(),comp);
        for(int i=0;i<blocks.size();i++){
            dp[blocks[i][1]]=max(dp[blocks[i][0]]+1,dp[blocks[i][1]]);
            ans=max(ans,dp[blocks[i][1]]);
        }
        return ans;
    }
