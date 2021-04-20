

https://www.geeksforgeeks.org/largest-rectangular-sub-matrix-whose-sum-0/



https://www.youtube.com/watch?v=eXA3F2WN3d0&t=159s&ab_channel=CodeLibrary

Largest rectangular sub-matrix whose sum is 0
Difficulty Level : Expert
 Last Updated : 28 May, 2018
Given a 2D matrix, find the largest rectangular sub-matrix whose sum is 0. for example consider the following N x M input matrix



Examples:

Input :  1,  2,  3
        -3, -2, -1          
         1,  7,  5

Output : 1,  2,  3          
        -3, -2, -1

Input :  9,  7, 16,  5
         1, -6, -7,  3          
         1,  8,  7,  9          
         7, -2,  0, 10

Output :-6, -7
          8,  7          
         -2,  0    
  
  
  
  


#include<bits/stdc++.h>
#define int long long int
using namespace std;
 
int subsum(vector<int> a,int n){
        int s = 0;
        int ma = 1;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            s = s + a[i];
            if(s==0){
                ma = max(ma,i+1);
            }
            else if(m[s]){
                ma = max(ma,i-m[s]+1);
            }
            else{
                m[s] = 1;
            }
        }
        return ma;
}
 
 
 
int32_t main(){
 
    int t;
    cin>>t;
    while(t--){
        int r,c;
        cin>>r>>c;
        vector<vector<int> > mat(r,vector<int>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>mat[i][j];
            }
        }
        int ma = INT_MIN;
        for(int i=0;i<r;i++){
            vector<int> ans(c);
            for(int j=i;j<r;j++){
                for(int col=0;col<c;col++){
                    ans[col] += mat[j][col]; 
                }
                ma = max(ma,subsum(ans,c)*(j-i+1));
            }
        }
        cout<<ma<<endl;
 
    }
 
 
    return 0; 
 
 
}
 
