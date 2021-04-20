
This problem is an extension of the original House Robber Problem. In this problem, our poor thief does not have a straight street, but have a binary-tree-like area instead.

To help better understand the problem, below is an example robbing plan on a binary tree:

one example robbing

Well, it looks a bit more complicated. For problems related to the tree data structure, often we could apply the recursion. Also, due to the characteristic of this problem, the memoization approach and the DP approach are available.

Below, we will discuss three approaches: Recursion , Recursion with Memoization, and Dynamic Programming. They are similar but have some differences. Generally, we recommend the first and the second approaches, and provide the third approach as an extension reading for interested readers.

Approach 1: Recursion
Intuition

In this part, we explain how to think of this approach step by step. If you are only interested in the pure algorithm, you can jump to the algorithm part.

Since the tree itself is a recursive data structure, usually recursion is used to tackle these tree-relative problems.

Now we need a recursive function, let's call it helper (or whatever you want to call it).

Usually, we use a node as the input to the helper and add other arguments if we need more information.

The pseudo code of the common structure to solve recursive problems is as below:

function helper(node, other_information) {
    // basic case, such as node is null
    if node is null:
        return things like 0 or null
    else:
        do something relates to helper(node.left) and helper(node.right)
}
function answerToProblem(root) {
    return helper(root, other_information)
}
In some cases, we can use answerToProblem itself as the helper function.

OK, back to our problem. The next question is what should our helper function return.

Since the problem asks us to find out the maximum amount of money the thief can get, we could try using this maximum value as the return value of the helper function.

So helper receives a node as input, and returns the maximum amount the thief can get starting from this node.

Let's try writing the actual code. Well, it's a bit of trouble...

function helper(node) { // return the maximum by starting from this node
    if node is null: // basic case
        return 0
    else:
        two choices: rob this node or not?
        if not rob... we have: helper(node.left) + helper(node.right)

        what if rob? we get node.val!
        what about node.left and node.right? we can not rob them.
        Hmm... maybe we need to touch node.left.left and its other siblings... troublesome!
}
If we need to touch the grandchildren of this node, the case becomes complicated. Well, it is not infeasible but requires extra effort and code. Often, the best practice is to only touch its children, not its grandchildren.

The ideal situation is to make node.left and node.right automatically handle the grandchildren for us.

How to do it? Well, we can let them know whether we robbed this node or not by passing this information as input, like this:

    two choices: rob this node or not?

    rob = node.val + helper(node.left, parent_robbed=True)
                + helper(node.right,  parent_robbed=True)

    not_rob = helper(node.left, parent_robbed=False)
            + helper(node.right, parent_robbed=False)

    return max(rob, not_rob)
Cool, we also need to change the input correspondingly:

function helper(node, the parent is robbed or not?) {
    // return the maximum by starting from this node
    tackle basic case...

    if the parent is robbed:
        we can not rob this node.
        return helper(node.left, False) + helper(node.right, False)

    if the parent is not robbed:
        two choices: rob this node or not?
        calculate `rob` and `not_rob`...
        return max(rob, not_rob)
}
Good, now we have a functioning code. But the code is still not perfect.

An obvious problem is that the helper is called too many times. Ideally, it should only be called as least as possible to reduce redundant calculations.

For example, when calculating rob and not_rob:

    rob = node.val + helper(node.left, True) + helper(node.right, True)
    not_rob = helper(node.left, False) + helper(node.right, False)
The helper is called four times. Moreover, when we call helper(node.left, True) and helper(node.left, False), those two involve same calculations internally, such as helper(node.left.left, False).

In other words, helper(node.left.left, False) is called inside helper(node.left, True), and also is called inside helper(node.left, False). It is calculated twice! We do not want that.

What if... we can combine them together?

We return the results of helper(node.left, True) and helper(node.left, False) in a single function: helper(node.left). Those two results can be stored in a two-element array.

function helper(node) {
    // return original [`helper(node.left, True)`, `helper(node.left, False)`]
    tackle basic case...
    left = helper(node.left)
    right = helper(node.right)
    some calculation...
    return [max_if_rob, max_if_not_rob]
}
In this case, we fully use the calculation results without redundant calculation.

Also, you can reduce extra calculations by memoization or by DP, which we will discuss in the following approaches.

Algorithm

Use a helper function which receives a node as input and returns a two-element array, where the first element represents the maximum amount of money the thief can rob if starting from this node without robbing this node, and the second element represents the maximum amount of money the thief can rob if starting from this node and robbing this node.

The basic case of the helper function should be null node, and in this case, it returns two zeros.

Finally, call the helper(root) in the main function, and return its maximum value.



337. House Robber III
Medium

3713

65

Add to List

Share
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.





class Solution {
public:
    int rob(TreeNode* root) {
        int max_include_root = 0;
        int max_donnot_include_root = 0;
        return dfs(root, max_include_root, max_donnot_include_root);
    }
    
    int dfs(TreeNode* root, int& max_include_root, int& max_donnot_include_root) {
        if (root == NULL) {
            max_include_root = 0;
            max_donnot_include_root = 0;
            return 0;
        }
        int max_donnot_include_root_left = 0;
        int max_donnot_include_root_right = 0;

        int max_include_root_left = 0;
        int max_include_root_right = 0;

        int max_left = dfs(root->left, max_include_root_left, max_donnot_include_root_left);
        int max_right = dfs(root->right, max_include_root_right, max_donnot_include_root_right);

        max_include_root = root->val + max_donnot_include_root_left + max_donnot_include_root_right;
        max_donnot_include_root = max_left + max_right;

        return max(max_include_root, max_donnot_include_root);
    }
};
