112. Path Sum
Easy

2752

573

Add to List

Share
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: false
Example 3:

Input: root = [1,2], targetSum = 0
Output: false
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000





bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        int new_sum = sum - root->val;
        if(!root->left && !root->right) return new_sum==0;
        return hasPathSum(root->left, new_sum) || hasPathSum(root->right, new_sum);
    }







class Solution {
public:
      bool hasPathSum(TreeNode* root, int sum) {
        vector<TreeNode*> my_stack;
        my_stack.emplace_back(root);
        while(!my_stack.empty()){
            root = my_stack.back();
            my_stack.pop_back();
            if(root){
                if(!root->left&&!root->right&&root->val==sum) return true; //check terminating condition only at leaf node 
                if(root->right){
                    root->right->val += root->val;
                    my_stack.emplace_back(root->right);
                }  
                if(root->left){
                    root->left->val += root->val;
                    my_stack.emplace_back(root->left);
                }  
            }
            
        }
        return false;
    }
};
