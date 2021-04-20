Tree Pruning
Question 80 of 866
Given a binary tree root, prune the tree so that subtrees containing all 0s are removed.


https://binarysearch.com/problems/Tree-Pruning


Given a binary tree root, prune the tree so that subtrees containing all 0s are removed
Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize Tree
root =


Output
Visualize Tree


Explanation
We do not remove the tree at the root or its right child because they still have a 1 as a descendant.



Observe that just a post order traversal and our job is done!!


/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
Tree* solve(Tree* root) {
    if (root == NULL) return root;


    root->left = solve(root->left);
    root->right = solve(root->right);

    if (root->left == root->right && root->val == 0) return NULL;

    return root;
}
