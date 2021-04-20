
https://cses.fi/problemset/task/1680

Time limit: 1.00 s Memory limit: 512 MB
Uolevi has won a contest, and the prize is a free flight trip that can consist of one or more flights through cities. Of course, Uolevi wants to choose a trip that has as many cities as possible.

Uolevi wants to fly from Syrjälä to Lehmälä so that he visits the maximum number of cities. You are given the list of possible flights, and you know that there are no directed cycles in the flight network.

Input

The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,…,n. City 1 is Syrjälä, and city n is Lehmälä.

After this, there are m lines describing the flights. Each line has two integers a and b: there is a flight from city a to city b. Each flight is a one-way flight.

Output

First print the maximum number of cities on the route. After this, print the cities in the order they will be visited. You can print any valid solution.

If there are no solutions, print "IMPOSSIBLE".

Constraints
2≤n≤105
1≤m≤2⋅105
1≤a,b≤n


Example

Input:
5 5
1 2
2 5
1 3
3 4
4 5

Output:
4
1 3 4 5











#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
 
int n, m;
vector<set<pair<int,int>>> g;
vector<int> dist;
vector<int> par;
 
void dij()
{
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,1});
	dist[1] = 0;
	par[1] = -1;
 
	while(!pq.empty())
	{
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
 
		if(dist[u] < d) continue;
 
		for(auto e: g[u])
		{
			int v = e.first;
			int c = e.second;
			if(dist[v] > dist[u]+c)
			{
				dist[v] = dist[u]+c;
				pq.push({dist[v],v});
				par[v] = u;
			}
		}
 
 
	}
 
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dist.resize(n+1);
	par.resize(n+1);
 
	for(int i = 1; i <= n; ++i)
	{
		par[i] = -1;
	}
 
	g.resize(n+1);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].insert({v,-1});
	}
	dij();
	if(dist[n] == 0)
	{
		cout << "IMPOSSIBLE";
		return 0;
	}
 
	cout << 1 + dist[n]*(-1) << endl;
	vector<int> ans;
	int temp = n;
	while(temp != -1)
	{
		ans.push_back(temp);
		temp = par[temp];
	}
	reverse(ans.begin(), ans.end());
	for(auto u: ans)
	{
		cout << u << " ";
	}
 
}
