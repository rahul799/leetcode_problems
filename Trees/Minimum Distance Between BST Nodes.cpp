783. Minimum Distance Between BST Nodes
Easy

725

204

Add to List

Share
Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \    
    1   3  

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
Note:

The size of the BST will be between 2 and 100.
The BST is always valid, each node's value is an i





class Solution {
  public:
    int res = INT_MAX, pre = -1;
    int minDiffInBST(TreeNode* root) {
        if (root->left != NULL) minDiffInBST(root->left);
        if (pre >= 0) res = min(res, root->val - pre);
        pre = root->val;
        if (root->right != NULL) minDiffInBST(root->right);
        return res;
    }
};
