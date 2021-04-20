
https://leetcode.com/problems/sparse-matrix-multiplication/



311. Sparse Matrix Multiplication
Medium

637

247

Add to List

Share
Given two sparse matrices mat1 of size m x k and mat2 of size k x n, return the result of mat1 x mat2. You may assume that multiplication 
is always possible.

 

Example 1:


Input: mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]
Output: [[7,0,0],[-7,0,3]]
Example 2:

Input: mat1 = [[0]], mat2 = [[0]]
Output: [[0]]
 

Constraints:

m == mat1.length
k == mat1[i].length == mat2.length
n == mat2[i].length
1 <= m, n, k <= 100
-100 <= mat1[i][j], mat2[i][j] <= 100
  
  
  
  
  
  
  typedef unordered_map<int, vector<pair<int, int>>> SparseMatrix;
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {        
        return multiplySparseMatrix(toSparseMatrix(A), toSparseMatrix(B),  A.size(), B[0].size());
    }
    
    SparseMatrix toSparseMatrix(vector<vector<int>>& matrix) {
        SparseMatrix sm;
        for(int i = 0 ; i < matrix.size() ; ++i)
            for(int j = 0 ; j < matrix[0].size() ; ++j)
                if(matrix[i][j]) sm[i].push_back({j, matrix[i][j]});
        return sm;
    }
    
    vector<vector<int>> multiplySparseMatrix(SparseMatrix mA, SparseMatrix mB, int height, int width) {
        vector<vector<int>> result(height, vector<int>(width, 0));
        for(auto item : mA) {
            for(auto& [k, a] : item.second) {
                for(auto& [j, b] : mB[k]) {
                    result[item.first][j] += a*b;
                }
            }
        }
        return result;
    }
 
  
