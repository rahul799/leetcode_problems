662. Maximum Width of Binary Tree
Medium


Share
Given a binary tree, write a function to get the maximum width of the given tree. The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int result = 1;
        queue<pair<TreeNode*, int>> Q;
        Q.push({root, 0});
        while(!Q.empty()){
            int count = Q.size();
            int start = Q.front().second;
            int end = Q.back().second;
            result = max(result, end-start+1);
            for(int i = 0; i < count; ++i){
                pair<TreeNode*, int> p = Q.front();
                // we are doing this to prevent integer overflow
                int idx = p.second - start;
                Q.pop();
                if(p.first->left) Q.push({p.first->left, 2*idx+1});
                if(p.first->right) Q.push({p.first->right, 2*idx+2});
            }
            
        }
        return result;
    }

    
};






// The idea is to use heap indexing:

//         1
//    2         3
//  4   5     6   7
// 8 9 x 11  x 13 x 15
// Regardless whether these nodes exist:

// Always make the id of left child as parent_id * 2;
// Always make the id of right child as parent_id * 2 + 1;
// So we can just:

// Record the id of left most node when first time at each level of the tree during an pre-order run.(you can tell by check the size of the container to hold the first nodes);
// At each node, compare the distance from it the left most node with the current max width;
