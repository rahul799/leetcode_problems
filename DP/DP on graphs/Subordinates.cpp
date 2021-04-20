
https://cses.fi/problemset/task/1674/


Given the structure of a company, your task is to calculate for each employee the number of their subordinates.

Input

The first input line has an integer n: the number of employees. The employees are numbered 1,2,…,n, and employee 1 is the general director of the company.

After this, there are n−1 integers: for each employee 2,3,…,n their direct boss in the company.

Output

Print n integers: for each employee 1,2,…,n the number of their subordinates.

Constraints
1≤n≤2⋅105
Example

Input:
5
1 1 2 3

Output:
4 1 1 0 0




 
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
 
vector<int> tree[200001];
 
void solve(int src, int par, vector<int>& ans)
{
    int subords = 0;
    for(int child : tree[src])
    {
        if(child != par)
        {
            solve(child, src, ans);
            subords += (1 + ans[child]);
        }
    }
    ans[src] = subords;
}
 
int main() {
   fast_io;
   ll t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   while(t--)
   {
        cin >> n;
        vector<int> ans(n+1);
        fr(2,n+1)
        {
            cin >> x;
            tree[x].push_back(i);
            tree[i].push_back(x);
        }
        solve(1, 0, ans);
        fr(1,n+1)
            cout << ans[i] <<' ';
   }
   return 0;
}
