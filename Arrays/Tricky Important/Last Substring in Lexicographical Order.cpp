LeetCode 1163. Last Substring in Lexicographical Order




Given a string  s, return the last substring of  s in lexicographical order.

Example 1:

Input: "abab"
 Output: "bab"
 Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".
Example 2:

Input: "leetcode"
 Output: "tcode"
Note:

1 <= s.length <= 10^5
s contains only lowercase English letters.
Key observation: The last substring must be a suffix of the original string, can't a substring in the middle since we can always extend it.
eg leetcode -> tcode, can't be “t”, “tc”, “tco ”, “tcod”

Solution 1: Brute Force
Try all possible suffixes.
Time complexity: O(n^2)
Space complexity: O(1)












Consider the following cases:

Input: zyxbzyxa
Expected output: zyxbzyxa

Input: zyxbzyxc
Expected output: zyxc
We have two index pointers, i and j. i will always be set to the index of the final substring result. j is a moving 
lookahead index pointer that is used to loop through and compare the character at j with the character at i.

When s[i] and s[j] are the same (the first z and the second z in the above example), we need to compare the characters next
to them (the first y and the second y). Since they are the same, we need to compare the characters next to them (the first
x and the second x), and so on. To achieve this, we use an offset k to compare the k character next to i and j. Note that 
k starts at 0, and this is essentially comparing characters s[i+k] and s[j+k].

When s[i+k] is bigger than s[j+k], we just need to let i remain as is, continue move j forward to the next character at j+k+1,
and reset k back to 0.

When s[i+k] is smaller than s[j+k], this means that the substring starting at j is a better result than the substring at i. At
this point, there are two situations to consider:

When j is more than i+k: Consider an input hhhccchhhddd, when i is 0, j is 6, and k is 3, both i and j are pointing to h, and 
you are comparing the first c and the first d. You would want to set i = j.
When j is less than i+k: Consider an input nnnp, when i is 0, j is 1, and k is 2, you are comparing the last n and p. You 
would want to change i to point to p, so you need to set i = i+k+1. Note that in this case, even though j is equal to i+1, j
is not always equal to i+1 (see situation 1 above), and hence you should not use i = j+k.
So with the above considerations, when s[i+k] is smaller than s[j+k], we can simply set i = Math.max(i + k + 1, j).

In the end, the result would be the substring starting at i.





class Solution {
public:
    string lastSubstring(string s) {
         ios_base::sync_with_stdio(0); cin.tie(0);   
        int pointer1=0,pointer2=1,currletter=0;
        while(pointer2+currletter<s.size()){
            if(s[pointer1+currletter] == s[pointer2+currletter]){
                currletter++;
            } else if(s[pointer1+currletter] < s[pointer2+currletter]){
                pointer1 = pointer2;
                pointer2++;
                currletter=0;
            } else {
                pointer2+=currletter+1;
                currletter=0;
            }
        }
        return s.substr(pointer1);
    }
};






class Solution {
public:
  string lastSubstring(string_view s) {
    string_view ans;
    for (int i = 0; i < s.length(); ++i)
      if (s.substr(i) > ans) ans = s.substr(i);
    return string(ans);
  }
};
Solution 2: Keep max and compare with candidates
Find the first largest letter as a starting point, whenever there is a same letter, keep it as a candidate and compare with the current best. If the later is larger, take over the current best.

eg "acbacbc"

“C”> “a”, the first “c” becomes the best.
“c” = “c”, the second “c” becomes a candidate
starting compare best and candidate.
“cb” = “cb”
“cba” < "Cbc", cand_i is the new best.

Time complexity: O(n)
Space complexity: O(1)


// Author: Huahua
class Solution {
public:
  string lastSubstring(string s) {
    int max_i = 0;
    char max_c = 0;
    int cand_i = 0;
    int l = 0;
    
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] > max_c) {
        // Find a better starting point.
        max_c = s[i];
        max_i = i;
        cand_i = -1;
        l = 1;
      } else if (cand_i != -1) {
        // Has a candidate.
        if (s[i] > s[max_i + l]) {
          // The candidate is larger.
          max_i = cand_i;
          cand_i = -1;
        } else if (s[i] == s[max_i + l]) {
          // The candidate is the same as current best.
          ++l;
        } else {
          // The candidate is smaller, no longer needed.
          cand_i = -1;
        }
      } else if (s[i] == max_c) {
        // Find a new candidate, starting with length 1.
        cand_i = i;
        l = 1;
      } 
    }
    
    return s.substr(max_i);
  }
};
