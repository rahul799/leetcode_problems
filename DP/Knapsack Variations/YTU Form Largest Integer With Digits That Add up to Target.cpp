
1449. Form Largest Integer With Digits That Add up to Target
Hard

321

5

Add to List

Share
Given an array of integers cost and an integer target. Return the maximum integer you can paint under the following rules:

The cost of painting a digit (i+1) is given by cost[i] (0 indexed).
The total cost used must be equal to target.
Integer does not have digits 0.
Since the answer may be too large, return it as string.

If there is no way to paint any integer given the condition, return "0".

 

Example 1:

Input: cost = [4,3,2,5,6,7,2,5,5], target = 9
Output: "7772"
Explanation:  The cost to paint the digit '7' is 2, and the digit '2' is 3. Then cost("7772") = 2*3+ 3*1 = 9. You could also paint "977", but "7772" is the largest number.
Digit    cost
  1  ->   4
  2  ->   3
  3  ->   2
  4  ->   5
  5  ->   6
  6  ->   7
  7  ->   2
  8  ->   5
  9  ->   5
Example 2:

Input: cost = [7,6,5,5,5,6,8,7,8], target = 12
Output: "85"
Explanation: The cost to paint the digit '8' is 7, and the digit '5' is 5. Then cost("85") = 7 + 5 = 12.
Example 3:

Input: cost = [2,4,6,2,4,6,4,4,4], target = 5
Output: "0"
Explanation: It's not possible to paint any integer with total cost equal to target.
Example 4:

Input: cost = [6,10,15,40,40,40,40,40,40], target = 47
Output: "32211"
 

Constraints:

cost.length == 9
1 <= cost[i] <= 5000
1 <= target <= 5000





// Return a string maximum of two strings representing integer
string maxl(string a, string b)
{
    if(a.length()>b.length())
        return a;
    else if(a.length()<b.length())
        return b;
    else
    {
        int i=0;
        while(i<a.length() && a[i]==b[i])
            i++;
        if(i==a.length())
            return a;
        if(a[i]>b[i])
            return a;
        return b;
    }
}  
class Solution {
public:
    
    string largestNumber(vector<int>& a, int t) {
        vector<vector<string>> dp(t+1,vector<string>(9,"0"));
        // dp[i][j] stores a string represeting largest integer with digits [1,2,..,j+1] that add up to "i"
        for(int i=1;i<=t;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(i-a[j]==0)  // if i==a[j], we can form an integer= j+1
                    dp[i][j]=to_string(j+1);
                // keep max of either by not using the digit (j+1) or by using it
                if(j>0) 
                    dp[i][j]=maxl(dp[i][j-1], dp[i][j]); // case: not using (j+1) digit
                
                if(i-a[j]>=0 && dp[i-a[j]][8]!="0") //case: by using it after checking if it is possible to make an integer by i-a[j] as target
                    dp[i][j]=maxl(dp[i][j], dp[i-a[j]][8]+to_string(j+1)); // dp[i-a[j]][8] stores max integer represented by string that add up to i-a[j] as target 
            }
        }
        return dp[t][8];
    }
};
