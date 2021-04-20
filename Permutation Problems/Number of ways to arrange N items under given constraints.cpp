
Came in INterview


YET TO UNDERSTAND
https://www.geeksforgeeks.org/number-of-ways-to-arrange-n-items-under-given-constraints/



Number of ways to arrange N items under given constraints
Difficulty Level : Hard
 Last Updated : 29 Mar, 2019
We are given N items which are of total K different colors. Items of the same color are indistinguishable and colors can be numbered from 1 to K and count of items of each color is also given as k1, k2 and so on. Now we need to arrange these items one by one under a constraint that the last item of color i comes before the last item of color (i + 1) for all possible colors. Our goal is to find out how many ways this can be achieved.

Examples:

Input : N = 3        
        k1 = 1    k2 = 2
Output : 2
Explanation :
Possible ways to arrange are,
k1, k2, k2
k2, k1, k2 

Input : N = 4        
        k1 = 2    k2 = 2
Output : 3
Explanation :
Possible ways to arrange are,
k1, k2, k1, k2
k1, k1, k2, k2
k2, k1, k1, k2 
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
We can solve this problem using dynamic programming. Let dp[i] stores the number of ways to arrange first i colored items. For one colored item answer will be one because there is only one way. Now Let’s assume all items are in a sequence. Now, to go from dp[i] to dp[i + 1], we need to put at least one item of color (i + 1) at the very end, but the other items of color (i + 1) can go anywhere in the sequence. The number of ways to arrange the item of color (i + 1) is combination of (k1 + k2 .. + ki + k(i + 1) – 1) over (k(i + 1) – 1) which can be represented as (k1 + k2 .. + ki + k(i + 1) – 1)C(k(i + 1) – 1). In this expression we subtracted one because we need to put one item at the very end.
In below code, first we have calculated the combination values, you can read more about that from here. After that we looped over all different color and calculated the final value using above relation.

C++
filter_none
edit
play_arrow

brightness_4
// C++ program to find number of ways to arrange 
// items under given constraint 
#include <bits/stdc++.h> 
using namespace std; 
  
// method returns number of ways with which items  
// can be arranged 
int waysToArrange(int N, int K, int k[]) 
{ 
    int C[N + 1][N + 1]; 
    int i, j; 
  
    // Calculate value of Binomial Coefficient in  
    // bottom up manner 
    for (i = 0; i <= N; i++) { 
        for (j = 0; j <= i; j++) { 
  
            // Base Cases 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
  
            // Calculate value using previously  
            // stored values 
            else
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]); 
        } 
    } 
  
    // declare dp array to store result up to ith  
    // colored item 
    int dp[K]; 
  
    // variable to keep track of count of items  
    // considered till now 
    int count = 0; 
  
    dp[0] = 1; 
  
    // loop over all different colors 
    for (int i = 0; i < K; i++) { 
  
        // populate next value using current value  
        // and stated relation 
        dp[i + 1] = (dp[i] * C[count + k[i] - 1][k[i] - 1]); 
        count += k[i]; 
    } 
  
    // return value stored at last index 
    return dp[K]; 
} 
  
// Driver code to test above methods 
int main() 
{ 
    int N = 4; 
    int k[] = { 2, 2 }; 
  
    int K = sizeof(k) / sizeof(int); 
    cout << waysToArrange(N, K, k) << endl; 
    return 0; 
    }
