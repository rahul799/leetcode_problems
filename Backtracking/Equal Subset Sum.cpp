
Question: Given an array, of size n, divide the array into 2 non contiguous subarrays of size n/2 & n/2 (if n is even), and (n-1)/2 & (n+1)/2, (if n is odd), such that the absolute difference between the sums of the 2 subarrays is minimum.

Example:

4 5 3 55 -3 23 3 20 100 90





#include<bits/stdc++.h>
using namespace std;
void solve(int ele,int currSum,int index,int maxe,int * arr,int & answer,int sum,int n){
//      cout<<index<<" "<<ele<<" "<<currSum;
        if(ele==maxe){
            int ssum=sum-currSum;
            if(abs(currSum-ssum)<answer)
                answer=abs(currSum-ssum);
            return;
        }
        if(index>=n){
            return;
        }
        solve(ele+1,currSum+arr[index],index+1,maxe,arr,answer,sum,n);
        solve(ele,currSum,index+1,maxe,arr,answer,sum,n);
}
int FindMinimumDifference(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int answer=INT_MAX;
    solve(0,0,0,n/2,arr,answer,sum,n);
    return answer;
}
int main(){
    int n,x;
    cin>>n;
    int * arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>x;
        arr[i]=x;
    }
    cout<<FindMinimumDifference(arr,n);
    return 0;
}
