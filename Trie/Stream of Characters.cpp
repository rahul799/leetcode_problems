1032. Stream of Characters
Hard

729

105

Add to List

Share
Implement the StreamChecker class as follows:

StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.
 

Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist
 

Note:

1 <= words.length <= 2000
1 <= words[i].length <= 2000
Words will only consist of lowercase English letters.
Queries will only consist of lowercase English letters.
The number of queries is at most 40000.


The idea is based on suffix trie

class StreamChecker {
public:
    
    
    struct TrieNode{
        struct TrieNode* child[ 26 ];
        bool endsWord = false;        
    };
    
    TrieNode* root;
    vector< char > lastK; // only needs to be as long as longest word ( 2000 )
    
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        
        TrieNode* node;
        
        for( auto w : words ){
            node = root;
            for( int i = w.size() - 1; i >= 0; i-- ){
                if( node->child[ w[ i ] - 'a' ] == NULL )
                    node->child[ w[ i ] - 'a' ] = new TrieNode();
                node = node->child[ w[ i ] - 'a' ];
            }   
            node->endsWord = true;            
        }
        
    }
    
    bool query( char letter ) {
        lastK.emplace_back( letter );
        
        TrieNode* node = root;
        int reverseI = lastK.size() - 1;
        
        while( reverseI >= 0 && node ){
            if( node->endsWord )
                return true;
            
            if( node->child[ lastK[ reverseI ] - 'a' ] == NULL )
                break;
            
            node = node->child[ lastK[ reverseI-- ] - 'a' ];            
        }
        
        if( node && node->endsWord )
            return true;
        
        return false;
    }
};












