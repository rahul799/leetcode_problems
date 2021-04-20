Given a directed graph G with N vertices and M edges. The task is to find the length of the longest directed path in Graph.

Note: Length of a directed path is the number of edges in it.


Simple Approach: A naive approach is to calculate the length of the longest path from every node using DFS.

The time complexity of this approach is O(N2).

Efficient Approach: An efficient approach is to use Dynamic Programming and DFS together to find the longest path in the Graph.

Let dp[i] be the length of the longest path starting from the node i. Initially all positions of dp will be 0. We can call the DFS function from every node and traverse for all its children. The recursive formula will be:

dp[node] = max(dp[node], 1 + max(dp[child1], dp[child2], dp[child3]..))

At the end check for the maximum value in dp[] array, which will be the longest path in the DAG.





https://www.youtube.com/watch?v=BrLekXK2hxg&ab_channel=CodewithDemoralizer




#include "bits/stdc++.h"
using namespace std;

int dp[100005];
bool visited[100005];
vector<int> adj[100005];

void visit(int vertex){
	visited[vertex] = 1;
	dp[vertex] = 0;
	for(int child:adj[vertex]){
		if(!visited[child]){
			visit(child);
		}
		dp[vertex] = max(dp[vertex] , 1 + dp[child]);
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
	
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			visit(i);
		}
	}
	
	int ans = 0;
	for(int i = 1; i<=n ; i++){
		ans = max(ans, dp[i]);
	}
	
	cout<<ans;
	
}





















// C++ program to find the longest 
// path in the DAG 

#include <bits/stdc++.h> 
using namespace std; 

// Function to traverse the DAG 
// and apply Dynamic Programming 
// to find the longest path 
void dfs(int node, vector<int> adj[], int dp[], bool vis[]) 
{ 
	// Mark as visited 
	vis[node] = true; 

	// Traverse for all its children 
	for (int i = 0; i < adj[node].size(); i++) { 

		// If not visited 
		if (!vis[adj[node][i]]) 
			dfs(adj[node][i], adj, dp, vis); 

		// Store the max of the paths 
		dp[node] = max(dp[node], 1 + dp[adj[node][i]]); 
	} 
} 

// Function to add an edge 
void addEdge(vector<int> adj[], int u, int v) 
{ 
	adj[u].push_back(v); 
} 

// Function that returns the longest path 
int findLongestPath(vector<int> adj[], int n) 
{ 
	// Dp array 
	int dp[n + 1]; 
	memset(dp, 0, sizeof dp); 

	// Visited array to know if the node 
	// has been visited previously or not 
	bool vis[n + 1]; 
	memset(vis, false, sizeof vis); 

	// Call DFS for every unvisited vertex 
	for (int i = 1; i <= n; i++) { 
		if (!vis[i]) 
			dfs(i, adj, dp, vis); 
	} 

	int ans = 0; 

	// Traverse and find the maximum of all dp[i] 
	for (int i = 1; i <= n; i++) { 
		ans = max(ans, dp[i]); 
	} 
	return ans; 
} 

// Driver Code 
int main() 
{ 
	int n = 5; 
	vector<int> adj[n + 1]; 

	// Example-1 
	addEdge(adj, 1, 2); 
	addEdge(adj, 1, 3); 
	addEdge(adj, 3, 2); 
	addEdge(adj, 2, 4); 
	addEdge(adj, 3, 4); 

	cout << findLongestPath(adj, n); 
	return 0; 
} 
