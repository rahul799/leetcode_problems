1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
Medium

1012

49

Add to List

Share
Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= limit <= 10^9





Solution 2: Use TreeMap
Use one tree map can easily get the maximum and the minimum at the same time.
In java, we can use TreeMap to count elements.
In cpp, it suports multi treeset, that's even better.

Time O(NogN)
Space O(N)




 int longestSubarray(vector<int>& A, int limit) {
        int i = 0, j;
        multiset<int> m;
        for (j = 0; j < A.size(); ++j) {
            m.insert(A[j]);
            if (*m.rbegin() - *m.begin() > limit)
                m.erase(m.find(A[i++]));
        }
        return j - i;
    }








 int longestSubarray(vector<int>& A, int limit) {
        deque<int> maxd, mind;
        int i = 0, j;
        for (j = 0; j < A.size(); ++j) {
            while (!maxd.empty() && A[j] > maxd.back()) maxd.pop_back();
            while (!mind.empty() && A[j] < mind.back()) mind.pop_back();
            maxd.push_back(A[j]);
            mind.push_back(A[j]);
            if (maxd.front() - mind.front() > limit) {
                if (maxd.front() == A[i]) maxd.pop_front();
                if (mind.front() == A[i]) mind.pop_front();
                ++i;
            }
        }
        return j - i;
    }











