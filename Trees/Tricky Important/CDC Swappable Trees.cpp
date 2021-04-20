

Swappable Trees
Given two trees root0 and root1, return whether you can transform root0 into root1 by swapping any node's left and right subtrees any number of times.

Example 1
Input
Visualize
root0 =
1

3

4

0

2

root1 =
1

3

4

0

2

Output
true





/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool solve(Tree* root0, Tree* root1) {
    if (!root0 && !root1) return true;

    if (!root0 || !root1) return false;

    if (root0->val != root1->val) return false;

    return solve(root0->left, root1->right) && solve(root0->right, root1->left) ||
           solve(root0->left, root1->left) && solve(root0->right, root1->right);
}
