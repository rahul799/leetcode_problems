

https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/discuss/146808/C%2B%2BJavaPython-One-Pass







865. Smallest Subtree with all the Deepest Nodes
Medium

1075

278

Add to List

Share
Given the root of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is tree consisting of that node, plus the set of all descendants of that node.

Note: This question is the same as 1123: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

 

Example 1:

nput: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest nodes of the tree.
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.
Example 2:

Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree.
Example 3:

Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.
 

Constraints:

The number of nodes in the tree will be in the range [1, 500].
0 <= Node.val <= 500
The values of the nodes in the tree are unique.














Write a sub function deep(TreeNode root).
Return a pair(int depth, TreeNode subtreeWithAllDeepest)

In sub function deep(TreeNode root):

if root == null,
return pair(0, null)

if left depth == right depth,
deepest nodes both in the left and right subtree,
return pair (left.depth + 1, root)

if left depth > right depth,
deepest nodes only in the left subtree,
return pair (left.depth + 1, left subtree)

if left depth < right depth, deepest nodes only in the right subtree,  return pair (right.depth + 1, right subtree)




class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root)
            return root;
        pair<TreeNode*, int> result = helper(root, 0);
        return result.first;
    }
    
    pair<TreeNode*, int> helper(TreeNode* root, int depth){
        if(!root)
            return pair<TreeNode*, int>(NULL, 0);
        
        if (!root->left && !root->right){
            return pair<TreeNode*, int>(root, 1);
        }
        auto lpair = helper(root->left, depth);
        auto rpair = helper(root->right, depth);
        if (lpair.second == rpair.second){
            return pair<TreeNode*, int> ( root, lpair.second+1);
        }
        else if(lpair.second > rpair.second){
            return pair<TreeNode*, int> ( lpair.first, lpair.second+1);
        }
        else{
            return pair<TreeNode*, int> ( rpair.first, rpair.second+1);
        }
    }
};
