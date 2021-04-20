



1239. Maximum Length of a Concatenated String with Unique Characters
Medium

823

81

Add to List

Share
Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.

Return the maximum possible length of s.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible solutions are "chaers" and "acters".
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
 

Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lower case English letters







class Solution {
public:
    int maxLength(vector<string>& arr) {
        int res = 0;
        string s = "";
        for(int i = 0; i < arr.size(); i++)
           res = max(res ,backtrack(arr, s, i));
        
        return res;
        
    }
    
    int backtrack(vector<string>& arr, string str,  int start){
        
        unordered_set<char>s(str.begin(), str.end());
        if (s.size() != ((int)str.length())) 
            return 0;
        
        int ret = str.length();
        for (int i = start; i < arr.size(); i++)
            ret = max(ret, backtrack(arr, str+arr[i], i+1));

        return ret;
    }
    
};
