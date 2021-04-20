

864. Shortest Path to Get All Keys
Hard

530

19

Add to List

Share
We are given a 2-dimensional grid. "." is an empty cell, "#" is a wall, "@" is the starting point, ("a", "b", ...) are keys, and ("A", "B", ...) are locks.

We start at the starting point, and one move consists of walking one space in one of the 4 cardinal directions.  We cannot walk outside the grid, or walk into a wall.  If we walk over a key, we pick it up.  We can't walk over a lock unless we have the corresponding key.

For some 1 <= K <= 6, there is exactly one lowercase and one uppercase letter of the first K letters of the English alphabet in the grid.  This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

Return the lowest number of moves to acquire all keys.  If it's impossible, return -1.

 

Example 1:

Input: ["@.a.#","###.#","b.A.B"]
Output: 8
Example 2:

Input: ["@..aA","..B#.","....b"]
Output: 6
 

Note:

1 <= grid.length <= 30
1 <= grid[0].length <= 30
grid[i][j] contains only '.', '#', '@', 'a'-'f' and 'A'-'F'
The number of keys is in [1, 6].  Each key has a different letter and opens exactly one lock.
Accepted
15,108
Submissions
35,725







class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        // Dimensions
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Start location
        pair<int, int> start;
        
        // Number of keys
        int K = 0;
        
        // Find start and number of keys
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                char ch = grid[r][c];
                
                if (ch == '@') {
                    start = {r, c};
                } else if (isalpha(ch) && islower(ch)) {
                    ++K;
                }
            }
        }
        
        // Number of unique path states. K keys => 2^K states. Eack key has a unique bit in state.
        // If the key is found on the path then the corresponding bit is set.
        int numStates = 1 << K;
        
        // State when all keys are found
        int endState = numStates - 1;
        
        // Level order traversal. 
        // Visit a node mutiple times for each unique path state
        
        // Current level
        int level = -1;
        
        // All key found
        bool found = false;
        
        // Legal moves
        vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // State visited flag for each node and state
        vector<vector<vector<bool>>> states(rows, vector<vector<bool>>(cols, vector<bool>(numStates, false)));
        
        // Traversal queue - (row, col, path state)
        queue<tuple<int, int, int>> qu;
        
        // Push start node and mark start state - 0 visited
        qu.push(make_tuple(start.first, start.second, 0));
        states[start.first][start.second][0] = true;
        
        // Iterate until nodes to visit and all keys not found
        while (!qu.empty() && !found) {
            ++level;
            
            // Visit nodes at current level
            for (int i = 0, size = qu.size(); i < size; ++i) {
                auto& front = qu.front();
                int state = get<2>(front);
                
                // Break if all keys found
                if (state == endState) {
                    found = true;
                    break;
                }
                
                // Current location
                int r = get<0>(front);
                int c = get<1>(front);
                
                // Schedule neighbors
                for (auto& m: moves) {
                    // Next location
                    int nr = r + m.first; 
                    int nc = c + m.second; 
                    
                    // Out of bound or wall
                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] == '#') {
                        continue;
                    }
                    
                    // Next node was already visited in this state
                    if (states[nr][nc][state]) {
                        continue;
                    } 
                    
                    // Initialize next state
                    int nState = state;
                    
                    // Process next location
                    if (isalpha(grid[nr][nc])) {
                        if (isupper(grid[nr][nc])) {
                            // Lock id
                            int lockid = grid[nr][nc] - 'A';

                            // Treat like wall if key not found on path
                            if (!(state & (1 << lockid))) {
                                continue;
                            } 
                        } else {
                            // Key id
                            int keyid = grid[nr][nc] - 'a';

                            // Update state with key found
                            nState = state | (1 << keyid);
                        }  
                    }
                    
                    // Schedule next node and mark state visited
                    states[nr][nc][nState] = true;
                    qu.push(make_tuple(nr, nc, nState));           
                }
                
                // Pop current node
                qu.pop();
            } 
        }
           
        // Return path length if found
        return found ? level : -1;
    }
};
