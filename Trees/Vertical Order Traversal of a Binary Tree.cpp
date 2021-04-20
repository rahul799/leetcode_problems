987. Vertical Order Traversal of a Binary Tree
Medium



Share
Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.



class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    // here we are taking ordered map
        map<int, vector<int>> mp;
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0, root));
        while(!q.empty()){
            set<pair<int, int>> temp;
            int len = q.size();
            for(int i = 0; i < len; i++){
                auto p = q.front();
                q.pop();
                temp.insert(make_pair(p.first, p.second->val));
                if(p.second->left) q.push(make_pair(p.first -1, p.second->left));
                if(p.second->right) q.push(make_pair(p.first + 1, p.second->right)); 
            }
            for( auto p : temp) mp[p.first].push_back(p.second);
        }
        vector<vector<int>> result;
        for(auto i : mp) result.push_back(i.second);
        return result;
    }
};

