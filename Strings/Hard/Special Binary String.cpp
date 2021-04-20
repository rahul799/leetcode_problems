
761. Special Binary String

https://leetcode.com/problems/special-binary-string/discuss/113213/12-liner-readable-clean-C%2B%2B-(with-explanation-and-comments)


Hard

372

125

Add to List

Share
Special binary strings are binary strings with the following two properties:

The number of 0's is equal to the number of 1's.
Every prefix of the binary string has at least as many 1's as 0's.
Given a special string S, a move consists of choosing two consecutive, non-empty, special substrings of S, and swapping them. 
(Two strings are consecutive if the last character of the first string is exactly one index before the first character of the 
second string.)

At the end of any number of moves, what is the lexicographically largest resulting string possible?

Example 1:
Input: S = "11011000"
Output: "11100100"
Explanation:
The strings "10" [occuring at S[1]] and "1100" [at S[3]] are swapped.
This is the lexicographically largest string possible after some number of swaps.
Note:

S has length at most 50.
S is guaranteed to be a special binary string as defined above.



This solution is inspired by @lee215. Here is my key points on why it works (they can all be derived from the definition 
of special string):

Remove a special string prefix from a special string (if possible), the rest must a special string.
(This implies that a special string can be split into one or more special substrings)
A non-splitable special string must start with '1' and end with '0'.
Remove the leading '1' and ending '0' from a non-splitable special string, the rest must be a special string.
(this implies that we can recursively arrange on non-splitable special string to get largest string)
These properties shouldn't be hard to prove. But please let me know if you see any of them is non-trivial.

So the algorithm will be straightforward:

Split given special string s into special substrings specials.
Convert each special substring special recursively to largest lexicographical string.
Sort all maximized special substrings specials in greater lexicographical order.
Join all special substrings specials to form the final result res.
    string makeLargestSpecial(string s) {
        // 1. split s into special substrings
        vector<string> specials; 
        int cnt = 0;
        for (char c : s) {
            if (cnt==0) specials.push_back("");
            c=='1'? ++cnt : --cnt;
            specials.back() += c;            
        }

        // 2. recursively convert each "special" to largest special string
        for (auto& special : specials)
            special = '1' + makeLargestSpecial(special.substr(1, special.size()-2)) + '0';
        
        // 3. sort special substrings in greater lexicographic order
        sort(specials.begin(), specials.end(), greater<string>());

        // 4. join to get largest lexicographic special string
        string res;
        for (auto& special : specials) res += special;
        return res;
    }
    
    
    
    
  According to the description , there are 2 requirement for Special-String

The number of 0's is equal to the number of 1's.
Every prefix of the binary string has at least as many 1's as 0's.
The 2nd definition is essentially saying that at any point of the string, you cannot have more 0's than 1's.

If we map '1' to '(', '0's to ')', a Special-String is essentially Valid-Parentheses, therefore share all the properties of 
a Valid-Parentheses
A VP (Valid-Parentheses) have 2 form:

single nested VP like "(())", or "1100";
a number of consecutive sub-VPs like "()(())", or "101100", which contains "()" + "(())" or "10" + "1100"
And this problem is essentially ask you to reorder the sub-VPs in a VP to make it bigger. If we look at this example
: "()(())" or "101100", how would you make it bigger?
Answer is, by moving the 2nd sub-string to the front. Because deeply nested VP contains more consecutive '('s or '1's in
the front. That will make reordered string bigger.

The above example is straitforward, and no recursion is needed. But, what if the groups of sub-VPs are not in the root level?
Like if we put another "()(())" inside "()(())", like "()(( ()(()) ))", in this case we will need to recursively reorder the
children, make them MVP(Max-Valid-Parentheses), then reorder in root.

To summarize, we just need to reorder all groups of VPs or SS's at each level to make them MVP, then reorder higher level 
VPs;

class Solution {
public:
    string makeLargestSpecial(string s) {
        int i = 0;
        return dfs(s, i);
    }

private:
    string dfs(string& s, int& i) {
        string res;
        vector<string> toks;
        while (i < s.size() && res.empty()) {
            if (s[i++] == '1') toks.push_back(dfs(s, i));
            else res += "1";
        }
        bool prefix = res.size();
        sort(toks.begin(), toks.end());
        for (auto it = toks.rbegin(); it != toks.rend(); it++) res += *it;
        if (prefix) res += '0';
        return res;
    }
};
