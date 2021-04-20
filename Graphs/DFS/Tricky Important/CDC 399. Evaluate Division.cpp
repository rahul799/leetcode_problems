
399. Evaluate Division
Medium



https://www.youtube.com/watch?v=UcDZM6Ap5P4&ab_channel=NareshGupta


3349

271

Add to List

Share
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 

Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.






https://leetcode.com/problems/evaluate-division/





class Solution {
public:
    unordered_map<string,vector<pair<string,double>>>mp;
    
    double bfs(string src, string des){
        
        if(mp.find(src) == mp.end() || mp.find(des) == mp.end())
            return -1.0;
        
        unordered_set<string>visited;
        queue<pair<string,double>>q;
        
        q.push({src,1.0});
        
        visited.insert(src);
        
        while(!q.empty()){
            
            string node = q.front().first;
            double val = q.front().second;
            q.pop();
            
            if(node == des)
                return val;
            
            for(auto child : mp[node]){
                if(!visited.count(child.first)){
                    visited.insert(child.first);
                    q.push({child.first,child.second*val});
                }
            }
        }
        
        
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        for(int i = 0; i < equations.size(); i++){
            mp[equations[i][0]].push_back({equations[i][1],values[i]});
            mp[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        
        vector<double> ans;
        for(int i = 0; i < queries.size(); i++){
            ans.push_back(bfs(queries[i][0],queries[i][1]));
        }
        return ans;
    }
};
