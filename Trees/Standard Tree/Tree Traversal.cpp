
Tree Traversal
You are given a tree root and a list of strings moves consisting of "RIGHT", "LEFT" and "UP". Starting from root, traverse the tree by performing each move in moves where:

"RIGHT" means to traverse to the right child.
"LEFT" means to traverse to the left child.
"UP" means to traverse to its parent.
Return the value of the last node after all moves. You can assume that the moves are valid.

Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize
root =
9

1

8

6

0

3

2

moves = ["RIGHT", "RIGHT", "UP", "LEFT", "RIGHT"]
Output
2



int solve(Tree* root, vector<string>& moves) {
    unordered_map<Tree*, Tree*> parent;
    for (int i = 0; i < moves.size(); i++) {
        if (moves[i] == "LEFT") {
            Tree* temp = root;
            root = root->left;
            parent[root] = temp;
        } else if (moves[i] == "RIGHT") {
            Tree* temp = root;
            root = root->right;
            parent[root] = temp;
        } else {
            root = parent[root];
        }
    }
    return root->val;
}
