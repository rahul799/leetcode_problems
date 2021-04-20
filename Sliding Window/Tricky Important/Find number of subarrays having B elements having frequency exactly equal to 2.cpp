
https://www.interviewbit.com/test/f2cf2dd30a/#/problem_1

Find number of subarrays having B elements having frequency exactly equal to 2

Approach : directly calculating subarrays having exactly b ELEMENTS IS DIFICULT, better approach :


fun (at most B elements freq 2) - fun (at most B -1 elements having freq 2) 
int fun(vector<int>& a, int b){
    
    int n = a.size();
    int ans = 0;
    int occ = 0, j = 0;
    int countOcc[10009] = {0};
    for(int i = 0; i < n; i++){
        if(countOcc[a[i]] + 1 ==2) occ++;
        countOcc[a[i]]++;
        while(occ > b && j < n){
            if(countOcc[a[j]] == 2) occ--;
             countOcc[a[j]]--;
            j++;
        }
        ans += i - j + 1;
    }
    return ans;
        
    }
    
int Solution::solve(vector<int> &A, int B) {
    return fun(A, B) - fun(A, B-1);
}
