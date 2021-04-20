

https://www.geeksforgeeks.org/find-rectangle-binary-matrix-corners-1/

Find if there is a rectangle in binary matrix with corners as 1




Find if there is a rectangle in binary matrix with corners as 1
Difficulty Level : Hard
 Last Updated : 01 Feb, 2021
There is a given binary matrix, we need to find if there exists any rectangle or square in the given matrix whose all four corners are equal to 

Examples: 

Input :
mat[][] = { 1 0 0 1 0
            0 0 1 0 1
            0 0 0 1 0
            1 0 1 0 1}
Output : Yes
as there exists-
1 0 1
0 1 0
1 0
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Brute Force Approach- 

We start scanning the matrix whenever we find a 1 at any index then we try for all the combinations for index with which we can form the rectangle. 
algorithm– 

for i = 1 to rows
  for j = 1 to columns
   if matrix[i][j] == 1
     for k=i+1 to rows
       for l=j+1 to columns
         if (matrix[i][l]==1 &&
             matrix[k][j]==1 &&
             m[k][l]==1)
                return true
return false







// An efficient approach based CPP program to
// find if there is a rectangle with 1 as
// corners.
#include <bits/stdc++.h>
using namespace std;
 
// Returns true if there is a rectangle with
// 1 as corners.
bool isRectangle(const vector<vector<int> >& matrix)
{
    // finding row and column size
    int rows = matrix.size();
    if (rows == 0)
        return false;
 
    int columns = matrix[0].size();
 
    // map for storing the index of combination of 2 1's
    unordered_map<int, unordered_set<int> > table;
 
    // scanning from top to bottom line by line
    for (int i = 0; i < rows; ++i) {
 
        for (int j = 0; j < columns - 1; ++j) {
            for (int k = j + 1; k < columns; ++k) {
 
                // if found two 1's in a column
                if (matrix[i][j] == 1 && matrix[i][k] == 1) {
 
                    // check if there exists 1's in same
                    // row previously then return true
                    // we don't need to check (j, k) pair
                    // and again (k, j) pair because we always
                    // store pair in ascending order and similarly
                    // check in ascending order, i.e. j always less
                    // than k.
                    if (table.find(j) != table.end()
                        && table[j].find(k) != table[j].end())
                        return true;
 
                    // store the indexes in hashset
                    table[j].insert(k);
                }
            }
        }
    }
    return false;
}
 
// Driver code
int main()
{
    vector<vector<int> > mat = { { 1, 0, 0, 1, 0 },
                                 { 0, 1, 1, 1, 1 },
                                 { 0, 0, 0, 1, 0 },
                                 { 1, 1, 1, 1, 0 } };
    if (isRectangle(mat))
        cout << "Yes";
    else
        cout << "No";
}
// This code is improved by Gautam Agrawal
