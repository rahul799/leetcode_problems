#include <bits/stdc++.h>
using namespace std;



const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;


#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)
#define pb push_back
#define F first
#define S second
//#define biGinf 9e+18
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define inpv(v) for(auto &x:v) cin>>x
#define otpv(v) for(auto &x:v) cout<<x<<nwl
#define otpv2(v) for(auto &x:v) cout<<x<<" "
#define CASES int tt;cin>>tt; while(tt--)
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define sz(v) (int)(v).size()
#define vec(x) vector < x >
using vi = vector < int >;
using vvi = vector < vi >;
using pii = pair < int , int >;
using vpii = vector < pii >;
using int64 = long long;
//const int64 biGinf = 9e+18;
//const string yo = "YES", no = "NO";
const int inf = 2e9 + 7;
const char nwl = '\n';



void solve(int& ans) {
    int n = 0, k = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    int c = 0;

    for(int i = 0; i < n/2 ; i++)
    if(s[i] != s[n-i - 1 ]) c++;

    ans = k - c;
 


    

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int ans = 0;
        
        solve(ans);
       cout << "Case #" << t  << ": " << ans << "\n";

        
    }
    
}














