
1769. Minimum Number of Operations to Move All Balls to Each Box
Medium

93

5

Add to List

Share
You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.

 

Example 1:

Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.
Example 2:

Input: boxes = "001011"
Output: [11,8,5,4,3,4]
 

Constraints:

n == boxes.length
1 <= n <= 2000
boxes[i] is either '0' or '1'.







// Approach -
// The minimum number of moves to move all balls to box[i] will be the number of minimum moves to move balls to moves[i-1] + moves[i+1]
// i.e. box[i] = moveLeft[i-1] + moveRight[i+1]

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> left(boxes.size(), 0), right(boxes.size(), 0), ans(boxes.size(), 0);
        int balls = 0;
        
        balls = boxes[0] - '0';
        for(int i=1;i<boxes.size();i++){
            left[i] = left[i-1] + balls;
            balls += boxes[i] - '0';
        }
        
        balls = boxes[boxes.size()-1] - '0';
        for(int i=boxes.size()-2;i>=0;i--){
            right[i] = right[i+1] + balls;
            balls += boxes[i] - '0';
        }
        
        for(int i=0;i<boxes.size();i++)
            ans[i] = left[i] + right[i];
        
        return ans;
    }
};
