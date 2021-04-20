


126. Word Ladder II
Hard

2323

278

Add to List

Share
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words such that:

The first word in the sequence is beginWord.
The last word in the sequence is endWord.
Only one letter is different between each adjacent pair of words in the sequence.
Every word in the sequence is in wordList.
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the strings in wordList are unique.




class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> visit;  //notice we need to clear visited word in list after finish this level of BFS
        queue<vector<string>> q;
        unordered_set<string> wordlist(wordList.begin(),wordList.end());
        q.push({beginWord});
        bool flag= false; //to see if we find shortest path
        while(!q.empty()){
            int size= q.size();
            for(int i=0;i<size;i++){            //for this level
                vector<string> cur = q.front();
                q.pop();
                vector<string> newadd =  addWord(cur.back(),wordlist); 
                for(int j=0;j<newadd.size();j++){   //add a word into path
                    vector<string> newline(cur.begin(),cur.end());
                    newline.push_back(newadd[j]);
                    if(newadd[j]==endWord){       
                     flag=true;
                    res.push_back(newline);
                    }
                    visit.insert(newadd[j]);
                    q.push(newline);
                }
            }
            if(flag) break;  //do not BFS further 
            for(auto it=visit.begin();it!=visit.end();it++) wordlist.erase(*it); //erase visited one 
            visit.clear();
        }
        return res;
    }
    
    // find words with one char different in dict
    // hot->[dot,lot]
    vector<string> addWord( string word,unordered_set<string>& wordlist ){
        vector<string> res;
        for(int i=0;i<word.size();i++){
            char s =word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(wordlist.count(word)) res.push_back(word);
            }
            word[i]=s;
        }
        return res;
    }
};












