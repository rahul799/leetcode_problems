


https://leetcode.com/problems/diagonal-traverse/

498. Diagonal Traverse
Medium

1232

411

Add to List

Share
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 

Example 1:


Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
-105 <= mat[i][j] <= 105







class Solution {
public:
       
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> ans;
        
        for(int i = 0; i < m+n-1; i++){ // i == row index + col index. Range 0 ~ m+n-1
            if(i%2){ // Add values from top to bottom
                for(int r = 0; r <= i && r < m; r++){
                    int c = i - r;
                    if(c < n)
                        ans.push_back(mat[r][c]);
                }        
            }else{ // Add values from bottom to top
                for(int c = 0; c <= i && c < n ; c++){
                    int r = i - c;
                    if(r < m)
                        ans.push_back(mat[r][c]);
                }        
            }
        }
        
        return ans;
    }
};
