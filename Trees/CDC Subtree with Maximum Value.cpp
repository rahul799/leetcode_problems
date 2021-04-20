Subtree with Maximum Value
Given a binary tree root, return the maximum sum of a subtree. A subtree is defined to be some node in root including all of its descendants. A subtree sum is the sum of all the node values in the subtree. A subtree can be null in which case its sum is 0.

Constraints

1 ≤ n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize
root =
3

0

2

0

Output
5


int helper(Tree* root, int& ans) {
    if (!root) return 0;
    int currSum = root->val + helper(root->left, ans) + helper(root->right, ans);
    ans = max(ans, currSum);
    return currSum;
}
int solve(Tree* root) {
    int ans = 0;
    helper(root, ans);
    return ans;
}


