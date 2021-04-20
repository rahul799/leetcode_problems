


https://leetcode.com/problems/binary-tree-upside-down/

156. Binary Tree Upside Down
Medium

330

1020

Add to List

Share
Given the root of a binary tree, turn the tree upside down and return the new root.

You can turn a binary tree upside down with the following steps:

The original left child becomes the new root.
The original root becomes the new right child.
The original right child becomes the new left child.


The mentioned steps are done level by level, it is guaranteed that every node in the given tree has either 0 or 2 children.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: [4,5,2,null,null,3,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree will be in the range [0, 10].
1 <= Node.val <= 10
Every node has either 0 or 2 children.
















class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        /** the left most node, when backtrack we need to set the parent node left & right point to null **/
        if(!root || !root->left) return root;
        /** record the current left & right node before DFS **/
        TreeNode* cur_left = root->left;
        TreeNode* cur_right = root->right;
        /** DFS call to build the right sub tree **/
        TreeNode* new_root = upsideDownBinaryTree(root->left);
        cur_left->right = root;
        cur_left->left = cur_right;
        /** now the root node become the child node, so we need to clear the left & right sub node to avoid cycles**/
        root->left = nullptr;
        root->right = nullptr;
        return new_root;
    }
};
Here is a graph that can help you grasp the key ideas by one step of the algorithm:

                          1                                               4 
                        /     \                 ----->                 /    \
                      2       3                                       5    c(2)
                    /    \                                                 /  \ 
                  c(4)    5                                              n     n

                    root = 4                                       root = 2
Now let us check the Non-Recursive Solution

The idea is to record the parent node and child sibling node of the current node and assign them level by level ...

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        /** cur   : record the current root node 
         * parent : record the parent node of the current node
         * right  : record the right child node of the parent node 
         * next   : record the next level left child node **/
        TreeNode* cur = root;
        TreeNode* parent = NULL;
        TreeNode* right = NULL;
        TreeNode* next = NULL;
        while(cur != NULL) {
            next = cur->left;
            /** set the cur->left point to right and cur->right point to parent **/
            cur->left = right;
            right = cur->right;
            cur->right = parent;
            parent = cur;
            /** move left down to the next node **/
            cur = next;
        }
        return parent;
    }
};
