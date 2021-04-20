
348. Design Tic-Tac-Toe
Medium

933

66

Add to List

Share
Assume the following rules are for the tic-tac-toe game on an n x n board between two players:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves are allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Implement the TicTacToe class:

TicTacToe(int n) Initializes the object the size of the board n.
int move(int row, int col, int player) Indicates that player with id player plays at the cell (row, col) of the board. The move is guaranteed to be a valid move.
Follow up:
Could you do better than O(n2) per move() operation?

 

Example 1:

Input
["TicTacToe", "move", "move", "move", "move", "move", "move", "move"]
[[3], [0, 0, 1], [0, 2, 2], [2, 2, 1], [1, 1, 2], [2, 0, 1], [1, 0, 2], [2, 1, 1]]
Output
[null, 0, 0, 0, 0, 0, 0, 1]

Explanation
TicTacToe ticTacToe = new TicTacToe(3);
Assume that player 1 is "X" and player 2 is "O" in the board.
ticTacToe.move(0, 0, 1); // return 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

ticTacToe.move(0, 2, 2); // return 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

ticTacToe.move(2, 2, 1); // return 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

ticTacToe.move(1, 1, 2); // return 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

ticTacToe.move(2, 0, 1); // return 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

ticTacToe.move(1, 0, 2); // return 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

ticTacToe.move(2, 1, 1); // return 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
 

Constraints:

2 <= n <= 100
player is 1 or 2.
1 <= row, col <= n
(row, col) are unique for each different call to move.
At most n2 calls will be made to move.






To keep track of which player, I add one for Player1 and -1 for Player2. There are two additional variables to keep track of the count of the diagonals. 
ach time a player places a piece we just need to check the count of that row, column, diagonal and anti-diagonal.


Naive :

There are four strikes that can win for you. Row, Col, Diagonal, Anti-Diagonal.
Diagonal: row == col. Anti-Diagonal: row+col=self.n-1. Use this condition to check diagonal and anti-diagonal.
O(N) solution: At every move, test each strike if they have the same player. This will be like 4 times N.




Optimized Solution : 

O(1) solution: Keep 2 arrays nrow and ncol. Keep 2 variables diagonal and anti_diagonal.
nrow[i] = [player_index, count] and similarly ncol[i] = [player_index, count]. At each move, there is a win with respect to row if the current player is row[i,0] and its previous count is N-1. Similarly, we can derive a condition for col win.
if row == col, then we test the diagonal variable whether it stored the current player and whether its previous count was N-1.
if row+col =N-1, then we check the anti-diagonal.



class TicTacToe {
    vector<int> rows;
    vector<int> cols;
    int score, diag, antiDiag;
public:
    TicTacToe(int n) : score(n), diag(0), antiDiag(0){
        rows = vector<int>(n,0);
        cols = vector<int>(n,0);   
    }

    int move(int row, int col, int player) {
        int point = (player == 1) ? 1:-1;
        rows[row] += point;
        cols[col] += point;
        if(row == col)
            diag += point;
        if(row + col == score - 1)
            antiDiag += point;
        int c = point*score;
        if (rows[row] == c || cols[col] == c || diag == c || antiDiag == c)
            return player;
        return 0;   
    }
};
