1358. Number of Substrings Containing All Three Characters
Medium

632

15

Add to List

Share
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.




I am using a map(f) for storing the frequency of the characters.
l and r are the left and right pointers each.
Once we reach a point where frequency of all the characters >0 then the number of substrings possible are size(s) - r. Now shifting the left pointer and calculating the answer for each case while the condition holds that f[a], f[b], f[c] > 0

int numberOfSubstrings(string s) {
        map<char, int> f;
        int l=0, r=0, cnt=0;
        int n = s.size();
        while(r < n) {
            f[s[r]]++;
            while(f['a'] && f['b'] && f['c']) {
                cnt += n-r;
                f[s[l++]]--;
            }
            r++;
        }
        return cnt;
    }
