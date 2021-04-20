
199. Binary Tree Right Side View
Medium

Share
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---


      
      
 Algorithm

Initiate the list of the right side view rightside.

Initiate the queue by adding a root.

While the queue is not empty:

Write down the length of the current level: levelLength = queue.size().

Iterate over i from 0 to level_length - 1:

Pop the current node from the queue: node = queue.poll().

If i == levelLength - 1, then it's the last node in the current level, push it to rightsize list.

Add first left and then right child node into the queue.

Return rightside







class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> view;
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = todo.front();
                todo.pop();
                if (i == n - 1) {
                    view.push_back(node -> val);
                }
                if (node -> left) {
                    todo.push(node -> left);
                }
                if (node -> right) {
                    todo.push(node -> right);
                }
            }
        }
        return view;
    }
};
