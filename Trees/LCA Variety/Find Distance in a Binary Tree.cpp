
1740. Find Distance in a Binary Tree
Medium

27

5

Add to List

Share
Given the root of a binary tree and two integers p and q, return the distance between the nodes of value p and value q in the tree.

The distance between two nodes is the number of edges on the path from one to the other.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 0
Output: 3
Explanation: There are 3 edges between 5 and 0: 5-3-1-0.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 7
Output: 2
Explanation: There are 2 edges between 5 and 7: 5-2-7.
Example 3:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 5
Output: 0
Explanation: The distance between a node and itself is 0.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
0 <= Node.val <= 109
All Node.val are unique.
p and q are values in the tree.






class Solution {
    // solution based on the assumption that both nodes are there in the tree and it have unique nodes
    
    // find path to the node
    bool find_dfs(TreeNode* root, int p, list<int> &path){
        if(root==nullptr)return false;
        
        if(root->val==p){
            path.push_front(root->val);
            return true;
        }
        
        if(find_dfs(root->left, p, path) || find_dfs(root->right, p, path)){
            path.push_front(root->val);
            return true;
        }
        
        return false;
    }
public:
    int findDistance(TreeNode* root, int p, int q, int level=1) {
        list<int> path_p;
        list<int> path_q;
        
        // find the paths from root to p and q
        find_dfs(root, p, path_p);
        find_dfs(root, q, path_q);
                
        // while they have some common elements on both paths remove them
        while(!path_p.empty() && !path_q.empty() && path_p.front()==path_q.front()){
            path_p.pop_front();
            path_q.pop_front();
        }
        
        return path_p.size() + path_q.size();
    }
};
