Longest Prefix that Is a Suffix
Question 710 of 906
Given a string s, return the longest prefix of s that is not equal to s and exists as a suffix of s.




https://binarysearch.com/problems/Longest-Prefix-that-Is-a-Suffix



Constraints

n ≤ 100,000 where n is the length of s
Example 1
Input
s = "abazfaba"
Output
"aba"
Explanation
"aba" is the longest prefix that is also a suffix

Example 2
Input
s = "aaa"
Output
"aa"








string solve(string s) {
    int n = s.size();
    vector<int> pre(n);
    int i = 0, j = 1;
    while (j < n) {
        if (s[i] == s[j]) {
            pre[j] = i + 1;
            i++;
            j++;
        } else if (i != 0 && s[i] != s[j]) {
            i = pre[i - 1];
        } else {
            j++;
        }
    }

    int l = pre[n - 1];
    string ans = s.substr(0, l);
    return ans;
}
