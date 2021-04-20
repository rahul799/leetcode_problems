


Inorder Traversal
Given a binary tree root, return an inorder traversal of root as a list.

Bonus: Can you do this iteratively?

Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize
root =
1

159

80

Output
[1, 80, 159]




/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int> solve(Tree* root) {
    vector<int> result;

    stack<Tree*> st;
    auto cur = root;
    while (!st.empty() || cur) {
        if (cur) {
            st.push(cur);
            cur = cur->left;
        }

        else {
            cur = st.top();
            st.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
    }
    return result;
}
