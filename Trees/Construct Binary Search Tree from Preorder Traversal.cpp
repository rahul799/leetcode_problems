1008. Construct Binary Search Tree from Preorder Traversal

Add to List

Share
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct.



class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size()-1);        
    }
    TreeNode* helper(vector<int>& preorder, int left, int right){
         
        if(left > right) return nullptr;
        TreeNode* root = new TreeNode(preorder[left]);
        if(left == right) return root;
       
        int idx = left + 1;
        while(idx <= right && preorder[idx] < preorder[left]) idx++;
        root->left = helper(preorder, left+1, idx - 1);
        root->right = helper(preorder, idx, right);
            return root; 
        }  
    
    
};
