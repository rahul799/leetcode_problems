Minimum Deletions From the Ends for Equilibrium
Question 177 of 991
Given an integer list nums containing 0s and 1s, you can delete numbers from the front or from the back.

Return the minimum number of deletions such that the remaining list has an equal number of 0s and 1s.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [1, 1, 1, 1, 0, 0]
Output
2
Explanation
You can delete the first two 1s so that there's two 1s and two 0s.

Example 2
Input
nums = [0, 1, 1, 0]
Output
0
Explanation
This list already has equal number of 1s and 0s.


int solve(vector<int>& nums) {
    unordered_map<int, int> m;
    int diff = 0;
    m[diff] = -1;
    int mlen = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 1)
            diff++;
        else
            diff -= 1;
        if (m.find(diff) != m.end()) {
            mlen = max(mlen, i - m[diff]);
        } else {
            m[diff] = i;
        }
    }
    return nums.size() - mlen;
}
