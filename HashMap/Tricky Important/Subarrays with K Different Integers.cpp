
992. Subarrays with K Different Integers
Hard

1416

24

Add to List

Share
Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of A.

 

Example 1:

Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
Example 2:

Input: A = [1,2,1,3,4], K = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

Note:

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length











class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        if (K == 0 || A.size() == 0) return 0;
        
        int left = 0, right = 0, rst = 0;
        unordered_map<int, int> m; // number -> occurance
        while (right < A.size())
        {
            m[A[right]] ++;
            right ++;
            
            while (m.size() > K) // erase front if oversee
            {
                if (m[A[left]] > 1){
                    m[A[left]] --;
                } else {
                    m.erase(A[left]);
                }
                left ++;
            }
            
            
            int cur = left;
            
            
            
            // [1,2,1,2, 3]
            
            
            
            // The key here is to maintain a current index for the subarrays, at the same time don't bother the left index
            while (m.size() == K) // If the subarray has K distince integers, need to check it's subarray
            {
                rst ++;
                if (m[A[cur]] > 1){
                    m[A[cur]] --;
                } else {
                    m.erase(A[cur]);
                }
                cur ++;
            }
            
            while (cur > left) { // put all the subarray values back
                m[A[cur-1]] ++;
                cur --;
            } 
        }
        
        return rst;
    }
};
