Binary Tree Cameras

Given a binary tree, we install cameras on the nodes of the tree.

Each camera at a node can monitor its parent, itself, and its immediate children.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.

https://github.com/grandyang/leetcode/issues/968

Example 1:



Input: [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:



Input: [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
Note:

The number of nodes in the given tree will be in the range [1, 1000].
Every node has value 0.



This question is given to a binary tree. It is said that you can put a camera on the node, and you can shoot the parent node, itself, and the left and right child nodes. Now ask us how many cameras we need at least to capture all the nodes. Since it was a Hard topic, the blogger subconsciously looked at Related Topics and found that it was DP. So bloggers began to think about how to define dp and think about the state transition equation. But I didn't come up with a feasible solution, so I went to the forum and found that everyone used the Greedy Algorithm. It seems that the blogger was misled by Topics. But it does not matter, the important thing is to solve the problem with the great god lee215. Let's consider first, where exactly can the camera be placed to capture the most nodes? Is it Ye Node? Not necessarily, because if it is placed on a leaf node, only the leaf node and its parent node can be photographed. Is it the root node? Not necessarily, because at the root node, at most the root node and its left and right sub-nodes can be photographed, and there are only three in total. The optimal solution is placed on the parent node of the leaf node, so that up to four nodes can be photographed. So the strategy should be to find the leaf node first, then put a camera on its parent node, and mark the parent node of the parent node as being photographed. In this way, there are 3 different states. Use 0 to indicate that the current node is a leaf node, 1 indicates that the current node is the parent node of the leaf node, and the camera is placed, and 2 indicates that the current node is a leaf node. The grandfather who clicked the node was photographed by the camera. Here a sub-function is used to pass in the global variable res to record the total number of cameras placed. In the recursive function, if the current node does not exist, it returns 2. The empty node can also be regarded as being photographed by the camera. Otherwise, the recursive function is called on the left and right child nodes respectively. If one of the two returns 0, at least one child node of the current node is a leaf node, and a camera needs to be placed at the current position. As a result, res increases by 1, and Returns 1. Otherwise, if one of the return values ​​of the left and right child nodes is 1, it means that at least one of the left and right child nodes has been put on the camera, and the current node has been photographed, so return 2. If neither is, it means that the current node is a leaf node, and 0 is returned. In the main function, if the return value of the recursive call to the root node is 0, it means that the root node is a leaf node. At this time, there is no way but to put a camera on the leaf node, so add 1. Otherwise, no need to add, see the code as follows:

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int res = 0;
        return (helper(root, res) < 1 ? 1 : 0) + res;
    }
    // Return 0 if leaf, 1 if parent of leaf with camera on this node, 2 if covered without camera on this node.
    int helper(TreeNode* node, int& res) {
        if (!node) return 2;
        int left = helper(node->left, res), right = helper(node->right, res);
        if (left == 0 || right == 0) {
            ++res;
            return 1;
        }
        return (left == 1 || right == 1) ? 2 : 0;
    }
