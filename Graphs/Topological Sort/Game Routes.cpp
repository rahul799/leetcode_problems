
https://www.youtube.com/channel/UC0PYAh68WLY69tMXCzPKpLA

https://cses.fi/problemset/task/1681

https://ideone.com/GARnIV

A game has n levels, connected by m teleporters, and your task is to get from level 1 to level n. The game has been designed so that there are no directed 
cycles in the underlying graph. In how many ways can you complete 
the game?


Input

The first input line has two integers n and m: the number of levels and teleporters. The levels are numbered 1,2,…,n.

After this, there are m lines describing the teleporters. Each line has two integers a and b: there is a teleporter from level a to level b.

Output

Print one integer: the number of ways you can complete the game. Since the result may be large, print it modulo 109+7.

Constraints
1≤n≤105
1≤m≤2⋅105
1≤a,b≤n
Example

Input:
4 5
1 2
2 4
1 3
3 4
1 4

Output:
Input

The first input line has two integers n and m: the number of levels and teleporters. The levels are numbered 1,2,…,n.

After this, there are m lines describing the teleporters. Each line has two integers a and b: there is a teleporter from level a to level b.

Output

Print one integer: the number of ways you can complete the game. Since the result may be large, print it modulo 109+7.

Constraints
1≤n≤105
1≤m≤2⋅105
1≤a,b≤n
Example

Input:
4 5
1 2
2 4
1 3
3 4
1 4

Output:
https://ideone.com/GARnIV



The idea of this problem is to use topological Sort two times : first to prune the graph and ensure that every node has indegree greater than zero and then 

apply the second order topological sort



#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
 
int n, m;
vector<vector<int>> g;
vector<int> cnt;
vector<int> inDegree;
const int modb = 1e9+7;
 
void top_sort()
{
	queue<int> q;
	for(int i = 2; i <= n; ++i)
	{
		if(inDegree[i] == 0)
		{
			q.push(i);	
		}
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto v: g[u])
		{
			--inDegree[v];
			if(inDegree[v] == 0)
				q.push(v);
		}
	}
	q.push(1);
	cnt[1] = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto v: g[u])
		{
			--inDegree[v];
			cnt[v] = cnt[v] + cnt[u];
			cnt[v] %=  modb;
			if(inDegree[v] == 0)
				q.push(v);
		}
	}
}
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	cnt.resize(n+1);
	inDegree.resize(n+1);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		inDegree[v]++;
		g[u].push_back(v);
	}
	for(int i = 2; i <= n; ++i)
	{
 
	}
	top_sort();
	cout << cnt[n];
}
