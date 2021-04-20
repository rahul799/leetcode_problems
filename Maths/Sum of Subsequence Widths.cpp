

891. Sum of Subsequence Widths
Hard



Share
Given an array of integers A, consider all non-empty subsequences of A.

For any sequence S, let the width of S be the difference between the maximum and minimum element of S.

Return the sum of the widths of all subsequences of A. 

As the answer may be very large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [2,1,3]
Output: 6
Explanation:
Subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
The sum of these widths is 6.
 

Note:

1 <= A.length <= 20000
1 <= A[i] <= 20000







// observation is we do not need the exact order here, we can simply calculate number of times particular item will be maximum or minimum 

class Solution {
public:
    int sumSubseqWidths(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        long power = 1, res = 0, mod = 1e9+7,n = arr.size();
        
        //adding maximums
        //number of times this item will be maximum
        for(int i=0;i<n;i++){
            res = (res + arr[i]*power)%mod;
            power = (power*2)%mod;
        }
        
        //subtracting minimums
        //number of times this item will be minimum
        power = 1;
        for(int i=n-1;i>=0;i--){
            res = (res - arr[i]*power +mod)%mod;
            power = (power*2)%mod;
        }
        return (res+mod)%mod;
    }
};
