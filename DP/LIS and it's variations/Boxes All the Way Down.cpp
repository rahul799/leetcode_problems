
Boxes All the Way Down


You are given a two-dimensional list of integers boxes. Each list contains two integers [width, height] which represent the width and height of a box. Given that you can put a box in another box if both of its width and height are smaller than the other box, return the maximum number of boxes you can fit into a box.


https://binarysearch.com/problems/Boxes-All-the-Way-Down



Constraints

The number of lists in boxes is at most 100,000.
Example 1
Input

matrix = [
    [10, 10],
    [9, 9],
    [5, 5],
    [4, 9]
]
Output

3
Explanation

We can fit the box [5, 5] into [9, 9] which we can fit into the [10, 10] box.



First, we want to sort the boxes by one of the dimension.
If boxes of width is strictly increasing, we can reduce the problem to "Longest Increasing Subsequence"(LIS) that can be solved in NlogN time using greedy binary search.

However, boxes could have the same width, and you can't place one in the other.
To resolve this issue, we can sort the other dimension (height) in decreasing order if they have the same width, this will ensure that during the LIS algorithm, 
we won't place boxes with same width
inside the other.



#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(vector<vector<int>>& matrix) {
        sort(matrix.begin(), matrix.end(), [](auto a, auto b) {
            if (a[0] == b[0]) return a[1] > b[1];  // sort ht by larger
            return a[0] < b[0];                    // width by smaller first
        });
        vector<int> hts;
        for (auto x : matrix) {
            hts.push_back(x[1]);
        }
        vector<int> lis;
        for (int x : hts) {
            auto lower = lower_bound(lis.begin(), lis.end(), x);
            if (lower == lis.end())
                lis.push_back(x);
            else
                *lower = x;
        }
        return lis.size();
    }
};


int solve(vector<vector<int>>& matrix) {
    return (new Solution())->solve(matrix);
}
