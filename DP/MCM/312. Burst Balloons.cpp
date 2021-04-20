



https://www.youtube.com/watch?v=zfgZtcDQAxw&ab_channel=KeertiPurswani



312. Burst Balloons
Hard

3458

104

Add to List

Share
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a 
balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10
 

Constraints:

n == nums.length
1 <= n <= 500
0 <= nums[i] <= 100




We keep merging K piles of stones until there is only one pile.

For the last step, stones[i .. j] are divided into K piles, and we merge them into one pile, which costs sum(nums[i .. j]) + cost to make stones[i .. j] form K piles.

The problem get the minimum cost to make stones[i .. j] form 1 pile equals to

	the minimum cost to make stones[i .. j] form K piles
	+ sum(nums[i .. j])
The subproblem the minimum cost to make stones[i .. j] form K piles equals to

	the minimum cost to make stones[i .. k] form K - 1 piles
	+ the minimum cost to make stones[k + 1 .. j] form 1 pile 
	+ sum(nums[i .. j])
  
  
  
  




class Solution {
    public:
        int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        // dp[i][j]=max( dp[i][j], dp[i][x-1]+nums[i-1]*nums[x]*nums[j+1]+dp[x+1][j] )
        // dp[i][j] means max coins in range [i,j].
        for(int len=1;len<=n;len++)
            for(int start=1;start<=n-len+1;start++)
            {
                int end=start+len-1;
                for(int x=start;x<=end;x++)
                    dp[start][end]=max(dp[start][end],dp[start][x-1]+nums[start-1]*nums[x]*nums[end+1]+dp[x+1][end]);
            }
        return dp[1][n];   
        }
    };
