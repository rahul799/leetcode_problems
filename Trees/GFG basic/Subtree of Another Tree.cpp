572. Subtree of Another Tree
Easy

3092

152

Add to List

Share
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
 

Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.



class Solution {
public:
    bool isSame(TreeNode* s, TreeNode* t) {
        if (!s && !t)
            return true;
        if (!s || !t)
            return false;
        if (s->val != t->val)
            return false;
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t != nullptr)
            return false;
        if (isSame(s, t))
            return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};



Complexity Analysis

Time complexity : O(m*n)O(m∗n). In worst case(skewed tree) traverse function takes O(m*n)O(m∗n) time.

Space complexity : O(n)O(n). The depth of the recursion tree can go upto nn. nn refers to the number of nodes in ss.
