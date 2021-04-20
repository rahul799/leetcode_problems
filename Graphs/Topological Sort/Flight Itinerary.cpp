Flight Itinerary


https://binarysearch.com/problems/Flight-Itinerary


Question 143 of 866
You are given a list of flights that were taken, represented as origin to destination airport pairs. Given that this list was shuffled, find all the airports that were visited in the correct order.

Note: you can assume that no airport was visited twice.

Constraints

n ≤ 100,000 where n is the length of flights
Example 1
Input
flights = [
    ["WRE", "RPM"],
    ["AGN", "WRE"],
    ["NTL", "AGN"]
]
Output
["NTL", "AGN", "WRE", "RPM"]
Explanation
The only way to have taken the 3 flights was to have taken "NTL" -> "AGN" first. After that, "AGN" -> "WRE", and "WRE" -> "RPM" could be taken.





vector<string> order;
unordered_map<string, vector<string>> graph;
unordered_map<string, int> indegree;
unordered_set<string> nodes;

bool topologicalSort() {
    // function returns true if graph is not a DAG
    queue<string> Q;
    for (auto keys : nodes) {
        if (indegree[keys] == 0) {
            Q.push(keys);
        }
    }
    while (!Q.empty()) {
        string u = Q.front();
        Q.pop();
        order.push_back(u);
        for (string& it : graph[u]) {
            if (--indegree[it] == 0) {
                Q.push(it);
            }
        }
    }
    return (order.size() == nodes.size());
}

vector<string> solve(vector<vector<string>>& flights) {
    int e = flights.size();
    for (int i = 0; i < e; i++) {
        string u = flights[i][0];
        string v = flights[i][1];
        nodes.insert(u), nodes.insert(v);
        graph[u].push_back(v);
        indegree[v]++;
    }
    bool valid = topologicalSort();
    if (!valid) cout << "TopSort does not exists" << endl;
    return order;
}
