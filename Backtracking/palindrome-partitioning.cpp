131. Palindrome Partitioning
Medium


Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]


The problem has a nice structure that backtracking naturally fits in. The structure is, given a starting position start, we search from start till the end of the string. Once we reach a position i such that the sub-string from start to i (s.substr(start, i - start + 1)) is a palindrome, we add it to a temporary par. Then we recursively call the same function to process the remaining sub-string. Once we reach the end of the string, we add par into the result pars 
of all the possible partitioning.

Then, backtracking happens. Remember that at position i, we find s.substr(start, i - start + 1) to be a palindrome and we 
immediately add it to par. It is obvious that there may be some other position j such that j > i and 
s.substr(start, j - start + 1) 
  is also a palindrome. So we need to recover to the state before adding s.substr(start, i - start + 1) to par and continue 
  to find
  the next palindrome position after i. And we simply need to pop s.substr(start, i - start + 1) out of par to make things 
  work.

  
  
  
  
  The idea is to generate all possible substrings of a given string and expand each possibility if is a potential candidate.
    The first thing that comes to our mind is Depth First Search. In Depth First Search, we recursively expand potential candidate until the defined goal is achieved. After that, we backtrack to explore the next potential candidate.

Backtracking incrementally build the candidates for the solution and discard the candidates (backtrack) if it doesn't
  satisfy the condition.

The backtracking algorithms consists of the following steps:

Choose: Choose the potential candidate. Here, our potential candidates are all substrings that could be generated from the 
given string.

Constraint: Define a constraint that must be satisfied by the chosen candidate. In this case, the constraint is that the 
string must be a palindrome.

Goal: We must define the goal that determines if have found the required solution and we must backtrack. Here, our goal is
achieved if we have reached the end of the string.

Algorithm

In the backtracking algorithm, we recursively traverse over the string in depth-first search fashion. For each recursive call,
the beginning index of the string is given as \text{start}start.

Iteratively generate all possible substrings beginning at \text{start}start index. The \text{end}end index increments from
\text{start}start till the end of the string.

For each of the substring generated, check if it is a palindrome.

If the substring is a palindrome, the substring is a potential candidate. Add substring to the \text{currentList}currentList
and perform a depth-first search on the remaining substring. If current substring ends at index \text{end}end, \text
{end}+1end+1 becomes the \text{start}start index for the next recursive call.

Backtrack if \text{start}start index is greater than or equal to the string length and add the \text{currentList}currentList
to the result.
  
  
  
  
  
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) return ret;
        
        vector<string> path;
        dfs(0, s, path, ret);
        
        return ret;
    }
    
    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
        if(index == s.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, path, ret);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};
