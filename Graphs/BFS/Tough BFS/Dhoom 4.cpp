https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/dhoom-4/editorial/



Samarpit is the main hero of the Dhoom 4.He is trying to steal from the Code Bank Of Hackers.Samarpit has a key with an integer value printed on it. He also has N other keys with each key having its own specific value.Samarpit is trying to break the Lock for which he is supposed to get to the lock's key value. He can perform one type of operation.Take his own key and one of the other N keys and merge them.During merging Samarpit's Key value changes to product of both the keys modulus 100000.

For example if his key value was X and he took a key with value Y the his new key will be (X*Y)%100000.The other key that was used during the merging process remains along with other N-1 keys.

This entire process of merging takes 1 second.Now since he is in a hurry he asks to you to find the minimum time in which he could reach to the lock's key value.

Input:
The first line contains 2 integers they are Samarpit's Key value and the Lock's key value.
The second line contains N indicating the number of other keys Samarpit has.
Third line contains N space separated integers indicating the value of N other keys.

Output:
The minimum time required to get to the Lock's Key.If he is unable to reach that print -1.



#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define mp make_pair
#define all(a) a.begin(),a.end()
#define bitcnt(x) __builtin_popcountll(x)
#define MOD 1000000007
#define total 5000005
#define Me 1000000000001
#define NIL 0
#define MAXN 210005
#define EPS 1e-5
#define INF (1<<28)
#define pi 3.141593
typedef unsigned long long int uint64;
typedef long long int int64;
int a[1005];
int main(){
	int owkey,reqkey,n,i;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>owkey>>reqkey;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	int ans[100005];
	memset(ans,-1,sizeof(ans));
	queue<int>q;
	q.push(owkey);
	ans[owkey]=0;
	while(!q.empty()){
		int64 val=q.front();
		q.pop();
		if(val==reqkey)
		break;
		for(i=0;i<n;i++){
			int64 to=a[i];
			to=to*val;
			to%=100000;
			if(ans[to]==-1){
				ans[to]=ans[val]+1;
				q.push(to);
			}
		}
	}
	printf("%d\n",ans[reqkey]);
	fclose(stdout);
	return 0;
}
