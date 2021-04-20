
Connected Cities

https://binarysearch.com/problems/Connected-Cities/editorials/2481559


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




To reach from any city to, any city our Graph should be Strongly Connected Component.
So, you should have a Knowledge of Strongly Connected Components to solve this Q's.(https://en.wikipedia.org/wiki/Strongly_connected_component)

Now we have to check whether our Graph is Strongly Connected Component or not.
There are Two Algorithms to check whether Graph is Strongly Connected Component or Not.

Kosa Raju Algorithm
Tarjan's Algorithm
I have used Tarjan's Algorithm to check whether Graph is Strongly Connected or not.
Time Complexity: O(V+E) // (Only Single traversal is Required)
Space Complexity:- O(V)
(https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/) . If you don't know about this Algorithm, please go through this link.
If you have read this Algorithm, now we just have to count the Strongly Connected Component, and if it's equals to 1, then there is only one Strongly
Connected Component and you can reach from any city to, any city. If it's greater than 1, then you can't reach to other cities that are in Different
Strongly Connected Components.
(i.e, your graph is not Strongly Connected Component).




class Solution {
    public:
    bool solve(int n, vector<vector<int>> &roads) {
        vector<vector<int>> G(n);
        int l = roads.size();
        for (int i = 0; i < l; ++i) G[roads[i][0]].push_back(roads[i][1]);

        vector<int> low(n, -1), disc(n, -1);
        vector<bool> InStack(n, false);
        stack<int> myStack;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (disc[i] == -1) DFS(i, G, low, disc, InStack, myStack, count);
        }
        return (count == 1) ? true : false;
    }
    void DFS(int src, vector<vector<int>> &G, vector<int> &low, vector<int> &disc,
             vector<bool> &InStack, stack<int> &myStack, int &count) {
        static int timer = 0;
        low[src] = disc[src] = timer;
        timer++;
        InStack[src] = true;
        myStack.push(src);
        for (auto it : G[src]) {
            if (disc[it] == -1) {
                DFS(it, G, low, disc, InStack, myStack, count);

                low[src] = min(low[src], low[it]);
            } else if (InStack[it])
                low[src] = min(low[src], disc[it]);
        }
        if (low[src] == disc[src]) {
            count++;
            while (myStack.top() != src) {
                InStack[myStack.top()] = false;
                myStack.pop();
            }
            InStack[myStack.top()] = false;
            myStack.pop();
        }
    }
};

bool solve(int n, vector<vector<int>> &roads) {
    return (new Solution())->solve(n, roads);
}
