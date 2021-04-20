Left Side View of a Tree
Question 187 of 978
Given a binary tree root, return the leftmost node's value on each level of the tree.

Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize
root =
0

5

2

1

Output
[0, 5, 1]



Breadth-First Search (Level Order Traversal)

Traverse the tree by level, and at each level, the first node is always the left most node since we are traversing each level left->right.
We keep an array of left most nodes from each level.





To perform a breadth first traversal, I use a queue.

I use a level_size variable to help me keep track of the level I'm on. At the beginning of each level, I set a leftest variable to True.
Using that variable, as we pop the first node in the Queue, we check if leftest is True (if this is indeed the first node on that level), if it is, we add it to the left_most array, and set leftest to False (since we have traversed the left most node on this level already) and we continue the iteration.



vector<int> solve(Tree* root) {
    vector<int> v;
    queue<Tree*> q;

    q.push(root);

    while (!q.empty()) {
        int s = q.size();

        for (int i = 0; i < s; i++) {
            root = q.front();
            q.pop();
            if (i == 0) {
                v.push_back(root->val);
            }
            if (root->left) q.push(root->left);
            if (root->right) q.push(root->right);
        }
    }
    return v;
}
