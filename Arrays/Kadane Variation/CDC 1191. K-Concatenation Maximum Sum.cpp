




1191. K-Concatenation Maximum Sum
Medium

493

45

Add to List

Share
Given an integer array arr and an integer k, modify the array by repeating it k times.

For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].

Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.

As the answer can be very large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [1,2], k = 3
Output: 9
Example 2:

Input: arr = [1,-2,1], k = 5
Output: 2
Example 3:

Input: arr = [-1,-2], k = 7
Output: 0
 

Constraints:

1 <= arr.length <= 105
1 <= k <= 105
-104 <= arr[i] <= 104







#define mod 1000000007
typedef long long ll;

class Solution {
    ll kadane(vector<int>& arr) {
        ll curr_sum = 0;
        ll sum_so_far = 0;
        for(int i=0; i<arr.size(); i++)
        {
            curr_sum += arr[i];
            if(curr_sum < 0)
                curr_sum = 0;
            else if(curr_sum > sum_so_far)
                sum_so_far = curr_sum;
            
        }
        return sum_so_far%mod;
    }
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        //if (k==1) means simply do to Kadane's Algo and done
        if(k==1)
            return kadane(arr);
        
        // if (k != 1) that means we have to modify our array
        ll sum=0;
        for(int i=0; i<arr.size() ; i++)
            sum+=arr[i];
        
        // Let's have a 2 copy of original array.
        vector<int> newv;
            for(int i=0; i<2*arr.size(); i++)
                newv.push_back(arr[i%arr.size()]);
        
        if(sum<0)   // if sum if -ve then apply Kadane's over new vector
            return kadane(newv);
        
        else        // if sum is +ve means we have to apply Kadane's over n*k array
            return kadane(newv) + (k-2)*sum%mod;
            //taking Kadane's of 2 copy and adding (k-2) times the sum of original array.

    }
};
