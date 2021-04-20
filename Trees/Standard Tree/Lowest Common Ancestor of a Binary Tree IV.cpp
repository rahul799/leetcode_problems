

1676. Lowest Common Ancestor of a Binary Tree IV
Medium

49

1

Add to List

Share
Given the root of a binary tree and an array of TreeNode objects nodes, return the lowest common ancestor (LCA) of all the nodes in nodes. All the nodes will exist in the tree, and all values of the tree's nodes are unique.

Extending the definition of LCA on Wikipedia: "The lowest common ancestor of n nodes p1, p2, ..., pn in a binary tree T is the lowest node that has every pi as a descendant (where we allow a node to be a descendant of itself) for every valid i". A descendant of a node x is a node y that is on the path from node x to some leaf node.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [4,7]
Output: 2
Explanation: The lowest common ancestor of nodes 4 and 7 is node 2.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [1]
Output: 1
Explanation: The lowest common ancestor of a single node is the node itself.

Example 3:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [7,6,2,4]
Output: 5
Explanation: The lowest common ancestor of the nodes 7, 6, 2, and 4 is node 5.
Example 4:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [0,1,2,3,4,5,6,7,8]
Output: 3
Explanation: The lowest common ancestor of all the nodes is the root node.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-109 <= Node.val <= 109
All Node.val are unique.
All nodes[i] will exist in the tree.
All nodes[i] are distinct.








This problem is same as the original LCA problem.
Except, we will check whether the current root is in the given node list, for which LCA is to be found.

If the current root is any of the node in the given node list, return it and check for the LCA (post order traceback to the parent on higher level.)

class Solution { 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<TreeNode*> s;
        for (auto node: nodes) {
            s.insert(node);
        }    
        return lca(root, s);
    }
    
    TreeNode* lca(TreeNode* root, unordered_set<TreeNode*> s) {
        if (root == NULL || s.find(root) != s.end())
            return root;
        
        TreeNode* left  = lca(root->left,  s);
        TreeNode* right = lca(root->right, s);
		
        if (left && right)
            return root;
        if (left)
            return left;
        return right;
    }
};
