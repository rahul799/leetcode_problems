1038. Binary Search Tree to Greater Sum Tree
Medium

836


Given the root of a binary search tree with distinct values, modify it so that every node has a new value equal to the sum of the values of the original tree that are greater than or equal to node.val.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


We need to do the work from biggest to smallest, right to left.
pre will record the previous value the we get, which the total sum of bigger values.
For each node, we update root.val with root.val + pre.




class Solution {
public:
    int sum=0;
    TreeNode* bstToGst(TreeNode* root) {
        helper(root);
        return root;
    }
    
    void helper(TreeNode* r) {
        if(r==NULL) return;
        bstToGst(r->right);
        r->val+=sum;
        sum=r->val;
        bstToGst(r->left);
    }
    
};
