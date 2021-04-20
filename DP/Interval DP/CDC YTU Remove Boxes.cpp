


546. Remove Boxes
Hard

819

56

Add to List

Share
You are given several boxes with different colors represented by different positive numbers.

You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.

Return the maximum points you can get.

 

Example 1:

Input: boxes = [1,3,2,2,2,3,4,3,1]
Output: 23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)
Example 2:

Input: boxes = [1,1,1]
Output: 9
Example 3:

Input: boxes = [1]
Output: 1
 

Constraints:

1 <= boxes.length <= 100
1 <= boxes[i] <= 100





class Solution {
public:
    int removeBoxes(vector<int>& boxes)
    {
        int dp[100][100][100] = {0};    // number of boxes would not exceed 100
        int n = boxes.size();
        return operate(boxes, 0, n-1, 0, dp);   // in the closed interval [0, n-1]
    }

    int operate(vector<int>& boxes, int i, int j, int k, int dp[100][100][100])
    {
        // [i, j] is the operating closed interval
        // k is the number of adjacent boxes on the left of boxes[i] with the same value
        if (i>j) return 0;
        if (dp[i][j][k]>0) return dp[i][j][k];

        // start with boxes[i] and interval [i+1, j]
        int res = (k+1)*(k+1) + operate(boxes, i+1, j, 0, dp);
        for (int m=i+1; m<=j; m++)
        {
            // if boxes[i]==boxes[m], we can thus eliminate interval [i+1, m-1]
            // to make boxes[i] and boxes[m] adjacent to have a higher score
            if (boxes[i]==boxes[m])
                // if boxes[i] and boxes[m] are adjacent, then
                // there will be k+1 boxes on the left of boxes[m] with the same value
                res = max( res, operate(boxes, i+1, m-1, 0, dp)+operate(boxes, m, j, k+1, dp) );
        }
        dp[i][j][k] = res;
        return res;
    }
};
As we can see, the score is quadratic, thus the bigger box section with same value, the higher score. The straightforward DP solution is pretty clear by testing each possible 
elimination and solving the subproblems, but it is infeasible since it will lead to TLE.

The trick is, by eliminate some certain boxes, some bigger box sections can be adjacent and eliminated. For example, for boxes 3, 3, 1, 3, 3, we can eliminate 1 to make all 
the 3 adjacent to eliminate and get higher score.

For the algorithm, dp[i][j][k] means the highest score from the closed interval [i, j], with k means the number of adjacent boxes on the left of boxes[i] with the same value
of boxes[i]. For any intermediate number m in [i, j], we test if boxes[i]==boxes[m]. If so, by eliminate interval [i+1, m-1], we can make boxes[i] and boxes[m] adjacent to get 
a bigger box section with same value, and thus a chance to get higher score. Thus we can seperate the interval into two parts and we
just need to pay attention to the change of k.
