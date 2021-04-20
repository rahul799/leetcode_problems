1602. Find Nearest Right Node in Binary Tree

Given the root of a binary tree and a node u in the tree, return the nearest node on the same level that is to the right of u, or return null if u is the rightmost node in its level.

 

Example 1:



Input: root = [1,2,3,null,4,5,6], u = 4
Output: 5
Explanation: The nearest node on the same level to the right of node 4 is node 5.
Example 2:



Input: root = [3,null,4,2], u = 2
Output: null
Explanation: There are no nodes to the right of 2.
Example 3:

Input: root = [1], u = 1
Output: null
Example 4:

Input: root = [3,4,2,null,null,null,1], u = 4
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
All values in the tree are distinct.
u is a node in the binary tree rooted at root


Another approach is to push all the nodes in one queue and to use a sentinel node to separate the levels. Typically, one could use null as a sentinel.

diff

The first step is to initiate the first level: root + null as a sentinel. Once it's done, continue to pop the nodes one by one from the left and push their children to the right. Stop each time the current node is null because it means we hit the end of the current level. Each stop is a time to push null in the queue to mark the end of the next level.

Algorithm

Initiate the queue by adding a root. Add null sentinel to mark the end of the first level.

Initiate the current node as root.

While queue is not empty:

Pop the current node from the queue curr = queue.poll().

If this node is u, return the next node from the queue. If there is no more nodes in the queue, return null.

If the current node is not null:

Add first left and then right child node into the queue.

Update the current node: curr = queue.poll().

Now, the current node is null, i.e. we reached the end of the current level. If the queue is not empty, push the null node as a sentinel, to mark the end of the next level.



Approach 3: BFS: One Queue + Level Size Measurements
Instead of using the sentinel, we could write down the length of the current level.

diff

Algorithm

Initiate the queue by adding a root.

While the queue is not empty:

Write down the length of the current level: levelLength = queue.size().

Iterate over i from 0 to level_length - 1:

Pop the current node from the queue: node = queue.poll().

If this node is u, return the next node from the queue. Check that the next node is on the same level: i != levelLength - 1, otherwise return null.

Add first left and then right child node into the queue.













class Solution {
public:
    TreeNode* findNeartestRightNode(TreeNode* root, TreeNode* u) {
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* last = nullptr;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto front = q.front();
                q.pop();
                if (last == u)
                    return front;
                last = front;
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }
        
        return nullptr;
    }
};
