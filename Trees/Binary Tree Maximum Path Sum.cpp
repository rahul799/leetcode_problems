124. Binary Tree Maximum Path Sum
Hard




https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/603072/C%2B%2B-solution-O(n)-with-detailed-explanation



3922

303

Add to List

Share
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6



       
       
       
 The way to think of a solution to this is that when we are looking a path in a tree its unidirectional and cannot retrace back what i mean by that is:
    _
  / 1 \ 
 / / \ \ <-----path that goes like a depth first search without backtracking
/ 2   3 v  

So a way to solve this is that if i am at a node i can choose a left or right subtree but if i choose both this is the only subtree that will contain my maximum

I first set my max_sum to INT_MIN.
I can do either either of the options presented:
1.I can choose to take up the left subtree or drop it.
2.I can either choose to take up the right subtree or drop it.
3.I check for a possibility whether if i were to take both left subtree and right subtree would that beat my current max_sum?
Lets consider
   -10
   / \
  9  20
    /  \
   15   7
I do my postorder traversal with a bit of variation:-

int l=max(max_gain(root->left),0);
int r=max(max_gain(root->right),0);
But why?
This is because I have the option to choose the left or right subtree or whether i will just settle with my root value.

So I do my regular postorder traversal and do the above steps
I hit 9

    9
   / \
NULL  NULL

int l=0,r=0(Base condition)
i store the value of 9+0+0 in a variable
Then check if this is greater than maxsum or not is so i update it.
As my max_sum was INT_MIN it gets updated to 9

Now we explore the right tree of root which reaches 15

    15
   / \
NULL  NULL

int l=0,r=0(Base condition)
i store the value of 9+0+0 in a variable
Then check if this is greater than maxsum or not is so i update it.
As my max_sum was 9 it gets updated to 15

Similarly with 7 but 7 doesnt beat the max_sum so nothing happens.

       
       
  int max_sum=INT_MIN;
    int max_gain(TreeNode* root)
    {
        if(!root)return 0;
        int l=max(max_gain(root->left),0);
        int r=max(max_gain(root->right),0);
        int new_price=root->val+l+r;
        max_sum=max(max_sum,new_price);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;
    }     
       






class Solution {
    int sum;
public:
    int maxPathSum(TreeNode* root) {
        sum=INT_MIN;
        help(root);
        return sum;
    }
    
    /*** return the max-value-ended-at-root-node ***/
    int help(TreeNode* root){
        if(!root)   return 0;
        int left = max(0, help(root->left));
        int right = max(0, help(root->right));
        /*** key parts : embedding the max-value-find in the recursion process ***/
        sum = max(sum, left+right+root->val);
        /*** get the max-value-ended-at-root ***/
        return max(left, right)+root->val;
    }
};
