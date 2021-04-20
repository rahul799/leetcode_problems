Problem Description :
Given N monkeys and M rituals. Each monkey teams up two monkeys. Also if A and B are in same team and B and C are in same team then A and C will also be in
same team (transitive relation). Now given an array A where Ai represents the number of bananas. Print the maximum number of bananas that
a team can collect.

https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/kingdom-of-monkeys/

Approach :

For the M given rituals prepare a adjacency list of the teams formed. pseudocode :

vector<int>adj[N+1];
while M do
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
Apply dfs on the adjacency list prepared and also save the sum of bananas which are collected by the monkeys of team. Return the maximum sum.

pseudocode:

int dfs ( int pos )
{
    if ( vis[pos]==true )
        return 0;

    vis[pos] = true;
    lli sum = A[pos];
    for ( int i=0;i<adj[pos].size();i++ )
    {
        if ( vis[adj[pos][i]]==false )
            sum += dfs(adj[pos][i]);
    }
    return sum;
}














#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define f first
#define s second
#define mod 1000000007
#define inf 1e9
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define f first
#define s second
#define rep(i,n) for(int i=0;i<n;i++)																															
int visi[200000];
ll int arr[200000];
std::vector< vector<int> > gr;
ll int te=0;									
void dfs( int no )						
{			
  //cout<<no<<" ";				
	visi[no]=1;
	te+=arr[no];
	int i;
	for(i=0;i<gr[no].size();i++)
	{
		int tn=gr[no][i];
		if(!visi[tn])
		{
           dfs(tn);
		}
	}
}
int main()
{
	
//	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int i,j,k,n,m;
		cin>>n>>m;
		gr.clear();
		gr.resize(n+5);
		assert(1<=n && n<=100000);
		assert(1<=m && m<=100000);
		rep(i,m)
		{
	      cin>>j>>k;
	      j--;
	      k--;
	      gr[j].pb(k);
	      gr[k].pb(j);
		}
		rep(i,n){
		cin>>arr[i];
		assert(arr[i]>=0 && arr[i]<=1000000000000);
	}
		memset(visi,0,sizeof(visi));
		ll int ans=0;
		rep(i,n)
		{
			if(visi[i]==0)
			{
				te=0;
				dfs(i);
				ans=max(te,ans);
			}
			else
				continue;
		}
		cout<<ans;
		if(t>0)cout<<"\n";
	}
	return 0;
}
