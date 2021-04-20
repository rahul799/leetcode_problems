/*
    author: kartik8800
*/
 
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
 
struct project
{
    int st,ed,rwd;
};
 
// can two projects have same end time?
bool cmp(project& p1, project& p2)
{
    return p1.ed < p2.ed;
}
 
int findBest(vector<int>& endPts, int val)
{
    auto it = lower_bound(endPts.begin(), endPts.end(), val);
    if(it == endPts.begin())
        return 0;
    else
    {
        it--;
        return 1 + distance(endPts.begin(), it);
    }
}
 
ll solve(vector<project>& v)
{
    int n = v.size();
    ll dp[n+1];
    dp[0] = 0;
 
    vector<int> endPts;
    for(int i = 1; i < v.size(); i++)
            endPts.push_back(v[i].ed);
 
    for(int i = 1; i < n; i++)
    {
        ll op1 = dp[i-1];
        ll op2 = v[i].rwd;
        // find largest j s.t. end point of i is less than si.
        int j = findBest(endPts,v[i].st);
        op2 += dp[j];
        dp[i] = max(op1,op2);
    }
 
    return dp[n-1];
}
 
int main() {
   fast_io;
   ll t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   while(t--)
   {
       cin >> n;
       vector<project> v(n+1);
 
       fr(1,n+1)
            cin >> v[i].st >> v[i].ed >> v[i].rwd;
       sort(v.begin() + 1, v.end(), cmp);
 
       cout << solve(v);
   }
   return 0;
}
