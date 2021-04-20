
Given an integer N denoting the Length of a line segment. you need to cut the line segment in such a way that the cut length of a line segment each time is integer either x , y or z. and after performing all cutting operation the total number of cutted segments must be maximum. 


Input
First line of input contains of an integer 'T' denoting number of test cases. First line of each testcase contains N . Second line of each testcase contains 3 space separated integers x , y and z.

Output
For each test case print in a new line an integer corresponding to the answer 

https://practice.geeksforgeeks.org/problems/cutted-segments/0

using namespace std;
#define ll long long 
int main()
 {
    ll t,n,m,k,i,j;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    ll a[3];
	    ll x,y,z;
	    cin>>x>>y>>z;
	    //sort(a,a+3);
	    ll dp[n+1];
	    memset(dp,-1,sizeof(dp));
	    dp[0]=0;
	    for(i=1;i<=n;i++)
	    {
	        if(i>=x && dp[i-x]!=-1)
	        dp[i]=max(dp[i-x]+1,dp[i]);
	        if(i>=y && dp[i-y]!=-1)
	        dp[i]=max(dp[i-y]+1,dp[i]);
	        if(i>=z && dp[i-z]!=-1)
	        dp[i]=max(dp[i-z]+1,dp[i]);
	    }
	    cout<<dp[n]<<endl;
	}
	return 0;
}
