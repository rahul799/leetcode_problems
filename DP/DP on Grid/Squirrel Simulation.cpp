573. Squirrel Simulation
Medium



https://leetcode.com/problems/squirrel-simulation/



263

29

Add to List

Share
There's a tree, a squirrel, and several nuts. Positions are represented by the cells in a 2D grid. Your goal is to find the minimal distance for the squirrel to collect all the nuts and put them under the tree one by one. The squirrel can only take at most one nut at one time and can move in four directions - up, down, left and right, to the adjacent cell. The distance is represented by the number of moves.
Example 1:

Input: 
Height : 5
Width : 7
Tree position : [2,2]
Squirrel : [4,4]
Nuts : [[3,0], [2,5]]
Output: 12
Explanation:
​​​​​
Note:

All given positions won't overlap.
The squirrel can take at most one nut at one time.
The given positions of nuts have no order.
Height and width are positive integers. 3 <= height * width <= 10,000.
The given positions contain at least one nut, only one tree and one squirrel.



/**
 * find out the minimum distance dist[i] to all nuts, and the dist_sum;
 * if Squirrel is start at the tree, then the min distance to collect all nuts would be 2 * dist_sum;
 * but most likely, it is not at the tree, Squirrel need to go to a nuts, then come to the tree single-trip, the round trip to the rest nuts.
 * The sum would be : dist_sum + (dist_Squirrel_to_nut[I] - dist_nut[I]-to-tree), and we want the latter to be minimal.
 * 
 */
class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int sum = 0;
        int minextra = INT_MAX; // nut with the minimal (nut2squirrel - nut2tree)
        for (vector<int> nut : nuts) {
            int nut2tree = dist(nut, tree);
            int nut2squirrel = dist(nut, squirrel);
            sum += nut2tree;
            minextra = min(minextra, nut2squirrel - nut2tree);
        }
        return 2 * sum + minextra;
    }

private:
    int dist(vector<int> a, vector<int> b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

};
