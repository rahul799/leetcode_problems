



642. Design Search Autocomplete System
Hard

1254

90

Add to List

Share
Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special character '#'). For each character they type except '#', you need to return the top 3 historical hot sentences that have prefix the same as the part of sentence already typed. Here are the specific rules:

The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same degree of hot, you need to use ASCII-code order (smaller one appears first).
If less than 3 hot sentences exist, then just return as many as you can.
When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.
Your job is to implement the following functions:

The constructor function:

AutocompleteSystem(String[] sentences, int[] times): This is the constructor. The input is historical data. Sentences is a string array consists of previously typed sentences. Times is the corresponding times a sentence has been typed. Your system should record these historical data.

Now, the user wants to input a new sentence. The following function will provide the next character the user types:

List<String> input(char c): The input c is the next character typed by the user. The character will only be lower-case letters ('a' to 'z'), blank space (' ') or a special character ('#'). Also, the previously typed sentence should be recorded in your system. The output will be the top 3 historical hot sentences that have prefix the same as the part of sentence already typed.

 
Example:
Operation: AutocompleteSystem(["i love you", "island","ironman", "i love leetcode"], [5,3,2,2])
The system have already tracked down the following sentences and their corresponding times:
"i love you" : 5 times
"island" : 3 times
"ironman" : 2 times
"i love leetcode" : 2 times
Now, the user begins another search:

Operation: input('i')
Output: ["i love you", "island","i love leetcode"]
Explanation:
There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman". Also we only need to output top 3 hot sentences, so "ironman" will be ignored.

Operation: input(' ')
Output: ["i love you","i love leetcode"]
Explanation:
There are only two sentences that have prefix "i ".

Operation: input('a')
Output: []
Explanation:
There are no sentences that have prefix "i a".

Operation: input('#')
Output: []
Explanation:
The user finished the input, the sentence "i a" should be saved as a historical sentence in system. And the following input will be counted as a new search.

 
Note:

The input sentence will always start with a letter and end with '#', and only one blank space will exist between two words.
The number of complete sentences that to be searched won't exceed 100. The length of each sentence including those in the historical data won't exceed 100.
Please use double-quote instead of single-quote when you write test cases even for a character input.
Please remember to RESET your class variables declared in class AutocompleteSystem, as static/class variables are persisted across multiple test cases. Please see here for more details.










Approach 1:

class AutocompleteSystem {
public:
    
    
    
    struct trie {
        map<int, set<string> > mp;
        bool eow = false;
        trie* a[27];  
    };
    
    map<string, int> mt;
    string q = "";
    trie* root;
    trie* node;
    
    void insert(trie* head, string s, int t) {
        for (int i = 0; i < s.length(); i++) {
            int j = (s[i] == ' ') ? 26 : s[i]-'a';
            if (head -> a[j] != NULL) {
                head = head->a[j];
            } else {
                head -> a[j] = new trie();
                head = head->a[j];
            }
            head->mp[t].insert(s);
            head->mp[t-1].erase(s);
        }
        head -> eow = true;
    }
    
    AutocompleteSystem(vector<string>& s, vector<int>& t) {
        root = new trie();
        for (int i = 0; i < s.size(); i++) {
            insert(root, s[i], t[i]);
            mt[s[i]] = t[i];
        }
        node = root;
    }
    
    vector<string> input(char c) {
        vector<string> ans;
        if (c == '#') {
            mt[q] ++;
            insert(root, q, mt[q]);
            q = "";
            node = root;
            return ans;
        }
        q += c;
        int j = (isspace(c)) ? 26 : c - 'a';
        if (node == NULL) {
            return ans;
        }
        node = node -> a[j];
        if (node == NULL || node->mp.empty()) {
            return ans;
        }
        int ct = 0;
        for (auto it = node->mp.rbegin(); it != node->mp.rend() && ct < 3; ++it) {
            auto jt = it->second.begin();
            for (; jt!=it->second.end() && ct < 3; ++jt) {
                ans.push_back((*jt));
                ct++;
            }
        }
        return ans;
    }
};


Approach 2:



class AutocompleteSystem {
    struct TrieNode {
        map<char, TrieNode*> next;
        pair<string, int> p;
        TrieNode() {}
    };
    class Trie {
        TrieNode *root;
        
        struct Comp {
            bool operator() (pair<string, int> a, pair<string, int> b) {
                return a.second > b.second || a.second == b.second && a.first < b.first;
            }
        };
            
        void dfs(TrieNode *run, priority_queue<pair<string, int>, vector<pair<string, int>>, Comp>& q) {
            if (run->p.first != "") {
                q.push(run->p);
                if (q.size() > 3) q.pop();
            }
            for (auto next : run->next) {
                dfs(next.second, q);
            }
        }        
    public:
        Trie() {
            root = new TrieNode;
        }
            
        void insert(string s, int times) {
            TrieNode* run = root;
            for (auto c : s) {
                if (!run->next[c]) {
                    run->next[c] = new TrieNode;
                }
                run = run->next[c];
            }
            run->p.first = s;
            run->p.second += times;
        }
        
        vector<string> search(string s) {
            TrieNode* run = root;
            for (int i = 0; i < s.size(); i++) {
                if (!run) return {};
                run = run->next[s[i]];
            }
            if (!run) return {};
            priority_queue<pair<string, int>, vector<pair<string, int>>, Comp> q;                 
            dfs(run, q);
            vector<string> res;
            while (!q.empty()) {
                res.push_back(q.top().first);
                q.pop();
            }
            reverse(res.begin(), res.end());
            return res;
        }
    };
    Trie trie;
    string s = "";
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        for (int i = 0; i < sentences.size(); i++) 
            trie.insert(sentences[i], times[i]);
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            trie.insert(s, 1);
            s.clear();
            return {};
        }
        s += c;
        return trie.search(s);
    }
};
