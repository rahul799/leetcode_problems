

1372. Longest ZigZag Path in a Binary Tree
Medium

475

10

Add to List

Share
Given a binary tree root, a ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right then move to the right child of the current node otherwise move to the left child.
Change the direction from right to left or right to left.
Repeat the second and third step until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

 

Example 1:



Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
Example 2:



Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).
Example 3:

Input: root = [1]
Output: 0
 

Constraints:

Each tree has at most 50000 nodes..
Each node's value is between [1, 100].


Longest ZigZag Path in a Binary Tree



class Solution {
public:
    int maxStep = 0;
    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        dfs(root, false, 0);
        return maxStep;
    }
    void dfs(TreeNode* root, bool isLeft, int step) {
        if (!root) return;
        maxStep = max(maxStep, step); // update max step sofar
        if (isLeft) {
            dfs(root->left, false, step + 1); // keep going from root to left
            dfs(root->right, true, 1); // restart going from root to right
        } else {
            dfs(root->right, true, step + 1); // keep going from root to right
            dfs(root->left, false, 1); // restart going from root to left
        }
    }
};
