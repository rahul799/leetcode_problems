https://binarysearch.com/problems/Number-of-Sublists-With-Sum-of-Target


Number of Sublists With Sum of Target
Question 383 of 764
Given a list of integers nums and an integer target, return the number of sublists whose sum is equal to target.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input

nums = [2, 0, 2]
target = 2
Output

4

xplanation

We have these sublists whose sum is 2: [2], [2, 0], [0, 2], [2]




#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<int>& nums, int target) {
       unordered_map<int, int> mp;
       int count = 0 , sum = 0;
       mp[0] = 1;
       for(int  i= 0; i < nums.size(); i++){
       sum += nums[i];
       if(mp.find(sum - target) != mp.end())
       count += mp[sum - target];
        mp[sum]++;
    }
    return count;
    }
};
