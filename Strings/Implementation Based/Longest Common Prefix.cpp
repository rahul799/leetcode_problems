
14. Longest Common Prefix
Easy

3903

2182

Add to List

Share
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
  
  



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = 201, k;
        string ans = "";
        if(strs.size() == 0)
            return ans;

        char s = strs[0][0];
        for(int i=0; i<strs.size(); i++) {
            k = strs[i].size();
            n = min(n, k);
            if(s != strs[i][0])
                return ans;
        }
        
        
        for(int i=0; i < n; i++) {
            s = strs[0][i];
            for(int j = 0; j < strs.size(); j++) {
                if(strs[j][i] != s) {
                    return ans;
                }
                
            }
            ans+=s;
        }
        
        return ans;
        
    }
};
