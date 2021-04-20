



1522. Diameter of N-Ary Tree
Medium


Add to List

Share
Given a root of an N-ary tree, you need to compute the length of the diameter of the tree.

The diameter of an N-ary tree is the length of the longest path between any two nodes in the tree. This path may or may not pass through the root.

(Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value.)

 

Example 1:



Input: root = [1,null,3,2,4,null,5,6]
Output: 3
Explanation: Diameter is shown in red color.
Example 2:



Input: root = [1,null,2,null,3,4,null,5,null,6]
Output: 4
Example 3:



Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 7
 

Constraints:

The depth of the n-ary tree is less than or equal to 1000.
The total number of nodes is between [0, 10^4]





Approach:

1. The first insight is that the longest path in a tree can only happen between two leaves nodes or between a leaf node and the root node.

2. The second insight is that each non-leaf node acts as a bridge for the paths between its descendant leaves nodes. If we pick two longest sub-paths 
from a non-leaf node to its descendant leaves nodes, and combine them together, then the resulting path would be the longest path among all possible ones 
that are bridged by this
non-leaf node.


Based on the above definition, a leaf node will have a height of zero.



As we explained in the overview section, the longest path that is bridged by a non-leaf node will come from the combination of two longest sub-paths downward to the leaves nodes from this non-leaf node.

As one might see now, the sub-paths that we mentioned above consist of the top two largest heights of the children nodes.

If we define the top two largest heights of the children nodes as height(node.child_m) and height(node.child_n), then the longest path bridged by this node would be
height(node.child_m) + height(node.child_n) + 2.





If we know the top two largest depths among two leaves nodes starting from the node, namely depth(node.leaf_m) and depth(node.leaf_n), then this 
longest path could be calculated as the sum of top two largest depths minus the depth of the parent node, namely


depth(node.leaf_m) + depth(node.leaf_n) - 2 * depth(node)







Max diameter


int max_dia = 0;
int diameter(Node* r, bool isRoot = true) {
    int max_depth = 0;
    for (auto ch : r->children) {
        auto depth = 1 + diameter(ch, false);
        max_dia = max(max_dia, max_depth + depth);
        max_depth = max(max_depth, depth);
    }
    return isRoot ? max_dia : max_depth;
}




DFS through each node and calculate height of each node.


class Solution {
public:
    int treeHeight(Node* root, int& ans) {
        if (!root)
            return 0;
        
        int max_height = 0, second_max_height = 0;

        for (int i = 0; i < root->children.size(); i++) {
            Node* child = root->children[i];
            int cheight = treeHeight(child, ans);
            
            if (cheight > max_height) {
                second_max_height = max_height;
                max_height = cheight;
            } else if (cheight > second_max_height) {
                second_max_height = cheight;
            }
        }
        ans = max(ans, max_height + second_max_height);
        return max_height + 1; 
    }

    int diameter(Node* root) {
        int ans = 0; 
        treeHeight(root, ans);
        return ans;
    }
};



