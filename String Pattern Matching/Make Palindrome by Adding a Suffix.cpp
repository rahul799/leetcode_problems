


Make Palindrome by Adding a Suffix
Question 443 of 987
Given a string s, return the minimum number of characters that can be appended to s to make it a palindrome.

Constraints

n ≤ 100,000 where n is the length of s
Example 1
Input
s = "rad"
Output
2
Explanation
We can add "ar"



int help(string &s) {
    int n = s.size();
    int lps[n];
    lps[0] = 0;
    int i = 1, j = 0;
    while (i < n) {
        if (s[i] == s[j]) {
            lps[i++] = ++j;
        } else {
            if (j)
                j = lps[j - 1];
            else
                lps[i++] = 0;
        }
    }
    return lps[n - 1];
}
int solve(string s) {
    string t = s;
    int n = t.size();
    reverse(t.begin(), t.end());
    t = t + '&' + s;
    return n - help(t);
}
