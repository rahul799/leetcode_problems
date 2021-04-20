

 Binary Tree Longest Consecutive Sequence II

https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/




549. Binary Tree Longest Consecutive Sequence II
Medium

667

50

Add to List

Share
Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.

Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid. On the 
other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.

Example 1:

Input:
        1
       / \
      2   3
Output: 2
Explanation: The longest consecutive path is [1, 2] or [2, 1].
 

Example 2:

Input:
        2
       / \
      1   3
Output: 3
Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
 

Note: All the values of tree nodes are in the range of [-1e7, 1e7].


Approach #1 Brute Force [Time Limit Exceeded]
We can easily see that in a tree there is exactly one unique path one from one node to another. So, the number of paths possible will be equal to number of pairs of nodes
{{N}\choose{2}}( 
2
N
​	
 ), where NN is the number of nodes.

Brute force solution of this problem is to find the path between every two nodes and check whether it is increasing or decreasing. In this way we can find maximum length
increasing or decreasing sequence.

Complexity Analysis

Time complexity : O(n^3)O(n 
3
 ). Total possible number of paths are n^2n 
2
  and checking every path whether it is increasing or decreasing will take O(n)O(n) for one path.

Space complexity : O(n^3)O(n 
3
 ). n^2n 
2
  paths each with O(n)O(n) nodes.

Approach #2 Single traversal [Accepted]
Algorithm

This solution is very simple. With every node, we associate two values/variables named inrinr and dcrdcr, where incrincr represents the length of the longest incrementing
branch below the current node including itself, and dcrdcr represents the length of the longest decrementing branch below the current node including itself.

We make use of a recursive function longestPath(node) which returns an array of the form [inr, dcr][inr,dcr] for the calling node. We start off by assigning both inrinr and
dcrdcr as 1 for the current node. This is because the node itself always forms a consecutive increasing as well as decreasing path of length 1.

Then, we obtain the length of the longest path for the left child of the current node using longestPath[root.left]. Now, if the left child is just smaller than the current
node, it forms a decreasing sequence with the current node. Thus, the dcrdcr value for the current node is stored as the left child's dcrdcr value + 1. But, if the left child 
is just larger than the current node, it forms an incrementing sequence with the current node. Thus, we update the current node's inrinr value as left\_child(inr) + 1left_child(inr)+1.

Then, we do the same process with the right child as well. But, for obtaining the inrinr and dcrdcr value for the current node, we need to consider the maximum value
out of the two values obtained
from the left and the right child for both inrinr and dcrdcr, since we need to consider the longest sequence possible.

Further, after we've obtained the final updated values of inrinr and dcrdcr for a node, we update the length of the longest consecutive path found so far
as maxval = \text{max}(inr + dcr - 1)maxval=max(inr+dcr−1).



class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int longest = 0;
        dfs(root, root, longest);
        return longest;
    }

    pair<int, int> dfs(TreeNode * node, TreeNode * parent, int & longest) {
        if ( NULL == node ) {
            return make_pair(0, 0);
        }
        auto left = dfs(node->left, node, longest);
        auto right = dfs(node->right, node, longest);
        longest = max(longest, left.first + right.second + 1);
        longest = max(longest, left.second + right.first + 1);
        int inc = 0, dec = 0;
        if ( node->val == parent->val + 1 ) {
            inc = max(left.first, right.first) + 1;
        }
        if ( node->val == parent->val - 1 ) {
            dec = max(left.second, right.second) + 1;
        }
        return make_pair(inc, dec);
    }
};
