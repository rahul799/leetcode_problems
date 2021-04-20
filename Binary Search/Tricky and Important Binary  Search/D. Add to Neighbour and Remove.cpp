



https://www.youtube.com/watch?v=Lq907K6Isp8&ab_channel=sKSama


http://codeforces.com/contest/1462/problem/D



https://github.com/bhallashivam1997/Code_Explainer_Youtube/blob/main/Codeforces/Add_to_Neighbour_and_Remove.cpp




Polycarp was given an array of a[1…n] of n integers. He can perform the following operation with the array a no more than n times:

Polycarp selects the index i and adds the value ai to one of his choice of its neighbors. More formally, Polycarp adds the value of ai to ai−1 or to ai+1 (if such a neighbor does not exist, then it is impossible to add to it).
After adding it, Polycarp removes the i-th element from the a array. During this step the length of a is decreased by 1.
The two items above together denote one single operation.

For example, if Polycarp has an array a=[3,1,6,6,2], then it can perform the following sequence of operations with it:

Polycarp selects i=2 and adds the value ai to (i−1)-th element: a=[4,6,6,2].
Polycarp selects i=1 and adds the value ai to (i+1)-th element: a=[10,6,2].
Polycarp selects i=3 and adds the value ai to (i−1)-th element: a=[10,8].
Polycarp selects i=2 and adds the value ai to (i−1)-th element: a=[18].
Note that Polycarp could stop performing operations at any time.

Polycarp wondered how many minimum operations he would need to perform to make all the elements of a equal (i.e., he wants all ai are equal to each other).

Input
The first line contains a single integer t (1≤t≤3000) — the number of test cases in the test. Then t test cases follow.

The first line of each test case contains a single integer n (1≤n≤3000) — the length of the array. The next line contains n integers a1,a2,…,an (1≤ai≤105) — array a.





#include<bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "uj.h"
#endif
 
const int nax = (int)1e4;
 
int arr[nax];
int sum = 0;
int n;
 
bool F( int x ){
	x = n - x;
 
	if(sum % x != 0) return false;
	const int val = sum / x;
	int curr = 0;
	for(int i = 0; i < n; ++i){
		curr += arr[i];
		if(curr == val){
			curr = 0;
			
		} else if(curr > val) return false;
	}
 
	return curr == 0;
}
 
void solve(){
	scanf("%d",&n);
	
	sum = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d",&arr[i]);
		sum += arr[i];
	}
	
	for(int i = 0; i < n; ++i){
		if(F(i)){
			printf("%d\n",i);
			return;
		}
	}
	
	puts("-1");
	
}
 
 
 
int main(){
	int tt;
	scanf("%d",&tt);
	
	for(int i = 0; i < tt; ++i){
		solve();
	}
	
#ifndef ONLINE_JUDGE
 	cerr << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
	return 0;
}





















#include <bits/stdc++.h>
        #include <math.h>
    
        using namespace std;
        typedef long long ll;
        typedef unsigned long long ull;
        # define M_PI  3.14159265358979323846
    
    
        // const int M=1e9+7;
        const int M=998244353;
        long long mod(long long x){
            return ((x%M + M)%M);
        }
        long long add(long long a, long long b){
            return mod(mod(a)+mod(b));
        }
        long long mul(long long a, long long b){
            return mod(mod(a)*mod(b));
        }
    
        ll modPow(ll a, ll b){
            if(b==0)
                return 1LL;
            if(b==1)
                return a%M;
            ll res=1;
            while(b){
                if(b%2==1)
                    res=mul(res,a);
                a=mul(a,a);
                b=b/2;
            }
            return res;
        }
 
        int check(vector<int>&a , int k){
            int total=0;
            int n=a.size();
            int sum=0;
            int j=0;
            for(int i=0;i<n;i++){
                sum+=a[i];
                if(sum==k){
                    total+=(i-j);
                    j=i+1;
                    sum=0;
                }
                else if(sum>k){
                    return -1;
                }
            }
            return total;
        }
       
        void solve(){
            int n;
            cin>>n;
            vector<int>a(n);
            int total=0;
            for(int i=0;i<n;i++){
                cin>>a[i];
                total+=a[i];
            }
            int ans=n-1;
            for(int i=1;i*i<=total;i++){
                if(total%i==0){
                    int f1=i;
                    int f2=total/i;
                    int a1=check(a,f1);
                    int a2=check(a,f2);
                    // cout<<f1<<" "<<a1<<"\n";
                    // cout<<f2<<" "<<a2<<"\n";
                    if(a1!=-1)
                        ans=min(ans,a1);
                    if(a2!=-1)
                        ans=min(ans,a2);
                }
            }
            cout<<ans<<"\n";
        }
        int main(){
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cout<<fixed;
            cout<<setprecision(10);
    //        freopen("timber_input.txt", "r", stdin);
    //        freopen("timber_output.txt", "w", stdout);
            int t=1;
            cin>>t;
            // g();
            for(int i=1;i<=t;i++){
            //    cout<<"Case #"<<i<<": ";
                solve();
            }
            return 0;
        }
