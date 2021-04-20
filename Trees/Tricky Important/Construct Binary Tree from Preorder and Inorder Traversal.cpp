

105. Construct Binary Tree from Preorder and Inorder Traversal
Medium

4492

116

Add to List

Share
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7


class Solution {
private:
    // start and end variables indicate the start of the inorder index and the end of the inorder index respectively. 
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int start, int end, int &index, unordered_map<int, int> dict) {
        if (start > end) return NULL;
    
        TreeNode *node = new TreeNode(preorder[index]);
        int i = dict[preorder[index++]];
        node -> left = helper(preorder, inorder, start, i - 1, index, dict);
        node -> right = helper(preorder, inorder, i + 1, end, index, dict);
        return node;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        unordered_map<int, int> dict;
        
        // Store all the inorder indices to get start and end for each node's left and right nodes
        for (int i = 0; i < inorder.size(); ++i) 
            dict[inorder[i]] = i;
        
        
        return helper(preorder, inorder, 0, preorder.size() - 1, index, dict);
    }
};







class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //         1
        //       2    3
        //     4  5  6
        //            7
        // preorder: root, left, right
        //   1 2 4 5 3 6 7
        // inorder: left, root, right
        //   4 2 5 1 6 7 3
        //
        // observations
        // 1. the 1st number of preorder is always root
        // followed by all numbers in left subtree, then all numbers in right subtree
        // 2. the corresponding index of root in inorder can be used to determine size of left/right subtree
        
        int treeSize = preorder.size();
        if (treeSize == 0) {
            return NULL;
        }
        
        // build a hash table for fast lookup
        unordered_map<int, int> iIndexMap;
        for (int i = 0; i < treeSize; i++) {
            iIndexMap[inorder[i]] = i;
        }
        
        return buildTreeRecur(preorder, 0, inorder, 0, treeSize, iIndexMap);
    }
    TreeNode* buildTreeRecur(vector<int>& preorder, int pBegin, vector<int>& inorder, int iBegin, int treeSize, unordered_map<int, int>& iIndexMap) {
        // given a subtree defined by preorder[pBegin, pEnd] and inorder[iBegin, iEnd]
        // construct the subtree and return its root
        int rootVal = preorder[pBegin];
        TreeNode* root = new TreeNode(rootVal);
        if (treeSize == 1) {
            return root;
        }
        
        int iIndex = iIndexMap[rootVal];
        int leftSize = iIndex - iBegin;
        int rightSize = treeSize - leftSize - 1;
        if (leftSize > 0) {
            root->left = buildTreeRecur(preorder, pBegin + 1, inorder, iBegin, leftSize, iIndexMap);
        }
        if (rightSize > 0) {
            root->right = buildTreeRecur(preorder, pBegin + 1 + leftSize, inorder, iIndex + 1, rightSize, iIndexMap);
        }
        return root;
    }
};

