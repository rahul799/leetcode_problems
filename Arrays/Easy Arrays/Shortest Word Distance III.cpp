245. Shortest Word Distance III
Medium

247

76

Add to List

Share
Given an array of strings wordsDict and two strings that already exist in the array word1 and word2, return the shortest distance between these two words in the list.

Note that word1 and word2 may be the same. It is guaranteed that they represent two individual words in the list.

 

Example 1:

Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "coding"
Output: 1
Example 2:

Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "makes"
Output: 3
 

Constraints:

1 <= wordsDict.length <= 3 * 104
1 <= wordsDict[i].length <= 10
wordsDict[i] consists of lowercase English letters.
word1 and word2 are in wordsDict.






class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int ret = words.size() - 1;
        int t1 = -1;
        int t2 = -1;
        
        for(int i=0;i<words.size();i++)
        {
            if(words[i]==word1)
            {
                t1 = i;
                if(t2 != -1 && ret > t1 - t2)
                {
                    ret = t1 - t2;
                }
            }
            
            if(words[i]==word2)
            {
                t2 = i;
                if(t1 != -1 && t1 != t2 && ret > t2 - t1)
                {
                    ret = t2 - t1;
                }
            }
        }
        
        return ret;
    }
};
