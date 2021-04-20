99. Recover Binary Search Tree

Add to List

Share
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

class Solution {
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* prev = NULL;
    long preVal = LONG_MIN; // int min was showing error 
public:
    void recoverTree(TreeNode* root) {
        help(root);
        swap(first->val, second->val);
    }
    
    void help(TreeNode* root){
        if(root==NULL)  return;
        help(root->left);
        if(first==NULL && preVal >= root->val)   first=prev;
        if(first!=NULL && preVal >= root->val)   second=root;
        prev=root;
        preVal=prev->val;
        help(root->right);
    }
};
