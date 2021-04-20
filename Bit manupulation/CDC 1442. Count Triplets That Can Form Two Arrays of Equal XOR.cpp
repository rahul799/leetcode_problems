1442. Count Triplets That Can Form Two Arrays of Equal XOR
Medium





Add to List

Share
Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.

 

Example 1:

Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
Example 2:

Input: arr = [1,1,1,1,1]
Output: 10
Example 3:

Input: arr = [2,3]
Output: 0
Example 4:

Input: arr = [1,3,5,7,9]
Output: 3
Example 5:

Input: arr = [7,11,12,9,5,2,7,17,22]
Output: 8
 

Constraints:

1 <= arr.length <= 300
1 <= arr[i] <= 10^8






class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // Time Complexity: O(n^2)
        // Space Complexity: O(n)
        
        int n(arr.size()), ans(0);
        int xors[n + 1]; xors[0] = 0;
        
        for (int i = 0; i < n; ++i)
            xors[i + 1] = xors[i] ^ arr[i];
        
        for (int i = 0; i < n; ++i)
            for (int k = i + 1; k < n; ++k)
                // j ranges from i + 1 to k
                // we check if xors[j] ^ xors[i] == xors[k + 1] ^ xors[j]
					// property of xor: x ^ x = 0, 0 ^ x = x ^ 0 = x
					// Thus, a_i ^ ... ^ a_j = (a_1 ^ ... ^ a_(i - 1)) ^ (a_1 ^ ...^ a_(i - 1) ^ a_i ^ ... ^ a_j)
					//                       = xors[i - 1] ^ xors[j].
                // which is equivalent to xors[i] == xors[k + 1]
                // if that is true, it is true for every j, and we increment ans by k - i
                if (xors[i] == xors[k+1])
                    ans += k - i;
        return ans;
    }
};
