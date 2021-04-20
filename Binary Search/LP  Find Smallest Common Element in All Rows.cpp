1198. Find Smallest Common Element in All Rows



Given a matrix mat where every row is sorted in strictly increasing order, return the smallest common element in all rows.

If there is no common element, return -1.

 

Example 1:

Input: mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
Output: 5




Algorithm:

Iterate through the first row in O(C) time.
Check if current element is common -- search for it in every other row in O(RlogC) time.
First common element is an answer, because rows are sorted




nt smallestCommonElement(vector<vector<int>>& mat) {
        // corner case
        if (mat.size() == 1)
            return mat[0][0];
			
        for (int v : mat[0]) {
            bool is_common = true;
            for (auto &row : mat) {
                // Note: first row wasn't skipped for simplicity 
                if (!binary_search(begin(row), end(row), v)) {
                    is_common = false;
                    break;
                }                    
            }
            if (is_common)
                return v;
        }
        return -1;
    }
