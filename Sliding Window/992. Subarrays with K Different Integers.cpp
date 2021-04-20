992. Subarrays with K Different Integers
Hard


Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of A.



Here we are using prefix to store the length for which size of window remains same


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int res = 0;
      	vector<int> m(A.size() + 1);
        int end = 0, begin = 0, prefix = 0, cnt = 0;
      	while(end < A.size()) {
        	if (m[A[end++]]++ == 0) ++cnt;
        	if (cnt > K) {
                --m[A[begin++]];
                --cnt;
                prefix = 0;
            }
        	while (m[A[begin]] > 1) {
                ++prefix; 
                --m[A[begin++]];
            }
        	if (cnt == K) 
                res += prefix + 1;
      	}
      	return res;
    }
};





























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
    // we don't want to loose our original left index
            int cur = left; // The key here is to maintain a current index for the subarrays, at the same time don't bother the left index
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



