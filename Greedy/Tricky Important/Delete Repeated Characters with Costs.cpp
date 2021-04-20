Delete Repeated Characters with Costs
Question 736 of 906
You are given a lowercase alphabet string s and a list of non-negative integers costs, both of which have the same length. You can remove character 
s[i] for cost costs[i], after which both s[i] and costs[i] is removed.

Return the minimum cost needed to delete all consecutively repeating characters.

Constraints

n ≤ 100,000 where n is the length of s and costs
Example 1
Input
s = "aabba"
nums = [1, 2, 9, 3, 5]
Output
4
Explanation
We can remove s[0] and s[3] for a total cost of 1 + 3









int solve(string s, vector<int>& nums) {
         int totalCost = 0;
        int start = 0;
        
         for (int i = 1; i < s.length(); i++) {
                if(s[start] == s[i]){
                if (nums[start] < nums[i]) {
                totalCost += nums[start];
                start = i;
                }
                else totalCost += nums[i];
            } 
            else {
                start = i;
            }
        }
        return totalCost;
    }
