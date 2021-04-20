200. Number of Islands
Medium

6312

207

Add to List

Share
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3



class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    eraseIslands(grid, i, j);
                }
            }
        }
        return islands;
    }
private:
    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
    }
};







https://leetcode.com/problems/number-of-islands/discuss/640295/Optimized-by-memory-(follow-up-question-what-if-matrix-is-too-big)







There is this follow-up for this task: "what if the input data is too big (and sparse)"

Lets say the input data is such big that we can not even load it in memory so instead we want to read it line-by-line (for example, from file). Lets say we have a method readR(int r) that returns r row of the matrix;
Say currLine is a row we are checking, prevLine - one before it;
Now we can read line-by-line and follow these rules:

if currLine[i-1] && prevLine[i] are not set, we consider i as a start of the new island;
if currLine[i-1] is set but prevLine[i] is not we consider i belongs to island currLine[i-1]
if prevLine[i] is set but currLine[i-1] is not we consider i belongs to island prevLine[i]
if both currLine[i-1] && prevLine[i] are set, we conider i belongs to currLine[i-1] AND we update prevLine[i] island to be currLine[i-1].
For keeping track / updating indices of islands we use Union-Find: keep a map(k,v) where island k is considered connected to island v. When we create a new island, we create k->k record, when updating k, we recursively traverse through all connected islands and update their values to the new one;

code:


public int numIslands(char[][] grid) {
        if (grid.length < 1) return 0;
        int[] firstR = readFirtsR(grid);
        Map<Integer, Integer> sets = new HashMap<>();
        int count = 0;
        // read first row and create first islands:
		// [0 1 0 0 1 0 1] => [0 1 0 0 2 0 3]
		for (int n: firstR) if (n != 0) {
            sets.put(n, n);
            count = n;
        }
        int r = 1;
        while (r < grid.length) {
            char[] line = readR(r, grid);
            int[] secondR = new int[line.length];
            for (int i = 0; i < line.length; i++) {
                if (line[i] == '1') {
                    if (i != 0 && secondR[i - 1] != 0) {
                        secondR[i] = getRoot(secondR[i - 1],sets);
                    }
                    else if (firstR[i] != 0) {
                        secondR[i] = getRoot(firstR[i], sets);
                    }
                    else {
                        count++;
                        secondR[i] = count;
                        sets.put(count, count);
                    }
                    if (firstR[i] != secondR[i] && firstR[i] != 0) {
                        updateRoots(sets.get(firstR[i]), secondR[i], sets);
                    }
                }
            }
            firstR = secondR;
            r++;
        }
        int res = 0;
        for (int k : sets.keySet()) if (sets.get(k) == k) res++;
        return res;
    }
	
    // union-find "find" part
    private int getRoot(int v, Map<Integer, Integer> sets) {
        int k = v;
        while (k != sets.get(k)) k = sets.get(k);
        return k;
    }

    // connect island k to island newVal
    private void updateRoots(int k, int newVal, Map<Integer, Integer> sets) {
        while (k != newVal) {
            int v = sets.get(k);
            sets.put(k, newVal);
            k = v;
        }
    }

    private char[] readR(int i, char[][] grid) {
        return grid[i];
    }

    //  this is ugly and probably can be done better:
	// read first line and connect adjusted '1' 
    private int[] readFirtsR(char[][] grid) {
        int[] first = new int[grid[0].length];
        char[] r = readR(0, grid);
        int count = 1;
        int start = 0;

        while (start < first.length) {
            if (r[start] == '1' &&
                    (start == 0 || r[start - 1] != '1')) first[start] = count++;
            if (start != 0 && r[start] == '1' && r[start - 1] == '1') first[start] = first[start - 1];
            start++;
        }
        return first;
    }
Memory should be O(max(grig[0].length, res))
where res is number of islands. Worst-case res will be n/2 (if islands consist of one-element cells adjusted by diagonals only). Hovewer in case of sparse matrix we can probably assume grig[0].length >> res.

follow-up
