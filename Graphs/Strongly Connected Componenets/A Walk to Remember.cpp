A Walk to Remember


Problem : Given an unweighted directed graph with N nodes and M edges, for each node i , tell whether it is part of a cycle or not.
	
Solution:
Naive Solution O(N*M) : One way to solve this problem could be that for each node i, We perform a dfs with i as root and check if a back edge comes from any other vertex in the graph to node i. If yes, the node will be a part of a cycle otherwise not. Since for each node we perform a dfs, the complexity will be O(N*M) and would time out.

Faster Solution O(N+M) : Instead of performing a dfs for every node, we could find the strongly connected components (scc) of the given graph. If the size of 
an scc is greater than 1, the answer for all the nodes in that scc will be yes. This would work because an scc can be imagined as one or more directed cycles 
attached to each other by sharing common vertices. Hence, each vertex in an scc of size greater than 1 will be a part of a cycle. The scc's can be found by using 
	any one of the two standard algorithms : Kosaraju or Tarjan's algorithm.

Did you find this editorial helpful?  Yes (59)    No (8)
	
	
	
	
	

https://www.youtube.com/watch?v=ZKhOauZgACE&ab_channel=CodeNCode


https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/a-walk-to-remember-qualifier2/



Dilku was thinking about the first time he met his girl... It was indeed a walk to remember. The romantic weather and her silly talks. He was completely mesmarized. Those were the days!..

Today is his girl's birthday and he wants to make it special for her. He wants to again take her on a "special walk" that they would remember for the lifetime.

The city in which Dilku lives is represented as an unweighted directed graph with N nodes and M edges. A "special walk" in the graph starting at node u is a simple path that begins and ends at the same node u.

Formally, A special walk is path u , a1 , a2 , a3 ,..., ai ,.... , u where ai are distinct and not equal to u for all i.

Now since Dilku is really nervous about taking his girl out, he needs your help. For every node in the given graph, tell whether it is possible for Dilku to take his girl on a "special walk" starting at that node.

Input:

First line of a two space separated integers denoting N and M, the number of nodes and number of directed edges in the corresponding graph.
Following M lines contain two space separated integers u v denoting a directed edge in the graph from vertex numbered u to vertex numbered v.

Output:

Print N space separated integers, where ith integer can be either 1 or 0 depicting whether it is possible to go on a special walk starting at node i or not.

Constraints:

1 ≤ N ≤ 105
1 ≤ M ≤ 2 · 105
1 ≤ u, v ≤ N






#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'
 
using namespace std;
vi graph[100001];
vi revG[100001];
vi scc , order;
int vis[100001];
int ans[100001];
 
void dfs(int node)
{
	vis[node] = 1;
	for(int v : graph[node])
	{
		if(vis[v] == false) dfs(v);
	}
	
	order.pb(node);
}
 
void dfs1(int node)
{
	scc.pb(node);
	vis[node] = 1;
	for(int v : revG[node])
	{
		if(vis[v] == false) dfs1(v);
	}
}
 
void updateAnswer()
{
	if(scc.size() <= 1) return;
	
	for(int node : scc) ans[node] = 1;
}
 
int main()
{
	int n , m , a, b;
	cin>>n>>m;
	
	REP(i , m) cin>>a>>b , graph[a].pb(b) , revG[b].pb(a);
	
	REP(i , n)
	{
		if(vis[i] == 0) dfs(i);
	}
	
	reverse(order.begin() , order.end());
	REP(i , n) vis[i] = 0;
	
	for(int node : order)
	{
		if(vis[node] == false)
		{
			scc.clear();
			dfs1(node);
			updateAnswer();
		}
	}
	
	REP(i , n) cout<<ans[i]<<" ";
}
