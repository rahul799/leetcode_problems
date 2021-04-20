Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.




class Solution {
public:
        string minWindow(string s, string t) {
        unordered_map<char,int> map1; // map1  is the pattern string
        unordered_map<char,int> map2; // map2 defines window string
        int minLength = INT_MAX;
        string result;
        for(char &c:t)map1[c]++;   
        int slow=0,fast=0,lettercounter=0;
        for(fast = 0; fast<s.length();fast++)
        {
            char ch=s[fast];
            if(map1.find(ch)!=map1.end())
            {
                map2[ch]++;
            if(map2[ch]<= map1[ch])
                lettercounter++;
            }
            if(lettercounter>=t.length())
            {
                // current character is not in the string, move  my slow pointer
                while(map1.find(s[slow])==map1.end()||map2[s[slow]]>map1[s[slow]])
                {
                    map2[s[slow]]--;
                    slow++;
                }
                if(fast-slow+1<minLength)
                {
                    minLength=fast-slow+1;
                    result=s.substr(slow,minLength);
                }
            }
        }
        return result;
    }
        
    
};
