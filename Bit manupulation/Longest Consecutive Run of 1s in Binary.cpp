Longest Consecutive Run of 1s in Binary
Question 123 of 1000
Given a non-negative integer n, return the length of the longest consecutive run of 1s in its binary representation.

Constraints

0 ≤ n < 2 ** 31
Example 1
Input
n = 156
Output
3
Explanation
156 is10011100 in binary and there's a run of length 3.








Trying to find the length of each block of ones, and find out the maximum.

Implementation
Iterating over the bits of the given number n:

If a one is encountered then increment the counter variable.
When a zero is encountered then check if ans can be updated and reinitialize count to 0.
Example #1
n = 884
The binary representation of n = 0001101110100
Moving from right, first block of 1s has size = 1, then 3, and then 2. So our answer is 3.

Time Complexity
\mathcal{O}(\log(n))O(log(n)) : As we iterate over the bits of N.

Space Complexity
\mathcal{O}(1)O(1) : As we don't store anything other than cnt and ans.


https://binarysearch.com/problems/Longest-Consecutive-Run-of-1s-in-Binary/editorials/2934196





int solve(int n) {
    int ans = 0;
    int counter = 0;
    for (int i = 0; i < 32; i++) {
        if ((1 << i) & n)
            counter++;
        else
            counter = 0;
        ans = max(counter, ans);
    }
    return ans;
}
