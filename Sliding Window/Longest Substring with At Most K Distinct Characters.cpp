340. Longest Substring with At Most K Distinct Characters
Hard



Share
Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.



class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> mp;
        int res = 0;
        for(int i = 0, j = 0; j < s.size(); j++){
            if(mp.find(s[j]) == mp.end()){
                mp[s[j]] =  1;
            }else{
                mp[s[j]]++;
            }
            
            while(mp.size() > k){
                if(mp[s[i]] > 1){
                    mp[s[i]]--;
                }else{
                    mp.erase(s[i]);
                }
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};







class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int freq[256] = {0};  // frequency counter
        int left = 0, max_len = 0, unique_chars = 0;
        
        for (int right = 0; right < s.size(); ++right) {
            char right_char = s[right];
            if (freq[right_char] == 0) {
                // increment unique_chars only for the first
                // occurence of a character in our window
                ++unique_chars;
            }
            // expand window to the right
            ++freq[right_char];
            
            // if number if unique characters exceeds k
            // we need to shrink the window
            while (unique_chars > k) {
                char left_char = s[left++];
                --freq[left_char];
                // decrement unique_chars only if all instances
                // of a single character are no longer in our window
                if (freq[left_char] == 0) {
                    --unique_chars;
                }
            }
            
            // right - left + 1 = length of the current substring
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};




