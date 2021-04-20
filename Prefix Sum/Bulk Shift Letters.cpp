
Bulk Shift Letters
You are given a lowercase alphabet string s and a list of integers shifts. Each element shifts[i] means to shift the first i + 1 letters of s by shifts[i] positions. Shifting a letter should wrap over "z" to "a". For example, shifting “z” by 2 results in “b”.

Return the resulting string after applying shifts to s.

Constraints

1 ≤ n ≤ 100,000 where n is the length of s and shifts
Example 1
Input
s = "afz"
shifts = [1, 2, 1]
Output
"eia"
Explanation
We shift the first 1 letter by 1 position to get: "bfz"
We shift the first 2 letters by 2 position to get: "dhz"
We shift the first 3 letters by 1 position to get: "eia"


Intuition
The later shifts accumulate to the former shifts so if we find the iterate direction properly, we can save some memory.

Implementation
Go backward and sum the shifts from back to front to a current shift, and apply this shift at the current index.

Time Complexity
\mathcal{O}(n)O(n) because we have to step on each index once.

Space Complexity
\mathcal{O}(1)O(1) for controlling variables only but nothing else.






string solve(string s, vector<int>& shifts) {
    int d = 0;
    int i = s.size() -1 ;
   while(i >= 0) {
        (d += shifts[i]) %= 26;
        if (d) s[i] = (s[i] - 'a' + d) % 26 + 'a';
        i--;
    }
    return s;
}





