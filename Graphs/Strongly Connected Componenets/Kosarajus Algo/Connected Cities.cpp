https://www.geeksforgeeks.org/strongly-connected-components/



https://binarysearch.com/problems/Connected-Cities/editorials/1367870


Connected Cities
Question 89 of 951
You are given n cities represented as an integer in [0, n) and a list of one-way roads that connects one city to another.

Return whether you can reach any city from any city.

Constraints

n ≤ 10,000
m ≤ 100,000 where m is the length of roads
Example 1
Input
Visualize
0

1

Output
true
Explanation
You can go 0 to 1 and 1 to 0

Example 2
Input
Visualize
0

1

Output
false
Explanation
You can go 1 to 0 but not 0 to 1







Algo :


 Create an empty stack ‘S’ and do DFS traversal of a graph. In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, 
 push the vertex to stack.
 
 . In the above graph, if we start DFS from vertex 0, we get vertices in stack as 1, 2, 4, 3, 0.
2) Reverse directions of all arcs to obtain the transpose graph.


One by one pop a vertex from S while S is not empty. Let the popped vertex be ‘v’. Take v as source and do DFS (call DFSUtil(v)). The DFS starting from v
prints strongly connected component of v. In the above example, we process vertices in order 0, 3, 4, 2, 1 (One by one popped 
from stack).





prerequisite - Strong Connected Components
link- https://www.geeksforgeeks.org/strongly-connected-components/
Please go through the above link if u have no idea what Strongly Connected Components(SCCs) are

Basically we have to check if the number of strongly connected components is 1.
I have found SCC using Kosarajus Algo

void dfs2(vector<int>* graphT, int start, bool* visited) {
    visited[start] = true;
    for (int i : graphT[start]) {
        if (!visited[i]) {
            dfs2(graphT, i, visited);
        }
    }
}
void dfs1(vector<int>* graph, int start, bool* visited, stack<int>& s) {
    visited[start] = true;
    for (int i : graph[start]) {
        if (!visited[i]) {
            dfs1(graph, i, visited, s);
        }
    }
    s.push(start);
}

bool solve(int n, vector<vector<int>>& roads) {
    if (n == 0) {
        return false;
    }
    vector<int>* graph = new vector<int>[n];
    vector<int>* graphT = new vector<int>[n];
    for (vector<int> v : roads) {
        graph[v[0]].push_back(v[1]);
        graphT[v[1]].push_back(v[0]);
    }
    stack<int> s;
    bool* visited = new bool[n]();
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs1(graph, i, visited, s);
        }
    }

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    int c = 0;
    while (s.size() != 0) {
        int start = s.top();
        s.pop();
        if (!visited[start]) {
            c++;
            dfs2(graphT, start, visited);
        }
    }

    return c == 1;
}
