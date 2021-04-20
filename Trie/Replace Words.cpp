
648. Replace Words
Medium



https://leetcode.com/problems/replace-words/


Share
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

 

Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
Example 3:

Input: dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
Output: "a a a a a a a a bbb baba a"
Example 4:

Input: dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 5:

Input: dictionary = ["ac","ab"], sentence = "it is abnormal that this solution is accepted"
Output: "it is ab that this solution is ac"
 

Constraints:

1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 10^6
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Each two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.








struct trie{

struct trie* child[26];
bool isend;

trie(){
   
    isend=false;
    
    for(int i = 0; i < 26; i++)
        child[i] = NULL;
    
}
};

struct trie* root;

void insert(string str){

struct trie* cur=root;
for(char ch:str){
    
    int idx=ch-'a';
    if(cur->child[idx]==NULL)
        cur->child[idx]=new trie;
    cur=cur->child[idx];
}
cur->isend=true;
}

string getRoot(string str){

struct trie* cur=root;
string s="";
for(auto i: str){
    
    
    if(cur->child[i - 'a']!=NULL){
        
        
        s+=i;
        cur=cur->child[i - 'a'];
    }
    else 
        break;
    if(cur->isend==true)
        break;
}
if(s.length()!=0 and cur->isend==true) return s;
return str;
}

class Solution {
public:
 string replaceWords(vector<string>& dictionary, string sentence) {
    
    root=new trie;
    string temp;
    
    for(auto i: dictionary){
        insert(i);
    }
    
    string t="";
    
    vector<string> words;
    
    stringstream ss(sentence); 

    while(ss >> temp) 
    {
        words.push_back(temp);
    }
    
    for(int i=0; i<words.size(); i++){
        
        if(i!=words.size()-1){
            t+=getRoot(words[i])+' ';
        }
        else{
            t+=getRoot(words[i]);
        }
    }
    return t;
}
};
