

https://leetcode.com/problems/word-pattern/



290. Word Pattern
Easy

1688

208

Add to List

Share
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", s = "dog dog dog dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lower-case English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.









class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // goal
        // given a pattern of char
        // return true/false if string s follows the same pattern
        
        
        // questions/info
        // pattern length -> 1 and 300
        // s length -> 1 and 3000
        // s substrings are separated by a space
        // s does not contain any trailing or leading spaces
        
        // process
        // 1st map -> for char map -> unordered_map<char, int>
        // 2nd map -> for string map -> unordered_map<string, int>
        // loop over our string, make sure number of substring == size of pattern
        // time complexity -> o(n), size of pattern/number of substrings in s        
        // space complexity -> o(n), size of ordered_maps based on size of pattern/number substring of s 
    
            
        unordered_map<char, string> char_map;
        unordered_map<string, char> string_map;
        
        stringstream ss (s);
        string holder;
        int i = 0;           
        int num_substring = 0;
        
        while (ss >> holder) {                        
            if (char_map.count(pattern[i]) == 0 && string_map.count(holder) == 0) {                
                char_map[pattern[i]] = holder;
                string_map[holder] = pattern[i];                         
            } else if (char_map.count(pattern[i]) == 1 && string_map.count(holder) == 1) {                
                if (char_map[pattern[i]] != holder || string_map[holder] != pattern[i]) {
                    return false;
                }                
            } else {
                return false;                                            
            }    
            i++;
            num_substring++;
        }
        return num_substring == pattern.size() ? true : false;                
    }
};
