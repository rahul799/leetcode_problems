
1110. Delete Nodes And Return Forest
Medium

1506

49

Add to List

Share
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest.  You may return the result in any order.

 

Example 1:



Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
 

Constraints:

The number of nodes in the given tree is at most 1000.
Each node has a distinct value between 1 and 1000.
to_delete.length <= 1000
to_delete contains distinct values between 1 and 1000.




   vector<TreeNode*> result;
    set<int> to_delete_set;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int i : to_delete)
            to_delete_set.insert(i);
        helper(root, result, to_delete_set, true);
        return result;
    }

    TreeNode* helper(TreeNode* node, vector<TreeNode*>& result, set<int>& to_delete_set, bool is_root) {
        if (node == NULL) return NULL;
        bool deleted = to_delete_set.find(node->val) != to_delete_set.end();
        if (is_root && !deleted) result.push_back(node);
        node->left = helper(node->left, result, to_delete_set, deleted);
        node->right =  helper(node->right, result, to_delete_set, deleted);
        return deleted ? NULL : node;
    }
    
    
    
 
 
 
 
 class Solution {
    unordered_set<int> del;
    vector<TreeNode *> res;
    
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(const int &x: to_delete)    del.insert(x);
        
        dfs(root);
        // if main tree root is not to be deleted then add that remaining tree to result
        if(root != nullptr && del.count(root->val) == 0)    res.push_back(root);
        return res;
    }
    
    // traverse down to leaf nodes and check hashset to delete nodes and add children to result recursively
    void dfs(TreeNode *&root) {
        if(root == nullptr)     return;
        
        dfs(root->left);
        dfs(root->right);
        
        if(root != nullptr && del.count(root->val) == 1) {
            if(root->left != nullptr)   res.push_back(root->left);
            if(root->right != nullptr)  res.emplace_back(root->right);
            root = nullptr;
        }
    }
};
