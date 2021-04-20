62. Shortest Subarray with Sum at Least K
Hard

1228

32

Add to List

Share
Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.

If there is no non-empty subarray with sum at least K, return -1.

 
 
 
 
 https://www.youtube.com/watch?v=_JDpJXzTGbs&ab_channel=TechLifeWithShivank




Example 1:

Input: A = [1], K = 1
Output: 1
Example 2:

Input: A = [1,2], K = 4
Output: -1
Example 3:

Input: A = [2,-1,2], K = 3
Output: 3




 
 We will maintain the queue in increasing order which means the front part  is going to have the smallest element whereas the end part is going to
 
 contain the largest element
 

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n =  A.size();
        
        vector<long>prefix_sum(n+1,0);
        for(int i=0;i<n;i++)
            prefix_sum[i+1] = prefix_sum[i] + A[i];
        
        deque<int>q;
        int ans = INT_MAX;
        
        for(int i=0;i<=n;i++){ 
            // pop from front if the number difference in prefix sum index is greater than k
            while(!q.empty() && prefix_sum[i] - prefix_sum[q.front()] >= K){
                ans = min(ans, i- q.front());
                q.pop_front();
            }
    // if it is decreasing order pop from the back
            //trickiest part here
         
         
            while(!q.empty() && prefix_sum[i] - prefix_sum[q.back()] <=0 )
                q.pop_back();
            
            q.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
        
    
};











        
