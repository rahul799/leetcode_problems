

https://binarysearch.com/contest/Weekly-Contest-44-pr2UzmqsSR?questionsetIndex=1



Characters in Each Bracket Depth
You are a given a string s containing "X", "(", and ")". The string has balanced brackets and in between there are some "X"s along with possibly nested brackets recursively.

Return the number of "X"s at each depth of brackets in s, from the shallowest depth to the deepest depth.

Constraints

2 ≤ n ≤ 100,000 where n is the length of s
Example 1
Input
s = "(XX(XX(X))X)"
Output
[3, 2, 1]
Explanation
There's three "X"s at depth 0. Two "X"s at depth 1. And one "X" at depth 2.

Example 2
Input
s = "(())"
Output
[0, 0]
Explanation
There's no "X"s but depth goes to 1.



vector<int> solve(string s) {
    unordered_map<int, int> m;
    int d = 0, maxd = 0;
    for (auto &ch : s) {
        if (ch == '(')
            d += 1;
        else if (ch == ')')
            d -= 1;
        else
            m[d] += 1;
        maxd = max(maxd, d);
    }
    vector<int> ret(maxd);
    for (auto [dep, nu] : m) {
        ret[dep - 1] = nu;
    }
    return ret;
}
