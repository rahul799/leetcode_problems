


Base 3 to Integer
Given a string s representing a number in base 3 (consisting only of 0, 1, or 2), return its decimal integer equivalent. This should be implemented directly without using a built-in function.

Example 1
Input
s = "10"
Output
3
Example 2
Input
s = "21"
Output
7



int solve(string s) {
    int res = 0;
    int i = 0;
    while (i < s.length()) {
        res = res * 3 + (s[i] - '0');
        i++;
    }
    return res;
}
