Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
 
 
 
 
 
 class Solution {
public:
    int height(TreeNode* root){
        if(root== NULL) return 0;
        return max(height(root->left), height(root->right)) +1;
        
    }
    bool isBalanced(TreeNode* root) {
        if(root== NULL) return true;
        
        return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <=1;
    }
};
