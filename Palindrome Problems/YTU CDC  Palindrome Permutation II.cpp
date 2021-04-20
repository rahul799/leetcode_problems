
https://leetcode.com/problems/palindrome-permutation-ii/

267. Palindrome Permutation II
Medium

538

68

Add to List

Share
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

Example 1:

Input: "aabb"
Output: ["abba", "baab"]
Example 2:

Input: "abc"
Output: []





class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> result;
        unordered_map<char, int> charCount;
        int oddCnt=0, N=0;
        string mid;
        for (int i=0; i<s.size(); i++)
            charCount[s[i]] ++;
        for (auto &c : charCount) {
            if (c.second & 1) {
                mid = c.first;
                oddCnt++;
            }
            c.second /= 2;
            N += c.second;
        }
        if (oddCnt > 1)
            return result;
        helper(charCount, "", mid, N, result);
        return result;
    }
private:
    void helper(unordered_map<char, int> &charCount, string s, string &mid, int &N, vector<string> &r) {
        if (s.size() == N) {
            string rev = s;
            reverse(rev.begin(), rev.end());
            r.push_back(s + mid + rev);
            return;
        }
        for (auto &c : charCount) {
            if (c.second > 0) {
                c.second--;
                helper(charCount, s+c.first, mid, N, r);
                c.second++;
            }
        }
    }
};










class Solution {
 public :
    vector < string > generatePalindromes( string s) {
        unordered_set < string > res;
        unordered_map < char , int > m;
         string t = "" , mid = "" ;
         for (auto a: s) ++ m[a];
         for (auto it: m) {
             if (it.second% 2 == 1 ) mid += it.first;
            t += string (it.second / 2 , it.first);
             if (mid.size()> 1 ) return {};
        }
        permute(t, 0 , mid, res);
         return vector< string > (res.begin(), res.end());
    }
    void permute( string &t, int start, string mid, unordered_set< string > & res) {
         if (start >= t.size()) {
            res.insert(t + mid + string (t.rbegin(), t.rend()));
        } 
        for ( int i = start; i <t.size(); ++ i) {
             if (i != start && t[i] == t[start]) continue ;
            swap(t[i], t[start]);
            permute(t, start + 1 , mid, res);
            swap(t[i], t[start]);
        }
    }
};
