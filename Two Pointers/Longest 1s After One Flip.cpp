
Longest 1s After One Flip
Question 834 of 905
You are given a string s containing 1s and 0s. Given that you can flip at most one "0", return the length of the longest contiguous substring of 1s.

Constraints

n ≤ 100,000 where n is the length of s.
Example 1
Input
s = "10110"
Output
4
Explanation
If we flip the first zero then we get "11110".







int solve(string s) {
    int ret = 0;
    int ones = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            ret = max(ret, ++ones);
        } else {
            int curr = ones + 1;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] == '1') {
                    curr++;
                } else {
                    break;
                }
            }
            ret = max(ret, curr);
            ones = 0;
        }
    }
    return ret;
}
