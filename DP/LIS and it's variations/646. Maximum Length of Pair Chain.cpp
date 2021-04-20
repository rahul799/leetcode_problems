646. Maximum Length of Pair Chain

You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]

https://leetcode.com/problems/maximum-length-of-pair-chain/discuss/105641/C%2B%2B-DPDetailed-Explanation-for-Beginners


this problem is very much similar to another well-known DP problem----LIS(longest increasing subsequence). In LIS，we're given a sequence，
    say， 1 7 3 5 9 4 8，and the target is to get the length of the longest increasing subsequence(in this case 1 3 5 9 is a possible answer，
    thus 4 is returned) To solve LIS，we can define a state function d[i] to be the length of sequence ending at position i，then d[i]=max(d[j]|j<i && num[j]<num[i])+1,j∈[0,i)，the final result would be the largest of d[i]. This equation can be even shorter: d[i]=max(d[i],d[j]+1)，if num[j]>num[i]，j∈[0,i)，in this equation，we've guaranteed that we get the maximum of d[i] every time.
The solution of the current problem is almost the same as above. We define d[i] to be the length of the longest chain at position i， then there're two possibilities： 1)can't form a larger chain at position i，namely d[i]=d[j]，where j is a previous position less than i，2)can form a longer chain，d[i]=d[j]+1. Note that we need to guarantee d[i] is always the maximum， then we have: d[i]=max(d[i]，d[j])andd[i]=max(d[i]，d[j]+1)， that's how we get the state functions.
The last question: why must we sort the input array? Well，the problem has suggested You can select pairs in any order.，that's to say，in fact，this problem is a LIS problem with flexible order，sort the array guarantees we won't lose any possible solution



class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        //define dp[i]:the maximum chain we can get at position i
        //our goal:get d[totol_length-1](the final position)
        //dp[i]=max(dp[i],dp[j]), for j in range [0,i), if pairs[i][0]<=pairs[j][1]
        //dp[i]=max(dp[i],dp[j]+1), for j in range [0,i), if pairs[i][0]>pairs[j][1]
        //border:dp[0]=1
        //NOTE:we must sort the array
        int len=pairs.size();
        vector<int>dp(len,0);
        sort(pairs.begin(),pairs.end(),cmp);
        dp[0]=1;
        for(int i=0;i<len;i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0]<=pairs[j][1])
                    dp[i]=max(dp[i],dp[j]);
                else
                    dp[i]=max(dp[i],dp[j]+1);
            }
        }
        return dp[len-1];
    }
    //sort according to the first column, i.e. the first number in each pair
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0]<b[0];
    }
};





class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
    int max=1,i=0;
    sort(pairs.begin(),pairs.end(),[](vector<int> &a,vector<int>&b){
        return a[1]<b[1];
    });
    for(int j=1;j<pairs.size();j++){
    if(pairs[i][1]<pairs[j][0]){
        i=j;
        max++;
    }
    } 
        return max;
    }
};


















// class Solution {
// public:
//     int findLongestChain(vector<vector<int>>& pairs) {
//         if(!pairs.size()) return 0;
//         sort(pairs.begin(), pairs.end());
// 		// LIS array initialized as 1. As, every element is itself an answer
//         vector<int> lis(pairs.size(), 1);
//         int longestChainNum = 1;
// 		// Finding LIS in [0-----j]i for each 'i'
//         for(int i=1;i<pairs.size();i++){
//             for(int j=0;j<i;j++){
// 				// Condition similar to LIS
//                 if((pairs[j][1] < pairs[i][0]) && (lis[i] < lis[j] + 1)){
//                     lis[i] = lis[j] + 1;
// 					// Updating maximum
//                     longestChainNum = max(longestChainNum, lis[i]);
//                 }
//             }
//         }
//         return longestChainNum;
//     }
// };


// class Solution {
// public:
    
//     static bool cmp(vector<int>&a,vector<int>&b){
//         return a[0]<b[0];
//     }
    
    
    
     int findLongestChain(vector<vector<int>>& pairs) {
        
         int n = pairs.size();
         if(n<2)return n;
         vector<int> dp(n,1);
         int ans = 0;
         sort(pairs.begin(),pairs.end(),cmp);
         for(int i=1;i<n;i++){
/             for(int j=0;j<i;j++){
//                 if(pairs[i][0]>pairs[j][1]){
//                     dp[i] = max(dp[i],dp[j]+1);
//                 }
//             }
//             ans = max(ans,dp[i]);
//         }
//         return ans;
//     }
// };
