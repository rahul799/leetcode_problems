
https://binarysearch.com/problems/Length-of-Longest-Balanced-Subsequence




Length of Longest Balanced Subsequence
Given a string s containing brackets "(" and ")", return the length of the longest subsequence of balanced brackets.

Constraints

n ≤ 100,000 where n is length of s.
Example 1
Input
s = "())(()"
Output
4
Explanation
We can take the subsequence "()()"

Example 2
Input
s = "))(("
Output
0
Explanation
We can't take any letters from s that's balanced, so the longest balanced subsequence is "" (empty string).

Example 3
Input
s = "))()))()"
Output
4
Explanation
We can take the subsequence "()()". Note that characters in the subsequence do not have to be contiguous.

Example 4
Input
s = "((((())"
Output
4
Explanation
We can make the subsequence (())




we are using stacks here. if the character is "(" then we push it in the stack, and if it is ")" we check if the stack is empty or not. if it empty it means that there is a close bracket without an opening bracket but if it is not it means there exists an opening bracket for this closing bracket and hence push in vector, similarly do it for whole string and at end return the size of the vector.
time complexity-o(n)

int solve(string s) {
    stack<char> m;
    vector<char> r;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            m.push(s[i]);
        } else {
            if (m.empty()) {
                continue;
            } else {
                m.pop();
                r.push_back('(');
                r.push_back(s[i]);
            }
        }
    }
    int count = r.size();
    return count;
}








Maximum balanced subsequnece will be to remove to all invalid_close bracket and extra open bracket
Just iterate through string whenever you get opening bracket increase the count of invalid or extra open bracket; whenever you get close bracket if invalid/extra open bracket count is positive deacrase its count else increase the count of invalid close brackets;
ans =n-(extra_open+invalid_close);
where n is the length of string;

int solve(string s) {
    int ans = 0;
    int n = s.length();
    int invalidopen = 0;
    int invalidclose = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            invalidopen++;
        } else {
            if (invalidopen == 0) {
                invalidclose++;
            } else {
                invalidopen--;
            }
        }
    }
    return n - (invalidopen + invalidclose);
}



