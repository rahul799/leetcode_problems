https://leetcode.com/problems/serialize-and-deserialize-binary-tree/



297. Serialize and Deserialize Binary Tree
Hard

4117

190

Add to List

Share
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:

Input: root = [1,2]
Output: [1,2]





class Codec {
public:

void serialhelper(TreeNode* root, vector<string>& sol) {
    if (root==NULL) {
        sol.push_back("null");
        return;
    }   
    sol.push_back(to_string(root->val));
    serialhelper(root->left, sol);
    serialhelper(root->right, sol);
}

vector<string> serialize(TreeNode* root) {
    vector<string> sol;
    serialhelper(root,sol);
    return sol;
}

TreeNode* deserialize(vector<string> data) {
    int index = 0;
    return deserialize(data, index);
}

TreeNode* deserialize(vector<string>& data, int& i) {
    if (i >= data.size() || data[i] == "null") {
        return NULL;
    }
    TreeNode* root = new TreeNode(stoi(data[i]));
    root->left = deserialize(data, ++i);
    root->right = deserialize(data, ++i);  
    return root;
}
};

// Your Codec object will b
