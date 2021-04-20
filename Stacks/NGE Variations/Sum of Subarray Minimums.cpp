907. Sum of Subarray Minimums
Medium

1633

107

Add to List

Share
Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 

Note:

1 <= A.length <= 30000
1 <= A[i] <= 30000
 

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104




907. Sum of Subarray Minimums
Medium

1633

107

Add to List

Share
Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 

Note:

1 <= A.length <= 30000
1 <= A[i] <= 30000
 

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104











// key trick is to find the number on the left and right and then the product is going to be the product of both of them

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        stack<int>s;
        int n=A.size();
        vector<long long>r(n,n),l(n,-1);
        for(int i=0;i<n;i++){
            while(s.empty()==0 and A[s.top()]>=A[i])s.pop();
            if(s.empty()==0)l[i]=s.top();
            s.push(i);
        }
        s=stack<int>();
        for(int i=n-1;i>-1;i--){
            while(s.empty()==0 and A[s.top()]>A[i])s.pop();
            if(s.empty()==0)r[i]=s.top();
            s.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++)ans=(ans+A[i]*(i-l[i])*(r[i]-i))%(long long)(1e9+7);
        return ans;
    }
};

