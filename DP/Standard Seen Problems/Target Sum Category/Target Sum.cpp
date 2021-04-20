

494. Target Sum
Medium



Share
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
 

Constraints:

The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer





The original problem statement is equivalent to:
Find a subset of nums that need to be positive, and the rest of them negative, such that the sum is equal to target

Let P be the positive subset and N be the negative subset
For example:
Given nums = [1, 2, 3, 4, 5] and target = 3 then one possible solution is +1-2+3-4+5 = 3
Here positive subset is P = [1, 3, 5] and negative subset is N = [2, 4]

Then let's see how this can be converted to a subset sum problem:

                  sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
                       2 * sum(P) = target + sum(nums)
So the original problem has been converted to a subset sum problem as follows:
Find a subset P of nums such that sum(P) = (target + sum(nums)) / 2

Note that the above formula has proved that target + sum(nums) must be even



class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int cnt=0;
        if(sum<S || (S+sum)%2!=0)return 0;
        sum=(sum+S)/2;
        int dp[nums.size()+1][sum+1];
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)cnt++;
        }
        
        for(int i=0;i<sum+1;i++){
            dp[0][i]=0;
        }
        for(int i=0;i<nums.size()+1;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<nums.size()+1;i++){
            for(int j=1;j<sum+1;j++){
                if(nums[i-1]<=j && nums[i-1]!=0){
                    dp[i][j]=dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        // this is the case when our input term contains zero 
        return dp[nums.size()][sum]*pow(2,cnt);
    }
};










int solve(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (target > sum || (sum + target) % 2) return 0;

    int k = (sum + target) / 2;

    vector<int> dp(k + 1, 0);

    dp[0] = 1;

    for (auto i : nums) {
        for (int j = k; j >= i; j--) {
            dp[j] += dp[j - i];
        }
    }

    return dp[k];
}



