230. Kth Smallest Element in a BST


Share
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.





class Solution {
public:
    int i=0;
    void trav(TreeNode* root,int k,int& res)
    {
        if(!root)
            return ;
        trav(root->left,k,res);
        i++;
        if(k==i) res=root->val;
        trav(root->right,k,res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res=0;
        trav(root,k,res);
        return res;
    }
};
