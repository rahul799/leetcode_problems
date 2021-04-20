

567. Permutation in String
Medium

2132

75

Add to List

Share
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Constraints:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].

Most optimised Approach:



class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Map(26);
        vector<int> s2Map(26);
        int n = s1.size();
        if(s2.size() < n) return false;
        for(int i = 0; i < n; i++){
            s1Map[s1[i] - 'a']++;
            s2Map[s2[i] - 'a']++;
        }
        
        if(s1Map == s2Map) return true;
        for(int i = 1; i <= s2.size() - n; i++)
        {
            s2Map[s2[i-1] - 'a']--;
            s2Map[s2[i + n - 1] - 'a']++;
            if(s1Map == s2Map)
                return true;
        }
        return false;
    }
    
};








Approach #2 Using sorting [Time Limit Exceeded]:
Algorithm

The idea behind this approach is that one string will be a permutation of another string only if both of them contain the same characters the
same number of times. One string xx is a permutation of other string yy only if sorted(x)=sorted(y)sorted(x)=sorted(y).

In order to check this, we can sort the two strings and compare them. We sort the short string s1s1 and all the substrings of s2s2, sort them and compare them
with the sorted s1s1 string. If the two match completely, s1s1's permutation is a substring of s2s2, otherwise not.








public class Solution {

    public boolean checkInclusion(String s1, String s2) {
        s1 = sort(s1);
        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            if (s1.equals(sort(s2.substring(i, i + s1.length()))))
                return true;
        }
        return false;
    }
    public String sort(String s) {
        char[] t = s.toCharArray();
        Arrays.sort(t);
        return new String(t);
    }
}





Complexity Analysis

Time complexity : O\big(l_1log(l_1)+(l_2-l_1)l_1log(l_1)\big)O(l 
1
​	
 log(l 
1
​	
 )+(l 
2
​	
 −l 
1
​	
 )l 
1
​	
 log(l 
1
​	
 )). where l_1l 
1
​	
  is the length of string l_1l 
1
​	
  and l_2l 
2
​	
  is the length of string l_2l 
2
​	
 .

Space complexity : O(l_1)O(l 
1
​	
 ). tt array is used .

Approach #3 Using Hashmap [Time Limit Exceeded]
Algorithm

As discussed above, one string will be a permutation of another string only if both of them contain the same charaters with the same frequency. We can consider every
possible substring in the long string s2s2 of the same length as that of s1s1 and check the frequency of occurence of the characters appearing in the two. If the frequencies of every letter match exactly, then only s1s1's permutation can be a substring of s2s2.

In order to implement this approach, instead of sorting and then comparing the elements for equality, we make use of a hashmap s1maps1map which stores the frequency of 
occurence of all the characters in the short string s1s1. We consider every possible substring of s2s2 of the same length as that of s1s1, find its corresponding hashmap 
as well, namely s2maps2map. Thus, the substrings considered can be viewed as a window of length as that of s1s1 iterating over s2s2. If the two hashmaps obtained are identical
for any such window, we can conclude that s1s1's permutation is a substring of s2s2, otherwise not.




public class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length())
            return false;
        HashMap < Character, Integer > s1map = new HashMap < > ();
        for (int i = 0; i < s1.length(); i++)
            s1map.put(s1.charAt(i), s1map.getOrDefault(s1.charAt(i), 0) + 1);
        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            HashMap < Character, Integer > s2map = new HashMap < > ();
            for (int j = 0; j < s1.length(); j++) {
                s2map.put(s2.charAt(i + j), s2map.getOrDefault(s2.charAt(i + j), 0) + 1);
            }
            if (matches(s1map, s2map))
                return true;
        }
        return false;
    }
    public boolean matches(HashMap < Character, Integer > s1map, HashMap < Character, Integer > s2map) {
        for (char key: s1map.keySet()) {
            if (s1map.get(key) - s2map.getOrDefault(key, -1) != 0)
                return false;
        }
        return true;
    }
}


