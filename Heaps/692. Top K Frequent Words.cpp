692. Top K Frequent Words

Add to List

Share
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
    
    
    
    
class Solution {
public:
    // creating min heap here
    struct comp{
    // key step is to check for both the two conditions
        bool operator()( pair<int, string>& a,  pair<int, string>& b){
            if(a.first == b.first) return a.second < b.second;
            else return a.first > b.first;
        };
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> plot;
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> que;
        
        for(auto w : words) plot[w]++;
        
        for(auto it : plot){
            que.push({it.second, it.first});
            if(que.size() > k) que.pop();
        }
        
        vector<string> result;
       while(!que.empty()){
            result.push_back(que.top().second);
            que.pop();
        }
       reverse(result.begin(), result.end());
        
        return result;
    }
};
