
1525. Number of Good Ways to Split a String
Medium

307

10

Add to List

Share
You are given a string s, a split is called good if you can split s into 2 non-empty strings p and q where its concatenation is equal to s and the number of distinct letters in p and q are the same.

Return the number of good splits you can make in s.

 

Example 1:

Input: s = "aacaba"
Output: 2
Explanation: There are 5 ways to split "aacaba" and 2 of them are good. 
("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.
("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.
("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.
Example 2:

Input: s = "abcd"
Output: 1
Explanation: Split the string as follows ("ab", "cd").
Example 3:

Input: s = "aaaaa"
Output: 4
Explanation: All possible splits are good.
Example 4:

Input: s = "acbadbaada"
Output: 2
 

Constraints:

s contains only lowercase English letters.
1 <= s.length <= 10^5






class Solution {
public:
    int numSplits(string str) {
        int n = str.length();
        
        vector<int> pref(n), suff(n);
        
        unordered_map<char, int> freq;
        
        for(int i = 0; i < n; i++)
        {
            freq[str[i]]++;
            pref[i] = freq.size();
        }
        
        freq.clear();
        
        for(int i = n -1; i >= 0; i--)
        {
            freq[str[i]]++;
            suff[i] = freq.size();
            
        }
       
        int ans = 0;
        for(int i = 1; i < (n); i++)
        {
            if(pref[i - 1] == suff[i])
                ans++;
        }
        
        return ans;
        
    }
};
























 a  c  b  a  d  b  a  a  d  a "
 1  2  3  3  4 5 5 5    5  5  5
5  5  4   4   4  3  3      2   1
 




class Solution {
public:
    int numSplits(string s) {
        int count = 0; 
        int len = s.size() - 1;
        unordered_set<char> mp1, mp2;
        vector<int> pref(s.size(), 0), suff(s.size(), 0);
        for(int i = 0; i < s.size(); i++){
            mp1.insert(s[i]);
            mp2.insert(s[len - i]);
            pref[i] = mp1.size();
            suff[len - i] = mp2.size();
        }
        
        for(int i = 1; i <= len; i++){
            if(pref[i -1] ==  suff[i]) 
               count++; 
        }
        
        return count;
        
    }
};




