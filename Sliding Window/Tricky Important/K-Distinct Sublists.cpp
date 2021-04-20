K-Distinct Sublists
Given a list of integers nums and an integer k, return the number of sublists such that there's exactly k distinct numbers in the sublist.

Constraints

k ≤ n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [1, 1, 2, 3]
k = 2
Output
3
Explanation
We have the following sublists which have exactly 2 distinct numbers: [1, 1, 2], [1, 2], [2, 3]




Intuition
This is a great problem, but we need to get the idea -> exactly k is very hard by at most k is very easy (slide a window with the frequencies)

Implementation
atmost function will check how many sublists have atmost k distinct elements

wtf is res += r - l + 1; ?
simple...
this window moves forward with the right/r pointer that's cool right?

So how many sublists ending at this value of right/r ? EXACTLY how many values of left/l are possible for this right/r and 
notice when this line executes there will NEVER be more than k elements inside the window (while loop removes them ;)

Time Complexity
\mathcal{O}(n)O(n) optimal, see we only move the right and left pointers from 0 to n at most ;)

Space Complexity
\mathcal{O}(n)O(n) for the hash map of frequencies inside the atmost function;)





int solve(vector<int>& nums, int k) {
    auto atmost = [&](int k) {
        unordered_map<int, int> fre;
        int res = 0;
        for (int r = 0, l = 0; r < nums.size(); r++) {
            fre[nums[r]]++;

            while (fre.size() > k) {
                fre[nums[l]]--;
                if (fre[nums[l]] == 0) fre.erase(nums[l]);
                l++;
            }
            res += r - l + 1;
        }
        return res;
    };

    return atmost(k) - atmost(k - 1);
}
