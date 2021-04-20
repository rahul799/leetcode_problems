





https://binarysearch.com/problems/Sort-String-by-Flipping




Sort String by Flipping
Question 174 of 991
You are given a string s consisting of the letters "x" and "y". In addition, you have an operation called flip, which changes a single "x" to "y" or vice versa.

Determine the smallest number of times you would need to apply this operation to ensure that all "x"'s come before all "y"'s.

Constraints

n ≤ 100,000 where n is the length of s
Example 1
Input
s = "xyxxxyxyy"
Output
2
Explanation
It suffices to flip the second and sixth characters.








int solve(string s) {
    int n = 0;
    int x = 0, y = 0;
    for (char ch : s) x += ch == 'x', y += ch == 'y';
    int ans = min(x, y);
    int px = 0, py = 0;

    for (char ch : s) {
        px += ch == 'x';
        py += ch == 'y';
        int cost = py + (x - px);
        ans = min(ans, cost);
    }
    return ans;
}





int solve(string s) {
    int n = s.size();
    if (n == 0) {
        return 0;
    }
    int dp[n] = {0};
    dp[0] = 0;
    int countx = 0, county = 0;
    if (s[0] == 'x') {
        countx++;
    } else {
        county++;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == 'x') {
            int a = dp[i - 1] + 1;
            int b = county;
            int c = countx + 1;
            dp[i] = min({a, b, c});
        } else {
            int a = dp[i - 1];
            int b = countx;
            int c = county + 1;
            dp[i] = min({a, b, c});
        }
        if (s[i] == 'x') {
            countx++;
        } else {
            county++;
        }
    }
    return dp[n - 1];
}
