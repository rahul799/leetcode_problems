




Longest String Chain



1048. Longest String Chain
Medium

1503

96

Add to List

Share
Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chain is "a","ba","bda","bdca".
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of English lowercase letters






bool mycompare(string a,string b)
{
return a.length()<b.length();
}

class Solution {
public:
int longestStrChain(vector<string>& words) {
sort(words.begin(),words.end(),mycompare);
unordered_map<string,int>dp;
for(int i=0;i<words.size();i++) 
dp[words[i]]=1;
    
int result=1;
for(string word:words)
{
    for(int j=0;j<word.length();j++)
    {
        string search=word;
        search.erase(j,1);
        if(dp.find(search)!=dp.end())
         dp[word]=max(dp[word],1+dp[search]);
    }
    result=max(result,dp[word]);
}
    return result;
}
};
