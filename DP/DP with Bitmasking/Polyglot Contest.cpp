
Polyglot Contest
You are given a two-dimensional list of strings languages, where languages[i] is a list of programming languages person i is fluent in.

Consider any list of programming languages such that everyone knows at least one language in it. Return the minimum size of such list.

Constraints

1 ≤ n, m ≤ 16 where n and m are the number of rows and columns in languages.
1 ≤ l ≤ 32 where l is the total number of distinct strings in languages.
Example 1
Input
languages = [
    ["Java", "Perl"],
    ["C++", "Python"],
    ["Haskell"]
]
Output
3
Explanation
There is no overlap between the languages. Therefore any combination that uses one language from each participant is valid.

Example 2
Input
languages = [
    ["Java", "C++", "Python"],
    ["Python", "Cobol", "Java"],
    ["C++", "Haskell"],
    ["Ruby", "C++"]
]
Output
2
Explanation
Valid combinations are ["Cobol", "C++"], ["Java", "C++"] and ["Python", "C++"].

Example 3
Input
languages = [
    ["C", "Python", "Haskell", "Kotlin"],
    ["Java", "JavaScript", "C++", "Rust"],
    ["JavaScript", "Python", "C++"],
    ["Ruby", "C++"],
    ["Rust", "Python", "Java"]
]
Output
2
Explanation
The only minimal combination is ["Python", "C++"].







Define:
dp[mask], the minimum number of languages that we need in order to cover all the persons from the mask.
language_masks[i], a mask representing the persons that know language i.

Now we just need to iterate over each mask, set any particular person and try to pick a language that that person knows and update the dp.

Implementation
In order to update dp[mask]:
Pick just one person from the mask (it can be any bit that is set to 1).
Iterate over the languages that that person is knowing.
Now we need to eliminate all the persons that know that language.
In order to do this just use the formula:
new_mask = mask ^ (mask & language_masks[language])
Now update dp[mask] with min(dp[mask], 1 + dp[new_mask])

Time Complexity
\mathcal{O}(2^p * c)O(2 
p
 ∗c) where p is the number of rows and c is the number of columns.

Space Complexity
\mathcal{O}(2^p)O(2 
p
 ) where p is the number of rows

int solve(vector<vector<string>>& languages) {
    int persons_count = languages.size();

    vector<int> dp(1 << persons_count, INT32_MAX);

    unordered_map<string, int> language_masks;
    for (int i = 0; i < languages.size(); ++i) {
        for (const auto& language : languages[i]) {
            language_masks[language] |= (1 << i);
        }
    }

    dp[0] = 0;
    for (int mask = 1; mask < (1 << persons_count); ++mask) {
        int bit = __builtin_ctz(mask);

        for (auto& l : languages[bit]) {
            int new_mask = mask ^ (language_masks[l] & mask);
            dp[mask] = min(dp[mask], 1 + dp[new_mask]);
        }
    }

    return dp[(1 << persons_count) - 1];
}

int solve(vector<vector<string>>& languages) {
    int n = languages.size();
    unordered_set<string> L;
    for (auto v : languages)
        for (auto l : v) L.insert(l);
    vector<string> VL(L.begin(), L.end());
    unordered_map<string, int> dict;
    int m = VL.size();
    for (int i = 0; i < m; ++i) dict[VL[i]] = i;
    vector<vector<bool>> can(n, vector<bool>(m));
    for (int i = 0; i < n; ++i)
        for (auto l : languages[i]) can[i][dict[l]] = true;
    vector<int> dp(1 << n, 1e9);
    dp[0] = 0;
    for (int i = 0; i < m; ++i) {
        vector<int> ndp(dp);
        for (int last = 0; last < (1 << n); ++last) {
            if (dp[last] == 1e9) continue;
            int nxt = last;
            for (int j = 0; j < n; ++j)
                if (can[j][i]) nxt |= (1 << j);
            ndp[nxt] = min(ndp[nxt], dp[last] + 1);
        }
        dp = move(ndp);
    }
    return dp[(1 << n) - 1];
}
