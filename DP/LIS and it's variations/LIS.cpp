





class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 0){
            return 0;
        }
        
        vector<int> lis;
        
        lis.push_back(nums[0]);
        
        for(int i = 1; i<n; i++){
            
            if(nums[i] > lis.back()){
                lis.push_back(nums[i]);
            }
            else{
                
                int p = lower_bound(lis.begin(),lis.end(),nums[i]) - lis.begin();
                
                lis[p] = nums[i];
            }
        }
        
        return lis.size();
    }
};













/* Dynamic Programming C++ implementation of LIS problem */
#include<bits/stdc++.h> 
using namespace std; 
	
/* lis() returns the length of the longest increasing 
subsequence in arr[] of size n */
int lis( int arr[], int n ) 
{ 
	int lis[n]; 

	lis[0] = 1; 

	/* Compute optimized LIS values in bottom up manner */
	for (int i = 1; i < n; i++ ) 
	{ 
		lis[i] = 1; 
		for (int j = 0; j < i; j++ ) 
    // this is the trickest part. don't miss it!!
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1) 
				lis[i] = lis[j] + 1; 
	} 

	// Return maximum value in lis[] 
	return *max_element(lis, lis+n); 
} 
	
/* Driver program to test above function */
int main() 
{ 
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 }; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printf("Length of lis is %d\n", lis( arr, n ) ); 
	return 0; 
}
