
1220. Count Vowels Permutation
Hard




https://www.geeksforgeeks.org/count-all-possible-n-length-vowel-permutations-that-can-be-generated-based-on-the-given-conditions/





https://leetcode.com/problems/count-vowels-permutation/


268

49

Add to List

Share
Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
Example 2:

Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
Example 3: 

Input: n = 5
Output: 68
 

Constraints:

1 <= n <= 2 * 10^4

Intuition
We have the following statements:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Let

0 -> a, 1 -> e, 2 -> i, 3 -> o, 4 -> u
We have the following graph relationship:

0 -> {1}
1 -> {0,2}
2 -> {0,1,3,4}
3 -> {2,4}
4 -> {0}
Let dp[n][char] denotes the number of strings of length n starting at char.
Hence, dp[n+1][u] = sum of all dp[n][v] such that there is a directed connection from u to v (u -> v).


 Approach: The idea to solve this problem is to visualize this as a Graph Problem. From the given rules a directed graph can be constructed, where an edge from u to v means that v can be immediately written after u in the resultant strings. The problem reduces to finding the number of N-length paths in the constructed directed graph. Follow the steps below to solve the problem:



Let the vowels a, e, i, o, u be numbered as 0, 1, 2, 3, 4 respectively, and using the dependencies shown in the given graph, convert the graph into an adjacency list relation where the index signifies the vowel and the list at that index signifies an edge from that index to the characters given in the list.


Initialize a 2D array dp[N + 1][5] where dp[N][char] denotes the number of directed paths of length N which end at a particular vertex char.
Initialize dp[i][char] for all the characters as 1, since a string of length 1 will only consist of one vowel in the string.
For all possible lengths, say i, traverse over the directed edges using variable u and perform the following steps:
Update the value of dp[i + 1][u] as 0.
Traverse the adjacency list of the node u and increment the value of dp[i][u] by dp[i][v], that stores the sum of all the values such that there is a directed edge from node u to node v.
After completing the above steps, the sum of all the values dp[N][i], where i belongs to the range [0, 5), will give the total number of vowel permutations.
Below is the implementation of the above approach:

C++
filter_none
edit
play_arrow

brightness_4
// C++ program for the above approach 
#include <bits/stdc++.h>
using namespace std;
 
// Function to find the number of 
// vowel permutations possible 
int countVowelPermutation(int n)
{
     
    // To avoid the large output value
    int MOD = (int)(1e9 + 7);
 
    // Initialize 2D dp array
    long dp[n + 1][5];
     
    // Initialize dp[1][i] as 1 since
    // string of length 1 will consist
    // of only one vowel in the string
    for(int i = 0; i < 5; i++)
    {
        dp[1][i] = 1;
    }
     
    // Directed graph using the
    // adjacency matrix
    vector<vector<int>> relation = {
        { 1 }, { 0, 2 },
        { 0, 1, 3, 4 },
        { 2, 4 }, { 0 }
    };
 
    // Iterate over the range [1, N]
    for(int i = 1; i < n; i++) 
    {
         
        // Traverse the directed graph
        for(int u = 0; u < 5; u++)
        {
            dp[i + 1][u] = 0;
 
            // Traversing the list
            for(int v : relation[u])
            {
                 
                // Update dp[i + 1][u]
                dp[i + 1][u] += dp[i][v] % MOD;
            }
        }
    }
 
    // Stores total count of permutations
    long ans = 0;
 
    for(int i = 0; i < 5; i++) 
    {
        ans = (ans + dp[n][i]) % MOD;
    }
 
    // Return count of permutations
    return (int)ans;
}
 
// Driver code
int main()
{
    int N = 2;
     
    cout << countVowelPermutation(N);
}
 
// This code is contributed by Mohit kumar 29
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
 
 
 
 
 
 
class Solution {
public:
    int countVowelPermutation(int n) {
        unsigned long long int a=1,e=1,i=1,o=1,u=1;
        unsigned long long int updated_a,updated_e,updated_i,updated_o,updated_u;
        for(int ind=2;ind<=n;ind++)
        {
            updated_a=(e);     // modulo dividing is to handle large values
            updated_e=(a+i)%1000000007;
            updated_i=(a+e+u+o)%1000000007;
            updated_o=(i+u)%1000000007;
            updated_u=(a);
         
            a=updated_a;                   //updating a,e,i,o,u value for each iteration
            e=updated_e;
            i=updated_i;
            o=updated_o;
            u=updated_u;
        }
        return (a+e+i+o+u)%1000000007;
    }
};






class Solution {
public:
    
    // a 0 e 1 i 2 o 3 u 4
    long long int mod =1e9+7;
    
    int countVowelPermutation(int n) {
        long long dp[n][5];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<5;i++)
            dp[0][i]=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<5;j++){
                if(j==0){
                    dp[i][j]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][4])%mod;
                }
                
                if(j==1){
                   dp[i][j]=(dp[i-1][0]+dp[i-1][2])%mod; 
                }
                
                 if(j==2){
                   dp[i][j]=(dp[i-1][1]+dp[i-1][3])%mod; 
                }
                
                 if(j==3){
                   dp[i][j]=(dp[i-1][2])%mod; 
                }
                
                if(j==4){
                   dp[i][j]=(dp[i-1][2]+dp[i-1][3])%mod; 
                }
            }
        }
        return (dp[n-1][0] + dp[n-1][1] + dp[n-1][2] + dp[n-1][3] + dp[n-1][4])%mod;
    }
};
