Sum of Nodes with Even Grandparent Values
Given a binary tree root, return the sum of all node values whose grandparents have an even value.

Constraints

0 ≤ n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize
root =


Output
15
Explanation
Nodes 6, 7, and 2 have an even value grandparent.





/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
Keep Track of parent and grandparent node and do a DFS traversal of the tree and whenever you found that grandparent's value is even then add the current value's to the count.

Implementation
Initiate count to zero and start traversal from root. (Root have no parent and grandparent).

In the traversal method,

If the current node is null, then return.
If grandparent is there and is even value, then add current node value to count.
Traverse left and right. Now current node will be parent and parent will be grandparent.
Time Complexity
\mathcal{O}(n)O(n) Iteration over all the node once

Space Complexity
\mathcal{O}(\log n )O(logn) Atmost log n nodes will be on the stack


  void traverse(Tree* current, Tree* parent, Tree* grandparent, int& count) {
        if (current == NULL)
            return;
        if (grandparent != NULL && grandparent->val % 2 == 0) {
            count += current->val;
        }
        traverse(current->left, current, parent, count);
        traverse(current->right, current, parent, count);
    }
int solve(Tree* root) {
        int count = 0;
        traverse(root, NULL, NULL, count);
        return count;
}
