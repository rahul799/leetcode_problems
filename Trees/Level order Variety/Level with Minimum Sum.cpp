Level with Minimum Sum
Question 184 of 991
Given a binary tree tree, return the level of the tree with minimum sum. Note that the level of a tree starts at 0.

Constraints

n ≤ 100,000 where n is the number of nodes in tree
Example 1
Input
Visualize
root =
2

0

1

Output
1
Explanation
Level 1 has the lowest sum.

Example 2
Input
Visualize
r



Explanation
Level 0 has sum of -2
Level 1 has sum of 2
Level 2 has sum of 3
Level 3 has sum of 9








int solve(Tree* root) {
    int minLevel = 0;
    int minSum = INT_MAX;
    queue<Tree*> q;
    q.push(root);
    int currLevel = 0;
    while (!q.empty()) {
        int length = q.size();
        int currSum = 0;
        for (int i = 0; i < length; i++) {
            Tree* node = q.front();
            q.pop();
            currSum += node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        if (currSum < minSum) {
            minSum = currSum;
            minLevel = currLevel;
        }

        currLevel += 1;
    }

    return minLevel;
}
