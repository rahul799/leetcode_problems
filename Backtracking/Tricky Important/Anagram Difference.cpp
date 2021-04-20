





Anagram Difference
Question 454 of 1000
You are given two strings s0 and s1 which are anagrams of each other. Return the minimum number of swaps necessary within s0 to make it equal to s1.

Constraints

n ≤ 25 where n is the length of s0 and s1
Example 1
Input
s0 = "dom"
s1 = "mod"
Output
1
Explanation
We just need 1 swap between "d" and "m" to turn "dom" into "mod".






Lets ignore the already matching characters and make a new s0 and s1 that has all characters that dont match. (For example, "abc" and "acb" become "bc" and "cb".

Now, for every index i of s0, we want to match it with the character s1[i]. We are going to try every matching character at index j>i in s0 and recursively go to the next index i+1.

Implementation
I implemented backtracking by choosing a matching character for every index i in s1.

Time Complexity
\mathcal{O}(2^n)O(2 
n
 ) Backtracking is always hard to compute the time complexity. I'm simply upperbounding this

Space Complexity
\mathcal{O}(2^n)O(2n
 ) Backtracking is always hard to compute the time complexity. I'm simply upper bounding this



void swap(string& s, int l, int r) {
    char tmp = s[l];
    s[l] = s[r];
    s[r] = tmp;
}

int backtrack(string& s, string& target, int idx, int swaps) {
    if (idx == s.size()) return swaps;
    if (s[idx] == target[idx]) return backtrack(s, target, idx + 1, swaps);

    int res = INT_MAX;
    for (int cand = idx + 1; cand < s.size(); cand++) {
        if (s[cand] == target[idx]) {
            swap(s, idx, cand);
            res = min(res, backtrack(s, target, idx + 1, swaps + 1));
            swap(s, idx, cand);
        }
    }
    return res;
}

int solve(string s0, string s1) {
    int n = s0.length();
    string new_s0 = "", new_s1 = "";
    for (int i = 0; i < n; i++) {
        if (s0[i] != s1[i]) {
            new_s0 += s0[i];
            new_s1 += s1[i];
        }
    }
    return backtrack(new_s0, new_s1, 0, 0);
}
