
332. Reconstruct Itinerary

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.






class Solution {
public:
    
    unordered_map<string, priority_queue<string, vector<string> , greater<string>>> graph;
    vector<string> result;
    
    
    void dfs(string vertex){
        
        auto &edges = graph[vertex];
        while(!edges.empty()){
            string to_vertex = edges.top();
            edges.pop();
            dfs(to_vertex);
        }
        result.push_back(vertex);
    }
    
        
        
        
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for( auto e : tickets)
            graph[e[0]].push(e[1]);
        
        // observe carefully we used push here
            
            dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
        
    }
};




s
