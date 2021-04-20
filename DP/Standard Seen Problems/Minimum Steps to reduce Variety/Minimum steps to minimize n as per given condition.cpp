

Given a number n, count minimum steps to minimize it to 1 according to the following criteria:

If n is divisible by 2 then we may reduce n to n/2.
If n is divisible by 3 then you may reduce n to n/3.
Decrement n by 1.
Examples:

Input : n = 10
Output : 3

Input : 6
Output : 2
  
  
  
  
  Greedy Approach (Doesn’t work always) :
As per greedy approach we may choose the step that makes n as low as possible and continue the same, till it reaches 1.

while ( n > 1)
{
    if (n % 3 == 0)
        n /= 3;    
    else if (n % 2 == 0)
        n /= 2;
    else
        n--;
    steps++;
}
If we observe carefully, the greedy strategy doesn’t work here.
Eg: Given n = 10 , Greedy –> 10 /2 = 5 -1 = 4 /2 = 2 /2 = 1 ( 4 steps ).
But the optimal way is –> 10 -1 = 9 /3 = 3 /3 = 1 ( 3 steps ).
So, we must think of dynamic approach for optimal solution.

Dynamic Approach:
For finding minimum steps we have three possibilities for n and they are:



f(n) = 1 + f(n-1)
f(n) = 1 + f(n/2) // if n is divisible by 2
f(n) = 1 + f(n/3) // if n is divisible by 3
Below is memoization based implementation of above recursive formula.

// CPP program to minimize n to 1 by given 
// rule in minimum steps 
#include <bits/stdc++.h> 
using namespace std; 
  
// function to calculate min steps 
int getMinSteps(int n, int *memo) 
{ 
    // base case 
    if (n == 1) 
       return 0; 
    if (memo[n] != -1) 
       return memo[n]; 
  
    // store temp value for n as min( f(n-1), 
    // f(n/2), f(n/3)) +1 
    int res = getMinSteps(n-1, memo); 
  
    if (n%2 == 0) 
        res = min(res, getMinSteps(n/2, memo)); 
    if (n%3 == 0) 
        res = min(res, getMinSteps(n/3, memo)); 
  
    // store memo[n] and return 
    memo[n] = 1 + res; 
    return memo[n]; 
} 
  
// This function mainly initializes memo[] and 
// calls getMinSteps(n, memo) 
int getMinSteps(int n) 
{ 
    int memo[n+1]; 
  
    // initialize memoized array 
    for (int i=0; i<=n; i++) 
        memo[i] = -1; 
  
    return  getMinSteps(n, memo); 
} 
  
// driver program 
int main() 
{ 
    int n = 10; 
    cout << getMinSteps(n); 
    return 0; 
} 
