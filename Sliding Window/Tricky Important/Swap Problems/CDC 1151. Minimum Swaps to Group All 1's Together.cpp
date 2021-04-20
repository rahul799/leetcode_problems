


1151. Minimum Swaps to Group All 1's Together
Medium


https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/



298

2

Add to List

Share
Given a binary array data, return the minimum number of swaps required to group all 1’s present in the array together in any place in the array.

 

Example 1:

Input: data = [1,0,1,0,1]
Output: 1
Explanation: 
There are 3 ways to group all 1's together:
[1,1,1,0,0] using 1 swap.
[0,1,1,1,0] using 2 swaps.
[0,0,1,1,1] using 1 swap.
The minimum is 1.
Example 2:

Input: data = [0,0,0,1,0]
Output: 0
Explanation: 
Since there is only one 1 in the array, no swaps needed.
Example 3:

Input: data = [1,0,1,0,1,0,0,1,1,0,1]
Output: 3
Explanation: 
One possible solution that uses 3 swaps is [0,0,0,0,0,1,1,1,1,1,1].
Example 4:

Input: data = [1,0,1,0,1,0,1,1,1,0,1,0,0,1,1,1,0,0,1,1,1,0,1,0,1,1,0,0,0,1,1,1,1,0,0,1]
Output: 8
 

Constraints:

1 <= data.length <= 105
data[i] is 0 or 1.







class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = 0;
        // count the number of 1s
        for (int d : data) {
            ones += d;
        }
        if (ones == 1 || ones == data.size()) {
            return 0;
        }
        int zeros = 0;
        for (int i = 0; i < ones; i++) {
            if (data[i] == 0) 
                zeros++;
        }
        int minZeros = zeros;
        for (int i = 1; i < data.size() - ones + 1; i++) {
            int windowEnd = i + ones - 1;
            if (data[windowEnd] == 0) {
                zeros++;
            } 
            if (data[i - 1] == 0) {
                zeros--;
            }
          
            if (zeros < minZeros) {
                minZeros = zeros;
            }
        }
        return minZeros;
    }
};








class Solution {
public:
    int minSwaps(vector<int>& data) {
        int c1 = 0;
        
        // Count total 1s
        for (int i = 0; i < data.size(); i++) {
            c1 = data[i] == 1 ? c1 + 1 : c1;
        }
        
        // sliding window of size c1
        // find no. of zeros in each window
        // select the window having min no. of zeros to swap 1s
        int cs = 0;
        for (int i = 0; i < c1; i++) {
            cs = data[i] == 0 ? cs + 1 : cs;
        }
        
        int res = cs;
        for (int i = c1; i < data.size(); i++) {
            if (data[i-c1] == 0)
                cs--;
            
            if (data[i] == 0)
                cs++;
            
            res = res < cs ? res : cs;
        }
        
        return res;
    }
};
