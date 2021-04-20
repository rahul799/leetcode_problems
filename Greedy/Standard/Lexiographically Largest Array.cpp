
https://www.interviewbit.com/test/f2cf2dd30a/#/problem_2

vector<int> Solution::solve(vector<int> &A) {
    
    int n = A.size();
    vector<int> ans;
    int l = 0; 
    while( l < n){
        if(A[l] < A[n -1] )
        break;
        
        else ans.push_back(A[l]);
        l++;
        
    }
    
    for(int k = n-1; k >= l; k--){
        ans.push_back(A[k]);
        
    }
    return ans;
        
    
}

