


Binary Tree Nodes Around Radius
You are given a binary tree root containing unique integers and integers target and radius. Return a 
sorted list of values of all nodes that are distance radius away from the node with value target.


Intuition
Tree is actually directed graph. The idea is to convert the tree to a undirected graph so we can start from any vertex and move around freely.

Implementation
First of all, DFS to convert the graph, then BFS to get the result.

Time Complexity
\mathcal{O}(n)O(n), DFS to construct a graph, then BFS to get the answer. Visit each node twice at most




Constraints

1 ≤ n ≤ 100,000 where n is number of nodes in root
0 ≤ distance ≤ 100,000
Example 1
Input
Visualize
root =


target = 4
radius = 2
Output
[1, 3]
Example 2
Input
Visualize
root =
0

target = 0
radius = 0
Output
[0]



unordered_map<int, vector<int>> m;

void dfs(Tree* root) {
    if (!root) return;
    Tree *child1, *child2;
    child1 = root->left;
    child2 = root->right;

    if (child1) {
        m[root->val].push_back(child1->val);
        m[child1->val].push_back(root->val);
        dfs(child1);
    }
    if (child2) {
        m[root->val].push_back(child2->val);
        m[child2->val].push_back(root->val);
        dfs(child2);
    }
}

vector<int> solve(Tree* root, int k, int distance) {
    m.clear();
    dfs(root);

    vector<int> ans;
    queue<pair<int, int>> q;
    q.push({k, 0});
    unordered_set<int> vis;
    vis.insert(k);

    while (q.size()) {
        auto f = q.front();
        q.pop();
        if (f.second == distance) {
            ans.push_back(f.first);
            continue;
        }

        for (auto v : m[f.first]) {
            if (vis.find(v) == vis.end()) {
                vis.insert(v);
                q.push({v, f.second + 1});
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
