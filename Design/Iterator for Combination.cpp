

https://leetcode.com/problems/iterator-for-combination/


1286. Iterator for Combination
Medium

538

45

Add to List

Share
Design the CombinationIterator class:

CombinationIterator(string characters, int combinationLength) Initializes the object with a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
next() Returns the next combination of length combinationLength in lexicographical order.
hasNext() Returns true if and only if there exists a next combination.
 

Example 1:

Input
["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[["abc", 2], [], [], [], [], [], []]
Output
[null, "ab", true, "ac", true, "bc", false]

Explanation
CombinationIterator itr = new CombinationIterator("abc", 2);
itr.next();    // return "ab"
itr.hasNext(); // return True
itr.next();    // return "ac"
itr.hasNext(); // return True
itr.next();    // return "bc"
itr.hasNext(); // return False
 

Constraints:

1 <= combinationLength <= characters.length <= 15
All the characters of characters are unique.
At most 104 calls will be made to next and hasNext.
It's guaranteed that all calls of the function next are valid



Approach:


1. Generate all the combinations form left to rigth and add into the queue when length is equals to the combinationLength.
2. next simply poll from the queue and reutrn.
3. hasNext return true until queue is not empty.

    
    



class CombinationIterator {
public:
    vector<string> temp;
    int i = 0;
    
    
    void backtrack(string& characters, int combinationLength, int idx, string ans){ 
        for(int i = idx; i < characters.size() && ans.size() < combinationLength; i++){
            backtrack(characters, combinationLength, i + 1, ans + characters[i]);      
        }
         if(ans.size() == combinationLength) temp.push_back(ans);  
    }
    CombinationIterator(string characters, int combinationLength) {
        backtrack(characters, combinationLength, 0, "");   
    }
    string next() {
       return  temp[i++]   
    }
    
    bool hasNext() {
        return i < temp.size();  
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */








