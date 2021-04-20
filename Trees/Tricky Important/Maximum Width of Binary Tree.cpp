

662. Maximum Width of Binary Tree
Medium

1931

359

Add to List

Share
Given a binary tree, write a function to get the maximum width of the given tree. The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
 

Constraints:

The given binary tree will have between 1 and 3000 nodes.


https://www.youtube.com/watch?v=8eqy9axAUsY&ab_channel=ProgrammingTutorials


Approach:
For each node, we need two things : one is the node and other is the index of the node
index at each level   is basicallly right index - left index + 1
Assign the id to the nodes root node = 1, then left child as parent_id * 2 and right child as parent_id * 2 + 1




class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        unsigned long long maxe = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push(pair<TreeNode*, unsigned  long long>(root, 1));
        while (!q.empty()) {
            unsigned long long l = q.front().second, r = l; // right started same as left
            for (int i = 0, n = q.size(); i < n; i++) {
                TreeNode* node = q.front().first;
                r = q.front().second;
                q.pop();
                if (node->left) q.push(pair<TreeNode*, unsigned long long>(node->left, r * 2));
                if (node->right) q.push(pair<TreeNode*, unsigned  long long>(node->right, r * 2 + 1));
            }
            maxe = max({maxe, r + 1 - l});
        }
        return (int)maxe;
    }
};;










