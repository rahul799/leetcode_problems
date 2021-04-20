784. Letter Case Permutation
Medium

1752

117

Add to List

Share
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.

 

Example 1:

Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: S = "3z4"
Output: ["3z4","3Z4"]
Example 3:

Input: S = "12345"
Output: ["12345"]
Example 4:

Input: S = "0"
Output: ["0"]
 

Constraints:

S will be a string with length between 1 and 12.
S will consist only of letters or digits.






https://leetcode.com/problems/letter-case-permutation/







class Solution {
public:
    /**  
            a1b2   i=0, when it's at a, since it's a letter, we have two branches: a, A
         /        \
       a1b2       A1b2 i=1 when it's at 1, we only have 1 branch which is itself
        |          |   
       a1b2       A1b2 i=2 when it's at b, we have two branches: b, B
       /  \        / \
      a1b2 a1B2  A1b2 A1B2 i=3  when it's at 2, we only have one branch.
       |    |     |     |
      a1b2 a1B2  A1b2  A1B2 i=4 = S.length(). End recursion, add permutation to ans. 
      
      During this process, we are changing the S char array itself
    */
    vector<string> letterCasePermutation( string S ) {
        vector<string> result;
        backtrace( S, 0, result );
        return result;
    }
    
private:
    void backtrace( string S, int i, vector<string> &result ) {
        if( i == S.length() ) {
            result.push_back( S );
            return; 
        } 
        if( 'a' <= S[i] && S[i] <= 'z' ) { // two branches if a letter
            backtrace( S, i + 1, result );
            S[i] = 'A' + S[i] - 'a';
            backtrace( S, i + 1, result );
        } else if ( 'A' <= S[i] && S[i] <= 'Z' ) { // two branch if a letter 
            backtrace( S, i + 1, result );
            S[i] = 'a' + S[i] - 'A';
            backtrace( S, i + 1, result );
        } else { // one branch if a digit
            backtrace( S, i + 1, result );
        }
        
    }
};




Approach 2:



class Solution {
    void backtrack(string &s, int i, vector<string> &res) {
        if (i == s.size()) {
            res.push_back(s);
            return;
        }
        backtrack(s, i + 1, res);
        if (isalpha(s[i])) {
            // toggle case
            s[i] ^= (1 << 5);
            backtrack(s, i + 1, res);
        }
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtrack(S, 0, res);
        return res;
    }
};
