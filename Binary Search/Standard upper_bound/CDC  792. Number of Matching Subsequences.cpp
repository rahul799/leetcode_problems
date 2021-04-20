


Very Very Important CDC 



Intuition and Algorithm

Let's try to check separately whether each word words[i] is a subsequence of S.

For every such word, we try to find the first occurrence of word[0] in S, then from that point on try to find the first occurrence of word[1], and so on.


Complexity Analysis

Time Complexity: O(\text{words.length} * S\text{.length} + \sum_i \text{words[i].length})O(words.length∗S.length+∑ 
i
​	
 words[i].length). For each word, our subseq check on word words[i] may take time complexity O(S\text{.length} + \text{words[i].length})O(S.length+words[i].length).

Space Complexity: O(1)O(1). (In Java, our space complexity is O(S\text{.length} + \text{max(words[i].length)})O(S.length+max(words[i].length)), but can be made to be 
O(1)O(1) with a pointer based implementation.)


	
	
	
	
	
	
	



792. Number of Matching Subsequences
Medium

1248

89

Add to List

Share
Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].






/*
       Create a map that stores indices for each character a-z in S
       Then for each word, do a binary search for next index for current character in word 
       that is greater than the index we last found for the last character.
       If it doesn't exist, word doesn't exist, otherwise continue to search for word
    */

    int numMatchingSubseq( string S, vector<string>& words ) {
        unordered_map< char, vector<int> > charToIndex;
        for( int i=0; i < S.size(); i++ )
            charToIndex[ S[i] ].push_back( i );
            
        int result = 0;
        for( auto word : words ) {
            int isSubSeq = true;
            int pos = -1;
            for( auto c : word ) {
                auto it = upper_bound( charToIndex[c].begin(), charToIndex[c].end(), pos );
				if( it == charToIndex[c].end() )
                    isSubSeq = false;
				else 
                    pos = *it;
            }
            
            if( isSubSeq ) ++result;
        }
        return result;
    }


/*
       Create a map that stores indices for each character a-z in S
       Then for each word, do a binary search for next index for current character in word 
       that is greater than the index we last found for the last character.
       If it doesn't exist, word doesn't exist, otherwise continue to search for word
    */

    int numMatchingSubseq( string S, vector<string>& words ) {
        unordered_map< char, vector<int> > charToIndex;
        for( int i=0; i < S.size(); i++ )
            charToIndex[ S[i] ].push_back( i );
            
        int result = 0;
        for( auto word : words ) {
            int isSubSeq = true;
            int pos = -1;
            for( auto c : word ) {
                auto it = upper_bound( charToIndex[c].begin(), charToIndex[c].end(), pos );
				if( it == charToIndex[c].end() )
                    isSubSeq = false;
				else 
                    pos = *it;
            }
            
            if( isSubSeq ) ++result;
        }
        return result;
    }
