285. Inorder Successor in BST
Medium


https://binarysearch.com/problems/Inorder-Successor/editorials/2960758



Add to List

Share
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

The successor of a node p is the node with the smallest key greater than p.val.

 
 
 We either go left or right depending on the current node's value compared to target value.
If current node's value is higher than target value, we go left, looking for a smaller successor, but also we mark the current node as successor.
Otherwise, we go right, to try to find a higher value than target.

Implementation
Using depth first search, at each call we will go either left or right.
Each time we check if the node's value is higher than target value.
As we go, we keep updating the successor, as we know it is the lowest value so far that is higher than target, because we go left each time in this case, where only lower values exist.

Time Complexity
\mathcal{O}(h)O(h) - Where \mathcal{h}h is the height of the tree. Best case: O(log n), Worst case: O(n).

Space Complexity
\mathcal{O}(h)O(h) - Recursive call stack will be of size \mathcal{h}h.

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void get_successor(Tree* root, int target, Tree*& successor) {
    if (!root) return;

    if (root->val > target) {
        successor = root;
        get_successor(root->left, target, successor);
    } else {
        get_successor(root->right, target, successor);
    }
}

int solve(Tree* root, int t) {  // Time and Space: O(H)
    Tree* successor = nullptr;
    get_successor(root, t, successor);

    return successor ? successor->val : INT_MIN;
}






Example 1:


Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.



The idea is equivalent to doing binary search on a BST
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr || p == nullptr) {
            return nullptr;
        }
        
        TreeNode* res = nullptr;
        TreeNode* cur = root;
        while (cur != nullptr) {
            if (cur->val > p->val) {
                res = cur;
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        
        return res;
    }
};
