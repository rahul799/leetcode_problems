


https://atcoder.jp/contests/abc190/submissions/19801375



https://www.geeksforgeeks.org/count-ways-express-number-sum-consecutive-numbers/

Count ways to express a number as sum of consecutive numbers
Difficulty Level : Medium
 Last Updated : 06 Sep, 2019
Given a number N, find the number of ways to represent this number as a sum of 2 or more consecutive natural numbers.

Examples:

Input :15 
Output :3
15 can be represented as:
1+2+3+4+5
4+5+6
7+8

Input :10
Output :1
10 can only be represented as:
1+2+3+4
Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution.
The idea is to represent N as a sequence of length L+1 as:
N = a + (a+1) + (a+2) + .. + (a+L)
=> N = (L+1)*a + (L*(L+1))/2
=> a = (N- L*(L+1)/2)/(L+1)
We substitute the values of L starting from 1 till L*(L+1)/2 < N
If we get 'a' as a natural number then the solution should be counted.

filter_none
edit
play_arrow

brightness_4
// C++ program to count number of ways to express 
// N as sum of consecutive numbers. 
#include <bits/stdc++.h> 
using namespace std; 
  
long int countConsecutive(long int N) 
{ 
    // constraint on values of L gives us the  
    // time Complexity as O(N^0.5) 
    long int count = 0; 
    for (long int L = 1; L * (L + 1) < 2 * N; L++) 
    { 
        float a = (1.0 * N-(L * (L + 1)) / 2) / (L + 1); 
        if (a-(int)a == 0.0)  
            count++;         
    } 
    return count; 
} 
  
// Driver Code 
int main() 
{ 
    long int N = 15; 
    cout << countConsecutive(N) << endl; 
    N = 10; 
    cout << countConsecutive(N) << endl; 
    return 0; 
} 
