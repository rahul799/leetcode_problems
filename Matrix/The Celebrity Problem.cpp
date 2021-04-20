In a party of N people, only one person is known to everyone. Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. We can only ask questions like “does A know B? “. Find the stranger (celebrity) in the minimum number of questions.

We can describe the problem input as an array of numbers/characters representing persons in the party. We also have a hypothetical function HaveAcquaintance(A, B) which returns true if A knows B, false otherwise. How can we solve the problem.
Examples:

Input:
MATRIX = { {0, 0, 1, 0},
           {0, 0, 1, 0},
           {0, 0, 0, 0},
           {0, 0, 1, 0} }
Output:id = 2
Explanation: The person with ID 2 does not 
know anyone but everyone knows him

Input:
MATRIX = { {0, 0, 1, 0},
           {0, 0, 1, 0},
           {0, 1, 0, 0},
           {0, 0, 1, 0} }
Output: No celebrity
Explanation: There is no celebrity.
Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
We measure the complexity in terms of calls made to HaveAcquaintance().

Method 1: This uses Graph to arrive at the particular solution.

Approach:
Model the solution using graphs. Initialize indegree and outdegree of every vertex as 0. If A knows B, draw a directed edge from A to B, increase indegree of B and outdegree of A by 1. Construct all possible edges of the graph for every possible pair [i, j]. There are NC2 pairs. If a celebrity is present in the party, there will be one sink node in the graph with outdegree of zero and indegree of N-1.
Algorithm:
Create two arrays indegree and outdegree, to store the indegree and outdegree
Run a nested loop, the outer loop from 0 to n and inner loop from 0 to n.
For every pair i, j check if i knows j then increase the outdegree of i and indegree of j
For every pair i, j check if j knows i then increase the outdegree of j and indegree of i
Run a loop from 0 to n and find the id where the indegree is n-1 and outdegree is 0





// C++ program to find celebrity 
#include <bits/stdc++.h> 
#include <list> 
using namespace std; 

// Max # of persons in the party 
#define N 8 

// Person with 2 is celebrity 
bool MATRIX[N][N] = {{0, 0, 1, 0}, 
					{0, 0, 1, 0}, 
					{0, 0, 0, 0}, 
					{0, 0, 1, 0}}; 

bool knows(int a, int b) 
{ 
	return MATRIX[a][b]; 
} 

// Returns -1 if celebrity 
// is not present. If present, 
// returns id (value from 0 to n-1). 
int findCelebrity(int n) 
{ 
	//the graph needs not be constructed 
	//as the edges can be found by 
	//using knows function 
	
	//degree array; 
	int indegree[n]={0},outdegree[n]={0}; 
	
	//query for all edges 
	for(int i=0; i<n; i++) 
	{ 
		for(int j=0; j<n; j++) 
		{ 
			int x = knows(i,j); 
			
			//set the degrees 
			outdegree[i]+=x; 
			indegree[j]+=x; 
		} 
	} 
	
	//find a person with indegree n-1 
	//and out degree 0 
	for(int i=0; i<n; i++) 
	if(indegree[i] == n-1 && outdegree[i] == 0) 
		return i; 
	
	return -1; 
} 

// Driver code 
int main() 
{ 
	int n = 4; 
	int id = findCelebrity(n); 
	id == -1 ? cout << "No celebrity" : 
			cout << "Celebrity ID " << id; 
	return 0; 
} 
