54. Spiral Matrix
Medium

2587

579

Add to List

Share
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]



// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
//     }
// };


class Solution {
 public:
vector<int> spiralOrder(const vector<vector<int> > &A) {
     if (A.empty() || A[0].empty())
             return {};
    int T,B,L,R,dir;
    T=0;
    B=A.size()-1;
    L=0;
    R=A[0].size()-1;
    dir=0;
    int i;
    vector<int> ans;
    
    while(T<=B && L<=R)
    {
        if(dir==0)
        {
            for(i=L;i<=R;i++)
                ans.push_back(A[T][i]);
            T++;
        }
        else if(dir==1)
        {
            for(i=T;i<=B;i++)
                ans.push_back(A[i][R]);
            R--;
        }
        else if(dir==2)
        {
            for(i=R;i>=L;i--)
                ans.push_back(A[B][i]);
            B--;
        }
        else if(dir==3)
        {
            for(i=B;i>=T;i--)
                ans.push_back(A[i][L]);
            L++;
        }
        dir=(dir+1)%4;
    }
    return ans;
}
    };
















// class Solution {
// public:
//     // O(mn)
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         if (matrix.empty() || matrix[0].empty())
//             return {};
        
//         vector<int> res, dx{0, 1, 0, -1}, dy{1, 0, -1, 0};
//         int m = matrix.size(), n = matrix[0].size(), d = 0, x = 0, y = 0;
//         for (int k = 0; k < m * n; ++k) {
//             res.push_back(matrix[x][y]);
//             matrix[x][y] = 0;
//             int i = x + dx[d], j = y + dy[d];
//             if (i < 0 || i >= m || j < 0 || j >= n || !matrix[i][j]) {
//                 d = (d + 1) % 4;
//                 i = x + dx[d];
//                 j = y + dy[d];
//             }
//             x = i;
//             y = j;
//         }
//         return res;
//     }
// };
