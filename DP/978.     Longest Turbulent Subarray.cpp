https://leetcode.com/problems/longest-turbulent-subarray/



A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if and only if:

For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is even;
OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k is odd.
That is, the subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

Return the length of a maximum size turbulent subarray of A.


nput: [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: (A[1] > A[2] < A[3] > A[4] < A[5])
Example 2:

Input: [4,8,12,16]
Output: 2
Example 3:

Input: [100]
Output: 1






/* Note -- The space complexity can be further reduced to O(1) by using
           2 temporary variables for dp_greater[i+1] and dp_lesser[i+1]
           since we only need these to calculate dp[i] */
class Solution
{
public:
    int maxTurbulenceSize(vector<int>& A);
};

/* Returns the length of the longest turbulent subarray */
int Solution :: maxTurbulenceSize(vector<int>& a)
{
    // Get the size
    int n = a.size();
    
    // Handle the corner case
    if(n==0) return 0;
    if(n==1) return 1;
    
    int dp_greater[n];
    int dp_lesser[n];
    
    /* dp_greater[i] represents the longest turbulent subarray starting at i such that the first element of 
       the turbulent subarray is greater than the second */
    
    /* dp_lesser[i] represents the longest turbulent subarray starting at i such that the first element of 
       the turbulent subarray is less than the second */
    
    // Initialise the dp array
    // dp[i] is atleast 1 for each element, i.e, the element itself
    for(int i=0; i<n ;i++)
    {
        dp_greater[i] = 1;
        dp_lesser[i] = 1;
    }

    // Update the dp matrix starting from the second last element
    for(int i=n-2; i>=0; i--)
    {
        // If this is greater than right neighbour, append it to the lesser_turbulent subarray of the right
        if(a[i] > a[i+1])
            dp_greater[i] = dp_lesser[i+1] + 1;
        
        // Else, if it is less than the right element, append it to the greater_turbulent subarray of the right
        else if(a[i] < a[i+1])
            dp_lesser[i] = dp_greater[i+1] + 1;
    }
    
    // Claculate the maximum length subarray starting at any arbitrary index
    int maxLength = 0;
    for(int i=0; i<n; i++)
        maxLength = max({maxLength, dp_greater[i], dp_lesser[i]});
    
    // Return the maxLength turbulent subarray
    return maxLength;
}
