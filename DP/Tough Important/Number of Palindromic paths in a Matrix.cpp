Number of palindromic paths in a matrix

https://procoderforu.com/palindromic-paths-in-a-matrix/



http://geeksforgeeks.org/number-of-palindromic-paths-in-a-matrix/

Given a matrix containing lower alphabetical characters only, we need to count number of palindromic paths in given matrix. A path is defined as a sequence 
of cells starting from top-left cell and ending at bottom-right cell. We are allowed to move to right and down only
from current cell.




Key observation is there are four possibilities to reach from top left to bottom right depening upon the first step and last step you take



#include <bits/stdc++.h>

using namespace std;

#define N 3
#define M 4

int dp[N+1][M+1][N+1][M+1];
string S[N]; // matrix is represented by a string here

int path(int bi, int bj, int ci, int cj)
{
    if (bi>ci || bj>cj || S[bi-1][bj-1] != S[ci-1][cj-1]) return 0;

    if (abs(bi-ci) + abs(bj-cj) == 1) return 1;

    if (dp[bi][bj][ci][cj] != -1) return dp[bi][bj][ci][cj];

    return dp[bi][bj][ci][cj] = path(bi+1, bj, ci-1, cj) +
                                path(bi+1, bj, ci, cj-1) +
                                path(bi, bj+1, ci-1, cj) +
                                path(bi, bj+1, ci, cj-1);

}

int main()
{
    
    S[0] = "aaab", S[1] = "baaa", S[2] = "abba";
    memset(dp, -1, sizeof(dp));
    
    path(1, 1, N, M);
    
    cout << dp[1][1][N][M] << endl;

    // output is 3
    
    return 0;
}
