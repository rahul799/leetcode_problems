226. Invert Binary Tree
Easy

3531

57

Add to List

Share
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1




class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        swap(root -> left, root -> right);
        invertTree(root -> left);
        invertTree(root -> right);
        return root;
    }
};





class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        
        queue <TreeNode*> level;
            level.push(root);
        while(!level.empty())
        {
            TreeNode* node= level.front();
            level.pop();
            
            swap(root->left, root->right );
            if(node-> left)
                level.push(root->left);
            if(node->right)
                level.push(root->right);
        }
                
              return root;   
        }
       
   
        
        
    };
