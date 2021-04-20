Next Greater Element of a Linked List

https://binarysearch.com/problems/Next-Greater-Element-of-a-Linked-List


Given a singly linked list node, replace every node's value with the first greater node's value to its right. If a node doesn't have a next greater node, set its value to 0.

Constraints

n ≤ 100,000 where n is the number of nodes in node
Example 1
Input
Visualize
node =
3

2

4

5

Output
Visualize


Example 2
Input
Visualize
node =
1

1

1

1

Output
Visualize







void replace(LLNode* root, stack<int>& s) {
    if (root == NULL) return;
    replace(root->next, s);
    while (!s.empty() and s.top() <= root->val) s.pop();
    int vals = root->val;
    root->val = s.empty() ? 0 : s.top();
    s.push(vals);
}
LLNode* solve(LLNode* node) {
    stack<int> s;
    replace(node, s);
    return node;
}
