543. Diameter of Binary Tree
Easy

3282

202

Add to List

Share
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].


Height of a Binary Tree
Let us see how to calculate the height of a binary tree using post order traversal.

Suppose we know the height of the left and right subtree. What is the height of the root? Clearly, it is max(leftHeight,rightHeight) + 1.
This gives us the algorithm. Recursively calculate the height of the subtrees and update the height of the root. All that is left is to handle the corner cases.
If both the subtrees are non empty, we are done, as the formula is correct.
Suppose, exactly one subtree is empty. Then the result would be nonEmptyTreeHeight + 1. This is also valid.
What happens if both the subtree is empty? This means that the root is a leaf node. According to the formula, the height of the root is 1.
Conclusion ===> We are assuming the height of a leaf node as 1.
Calculating the diameter
The final diameter has the following form. It goes up certain nodes and after a specific node, say head, it comes down.
Recall that while calculating the height of the tree, the height was computed for each and every node due to recursion.
As soon as the height of the node head is computed, we can get the diameter as leftHeight + rightHeight. Observe that we didn't account for the
          fact that there are 2 extra edges to reach the left and right subtree. However, this is taken care of by the assumption that leaf nodes have height 1. 
          There is 1 leaf node in each tree which compensates the lost edges. Moreover, this also gives us that the diameter of a leaf node is 0,
          while its height is 1.



                    
                     
 Height of a Binary Tree
Let us see how to calculate the height of a binary tree using post order traversal.

Suppose we know the height of the left and right subtree. What is the height of the root? Clearly, it is max(leftHeight,rightHeight) + 1.
This gives us the algorithm. Recursively calculate the height of the subtrees and update the height of the root. All that is left is to handle the corner cases.
If both the subtrees are non empty, we are done, as the formula is correct.
Suppose, exactly one subtree is empty. Then the result would be nonEmptyTreeHeight + 1. This is also valid.
What happens if both the subtree is empty? This means that the root is a leaf node. According to the formula, the height of the root is 1.
Conclusion ===> We are assuming the height of a leaf node as 1.
Calculating the diameter
The final diameter has the following form. It goes up certain nodes and after a specific node, say head, it comes down.
Recall that while calculating the height of the tree, the height was computed for each and every node due to recursion.
As soon as the height of the node head is computed, we can get the diameter as leftHeight + rightHeight. Observe that we didn't account for the fact that there are 2 extra edges to reach the left and right subtree. However, this is taken care of by the assumption that leaf nodes have height 1. There is 1 leaf node in each tree which compensates the lost edges. Moreover, this also gives us that the diameter of a leaf node is 0, while its height is 1.
Algorithm
Calculate the height of each node and in the meanwhile, update the diameter at each node.
This ensures that the correct diameter is captured at some stage.


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // Check if tree exists
        if (root == NULL) return 0;
        int diam = 0;
        // Find depths of left and right subtrees
        int leftDepth = helper(root->left, diam);
        int rightDepth = helper(root->right, diam);
        
        // Return largest diameter (maybe not through root)
        return max(diam, leftDepth + rightDepth);
    }
    
    // Recursive DFS method
    int helper(TreeNode* root, int &diam) {
        // Check for leaf node
        if (root == NULL) return 0;
        
        // Find depths of left and right subtrees
        int leftDepth = helper(root->left, diam);
        int rightDepth = helper(root->right, diam);
        
        // Diameter is the number of edges between the farthest nodes
        diam = max(diam, leftDepth + rightDepth);
        // Return the depth of the current subtree
        return max(leftDepth, rightDepth) + 1;
    }
};

