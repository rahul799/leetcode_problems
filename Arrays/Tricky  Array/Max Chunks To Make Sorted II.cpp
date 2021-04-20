
768. Max Chunks To Make Sorted II
Hard

535

22

Add to List

Share
This question is the same as "Max Chunks to Make Sorted" except the integers of the given array are not necessarily distinct, the input array could be up to length 2000, and the elements could be up to 10**8.

Given an array arr of integers (not necessarily distinct), we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
Example 2:

Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
Note:

arr will have length in range [1, 2000].
arr[i] will be an integer in range [0, 10**8].











If the range [L, R) is one of the chunks, than the values in range [L,R) should be the same after sorting.
We can extend this to say that the values in range [0, R) should be the same after sorting(every chunk before [L, R) has the same property).

To check whether values in range [0, R) is the same after sorting, we only need to check
if max of values in range [0,R) is smaller than or equal to the min of values in range [R, N).
Each chunk is counted only once at its right boundary.



class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int N = arr.size();
        // Max[i]:Max value in range [0, i)
        vector<int> Max(N+1, INT_MIN);
        for(int i = 1 ; i <= N ; ++i)
            Max[i] = max(Max[i-1], arr[i-1]);
        
        // Min[i]:Min value in range [i,N)
        vector<int> Min(N+1, INT_MAX);
        for(int i = N - 1 ; i >= 0 ; --i)
            Min[i] = min(Min[i+1], arr[i]);
        
        // Calculate Chunks
        int nChunks = 0;
        for(int i = 1 ; i <= N ; ++i){
            // if max of range[0, i) <= min of range[i, N)
            // add 1 to number of chunks.
            nChunks += Max[i] <= Min[i];
        }
        return nChunks;
    }
};
