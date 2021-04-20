1208. Get Equal Substrings Within Budget



https://leetcode.com/problems/get-equal-substrings-within-budget/discuss/670264/Very-simple-C%2B%2B-Sliding-Window-with-explanation



Medium

340

25

Add to List

Share
You are given two strings s and t of the same length. You want to change s to t. Changing the i-th character of s to i-th character of t costs |s[i] - t[i]| that is, the absolute difference between the ASCII values of the characters.

You are also given an integer maxCost.

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of twith a cost less than or equal to maxCost.

If there is no substring from s that can be changed to its corresponding substring from t, return 0.

 

Example 1:

Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd". That costs 3, so the maximum length is 3.
Example 2:

Input: s = "abcd", t = "cdef", maxCost = 3
Output: 1
Explanation: Each character in s costs 2 to change to charactor in t, so the maximum length is 1.
Example 3:

Input: s = "abcd", t = "acde", maxCost = 0
Output: 1
Explanation: You can't make any change, so the maximum length is 1.
 

Constraints:

1 <= s.length, t.length <= 10^5
0 <= maxCost <= 10^6
s and t only contain lower case English letters.





int equalSubstring(string s, string t, int cost) {
        int size = s.size();
        int start=0,end=0;
        int count=0;
        int max_len=0;
        for(;end<size;end++){
            count += abs((s[end]-'a')-(t[end]-'a'));
			
            while(count>cost){
				//srinking  window 
                count -= abs((s[start]-'a')-(t[start]-'a'));
                start++;
            }
            max_len = max(max_len,end-start+1);
        }
        return max_len;
    }






