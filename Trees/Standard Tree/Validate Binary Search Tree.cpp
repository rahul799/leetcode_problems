Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6
    




class Solution {
public:
    bool valid(TreeNode *node,long min,long max)
    {
         if (node==NULL)  
        return true;  
              
 
    if (node->val < min || node->val > max)  
        return false;  
      
   
    return
        valid(node->left, min, (long)((long)node->val-1)) && // Allow only distinct values  
        valid(node->right, (long)((long)node->val+1), max); // Allow only distinct values 
    }
    bool isValidBST(TreeNode* node) 
    {
       return valid(node,LONG_MIN,LONG_MAX);
    }
};  
