Count all unique outcomes possible by performing S flips on N coins
Last Updated : 17 Mar, 2021
Given two positive integers N and S, the task is to count the number of unique outcomes possible when S flip operations are performed on N coins.

Examples:

Input: N = 3, S = 4
Output: 3
Explanation: Considering the intiial configuration of coins to be “HHH”, then the possible combinations of 4 flips are:

Flipping the 1st and 2nd coins once and the third coin twice modifies the configuration to “TTH”.
Flipping the 1st and 3rd coins once and the 2nd coin twice modifies the configuration to “THT”.
Flipping the 2nd and 3rd coins once and the 1st coin twice modifies the configuration to “HTT”.
The above three combinations are unique. Therefore, the total count is 3.

Input: N = 3, S = 6
Output: 4



Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Naive Approach: The given problem can be solved by using recursion whose recursive state is defined as:

Consider F(N, S) represents the number of unique outcomes when N coins are tossed with the total number of flips equals to S.
Then F(N, S) can also be expressed as the sum of all combinations with 1 flip or 2 flips i.e.,
F(N, S) = F(N – 1, S – 1) + F(N – 1, S – 2)

The base case for this recurrence relation is F(K, K) whose value is 1 for all (K > 1).
Below is the table that shows the distribution of F(N, S) = F(N – 1, S – 1) + F(N – 1, S – 2), where F(K, K) = 1.


Follow the below steps to solve the problem:

Declare a function, say numberOfUniqueOutcomes(N, S) that takes the number of coins and flips allowed as the parameters respectively and perform the following steps:
If the value of S is less than N, then return 0 from the function.
If the value of N is S or 1, then return 1 from the function as this is one of the unique combinations.
Recursively return summation of the two recursive states as:
return numberOfUniqueOutcomes(N – 1, S – 1) + numberOfUniqueOutcomes(N – 1, S – 2)

After completing the above steps, print the value returned by the function numberOfUniqueOutcomes(N, S) as the resultant number of outcomes.
Below is the implementation of the above approach:


// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to recursively count the
// number of unique outcomes possible
// S flips are performed on N coins
int numberOfUniqueOutcomes(int N, int S)
{
    // Base Cases
    if (S < N)
        return 0;
    if (N == 1 || N == S)
        return 1;
 
    // Recursive Calls
    return (numberOfUniqueOutcomes(N - 1, S - 1)
            + numberOfUniqueOutcomes(N - 1, S - 2));
}
 
// Driver Code
int main()
{
    int N = 3, S = 4;
 
    cout << numberOfUniqueOutcomes(N, S);
 
    return 0;
}








Time Complexity: O(2N)
Auxiliary Space: O(N)

Efficient Approach: The above approach can also be optimized by storing the recursive states as it contains overlapping subproblems. Therefore, the idea is to use memoization to store the repeated states. Follow the steps below to solve the problem:

Initialize a 2D array, say dp[][] of dimensions N*M such that dp[i][j] stores the number of possible outcomes using i coins and j number of flips.
Declare a function, say numberOfUniqueOutcomes(N, S), that takes the number of coins and flips allowed as the parameters respectively and perform the following steps:
If the value of S is less than N, then update the value of dp[N][S] as 0 and return this value from the function.
If the value of N is S or 1, then update the value of dp[N][S] as 1 and return this value from the function as this is one of the unique combinations.
If the value of dp[N][S] is already calculated, then return the value dp[N][S] from the function.
Recursively update the value of dp[N][S] summation of the two recursive states as shown below and return this value from the function.
dp[N][S] = numberOfUniqueOutcomes(N – 1, S – 1) + numberOfUniqueOutcomes(N – 1, S – 2)

After completing the above steps, print the value returned by the function numberOfUniqueOutcomes(N, S) as the resultant number of outcomes.
Below is the implementation of the above approach:


// C++ program for the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
// Dimensions of the DP table
#define size 1001
 
// Stores the dp states
int ans[size][size] = { 0 };
 
// Function to recursively count the
// number of unique outcomes possible
// by performing S flips on N coins
int numberOfUniqueOutcomes(int n, int s)
{
    // Base Case
    if (s < n)
        ans[n][s] = 0;
 
    else if (n == 1 || n == s)
        ans[n][s] = 1;
 
    // If the count for the current
    // state is not calculated, then
    // calculate it recursively
    else if (!ans[n][s]) {
        ans[n][s] = numberOfUniqueOutcomes(n - 1,
                                           s - 1)
                    + numberOfUniqueOutcomes(n - 1,
                                             s - 2);
    }
 
    // Otherwise return the
    // already calculated value
    return ans[n][s];
}
 
// Driver Code
int main()
{
    int N = 5, S = 8;
 
    cout << numberOfUniqueOutcomes(N, S);
 
    return 0;
}
