



https://www.cnblogs.com/grandyang/p/8955735.html


773. Sliding Puzzle
Hard

855

28

Add to List

Share
On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

Examples:

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
Input: board = [[3,2,4],[1,5,0]]
Output: 14
Note:

board will be a 2 x 3 array as described above.
board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5]









Then when 0 is at position 0, it can move to the right and bottom, that is, {1, 3} position; at position 1, it can move to the left, right and bottom, that is, {0, 2, 4} position; At position 2, it can be moved to the left and bottom, namely {1, 5} position; at position 3, it can be moved to the upper and right, namely {0, 4} position; at position 4, it can be moved to The left, right and top sides are {1, 3, 5} positions; at position 5, it can be moved to the top and left sides, namely {2, 4} positions.

Then there is the standard BFS process. Use a HashSet to record the visited state, put the initial state start in, use a 
queue to start traversal, and put the initial state start in. Then it is to traverse by layer, take out the state of the 
head of the team, compare it with the target first, return the number of steps directly if it is the same, otherwise find
the position of 0 in the current state, find the next position in dirs, and assign a temporary variable Cand, to exchange 
0 and its next position, generate a new state, if this state is not in visited, then join visited, and press into the queue, 
the number of steps increases by 1. If the while loop does not return to the correct state after exiting, it returns -1, see 
the code as follows


class Solution {
 public :
     int slidingPuzzle(vector<vector< int >>& board) {
         int res = 0 ;
         set <vector<vector< int >>> visited;
        queue <pair<vector<vector< int >>, vector< int >>> q;
        vector <vector< int >> correct{{ 1 , 2 , 3 }, { 4 , 5 , 0 }};
        vector <vector< int >> dirs{{ 0 , -1 }, {- 1 , 0 }, { 0 , 1 }, { 1 , 0 }};
         for ( int i = 0 ; i < 2 ; ++ i ) {
             for ( int j = 0 ; j < 3 ; ++ j) {
                 if (board[i][j] == 0 ) q.push({board, {i, j}});
            }
        }
        while (! q.empty()) {
             for ( int i = q.size()- 1 ; i >= 0 ; - i) {
                auto t = q.front().first;
                auto zero = q.front().second; q.pop();
                 if (t == correct) return res;
                visited.insert(t);
                for (auto dir: dirs) {
                     int x = zero[ 0 ] + dir[ 0 ], y = zero[ 1 ] + dir[ 1 ];
                     if (x < 0 || x >= 2 || y < 0 | | y >= 3 ) continue ;
                    vector <vector< int >> cand = t;
                    swap(cand[zero[ 0 ]][zero[ 1 ]], cand[x][y]);
                     if (visited.count(cand)) continue ;
                    q.push({cand, {x, y}});
                }
            }
            ++ res;
        }
        return - 1 ;
    }



class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = board.size(), n = m ==0? 0 : board[0].size();
        unordered_set<string> st;
        string target = "123450";
        queue<pair<int, string>> qu;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 0) {
                    qu.push({i*n+j, encode(board)});
                    break;
                }
            }
        }
        int steps = 0;
        vector<int> dir = {0, 1, 0, -1, 0};
        while (qu.size()) {
            int sz = qu.size();
            while (sz--) {
                auto cur = qu.front();
                string strBd = cur.second;
                qu.pop();
                if (strBd == target) 
                    return steps;
                if (st.count(strBd))
                    continue;
                st.insert(strBd);
                for (int k = 0; k < 4; ++k) {
                    int ni = cur.first/n + dir[k];
                    int nj = cur.first%n + dir[k+1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                        continue;
                    swap(strBd[cur.first], strBd[ni*n+nj]);
                    qu.push({ni*n+nj, strBd});
                    swap(strBd[cur.first], strBd[ni*n+nj]);
                }
            }
            steps++;
        }
        return -1;
    }
    string encode(vector<vector<int>>& board) {
      string s= "";
      for (auto v : board) 
          for (int i : v) 
              s.push_back(i + '0');
      return s;
    }
};
