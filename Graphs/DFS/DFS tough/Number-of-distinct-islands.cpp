


https://leetcode.com/problems/number-of-distinct-islands/



694. Number of Distinct Islands
Medium

1190

73

Add to List

Share
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all
four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal
the other.

Example 1:
11000
11000
00011
00011
Given the above grid map, return 1.
Example 2:
11011
10000
00001
11011
Given the above grid map, return 3.

Notice that:
11
1
and
 1
11
are considered different island shapes, because we do not consider reflection / rotation.






class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        unordered_set<string> islands;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    string island;
                    distinct(grid, i, j, i, j, island);
                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }
private:
    void distinct(vector<vector<int>>& grid, int i, int j, int r, int c, string& island) {
        int m = grid.size(), n = grid[0].size();
        if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c]) {
            grid[r][c] = 0;
            island += to_string(r - i) + to_string(c - j);
            distinct(grid, i, j, r - 1, c, island);
            distinct(grid, i, j, r + 1, c, island);
            distinct(grid, i, j, r, c - 1, island);
            distinct(grid, i, j, r, c + 1, island);
        }
    }
};



Complexity Analysis

Let MM be the number of rows, and NN be the number of columns.

Time Complexity : O(M \cdot N)O(M⋅N).

We're inserting each cell into a hash table (corresponding to the island it is a part of), and then inserting each of those hash tables into another hash table.

The cost of inserting each of the M \cdot NM⋅N cells into its initial hash table is O(1)O(1), so those insertions have a total complexity of O(M \cdot N)O(M⋅N).

To insert the "island" hash tables into the final hash table, each of them has to (within the library code) be hashed by a hash function. While often we assume that the process 
of hashing is O(1)O(1), in this we can't as the inputs to be hashed could be arbitrarily large. So instead, the cost of hashing them is linearly proportional to the number of cells in the hash table being hashed. Each cell is essentially getting hashed once in this process too though (as each can only be a part of one island), and so this part is also O(M \cdot N)O(M⋅N).

As both phases have a time complexity of O(M \cdot N)O(M⋅N), this is the total time complexity.

Be aware that the time complexity of this approach is dependent on a good hash function. The built-in hash functions for Java and Python seem okay, but I recommend being 
very careful. A poor hash function would lead to performance comparable to Approach 1.

Space complexity : O(M \cdot N)O(M⋅N). The seen set is the biggest use of additional memory.







Approach 1: Brute Force
Intuition

Assume we've already used a DFS to make a list of islands, where each island is represented as a list of coordinates. We now need to determine how many of these 
islands actually have a unique shape.

Since two islands are the same if one can be translated to the other, we can translate each island so that it is as pushed as far into the top left as possible. By doing
this, two islands that are the same shape, but in different locations, will now have identical coordinates. For example, if an island is made from
cells [(2, 1), (3, 1), (1, 2), (2, 2)], it would become [(1, 0), (2, 0), (0, 1), (1,1)] when anchored at the top-left corner.

The 4-cell island described above is moved as far up and left as possible.

Similarly, the island made from cells [(2, 0), (3, 0), (1, 1), (2, 1)] will also become [(1, 0), (2, 0), (0, 1), (1,1)].

The 4-cell island described above is moved as far up and left as possible.

Algorithm

Use DFS to make a list of islands, where each island is a list of coordinates.
Initialize a count of the number of unique islands to 0.
For each island, compare it cell-by-cell to every other island. If it is found to be unique, increment count by 1.
Return the value of count.
Order doesn't matter, so the two islands [(0, 1), (0, 2)] and [(0, 2), (0, 1)] should be considered as identical. However, we can avoid the need to worry about order by ensuring that two islands of the same shape are initially discovered from the same relative cell. Then from there, the DFS will always visit the cells in the same relative order. This is easy to do: we can simply search for islands by iterating left to right, top to bottom. This way, each island will always be discovered from the leftmost cell in its top row. The diagram below shows the first cell discovered for each island, using this traversal order. Notice that islands of the same shape are first discovered from the same relative cell.

Various islands, and their first cell that will be discovered is marked.

We can also make one other clever observation: we can simply translate each island so that the first cell of the island that is discovered is on (0, 0). If, for example, an island contains the cells [(2, 3), (2, 4), (2, 5), (3, 5)], we subtract (2, 3) off each cell to get [(0, 0), (0, 1), (0, 2), (1, 2)].






Complexity Analysis

Time Complexity: O(M^2 \cdot N^2)O(M 
2
 ⋅N 
2
 ).

In the worst case, we would have a large grid, with many unique islands all of the same size, and the islands packed as closely together as possible. This would mean
that for each island we discover, we'd be looping over the cells of all the other islands we've discovered so far. For example, here's a grid with M = 10M=10, N = 10N=10, 
and islands all
of size 5.



