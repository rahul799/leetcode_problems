Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.

Example:

Input: [10,5,15,1,8,null,7]

   10 
   / \ 
  5  15 
 / \   \ 
1   8   7

Output: 3
Explanation: The Largest BST Subtree in this case is the highlighted one.



 traverse the tree in bottom up manner, then we can pass information about subtrees to the parent. 
 
 Keep track of each subtree's info in X:

isBST == is the subtree a BST
minv == minimum value of the substree
maxv == maximum value of the substree
size == size of the largest BST subtree within this subtree


Perform post-order traversal in order to check each node's left and right subtrees first. There are 2 use cases: 1)
either both left and right subtrees are BSTs xor 2) one or the other or both left and right subtrees are not BSTs. 
Use case 1) If both left and right subtrees are BSTs, then check if the current node's value is also included a BST 
(i.e. the current node's value fits between its left substree's maximum value and the right subtrees minimum value), if so, then 
coalesce the left and right subtrees into a BST including the current node ( +1 to size of left and right subtrees in order to include 
the current node in the size of the newly coalesced BST ) and track the minimum and maximum values of the newly formed BST. Otherwise, 
use case 2) return the size of the maximum
BST within the subtree at the current node.

https://www.youtube.com/watch?v=ffKw8v0LH4I&ab_channel=KashishMehndiratta



TO convert that into a BST, left should be bst, right shpuld be BST,  left max < node, right min > node

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int mini = INT_MAX, maxi = INT_MIN, maxsize = 0, cursize = 0;
        subtree(root, mini, maxi, maxsize, cursize);
        return maxsize;
    }
    
    bool subtree(TreeNode* root, int& mini, int& maxi, int& maxsize, int& cursize){
        if (!root){
            cursize = 0; return true;
        }else{
            int minil = INT_MAX, minir = INT_MAX, maxil = INT_MIN, maxir = INT_MIN, sizel = 0, sizer = 0;
            bool l = subtree(root->left, minil, maxil, maxsize, sizel);
            bool r = subtree(root->right, minir, maxir, maxsize, sizer);
            cursize = sizel + sizer + 1;
            mini = min(minil, root->val);
            maxi = max(maxir, root->val);
            if (l && r && 
                (maxil == INT_MIN || maxil < root->val) && 
                (minir == INT_MAX || minir > root->val)){
                maxsize = max(maxsize, cursize);
                return true;
            }else{
                return false;
            }
        }
    }
};
