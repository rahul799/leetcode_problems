

218. The Skyline Problem
Hard

2586

147

Add to List

Share
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.

The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:

lefti is the x coordinate of the left edge of the ith building.
righti is the x coordinate of the right edge of the ith building.
heighti is the height of the ith building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

Note: There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]

 

Example 1:


Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
Explanation:
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.
Example 2:

Input: buildings = [[0,2,3],[2,5,3]]
Output: [[0,3],[5,0]]
 

Constraints:

1 <= buildings.length <= 104
0 <= lefti < righti <= 231 - 1
1 <= heighti <= 231 - 1
buildings is sorted by lefti in non-decreasing order.



Approach 1: Divide and Conquer
Solution Template

The problem is a classical example of divide and conquer approach, and typically implemented exactly the same way as merge sort algorithm.

Let's follow here a solution template for divide and conquer problems :

Define the base case(s).

Split the problem into subproblems and solve them recursively.

Merge the subproblems solutions into the problem solution.

Algorithm

getSkyline for n buildings :

If n == 0 : return an empty list.

If n == 1 : return the skyline for one building (it's straightforward).

leftSkyline = getSkyline for the first n/2 buildings.

rightSkyline = getSkyline for the last n/2 buildings.

Merge leftSkyline and rightSkyline.

Now let's discuss each step in more details.

Base Cases

The first base case is an empty buildings list. Then the skyline is an empty list, too.

The second base case is the only one building in the list, when the skyline construction is quite straightforward.

bla

How to split the problem

The idea is the same as for merge sort : at each step split the list exactly in two parts : from 0 to n/2 and from n/2 to n, and then construct the skylines recursively for each part.

bla

How to merge two skylines

The algorithm for merge function is quite straightforward and based on the same merge sort logic : the height of an output skyline is always a maximum between the left and right skylines.

bla

Let's use here two pointers pR and pL to track the current element index in both skylines, and three integers leftY, rightY, and currY to track the current height for the left skyline, right skyline and the merged skyline.

mergeSkylines (left, right) :

currY = leftY = rightY = 0

While we're in the region where both skylines are present (pR < nR and pL < nL) :

Pick up the element with the smallest x coordinate. If it's an element from the left skyline, move pL and update leftY. If it's an element from the right skyline, move pR and update rightY.

Compute the largest height at the current point : maxY = max(leftY, rightY).

Update an output skyline by (x, maxY) point, if maxY is not equal to currY.

While there are still elements in the left skyline (pL < nL), process them following the same logic as above.

While there are still elements in the right skyline (pR < nR), process them following the same logic as above.

Return output skyline.

Here are three usecases to illustrate the merge algorithm execution






class Solution {
 public :
    vector <pair< int , int >> getSkyline(vector<vector< int >>& buildings) {
        vector <pair< int , int >> h, res;
        multiset < int > m;
         int pre = 0 , cur = 0 ;
         for (auto &a : buildings) {
            h.push_back({a[ 0 ], -a[ 2 ]});
            h.push_back({a[ 1 ], a[ 2 ]});
        }
        sort(h.begin(), h.end());
        m.insert( 0 );
         for (auto &a : h) {
             if (a.second < 0 ) m.insert(- a.second);
             else m.erase(m.find(a.second));
            cur = * m.rbegin();
             if (cur != pre) {
                res.push_back({a.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};



                                                 
                                                 
                                                 
  class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> skyline;
        map<int, vector<pair<int, int>>> map; // key : pos, value : vector of <height, start|end> pairs
        for (auto& building : buildings) {
            map[building[0]].push_back({building[2], 0}); // add startpoint
            map[building[1]].push_back({building[2], 1}); // add endpoint
        }
        multiset<int> q;
        for (auto& [pos, heights] : map) {
            for (auto& [height, type] : heights) {
                if (type == 0) q.insert(height);
                else q.erase(q.find(height));
            }
            int newHeight = q.empty() ? 0 : *q.rbegin();
            if (!skyline.empty() && skyline.back()[1] == newHeight) continue;
            else skyline.push_back(vector<int>({pos, newHeight}));
        }
        return skyline;
    }
};
















class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> edges;
        int left, right, height;
        for(int i=0; i<buildings.size(); i++){
            left=buildings[i][0];
            right=buildings[i][1];
            height=buildings[i][2];
            /*** make sure : for the same left point we use the bigger height ***/
            edges.push_back(make_pair(left, -height));
            edges.push_back(make_pair(right, height));
        }
        sort(edges.begin(), edges.end());
        vector<vector<int>> result;
        /*** use the multiset to store the max height util current pos ***/
        multiset<int> m;
        /*** left most height ***/
        m.insert(0);
        int pre=0, cur=0;
        for(int i=0; i<edges.size(); i++){
            pair<int, int> e=edges[i];
            if(e.second < 0)  m.insert(-e.second);
            else m.erase(m.find(e.second));
            cur=*(m.rbegin());
            if(cur!=pre){
                result.push_back(make_pair(e.first, cur));
                pre=cur;
            }
        }
        return result;
    }
};
                                                 
                                                 
                                                 
                                                 
                                                 



vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        // use walls to record buildings; left wall is an insertion event, and right wall is a deletion event
        vector<pair<int, int>> walls, ans;                  // first: x, second: height
        for (auto b : buildings) {
            // push in left / right walls
            // let left wall has negative height to ensure left wall goes to multiset first if with same 'x' as right wall
            walls.push_back(make_pair(b[0], -b[2]));
            walls.push_back(make_pair(b[1], b[2]));
        }
        sort(walls.begin(), walls.end());                   // sort walls
        
        multiset<int> leftWallHeights = {0};                // keep left wall heights sorted; dummy '0' for convenience
        int top = 0;                                        // current max height among leftWallHeights
        for (auto w : walls) {
            if (w.second < 0) {                             // it's a left wall, insert the height
                leftWallHeights.insert(-w.second);
            } else {                                        // it's a right wall, delete the height
                leftWallHeights.erase(leftWallHeights.find(w.second));
            }
            
            if (*leftWallHeights.rbegin() != top) {         // mark a skyline point if top changes
                ans.push_back(make_pair(w.first, top = *leftWallHeights.rbegin()));
            }
        }
        
        return ans;
}
