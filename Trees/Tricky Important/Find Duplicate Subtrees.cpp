652. Find Duplicate Subtrees
Medium

1731

229

Add to List

Share
Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.

 https://www.youtube.com/watch?v=_j7yb_nWFO8&ab_channel=CodeLibrary

Example 1:


Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
Example 2:


Input: root = [2,1,1]
Output: [[1]]
Example 3:


Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]
 

Constraints:

The number of the nodes in the tree will be in the range [1, 10^4]
-200 <= Node.val <= 200


Approach #1: Depth-First Search [Accepted]
Intuition

We can serialize each subtree. For example, the tree

   1
  / \
 2   3
    / \
   4   5
can be represented as the serialization 1,2,#,#,3,4,#,#,5,#,#, which is a unique representation of the tree.

Algorithm

Perform a depth-first search, where the recursive function returns the serialization of the tree. At each node, record the result in a map, and analyze the map after to determine duplicate subtrees.


Complexity Analysis

Time Complexity: O(N^2)O(N 
2
 ), where NN is the number of nodes in the tree. We visit each node once, but each creation of serial may take O(N)O(N) work.

Space Complexity: O(N^2)O(N 
2
 ), the size of count.

Approach #2: Unique Identifier [Accepted]
Intuition

Suppose we have a unique identifier for subtrees: two subtrees are the same if and only if they have the same id.

Then, for a node with left child id of x and right child id of y, (node.val, x, y) uniquely determines the tree.

Algorithm

If we have seen the triple (node.val, x, y) before, we can use the identifier we've remembered. Otherwise, we'll create a new one



function returns true if the tree contains  a duplicate subtree of size 2 or more else returns unordered_map<string, int> m;


string solve(Node* root){

if(!root) return "$";

string s = "";

if(!root->right and !root->left){
 s = to_string(root->data); return s;

}
s = s +  to_string(root->data); s = s +  solve(root->left);
  s = s +  solve(root->right);
m[s]++; 
 return s;

bool dupSub(Node root) (

//your code here

m.clear(); solve(root);

for(auto x:m){

} if(x.second >= 2) return true;

return false;
 
 
 
 
 
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> map;
        vector<TreeNode*> dups;
        serialize(root, map);
        for (auto it = map.begin(); it != map.end(); it++)
            if (it->second.size() > 1) dups.push_back(it->second[0]);
        return dups;
    }
private:
    string serialize(TreeNode* node, unordered_map<string, vector<TreeNode*>>& map) {
        if (!node) return "";
        string s = "(" + serialize(node->left, map) + to_string(node->val) + serialize(node->right, map) + ")";
        map[s].push_back(node);
        return s;
    }
};

