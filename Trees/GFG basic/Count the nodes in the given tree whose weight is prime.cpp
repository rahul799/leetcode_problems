Count the nodes in the given tree whose weight is prime

Given a tree, and the weights of all the nodes, the task is to count the number of nodes whose weight is prime.




Approach: Perform dfs on the tree and for every node, check if it’s weight is prime or not.


// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

int ans = 0; 

vector<int> graph[100]; 
vector<int> weight(100); 

// Function that returns true 
// if n is prime 
bool isprime(int n) 
{ 
	for (int i = 2; i * i <= n; i++) 
		if (n % i == 0) 
			return false; 
	return true; 
} 

// Function to perform dfs 
void dfs(int node, int parent) 
{ 
	// If weight of node is prime or not 
	if (isprime(weight[node])) 
		ans += 1; 

	for (int to : graph[node]) { 
		if (to == parent) 
			continue; 
		dfs(to, node); 
	} 
} 

// Driver code 
int main() 
{ 
	// Weights of the node 
	weight[1] = 5; 
	weight[2] = 10; 
	weight[3] = 11; 
	weight[4] = 8; 
	weight[5] = 6; 

	// Edges of the tree 
	graph[1].push_back(2); 
	graph[2].push_back(3); 
	graph[2].push_back(4); 
	graph[1].push_back(5); 

	dfs(1, 1); 

	cout << ans; 

	return 0; 
} 



Time Complexity: O(N*sqrt(V)), where V is the maximum weight of a node in the given tree.
In DFS, every node of the tree is processed once and hence the complexity due to the DFS is O(N) when there are N total nodes in the tree. Also, while processing every node, in order to check if the node value is prime or not, a loop up to sqrt(V) is being run, where V is the weight of the node. Hence for every node, there is an added complexity of O(sqrt(V)). Therefore, the time complexity is O(N*sqrt(V)).
Auxiliary Space: O(1).
Any extra space is not required, so the space complexity is constant.
