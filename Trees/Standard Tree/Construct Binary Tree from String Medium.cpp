

536. Construct Binary Tree from String
Medium

481

98

Add to List

Share
You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

 

Example 1:


Input: s = "4(2(3)(1))(6(5))"
Output: [4,2,6,3,1,5]
Example 2:

Input: s = "4(2(3)(1))(6(5)(7))"
Output: [4,2,6,3,1,5,7]
Example 3:

Input: s = "-4(2(3)(1))(6(5)(7))"
Output: [-4,2,6,3,1,5,7]
 

Constraints:

0 <= s.length <= 3 * 104
s consists of digits, '(', ')', and '-' only.

class Solution {
public:
    TreeNode* str2tree(string s) {
        int i = 0;
        return s.size() == 0 ? nullptr : build(s, i);
    }

private:
    TreeNode* build(string& s, int& i) {
        int start = i;
        if (s[i] == '-') {
            i++;
        }
        while (isdigit(s[i])) {
            i++;
        }
        
        int num = stoi(s.substr(start, i - start));
        TreeNode* node = new TreeNode(num);
        if (s[i] == '(') {
            node->left = build(s, ++i);
            i++;    // )
        }
        if (s[i] == '(') {
            node->right = build(s, ++i);
            i++;    // )
        }
        return node;
    }
};
