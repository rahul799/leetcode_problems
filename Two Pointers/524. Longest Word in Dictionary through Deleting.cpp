524. Longest Word in Dictionary through Deleting
Medium


Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"




class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        queue<int> nodes;
        vector<int> indegrees(numCourses, 0);
        int visit_node_size = 0;
        vector<int> result;
        
        for (auto item : prerequisites) {
            graph[item.second].push_back(item.first);
            ++ indegrees[item.first];
        }
        for (int node_id = 0; node_id < indegrees.size(); ++ node_id) {
            if (indegrees[node_id] == 0) {
                nodes.push(node_id);
            }
        }
        while (!nodes.empty()) {
            ++ visit_node_size;
            int node_id = nodes.front();
            nodes.pop();
            result.push_back(node_id);
            for (auto neighber_id : graph[node_id]) {
                -- indegrees[neighber_id];
                if (indegrees[neighber_id] == 0) {
                    nodes.push(neighber_id);
                }
            }
        }
        
        return visit_node_size == numCourses ? result : vector<int>();
    }
};
