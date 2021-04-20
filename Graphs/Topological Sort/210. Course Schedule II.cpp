
210. Course Schedule II
Medium


There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .



Approach 1:


enum State { INIT, VISITING, VISITED };

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ans;
    vector<vector<int>> graph(numCourses);
    vector<State> state(numCourses);

    for (const vector<int>& p : prerequisites)
      graph[p[1]].push_back(p[0]);

    for (int i = 0; i < numCourses; ++i)
      if (hasCycle(i, graph, state, ans))
        return {};

    reverse(begin(ans), end(ans));
    return ans;
  }

 private:
  bool hasCycle(int i, const vector<vector<int>>& graph, vector<State>& state,
                vector<int>& ans) {
    if (state[i] == VISITING)
      return true;
    if (state[i] == VISITED)
      return false;

    state[i] = VISITING;
    for (const int neighbor : graph[i])
      if (hasCycle(neighbor, graph, state, ans))
        return true;
    state[i] = VISITED;
    ans.push_back(i);

    return false;
  }
};





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
