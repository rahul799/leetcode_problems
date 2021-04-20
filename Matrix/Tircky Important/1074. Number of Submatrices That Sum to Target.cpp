1074. Number of Submatrices That Sum to Target
Hard

863

31

Add to List

Share
Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example,
if x1 != x1'.

 

Example 1:


Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
Example 3:

Input: matrix = [[904]], target = 0
Output: 0
 

Constraints:

1 <= matrix.length <= 100
1 <= matrix[0].length <= 100
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8




class Solution {
public:
 
	// TIME COMPLEXITY:- O(N*M^2)
	// SPACE COMPLEXITY:- O(N*M)
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target)
    {
        int n = mat.size();
        int m = mat[0].size();
 
        // store prefix sum for each row
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
                mat[i][j]+=mat[i][j-1];
        }
 
        int ans = 0;
 
        // map to store prefix sum of rows for a particular range of columns
        unordered_map<int,int> mp;
 
        for(int start=0;start<m;start++)
        {
            for(int end=start;end<m;end++)
            {
                // we are considering columns b/w {start,end}
 
                // clear previous entries
                mp.clear();
 
                mp[0]++;
 
                int sum = 0;
 
                // add sum for each row b/w the given range of columns
 
                for(int i=0;i<n;i++)
                {
                    // add sum for this row b/w {start,end}
 
                    // curr stores sum of current row of matrix b/w given range of columns
                    int curr = mat[i][end];
 
                    if(start>0)
                        curr-=mat[i][start-1];
 
                    // sum of matrix elements upto now b/w given range
                    sum+=curr;
 
                    // increment answers
                    ans+=mp[sum-target];
 
                    mp[sum]++;
                }
 
            }
        }
 
        return ans;
 
    }
};





class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;
        
        for (int i = 0; i < m; i++){                      //Iterating over all possible row ranges between row i and row j
            vector<int> CumulativeColumns = matrix[i];    //Instead of setting up a prefix sum matrix, add to columns as we go row by row
            
            for (int j = i; j < m; j++){
                unordered_map<int,int> sumCount;          //track occurrences of corner matrix sums for the current row range
                int totalSum = 0;
                
                for (int k = 0; k < n; k++){
                    totalSum += CumulativeColumns[k];        //within the current row range, at every row cumulatively build matrix sums using cumulative column sums column by column
                    if (totalSum == target) count++;         //if the target is found or if a sum is found that has a difference with a previous sum in the same top/bottom bounds exactly equal to target, add submatrices found
                    if (sumCount.count(totalSum-target)) count += sumCount[totalSum-target];
                    sumCount[totalSum]++;                    //Store the current cumulative sum to be used later in the row to calculate target matrix counts        
                    if (j < m - 1) CumulativeColumns[k] += matrix[j+1][k];   //Increment the cumulative column sum for the next row iteration in the current row range if necessary
                }
            }
        }
        return count;
    }
};




