Tic Tac Toe
Implement the tic-tac-toe game with the following methods:

TicTacToe(int n) which instantiates an n x n game board. A player wins a game if their pieces either form a horizontal, vertical, or diagonal line of length n.
int move(int r, int c, boolean me) which places the next move at row r and column c. me indicates whether it's my move (me = true) or it's your opponent's (me = false) move. If this move makes you win, return 1, if your opponent wins, return -1, and otherwise return 0.
Constraints

1 ≤ n ≤ 100,000
0 ≤ m ≤ 100,000 where m is the number of calls to move
Example 1
Input
methods = ["constructor", "move", "move", "move", "move", "move"]
arguments = [[3], [0, 0, true], [2, 0, false], [0, 1, true], [2, 1, false], [0, 2, true]]`
Output
[null, 0, 0, 0, 0, 1]
Explanation
t = TicTacToe(3)
t.move(0, 0, True) == 0 # I place piece (0, 0)
t.move(2, 0, False) == 0 # Opponent places piece (2, 0)
t.move(0, 1, True) == 0 # I place piece (0, 1)
t.move(2, 1, False) == 0 # Opponent places piece (2, 1)
t.move(0, 2, True) == 1 # I place piece (0, 2) to win




Intuition
Use a counter for each player for the row, column and both diagonals. After every move, update the counters and check whether the winning condition is met.

Implementation
We can use winner = 2 * me - 1 to generalize both cases (I win, or the opponent wins).

Time Complexity
The time complexity of each move is \mathcal{O}(1)O(1) since we do a constant number of \mathcal{O}(1)O(1) hash table operations.

Space Complexity
The space complexity is \mathcal{O}(n)O(n) due to the hash table.

class TicTacToe {
    int n;
    unordered_map<int, int> row[2], col[2], diag[2], cross[2];

    public:
    TicTacToe(int n) : n(n) {
    }

    int move(int r, int c, bool me) {
        int winner = 2 * me - 1;
        if (++row[me][r] == n) return winner;
        if (++col[me][c] == n) return winner;
        if (++diag[me][r + c] == n) return winner;
        if (++cross[me][r - c] == n) return winner;
        return 0;
    }
};
