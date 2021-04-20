Consider a function rev(num) which reverses the digits of num. For example, rev(123) = 321 and rev(100) = 1.

Given a list of positive integers nums, return the number of pairs (i, j) where i ≤ j and nums[i] + rev(nums[j]) = nums[j] + rev(nums[i]). Mod the result by 
10 ** 9 + 7.


Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input

nums = [1, 20, 2, 11]
Output

7
Explanation

We can have the following pairs:

1 and 1
1 and 2
1 and 11
20 and 20
2 and 2
2 and 11
11 and 11
Example 2
Input

nums = [2, 2]
Output

3
Explanation

We can have the following pairs:

2 and 2 (nums[0] and nums[0])
2 and 2 (nums[0] and nums[1])
2 and 2 (nums[1] and nums[1])









int mod =  1e9 + 7;

int reverseNum(int n){
        int ans = 0;
        while(n){
                ans = (10 * ans) + (n%10);
                n = n/10;
        }
        return ans;
}
int solve(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        long long temp = 0, ans = 0;
        
        for(int i : nums){
                mp[i - reverseNum(i)]++;
        }
        
        for(auto it : mp){
                 temp = it.second;
                 temp = temp*(temp + 1)/2;
                ans = (ans + (temp) % mod)% mod;
        }
        return ans;
}




