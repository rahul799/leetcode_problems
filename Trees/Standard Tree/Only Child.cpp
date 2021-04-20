Only Child
Given a binary tree root, return the number of nodes that are an only child. A node x is an only child if its parent has exactly one child (x).

Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize
root =
0

4

2

1

3

Output
2
Explanation
Node 1 is an only child and 3 is an only child.

Example 2
Input
Visualize
root =
1

3

1

1

Output
1
Explanation
Node 3 is an only child



/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
 

    void helper(Tree* node, int& count) {
        if (node->right && !node->left) {
            count++;
        } else if (node->left && !node->right) {
            count++;
        }
        if (node->left) helper(node->left, count);
        if (node->right) helper(node->right, count);
    }
    int solve(Tree* root) {
        if (!root) return 0;
        int count = 0;
        helper(root, count);
        return count;
    }
