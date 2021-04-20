Longest Strictly Increasing then Decreasing Sublist
Question 692 of 834
You



You are given a list of integers nums. Return the length of the longest sublist such that its length is at least 3 and its values are strictly increasing and 
then decreasing. Both the increasing part and the decreasing part must be non-empty.

Constraints

n ≤ 100,000 where n is the length of nums


nums = [7, 1, 3, 5, 2, 0]
Output

5




#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(vector<int>& nums) {
        vector<int> decreasing(nums.size(), 1);
        vector<int> increasing(nums.size(), 1);

        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] > nums[i + 1]) decreasing[i] = decreasing[i + 1] + 1;
        }

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) increasing[i] = increasing[i - 1] + 1;
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (increasing[i] > 1 && decreasing[i] > 1)
                ans = max(ans, increasing[i] + decreasing[i] - 1);
        }

        if (ans < 3)
            return 0;
        else
            return ans;
    }
};


int solve(vector<int>& nums) {
    return (new Solution())->solve(nums);
}
