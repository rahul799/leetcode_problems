
https://binarysearch.com/problems/Detecting-an-Odd-Length-Cycle/editorials/3053798





Intuition
The basic intuition les on the fact that if a graph is Bipartite, then the graph can never contain an odd length cycle. If it contains an odd length cycle => it can never be bipartite.

Implementation
Make a function which checks for the 'bipartiteness' of the graph. If the graph comes out to be bipartite, then you just need to return false otherwise 
return true.

In the implementation we basically assign colors to each and every node in the graph. Using bfs, we will assign colors to each neighbor of the current node.
If we observe that any 2 adjacent nodes have the same color, we don't need to process further, we can just return false.
The color is assigned by the 2 intergers: {0, 1} and we assign it by the formula:
color[node] = 1 - color[parent node]
(think why it is logical)
We do not need to make the visited bool array either, we can initialize the color array with values = -1 indicating that the node has not been visited and 
then we go further and process the unvisited nodes.




Time Complexity
\mathcal{O}(n)O(n) : n is the number of nodes in the graph

Space Complexity
\mathcal{O}(n)O(n): 1 queue is maintained throughout and 1 color array of size n





bool isBip(int i, vector<int>& color, vector<vector<int>>& arr, int n) {
    queue<int> q;
    q.push(i);
    color[i] = 1;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int ele : arr[curr]) {
            if (color[ele] == color[curr]) {
                return false;
            }
            if (color[ele] == -1) {
                color[ele] = 1 - color[curr];
                q.push(ele);
            }
        }
    }
    /*    cout << "color array is: " << endl;
        for(int i = 0; i < n; i++){
            cout << color[i] << " ";
        }
        cout << endl;*/

    return true;
}

bool solve(vector<vector<int>>& arr) {
    int n = arr.size();
    // cout << "number of nodes: " << n << endl;
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!isBip(i, color, arr, n)) {
                return true;
            }
        }
    }
    return false;
}
