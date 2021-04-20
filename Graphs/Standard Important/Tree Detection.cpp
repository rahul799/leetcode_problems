


https://binarysearch.com/problems/Tree-Detection




what does binary tree tell us ?
there will be a single root
starting preorder/BFS from root will visit entire tree ;)
(also the BFS should not have any cycle :O)
1. find root
A root node is node that doesn't have any parent
i.e. it will be missing from left and right ;)
i made a set of left & right vals and then
-> found first missing element
Implementation
2. root visits all without cycle
maintain visited hashset
then do a BFS
if cycle ( visited second time ) -> return false..
if finished BFS, check that you visited all nodes




Intuition
To verify if the given arrays form a tree, the following conditions have to be met:
1. All cells can only have a single incoming edge (indegree = 1).
2. It has to have a root. A single node with (indegree = 0).
3. It has to be completely connected. Simple dfs that counts nodes can find if it is connected. Number of counted nodes needs to match n, total number of nodes.



Can we find single root node to start with? if (q.empty() || q.size() > 1)
Node with multiple parent (covered by [3] as well)? if (indegree[i] > 1)
Is there any cycle? seen.count(x)
Can we find all nodes from root node? size == left.size()



















Tree Detection
Question 894 of 1000
You are given two lists of integers left and right, both of them the same length and representing a directed graph. left[i] is the index of node i's left child and right[i] is the index of node i's right child. A null child is represented by -1.

Return whether left and right represents a binary tree.

Constraints

n ≤ 100,000 where n is the length of left and right
Example 1
Input
left = [1, -1, 3, -1]
right = [2, -1, -1, -1]
Output
true
Example 2
Input
left = [0]
right = [0]
Output
false
Explanation
This is a circular node.










bool solve(vector<int>& left, vector<int>& right) {
    if (left.size() != right.size()) return false;
    unordered_set<int> seen;
    queue<int> q;
    vector<int> indegree(left.size());
    for (int i=0; i<left.size(); i++) {
        if (left[i] != -1)  indegree[left[i]]++;
        if (right[i] != -1)  indegree[right[i]]++;
    }
    
    for (int i=0; i<indegree.size(); i++) {
        if (indegree[i] > 1) return false; // multiple parents
        if (indegree[i] == 0) {
            seen.insert(i);
            q.push(i);
        }
    }
    if (q.empty() || q.size() > 1) return false;
    int size = 0;
    while (!q.empty()) {
        auto i = q.front(); q.pop();
        size++;
        int l = left[i], r = right[i];
        if (l != -1) {
            if (seen.count(l)) return false; // cycle found
            q.push(l);
            seen.insert(l);
        }
        if (r != -1) {
            if (seen.count(r)) return false; // cycle found
            q.push(r);
            seen.insert(r);
        }
    }
    return size == left.size();
}
