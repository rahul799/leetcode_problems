



Make Palindrome by Adding a Suffix
Question 443 of 1000
Given a string s, return the minimum number of characters that can be appended to s to make it a palindrome.

Constraints

n ≤ 100,000 where n is the length of s
Example 1
Input
s = "rad"
Output
2
Explanation
We can add "ar





https://binarysearch.com/problems/Make-Palindrome-by-Adding-a-Suffix/editorials/1063810

We observe that if our string s is of the form 

Hence, we can add a^ra 
r
  at the end of string s to obtain a palindrome. Now how do we find the length of
a^ra 
r
  (or aa). We can do that by search for s^r = (b^{r})^r\ b^r\ a^r = b\ b^r\ a^rs 
r
 
  in string s. The extent of string s^rs 
r
  that is present in string ss gives us the length of a^ra 
r
  (or aa). For efficient search we can use KMP algorithm.
  
  
  
  
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
