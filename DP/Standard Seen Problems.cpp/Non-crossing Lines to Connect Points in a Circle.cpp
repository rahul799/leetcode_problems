Non-crossing lines to connect Points in a circle
Given n (n is even) points on the circumference of the circle, the task is to find the number of ways to connect these points such that no two connecting 
lines cross each other and every point is connected with exactly 
one other point.



Brute Force Approach
This is the most simple approach. We just have to find all the ways to connect points and count the ones which satisfies condition given in the question. But before doing so, let’s analyze the time complexity of this approach:

**Initially, we have n points, hence,
number of ways to form first line = nC2
**Now, we are left with n-2 points, hence,
number of ways to form second line = n-2C2
And so on, if we are left n-r points, then, 
number of ways to form (r/2+1)th line = n-rC2
Clearly Number of ways to connect all points = 
               product of number of ways to form (r/2+1)th line where r = 2*k and r < n
If you evaluate the expression we just found and consider its upper bound, then, time complexity of this algorithm will be of order nn which is monstrously bad. If you don’t understand the maths involved in founding upper bounds and combinatorics, then, it is total fine. You can simply ignore the last section.
So, until now, we had seen that brute force approach won’t work even for n>20, hence, we need to find an efficient approach. This is where dynamic programming comes into the picture.




Dynamic Programming Solution
I am going to repeat the fact that our game of solving problems using dynamic programming is an universal constant. We will play our game of guessing what is happening, what can or what cannot happen? Now, if you tried this problem, then, you would have observed that if we connect two points to make a line, then, that line divide circle into 2 independent sections of points. When I say independent, I mean that you can’t connect 2 points in different sections. Because if we do so, then, it will intersect the line with which we made the section. So you can see that we can divide the problem into subproblems as follows:
For n points, total number of lines we can make is m=n/2. Now, we can choose a line such that it divides circle into 2 sections such that in first section we can make i lines and in second section, we can make m-i-1 lines. If ans(m) denotes the number of ways to form m non intersecting lines, then, following result can be obtained easily:

ans(m) = sum of ans(i)*ans(m-i-1) where m > i
Obviously, we need a base case to stop this recursion. As you know that if number of lines, i.e., m is 0 or 1, then, number of ways to make non-intersecting lines will be 1. Hence, ans(0) = 1 and ans(1) = 1 can act as our base cases.

Memoization
Clearly, our algorithm is still running in exponential time due to overlapping of sub problems which you can easily observe by constructing recursion tree for m=10. In fact, we can create a 1-d array to store the values returned by all the n distinct function calls. Hence, our final algorithm after memoization will look like as follows:

ans(m) = 1 if m=0 or m=1,
         sum of ans(i)*ans(m-i-1) where m > i
         
         
#include <bits/stdc++.h>

using namespace std;

int dp[1001];

int count(int m) {
    
    if (m<=1) return dp[m] = 1;
    if (dp[m] != -1) return dp[m];
    
    int sum = 0;
    for (int i=0; i<m; i++) sum += count(i)*count(m-i-1);
    return dp[m] = sum; 
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<=n; i++) dp[i] = -1;
    
    if (n%2) cout << 0 << "\n";
    else cout << count(n/2) << "\n";
}
