https://binarysearch.com/problems/Randomized-Binary-Search


Consider a modified binary search, where instead of picking the middle element as the pivot, we pick it randomly between the low and the high indices.

Given a list of integers nums that's not necessarily sorted, return the number of elements that will always be found using this modified binary search.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input

nums = [1, 10, 5, 20]
Output

2
Explanation

We can always find the elements 1 and 20. For the element 5, if we had picked index 1 as the first pivot, we wouldn't be able to find it. Similarly for 10, if we had picked index 2 as the first pivot, it wouldn't be found.

Example 2
Input

nums = [0, 0]
Output

0
Explanation

For the first element, if we search for 0 we may have index 1 as the pivot and miss it. Similarly, if we search for the second element, we may get index 0 as the pivot. In both cases, we miss the elements.

















In an unsorted array, an element at position i can be found by randomized binary search if and only if all the elements before it are strictly smaller than it and all the elements after it are strictly greater than it..
So for every element we have to check if the above conditions apply..
We can maintain a prefix maximum and a suffix minimum to check these conditions in O(1).

Time - O(N)
Space - O(N)

#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        vector<int> left(n);   // largest element from left till i
        vector<int> right(n);  // smallest element from right till i
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            left[i] = max(nums[i], left[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(nums[i], right[i + 1]);
        }
        int ans = 0;
        if (nums[0] < right[1]) {
            ans++;
        }
        if (nums[n - 1] > left[n - 2]) {
            ans++;
        }
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > left[i - 1] && nums[i] < right[i + 1]) {
                ans++;
            }
        }
        return ans;
    }
};

int solve(vector<int>& nums) {
    return (new Solution())->solve(nums);
}


