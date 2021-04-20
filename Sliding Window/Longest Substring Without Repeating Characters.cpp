3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        int start = 0, curMax = 0, res = 0;
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); ++i) {
// map will store character as key and index of it's occurqance as position
            if (map.find(s[i]) != map.end() && start <= map[s[i]]) {
                res = max(res, curMax);
                curMax = i - map[s[i]];
                start = map[s[i]] + 1;
                map[s[i]] = i;
            } else {
                curMax++;
                map[s[i]] = i;
            }
        }
        return max(res, curMax);   //bug: final comparison
    }
};


