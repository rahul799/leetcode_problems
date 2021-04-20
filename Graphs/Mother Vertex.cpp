

https://www.youtube.com/watch?v=iYUil_m64Xg&ab_channel=KashishMehndiratta




Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.

Input:
The first line of input contains an integer T. Then T test cases follow. Each test case contains two integers V (number of vertices) and E (number of edges). In the next line are E space separated values u,v denoting an edge from u to v.

Output: For each testcase return the mother vertex of graph (if exists) else return -1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findMother() which takes a Directed graph and the number of vertices as inputs and returns a Mother Vertex in the Graph. If the graph has multiple Mother Vertices, return the one with the smallest value. If the Mother Vertex does not exist, return -1.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 500
1 <= V <= 500
1 <= E <= 3000
0 <= u, v < N

Example:
Input:
2
5 5
1 0 0 2 2 1 0 3 3 4
3 2
0 1 2 1

Ouput:
0
-1

Explanation:
Testcase 1: According to the given edges, all nodes can be reaced from nodes from 0, 1 and 2. But, since we are traversing from node 0, so 0 is the output.

Testcase 2: According to the given edges, no vertices are there from where we can reach all vertices. So, output is -1.




https://practice.geeksforgeeks.org/problems/mother-vertex/1



//Initial Template for C++


#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
/*
 * Function to find if there is a mother vertex in the given graph 
 * V: number of vertices in the graph
 * adj[]: graph representation
 */
void dfsfunc(int v, vector<bool> &vis, vector <int> adj[] ) {
    vis[v] = true;
    for(int i=0; i< adj[v].size(); i++) {
        if(!vis[adj[v][i]]) {
            dfsfunc(adj[v][i], vis, adj);
        }
    }
}




// Here v is denoting my last visited vertex


The intution of this problem is to use trick that I will take a visted vector, I will keep on marking visited nodes along 
and I will keep track of my last visited node








int findMother(int V, vector<int> adj[]) 
{ 
        vector <bool> vis(V, false);
    	int v=0;
    	int i;
    	for(i=0; i<V; i++) {
    	    if(!vis[i]) {
    	        dfsfunc(i, vis, adj);
    	        v=i;
    	    }
    	}
    	for(i=0; i<V; i++) {
    	    vis[i] = false;
    	}
    	dfsfunc(v,vis, adj);
    	for(i=0; i<V; i++) {
    	    if(vis[i] == false)
    	        return -1;
    	}
    	return v;
} 

// { Driver Code Starts.

int main() 
{ 
    int T;
    cin>>T;
    while(T--){
        int num, edges;
        cin>>num>>edges;
        
        vector<int> adj[num];
        
        int u, v;
        while(edges--){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        cout<<findMother(num, adj)<<endl;
    }

	return 0;
}   // } Driver Code Ends
