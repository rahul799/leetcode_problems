The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.






The reason it checks (x + j == y + i || x + y == i + j || x == i):

Every time we find a existing 'Q', 3 conditions need to be met before we can place a new 'Q' in the new column:

no confict in columns : self explanatory as we put 'Q' col by col.
no confict in rows : x == i
no conflict in diagonals : Math.abs(x-i) == Math.abs(y-j)
For Math.abs(x-i) == Math.abs(y-j),
if x > i, y > j , x - i = y - j => x + j = y + i
if x < i, y < j, i - x = j - y => x + j = y + i
if x > i, y < j, x - i = j - y => x + y = i + j
if x < i, y > j, i - x = y - j => x + y = i + j




class Solution {
public:
    bool isSafe(vector<string>& board, int r, int c, int n)
    {   // no confict in rows : x == i
        for(int i=0;i<n;++i)
            if(board[i][c]=='Q')
                return false;
        
        for(int i=0;i<n;++i)
        {
            if(r-i>=0 && c+i<n && board[r-i][c+i]=='Q')
                    return false;
            if(r+i<n && c-i>=0 && board[r+i][c-i]=='Q')
                    return false;
            if(r+i<n && c+i<n && board[r+i][c+i]=='Q')
                return false;
            if(r-i>=0&&c-i>=0 && board[r-i][c-i]=='Q')
                return false;                
        }
        return true;
    }  
    void solveNQ(vector<string>&board, int r, int n, vector<vector<string>>&ans)
    {
        if(n==r)
            ans.push_back(board);
    // here i am starting from row 0 and traversing all the columns
   //  no confict in columns : self explanatory as we put 'Q' col by col.
        for(int c=0;c<n;++c)
        {
            if(isSafe(board, r, c, n))
            {   
                board[r][c]='Q';
                solveNQ(board,r+1,n,ans);
                board[r][c]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>>ans;
        solveNQ(board,0,n,ans);
        return ans;
    }
};
