



120. Triangle
Medium

2499

281

Add to List

Share
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number on the row below.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?






class Solution {
public:
  
int minimumTotal1(vector<vector<int>>& triangle) {
    vector<int> res(triangle.size(), triangle[0][0]);
    for (unsigned int i = 1; i < triangle.size(); i++) 
        for (int j = i; j >= 0; j--) {
            if (j == 0)
                res[0] += triangle[i][j];
            else if (j == i)
                res[j] = triangle[i][j] + res[j-1];
            else 
                res[j] = triangle[i][j] + min(res[j-1], res[j]);
        }
    return *min_element(res.begin(), res.end());
}
};




class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int level = triangle.size() - 2; level >= 0; --level) {
            for(int offset = 0; offset <= level; ++offset) {
                triangle[level][offset] += min(triangle[level+1][offset],
                                              triangle[level+1][offset+1]);
            }
        }
        return triangle[0][0];
    }
};





