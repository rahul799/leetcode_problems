

https://binarysearch.com/problems/Longest-Substring-with-Even-Vowel-Counts


Longest Substring with Even Vowel Counts
Question 742 of 909






We do not need to know the exact count, of how many vowels are even or odd at a current point we can just use a bit to represent a current vowel if it is 1 than we have odd occurrence of the current vowel else we have even occurrence of the current vowel in the substring s [0....i]

Implementation
As we go through our string, we update mask, and track the smallest index for each mask combination. If we encounter the same mask later in the string, that means the string between smallest and current index is a valid substring

Example #1
in case you are still having hard time understanding the solution it's same as lc 1371 you can check votrubac and lee's solution they have explained the problem using pictures here external link's are banned otherwise i would have pasted it here
in case if you like the editorial do upvote ^_^





int solve(string s) {
    map<vector<int>, int> mp;  //  prefix vowels -> idx
    int n = s.size();
    vector<int> sum(5, 0);
    mp[sum] = -1;
    int res = 0;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == 'a') {
            sum[0] ^= 1;
        } else if (c == 'e') {
            sum[1] ^= 1;
        } else if (c == 'i') {
            sum[2] ^= 1;
        } else if (c == 'o') {
            sum[3] ^= 1;
        } else if (c == 'u') {
            sum[4] ^= 1;
        }
        if (mp.count(sum)) {
            // cout << mp[sum] << " " << i << endl;
            res = max(res, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }
    /*
    for (auto p : mp) {
        for (auto i : p.first) {
            cout << i;
        }
        cout << ": " << p.second << endl;
    }
    */
    return res;
}





int solve(string s) {
    unordered_map<char, int> m{{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
    string helper = "aeiou";
    unordered_map<int, int> dp;
    dp[0] = -1;
    int curr = 0;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (helper.find(s[i]) != -1) {
            curr ^= 1 << (m[s[i]]);
        }
        if (dp.find(curr) == dp.end())
            dp[curr] = i;
        else
            ans = max(ans, i - dp[curr]);
    }
    return ans;
}
