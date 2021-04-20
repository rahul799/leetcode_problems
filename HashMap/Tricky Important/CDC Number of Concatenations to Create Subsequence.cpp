

https://binarysearch.com/contest/Weekly-Contest-51-1Gz9m7UGHD/editorials/4102850?questionsetIndex=1



Number of Concatenations to Create Subsequence
You are given two lowercase alphabet strings s and t. Return the minimum number of times we must concatenate s such that t is a subsequence of s. For example,
if we concatenate "abc" three times, we'd get "abcabcabc". If it's not possible, return -1.

Constraints

1 ≤ n ≤ 100,000 where n is the length of s
1 ≤ m ≤ 100,000 where m is the length of t
Example 1
Input
s = "dab"
t = "abbd"
Output
3
Explanation
If we concatenate a = "dab" three times, we can get "dabdabdab". And "abbd" is a subsequence of "dabdabdab".

Example 2
Input
s = "abc"
t = "def"
Output
-1
Explanation
It's impossible to make t a subsequence of s





Stroe the index of each character in string s. Then for every character in t, get the index that is strictly greater than the previously taken index.
  If we can't find any index that is greater than the previous index then start over and add +1 to the answer.

Implementation
We can use HashMap to store the index of every character in s. Then go through t to find the next possible index using binary_search (upper_bound in c++).

Time Complexity
We use Binary Search to get the next element for every chacracter of t. So the total time complexity would be \mathcal{O}(n \cdot logn)O(n⋅logn)

Space Complexity
For each character we only store the indicies, so the Space Complexity is \mathcal{O}(n)O(n)
  
  
  



int solve(string s, string t) {
    unordered_map<char, set<int>> mp;
    int n = (int)s.size();
    for (int i = 0; i < n; i++) {
        mp[s[i]].insert(i);
    }
    int now = -1;
    int ans = 1;
    for (char& c : t) {
        if (!mp.count(c)) return -1;
        auto it = mp[c].upper_bound(now);
        if (it == mp[c].end()) {
            ans++;
            now = *mp[c].begin();
        } else {
            now = *it;
        }
    }
    return ans ;
}
