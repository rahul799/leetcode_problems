
Decode List Message
You are given a string s containing digits from 0 - 9 and an integer k. Return the number of different ways that s could represent a list of numbers from [1, k].

Return the result mod 10 ** 9 + 7.

Constraints

n ≤ 100,000 where n is the length of s
Example 1
Input
s = "123"
k = 200
Output
4
Explanation
s could represent [1, 2, 3], [12, 3], [1, 23], [123].



A short iterative DP solution.
For every substring of s from i to j the substring is converted to a number and if the number is less than of equal to k the DP vector is updated: DP[j + 1] += DP[i].

Implementation
Starting at every character of the string i (except if s[i]=='0' to exclude zero-leading substrings) the substring from i to j (including both characters) is converted to a number that should be less than or equal to k and the number of ways to represent the prefix of the string from 0 to j is:
DP[j + 1] = (DP[j + 1] + DP[i]) mod 1000000007; 

Time Complexity
\mathcal{O}(n)O(n) because for every character in the string there is a loop for the next 10 digits maximum

Space Complexity
\mathcal{O}(n)O(n) to store DP results in the vector having the same size as string



int solve(string s, int k) {
    int n = s.size();
    vector<int> res(n + 1);
    res[0] = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        for (long j = i, x = 0; j < min(i + 10, n); j++) {
            x = x * 10 + s[j] - '0';
            if (x > k) break;
            res[j + 1] = (res[j + 1] + res[i]) % 1000000007;
        }
    }
    return res.back();
}
