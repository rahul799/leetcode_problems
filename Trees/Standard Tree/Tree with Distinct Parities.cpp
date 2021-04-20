
https://binarysearch.com/room/Weekly-Contest-38-CNs3hGBp9j?questionsetIndex=0

Tree with Distinct Parities
Question 1 of 4
Given a binary tree root, return the number of perfect nodes. A perfect node has two properties:

Has both children
The sum of one subtree is even and the sum of the other subtree is odd
Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize


Output
2
Explanation
Nodes 1 and 3 meet the criteria.

Example 2
Input
Visualize
root =
1

2

3

Output
0
Explanation
No node has both a left and a right child.







/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int dfs(Tree* root, int& ans) {
    if (root == nullptr) return 0;
    int left = dfs(root->left, ans);
    int right = dfs(root->right, ans);
    int a = left & 1;
    int b = right & 1;
    if (root->left && root->right && a + b == 1) ans++;
    return left + right + root->val;
}
int solve(Tree* root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
}
