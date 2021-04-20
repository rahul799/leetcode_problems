
Your task is to count the number of ways you can fill an n×m grid using 1×2 and 2×1 tiles.

https://cses.fi/problemset/task/2181


Input

The only input line has two integers n and m.

Output

Print one integer: the number of ways modulo 109+7.

Constraints
1≤n≤10
1≤m≤1000
Example

Input:
4 7

Output:
78


https://cses.fi/paste/aa7f764ca1d62a2e18cc36/


https://www.youtube.com/watch?v=lPLhmuWMRag&ab_channel=KartikArora

https://www.youtube.com/watch?v=lPLhmuWMRag&ab_channel=KartikArora

DP with Bitmasking: Counting Tiling


/*
*   author: kartik8800
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
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
using namespace std;
 
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
 
void generate_next_masks(int current_mask, int i, int next_mask, int n, 
                            vector<int>& next_masks){
      if(i == n + 1){
        next_masks.push_back(next_mask);
        return;
      }
      
      if((current_mask & (1 << i)) != 0)
          generate_next_masks(current_mask, i + 1, next_mask, n, next_masks);
      
      if(i != n)
        if((current_mask & (1 << i)) == 0 && (current_mask & (1 << (i+1))) == 0)
          generate_next_masks(current_mask, i + 2, next_mask, n, next_masks);      
      
      if((current_mask & (1 << i)) == 0)
          generate_next_masks
                (current_mask, i + 1, next_mask + (1 << i), n, next_masks);    
}
 
int dp[1001][1<<11];
int solve(int col, int mask, const int m, const int n){
    // BASE CASE
    if(col == m + 1){
        if(mask == 0)
          return 1;
        return 0;
    }
 
    if(dp[col][mask] != -1)
      return dp[col][mask];
 
    int answer = 0;
    vector<int> next_masks;
    generate_next_masks(mask, 1, 0, n, next_masks);
 
    for(int next_mask: next_masks){
        answer = (answer + solve(col + 1, next_mask, m, n)) % mod;
    }
 
    return dp[col][mask] = answer;
}
 
int main() {
   init_code();
   int t = 1; //cin >> t;
   while(t--){
        read(n); read(m);
        memset(dp, -1, sizeof dp);
        cout << solve(1, 0, m, n); 
   }
   return 0;
}
