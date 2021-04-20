Sparse Matrix Multiplication

Was asked to Chinmay

https://medium.com/@glynnnnnnnnn/sparse-matrix-multiplication-c34ef43c16db



Description
Glyn Liu
Glyn Liu
May 1, 2018·2 min read

Given two Sparse Matrix A and B, return the result of AB. You may assume that A’s column number is equal to B’s row number.
Image for post
Analyses
Suppose the first matrix has shape (m, k) and the second (k, n), the outcome of the matrix multiplication is then (m, n). According to the rule of matrix multiplication — A[i][k] * B[k][j] => C[i][j], for normal matrix multiplication, we can simply calculate the product of the corresponding elements in A and B, and add it to the right entry of C. The complexity of the normal matrix multiplication is O(nmk).
However, for the sparse matrix, we can reduce the complexity to some extent. C[i][j] will be update only when A[i][k] * B[k][j] != 0, which means any of A[i][k] and B[k][j] should not be 0. Thus, we can extract the non-zero element from both matrices A and B, then calculate those elements that their k values are the same.
Implementation
The implementation can be different. Personally, I used the list to store the the B’s none-zero elements, and then go through
A calculating the necessary multiplications.
We need to consider how to store a sparse matrix. Generally if we want to save memory to store the sparse matrix, we only need
to consider the coordinate and the value of the none-zeron elements, like(<x,y>,val). Thus, Hashmap can be a good choise such
as HashMap in Java and dict in Python, but the problem is we need to find the elements with same k value.
One way to solve this problem is using HashMap with k as the key, and a set or a list of (<k,y>, val) as value. If so, we can 
simplify the tuple to become (y, val) since the k already there as the key. Alternatively we can use List<List> in Java, as the key now is the index of the outer list.
Once we transform A and B into the sparse representation, we can iterate through A multiplying by the elements in B with the 
same k value and update the output matrix C. A trick here is that we don’t need actually to transform A, since when iterating
A, we can easily jump over the 0.
Steps
Create a result matrix C for storing the final result
Transform B into sparse representation such as a list of (y, val) pair
Iterate over A, jump over 0s and multiply the elements with the same k in A nd B, at the same time update C
Return C as the final output
Conclusion
The key point is the representation of the sparse matrix and the rule of matrix multiplication, especially the relationship
between the coordinate








class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), n = mat1[0].size(), nb = mat2[0].size();
        vector<vector<int>> res(m, vector<int>(nb));
        
        for (int i = 0; i < m; i++)
        {
            for(int k = 0; k < n; k++)
            {
                if (mat1[i][k] != 0)
                {
                    for (int j = 0; j < nb; j++)
                    {
                        if (mat2[k][j] != 0)
                            res[i][j] += mat1[i][k] * mat2[k][j];    
                    }
                }
            }
        }
        
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size();
        int p = A[0].size();
        int n = B[0].size();
        vector<vector<int>> C(m, vector<int>(n));
        unordered_map<int, int> mp_A;
        unordered_map<int, int> mp_B;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < p; ++j) {
                if (A[i][j] != 0)
                    mp_A[i * p + j] = A[i][j];
            }
        }
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < n; ++j) {
                if (B[i][j] != 0)
                    mp_B[i * n + j] = B[i][j];
            }
        }
        for (const auto& kvp_A : mp_A) {
            int i = kvp_A.first / p;
            int j = kvp_A.first % p;
            for (const auto& kvp_B : mp_B) {
                int u = kvp_B.first / n;
                int v = kvp_B.first % n;
                if (j == u) {
                    C[i][v] += kvp_A.second * kvp_B.second;
                }
            }
        }
        return C;
    }
};


