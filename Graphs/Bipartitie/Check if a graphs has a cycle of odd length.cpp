https://www.geeksforgeeks.org/check-graphs-cycle-odd-length/



Check if a graphs has a cycle of odd length

Given a graph, the task is to find if it has a cycle of odd length or not.



It is obvious that if a graph has an odd length cycle then it cannot be Bipartite. In Bipartite graph there are two sets of vertices such that 
no vertex in a set is connected with any other vertex of the same set). For a cycle of odd length, two vertices must of the same set be connected 
which contradicts 
Bipartite definition


Therefore we conclude that every graph with no odd cycles is bipartite. One can construct a bipartition as follows:
(1) Choose an arbitrary vertex x0 and set X0 = {x0}.
(2) Let Y0 be the set of all vertices adjacent to x0 and iterate steps 3-4.
(3) Let Xk be the set of vertices not chosen that are adjacent to a vertex of Yk-1.
(4) Let Yk be the set of vertices not chosen that are adjacent to a vertex of Xk-1.
(5) If all vertices of G have been chosen then
X = X0 ∪ X1 ∪ X2 ∪. . . and Y = Y0 ∪ Y1 ∪ Y2 ∪ 


// C++ program to find out whether a given graph is 
// Bipartite or not 
#include <bits/stdc++.h> 
#define V 4 
using namespace std; 

// This function returns true if graph G[V][V] contains 
// odd cycle, else false 
bool containsOdd(int G[][V], int src) 
{ 
	// Create a color array to store colors assigned 
	// to all veritces. Vertex number is used as index 
	// in this array. The value '-1' of colorArr[i] 
	// is used to indicate that no color is assigned to 
	// vertex 'i'. The value 1 is used to indicate first 
	// color is assigned and value 0 indicates second 
	// color is assigned. 
	int colorArr[V]; 
	for (int i = 0; i < V; ++i) 
		colorArr[i] = -1; 

	// Assign first color to source 
	colorArr[src] = 1; 

	// Create a queue (FIFO) of vertex numbers and 
	// enqueue source vertex for BFS traversal 
	queue <int> q; 
	q.push(src); 

	// Run while there are vertices in queue (Similar to BFS) 
	while (!q.empty()) 
	{ 
		// Dequeue a vertex from queue 
		int u = q.front(); 
		q.pop(); 

		// Return true if there is a self-loop 
		if (G[u][u] == 1) 
		return true; 

		// Find all non-colored adjacent vertices 
		for (int v = 0; v < V; ++v) 
		{ 
			// An edge from u to v exists and destination 
			// v is not colored 
			if (G[u][v] && colorArr[v] == -1) 
			{ 
				// Assign alternate color to this adjacent 
				// v of u 
				colorArr[v] = 1 - colorArr[u]; 
				q.push(v); 
			} 

			// An edge from u to v exists and destination 
			// v is colored with same color as u 
			else if (G[u][v] && colorArr[v] == colorArr[u]) 
				return true; 
		} 
	} 

	// If we reach here, then all adjacent 
	// vertices can be colored with alternate 
	// color 
	return false; 
} 

// Driver program to test above function 
int main() 
{ 
	int G[][V] = {{0, 1, 0, 1}, 
		{1, 0, 1, 0}, 
		{0, 1, 0, 1}, 
		{1, 0, 1, 0} 
	}; 

	containsOdd(G, 0) ? cout << "Yes" : cout << "No"; 
	return 0; 
} 


