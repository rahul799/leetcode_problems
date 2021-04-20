



https://leetcode.com/discuss/interview-question/981597/Rubrik-or-OA-Question-or-Minimum-operations-to-transform-array





Given two arrays of size N each containing the elements 1 to N, find the minimum number of operations needed to transform the second array into the first.

An operation is defined as:
Taking any current value in an array and moving it to the beginning or end.

Example:
Turn Array2 into Array1

Array1 = [4,2,3,1,5,6]
Array2 = [3,1,4,6,5,2]

Returns 3:

Operation 1: Move 2 to beginning.
Array2 = [2,3,1,4,6,5]

Operation 2: Move 4 to beginning.
Array2 = [4,2,3,1,6,5]

Operation 3: Move 6 to end:
Array2 = [4,2,3,1,5,6]






Approach:

minimum number of moves = (total number of elements in Array2 - longest subarray-subsequence size)
where longest subarray-subsequence is the subarray of Array1 which is also a subsequence of Array2






Playground link : https://leetcode.com/playground/SCE7oKhM

*/
class Solution {
    /*
    Array1 = A
    Array2 = B
    We need to convert array B into array A
    Note that vice-versa (transforming A into B) could change the answer as length of longest subarray-subSequence could change
    */
    public int getMinMovesToConvertArray1ToArray2(int[] A, int[] B) {
        return (A.length - getLongestSubArraySubSequenceLength(A, B));
    }

    /*
    Generic method to get longest subarray-subSequence length between array A of size 'M' and array 'B' of size 'N'.
    Subarray-subSequence is defined as contiguous subarray in array 'A' which is subsequence in array 'B'.
    
    Assume we have 2 arrays 'B' and 'A' of size 'n' and 'm' respectively :
    B = b1, b2, b3, ....., bj-1, bj, bj+1, ..... bn-1, bn
                                 ^^ (currently getting matched with ai)
    A = a1, a2, a3, ....., ai-1, ai, ai+1, ..... am-1, am
                                 ^^ (currently getting matched with bj)
    
    We want to find longest subarray-subSequence length such that it's a contiguous subarray in array 'A' and subsequence in array 'B'.
    
    Let's assume we have value of the solution in DP[i][j]
    where DP[i][j] holds the longest subarray-subSequence length for subarray in array 'A' from first element till 'i'th element and subsequence in array 'B' from first element till 'j'th element.
    
    When we are at 'i' element in array 'A' and 'j' element in array 'B', we have 2 cases :
    Case 1. either ai == bj
    DP[i][j] = longest subarray-subSequence length for first 'i' elements of 'A' and first 'j' elements of 'B'
             = longest subarray-subSequence length for first 'i - 1' elements of 'A' and first 'j - 1' elements of 'B' + 1 (one is added as ai == bj and contributes in the length of the longest subarray-subSequence)
             = DP[i - 1][j - 1] + 1
    
    Case 2. or ai != bj
    DP[i][j] = longest subarray-subSequence length for first 'i' elements of 'A' and first 'j' elements of 'B'
             = longest subarray-subSequence length for first 'i - 1' elements of 'A' and first 'j' elements of 'B' (ai != aj but ai-1 could have been equal to aj in previous calculations)
             = DP[i - 1][j]
    
    Final value of the solution for 'longest subarray-subSequence length' would be max value of DP[i][j] where i ∈ [1, M] and j ∈ [1, N] and is returned from the method.
    
    Note : Deduction of recurrence in above two cases is similar (slight different) to standard 'LCS' problem.
    */
    private int getLongestSubArraySubSequenceLength(int[] A, int[] B) {
        int M = A.length, N = B.length, longestSubArraySubSequenceLength = 0;
        int[][] DP = new int[M + 1][N + 1];
        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N; j++) {
                if(A[i - 1] == B[j - 1]) {
                    DP[i][j] = 1 + DP[i - 1][j - 1];
                } else {
                    DP[i][j] = DP[i][j - 1];
                }
            }
        }
        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N; j++) {
                longestSubArraySubSequenceLength = Math.max(longestSubArraySubSequenceLength, DP[i][j]);
            }
        }
        return longestSubArraySubSequenceLength;
    }
}
