Minimum Depth of Binary Tree


111. Minimum Depth of Binary Tree
Easy

2089

790

Add to List

Share
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 

Constraints:

The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000


The intuitive approach is to solve the problem by recursion. Here we demonstrate an example with the DFS
(Depth First Search) strategy.


Iterative approach with QUEUE




int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        stack<pair<TreeNode*,int>> stack;
        stack.push({root,1});
        int result = INT_MAX;
        while(!stack.empty()) {
            TreeNode* current = stack.top().first; 
            int min_depth = stack.top().second; stack.pop();
            if(current->right) stack.push({current->right, min_depth+1});
            if(current->left) stack.push({current->left, min_depth+1});
            if(!current->left && !current->right) result = min(result, min_depth); //leaf
        }
        return result;
    }


Iterative approach with QUEUE

class Solution {
public:
    int minDepth(TreeNode* root) {
       queue<TreeNode*> nodes;
        if(root)
            nodes.push(root);
        int minDepth=0;
        while(!nodes.empty()){
            minDepth++;
            
            int size=nodes.size();
            for(int i=0;i<size;i++){
                TreeNode* currNode=nodes.front();
                if(currNode->left){
                    nodes.push(currNode->left);
                }
                if(currNode->right){
                    nodes.push(currNode->right);
                }
                if(!currNode->left && !currNode->right){
                    return minDepth;
                }
                nodes.pop();
            }
        }
        return 0;
    }
};



class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        if(!root->left)
            return minDepth(root->right)+1;
        if(!root->right)
            return minDepth(root->left)+1;
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};
