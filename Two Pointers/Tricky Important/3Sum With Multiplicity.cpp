923. 3Sum With Multiplicity

Share
Given an integer array A, and an integer target, return the number of tuples i, j, k  such that i < j < k and A[i] + A[j] + A[k] == target.

As the answer can be very large, return it modulo 109 + 7.

 

Example 1:

Input: A = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (A[i], A[j], A[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.
Example 2:

Input: A = [1,1,2,2,2,2], target = 5
Output: 12
Explanation: 
A[i] = 1, A[j] = A[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways




class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int n = A.size();
        sort(A.begin(), A.end());
        int ans = 0; 
        int mod = 1e9+7;
        for (int i=0; i<n-2; ++i) {
            int lo = i+1, hi = n-1;
            while (lo < hi) {
                if (A[i] + A[lo] + A[hi] == target) {
                    int cntlo=1, cnthi=1;
                    while (lo < hi && A[lo] == A[lo+1]) {cntlo++; lo++;}
                    while (lo < hi && A[hi] == A[hi-1]) {cnthi++; hi--;}
					// A[lo]==A[hi]
                    if (lo == hi) ans =(ans+cntlo*(cntlo-1)/2)%mod;
					// A[lo]!=A[hi]
                    else ans = (ans+cntlo*cnthi)%mod;
                    lo++; hi--; 
                } else if (A[i] + A[lo] + A[hi] > target) {
                    hi--;
                } else {
                    lo++;
                }
            }
            //cout << ans << endl;
        }
        return ans;
    }
};
