Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

We need to determine, if a 9x9 Sudoku board is valid.


Here, [i / 3][j / 3] was done to give you the segment in the block vector to evaluate plus gives you the column inside the segment of the subGrids.

Because by the earlier rules that each row and each column will have non-repeating values, i.e.

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
block[i/3 + j / 3] correctly checks for uniqueness.
Also whenever unique values are there, hashset is the way out



class Solution {
public:

bool isValidSudoku(vector<vector<char>>& board) 
{
		// creating 3 different hashset to maintain the check for rows, cols
		// and sub grid. We just need to check if row, col and subgrid 
		// doesnot have that char.
		
        unordered_set<char> row_visited[9];
        unordered_set<char> col_visited[9];
        unordered_set<char> subGrid_visited[3][3];
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
               char char_found = board[i][j];
			   
			   // if pos is blank then no issues, we had to check when it's not blank.
                if(char_found != '.') 
                {                     
                    if(row_visited[i].count(char_found) || col_visited[j].count(char_found) || subGrid_visited[i/3][j/3].count(char_found))
                        return false;
                }
                
				col_visited[j].insert(char_found);
				row_visited[i].insert(char_found);
				subGrid_visited[i / 3][j / 3].insert(char_found);
                
            }
        }
	 return true;
}
 };
