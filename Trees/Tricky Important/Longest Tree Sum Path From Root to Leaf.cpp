Longest Tree Sum Path From Root to Leaf


https://binarysearch.com/problems/Longest-Tree-Sum-Path-From-Root-to-Leaf

Editorial

https://binarysearch.com/problems/Longest-Tree-Sum-Path-From-Root-to-Leaf/editorials/1679392




Question 88 of 866
Given a binary tree root, return the sum of the longest path from the root to a leaf node. If there are two equally long paths, return the larger sum.

Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize Tree
root =


Output
18
Explanation
The longest path here is 5 nodes long: 1 -> 4 -> 7 -> 4 -> 2.



Intuition
The problem gets quite simple and faster when you start to use C++ pairs, in Python you may use a list. The idea is to reach every nodes through dfs and return a pair with following attributes;

first - To keep track of the maximum sum at the current Node reached from the longest path.
second - To keep track of the depth of the current Node.
Have a look at the comments I've made alongside each line of code for better understanding.

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
pair<int, int> longestSumPath(Tree* currNode) {
    // Create a pair for "max-sum & path-length" for a Node
    pair<int, int> ans;

    // Return empty pair for NULL Nodes
    if (!currNode) return ans;

    // Get the values for the Children Nodes
    pair<int, int> leftNode = longestSumPath(currNode->left);
    pair<int, int> rightNode = longestSumPath(currNode->right);

    // As the "path-length" attribute has higher precedency for the given question,
    // start comparing that first

    // For the first two-cases, update the current sum and the max-path length
    if (leftNode.second > rightNode.second) {
        ans.first = leftNode.first + currNode->val;
        ans.second = max(leftNode.second, rightNode.second) + 1;

    } else if (leftNode.second < rightNode.second) {
        ans.first = rightNode.first + currNode->val;
        ans.second = max(leftNode.second, rightNode.second) + 1;

    }
    // For equal path-lengths, figure out the maximum of the sums and update the path-length
    else {
        ans.first = max(leftNode.first, rightNode.first) + currNode->val;
        ans.second = leftNode.second + 1;  // (or) rightNode.second + 1;
    }
    return ans;
}

int solve(Tree* root) {
    return longestSumPath(root).first;
}










