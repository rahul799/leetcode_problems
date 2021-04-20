class BSTIterator {
public:
    std::stack<TreeNode*> stk;
    
    void fillStack(TreeNode *root) {
        if(root == nullptr)
            return;
        stk.push(root);
        fillStack(root->left);
    }
    
    BSTIterator(TreeNode* root) {
        fillStack(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *currNode = stk.top();
        stk.pop();
        fillStack(currNode->right);
        return currNode->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(stk.empty())
            return false;
        return true;
    }
};
