
1202. Smallest String With Swaps
Medium

757

27

Add to List

Share
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

 

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
 

Constraints:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.



We can traverse from right to left and keep a seen set. If the right child of the current node has been visited before, we know the current node is invalid.

We can use either DFS or BFS for this. BFS will save some space (same complexity) while DFS is cleaner.





class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_map<int, TreeNode*> mp;
        queue<TreeNode*> q;
        mp[root->val] = NULL;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* n = q.front(); q.pop();
            
            if (n->left) {
                mp[n->left->val] = n;
                q.push(n->left);
            }
            
            if (n->right) {
                if (mp.find(n->right->val) != mp.end()) {
                    TreeNode* parent = mp[n->val];
                    if (parent->left && parent->left->val == n->val) {
                        parent->left = NULL;
                    } else {
                        parent->right = NULL;
                    }
                    break;    
                }
                mp[n->right->val] = n;
                q.push(n->right);
            }
        }
        
        return root;
    }
};
