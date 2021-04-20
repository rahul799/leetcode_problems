Level Order Alternating
Question 214 of 978
Given a binary tree root, return values of the nodes in each level, alternating from going left-to-right and right-to-left.

Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize
root =
3

0

4

2

1

Output
[3, 4, 0, 2, 1]



vector<int> solve(Tree* root) {
    if (!root) return {};
    queue<Tree*> q{{root}};
    vector<int> ans;
    bool L2R = true;
    while (!q.empty()) {
        int pos = ans.size(), sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto t = q.front();
            q.pop();
            ans.push_back(t->val);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        if (!L2R) reverse(ans.begin() + pos, ans.end());
        L2R = !L2R;
    }
    return ans;
}
