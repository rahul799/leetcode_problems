
1788. Maximize the Beauty of the Garden
Hard

16

3

Add to List

Share
There is a garden of n flowers, and each flower has an integer beauty value. The flowers are arranged in a line. You are given an integer array flowers of size n and each flowers[i] represents the beauty of the ith flower.

A garden is valid if it meets these conditions:

The garden has at least two flowers.
The first and the last flower of the garden have the same beauty value.
As the appointed gardener, you have the ability to remove any (possibly none) flowers from the garden. You want to remove flowers in a way that makes the remaining garden valid. The beauty of the garden is the sum of the beauty of all the remaining flowers.

Return the maximum possible beauty of some valid garden after you have removed any (possibly none) flowers.

 

Example 1:

Input: flowers = [1,2,3,1,2]
Output: 8
Explanation: You can produce the valid garden [2,3,1,2] to have a total beauty of 2 + 3 + 1 + 2 = 8.
Example 2:

Input: flowers = [100,1,1,-3,1]
Output: 3
Explanation: You can produce the valid garden [1,1,1] to have a total beauty of 1 + 1 + 1 = 3.
Example 3:

Input: flowers = [-1,-2,0,-1]
Output: -2
Explanation: You can produce the valid garden [-1,-1] to have a total beauty of -1 + -1 = -2.
 

Constraints:

2 <= flowers.length <= 105
-104 <= flowers[i] <= 104
It is possible to create a valid garden by removing some (possibly none) flowers.













The only modification to the standard prefix sum-based approach that is used in questions such as Subarray Sum Equals K is that we don't 
add negative values to the rolling sum. This is because we can arbitrarily delete values ("remove flowers") from the subarray that exists between
the first occurence of a given flower f and the current occurrence of f, in an attempt to maximize the score of the subarray. For example, for flowers = [2, 1, -3, 1], 
we can remove the flower with beauty -3 and attain a higher score from the subarray [1, -3, 1].



class Solution {
public:
    int maximumBeauty(vector<int>& flowers) {
        unordered_map<int, int> mymap;
        int res = INT_MIN;
        int sum = 0;
        for (int beauty : flowers) {
            if (mymap.count(beauty) > 0) {
                // I have removed both the elements so add twice of  that
                res = max(res, sum - mymap[beauty] + 2 * beauty);
            }
            // 
            // i can remove negative elemetns any time, so only consider positive elements
            if (beauty > 0) {
                sum += beauty;
            }
            
            if (mymap.count(beauty) == 0) {
                mymap[beauty] = sum;
            }
        }
        
        return res;
    }
};

