Amazon
Still not understood 





Tree Shifting
Question 3 of 4
Given a binary tree root, shift all the nodes as far right as possible while maintaining the relative ordering in each level.

Constraints

n ≤ 100,000 where n is the number of nodes in root







Intuition
If we keep track of the nodes level by level, we can greedily update the children pointers by taking the rightmost unprocessed child and placing it in the rightmost child slot available on the upper nodes.

Implementation
We first perform a DFS through the tree, getting the nodes in order by level from left to right.

After that, we clear the child pointers for all the nodes. We then scan the tree level by level, processing all nodes at level i. We look at the nodes from right to left in that level in the for loop indexed by a, and keep track of the rightmost unprocessed node in the level below at j, making it first the right child and then the left child as feasible.

Time Complexity
We do two sweeps through the tree, so the time complexity is \mathcal{O}(N)O(N).

Space Complexity
Since we manually store a reference to each node, the space complexity is \mathcal{O}(N)O(N).



vector<Tree*> nodes[100005];
int maxd;
void dfs(Tree* curr, int d) {
    if (curr == NULL) return;
    maxd = max(maxd, d);
    nodes[d].push_back(curr);
    dfs(curr->left, d + 1);
    dfs(curr->right, d + 1);
}
Tree* solve(Tree* root) {
    maxd = 0;
    dfs(root, maxd);
    for (int i = 0; i <= maxd; i++) {
        for (auto& node : nodes[i]) {
            node->right = NULL;
            node->left = NULL;
        }
    }
    for (int i = 0; i < maxd; i++) {
        int j = nodes[i + 1].size() - 1;
        for (int a = nodes[i].size() - 1; a >= 0 && j >= 0; a--) {
            nodes[i][a]->right = nodes[i + 1][j--];
            if (j >= 0) nodes[i][a]->left = nodes[i + 1][j--];
        }
    }
    for (int i = 0; i <= maxd; i++) nodes[i].clear();
    return root;
}
