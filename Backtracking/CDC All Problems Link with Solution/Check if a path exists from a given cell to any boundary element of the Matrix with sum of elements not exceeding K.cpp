


Check if a path exists from a given cell to any boundary element of the Matrix with sum of elements not exceeding K




Check if a path exists from a given cell to any boundary element of the Matrix with sum of elements not exceeding K
Difficulty Level : Expert
Last Updated : 31 Mar, 2021
Given a matrix grid[][] of dimensions M * N, three integers X, Y, and K, the task is to check if there exists any path from the cell (X, Y) to any boundary cell of the matrix such that sum of the matrix elements present in the path is at most K. If no such path exists, print “No”. Otherwise, print “Yes”. Possible moves from any cell are up, down, left, or right.

Examples:

Input: grid[][] = {{25, 5, 25, 25, 25, 25},  {25, 1, 1, 5, 12, 25}, {25, 1, 12, 0, 15, 25}, {22, 1, 11, 2, 19, 15}, {25, 2, 2, 1, 12, 15}, {25, 9, 10, 1, 11, 25}, {25, 25, 25, 25, 25, 25}}, X = 2, Y = 3, K = 17
Output: Yes
Explanation:
Below image illustrates one of the possible ways to reach a boundary element of the given matrix from the cell (2, 3):
 



The concerned path is (2, 3) -> (3, 3) -> (4, 3) -> (4, 2) -> (4, 1) -> (3, 1) -> (2, 1) -> (1, 1).
The cost of the path = 0 + 2 + 1 + 2 + 2 + 1 + 1 + 1 + 0 = 15(  < K).



Input: grid[][] = {{1, 2, 3}, {1, 2, 3}, {3, 4, 5}}, X = 1, Y = 1, K = 0
Output: -1

Approach: The given problem can be solved by using Backtracking to consider all possible paths from the given starting cell, and check if there exists any path up to a boundary cell of the given matrix having the sum of its constituent elements equal to K or not. 

Follow the steps below to solve the problem:

Define a recursive function, say findPath(X, Y, K, board), to check if there exists any path from the starting cell (X, Y) to any boundary element or not.
Base Case: If X < 0 or Y < 0 or X >= M or Y >= N is reached, then return true.
Now, check if grid[X][Y] >= K or not. If found to be true, then mark the current cell visited. Decrement K by the value of grid[X][Y] and then visit the unvisited adjacent cells, i.e. recursively call for findPath(X + 1, Y, K), findPath(X, Y + 1, K), findPath(X – 1, Y, K), and findPath(X, Y – 1, K).
If any of the above recursive calls return true, then return true from the current recursive call.
Otherwise, mark the current cell as unvisited.
If none of the above conditions satisfy, then return false from the current recursive call.
Now, if the function findPath(X, Y, K) returns true, then print “Yes”. Otherwise, print “No”.
Below is the implementation of the above approach:


// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
  
// Function to check if it is valid
// to move to the given index or not
bool isValid(vector<vector<int> >& board,
             int i, int j, int K)
{
    if (board[i][j] <= K) {
        return true;
    }
  
    // Otherwise return false
    return false;
}
  
// Function to check if there exists a
// path from the cell (X, Y) of the
// matrix to any boundary cell with
// sum of elements at most K or not
bool findPath(vector<vector<int> >& board,
              int X, int Y,
              int M, int N, int K)
{
  
    // Base Case
    if (X < 0 || X == M
        || Y < 0 || Y == N) {
        return true;
    }
  
    // If K >= board[X][Y]
    if (isValid(board, X, Y, K)) {
  
        // Stores the current element
        int board_XY = board[X][Y];
  
        // Mark the current cell as visited
        board[X][Y] = INT_MAX;
  
        // Visit all the adjacent cells
        if (findPath(board, X + 1, Y, M,
                     N, K - board_XY)
            || findPath(board, X - 1, Y, M,
                        N, K - board_XY)
            || findPath(board, X, Y + 1, M,
                        N, K - board_XY)
            || findPath(board, X, Y - 1, M,
                        N, K - board_XY)) {
            return true;
        }
  
        // Mark the cell unvisited
        board[X][Y] = board_XY;
    }
  
    // Return false
    return false;
}
  
// Driver Code
int main()
{
    vector<vector<int> > grid = {
        { 25, 5, 25, 25, 25, 25 },
        { 25, 1, 1, 5, 12, 25 },
        { 25, 1, 12, 0, 15, 25 },
        { 22, 1, 11, 2, 19, 15 },
        { 25, 2, 2, 1, 12, 15 },
        { 25, 9, 10, 1, 11, 25 },
        { 25, 25, 25, 25, 25, 25 }
    };
  
    int K = 17;
    int M = grid.size();
    int N = grid[0].size();
    int X = 2, Y = 3;
  
    if (findPath(grid, X, Y, M, N, K))
        cout << "Yes";
    else
        cout << "No";
  
    return 0;
}
