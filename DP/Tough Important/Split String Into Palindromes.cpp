


https://www.youtube.com/watch?v=WPr1jDh3bUQ&ab_channel=IDeserve

https://github.com/ramankgp/Leetcode-Solutions2020/new/master/DP/Tough%20Important


firstly i have created basic palindrome substring dp array from which i can able to check if substring is palindrome or not
idea is simple each character is palindrome and for length 2 substring we will check s[i]==s[i+1]
then whole dp array can be filled dp[j+1][k-1] and s[j]==s[k]
the comes the cut array we will check after placing cut at each interval that string is palindrome or not if it is then cut[i]=0;
we wont be cutting string else we will check from j=0 to j<i where we will get minimum partitioning .
at last we will return cut[n-1] +1 because these are the string which we will be in need





Split String Into Palindromes
Question 52 of 995
Given a lowercase alphabet string s, split it into as few strings as possible such that each string is a palindrome and return the number of strings.

Constraints

0 ≤ n ≤ 1,000 where n is the length of s
Example 1
Input
s = "amanaplanacanalpanama"
Output
1
Explanation
The whole string is a palindrome.

Example 2
Input
s = "racecarannakayak"
Output
3
Example 3
Input
s = "abc"
Output
3
Example 4
Input
s = "atabatab"
Output
2
Explanation
This can be split into ["ata", "batab"] or ["atabata", "b"].





int solve(string s) {
    int n = s.length();
    if (n == 0) {
        return 0;
    }
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        a[i][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < n - i + 1; j++) {
            int k = i + j - 1;
            // special check for two length palindrome
            if (i == 2) {
                if (s[j] == s[k]) {
                    a[j][k] = 1;
                }

            } else if (a[j + 1][k - 1] && s[j] == s[k]) {
                a[j][k] = 1;
            }
        }
    }
    vector<int> cut(n);
    for (int i = 0; i < n; i++) {
        int temp = INT_MAX;
        if (a[0][i]) {
            cut[i] = 0;
        } else {   // checking for minimum possible cut
            for (int j = 0; j < i; j++) {
                if (a[j + 1][i] && temp > cut[j] + 1) {
                    temp = cut[j] + 1;
                }
            }
            cut[i] = temp;
        }
    }
    return cut[n - 1] + 1;
}
