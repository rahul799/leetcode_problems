
1382. Balance a Binary Search Tree

Add to List

Share
Given a binary search tree, return a balanced binary search tree with the same node values.

A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

If there is more than one answer, return any of them.

 

Example 1:



Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2,null,null] is also correct.
 

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The tree nodes will have distinct values between 1 and 10^5.






class Solution {
public:
    vector<TreeNode*> sortArr;
    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL) return nullptr;
        inorder(root);
        return sortedArrayToBST(0, sortArr.size() - 1);
        
    }
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        sortArr.push_back(root);
        inorder(root->right);
    }
    
    TreeNode* sortedArrayToBST(int start, int end){
        if(start > end) return nullptr;
        int mid = (start + end)/2;
        TreeNode* root = sortArr[mid];
        root->left = sortedArrayToBST(start, mid -1);
        root->right = sortedArrayToBST(mid + 1, end);
        return root;
    }
    
};
