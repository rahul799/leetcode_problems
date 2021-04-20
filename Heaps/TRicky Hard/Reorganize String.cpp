767. Reorganize String

Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500]


class Solution {
public:
    string reorganizeString(string S) {
        priority_queue<pair<int, char>> pq;
        int map[26] = { 0 };
        
        for (auto c : S) {
            if (++map[c-'a'] > (S.size() + 1)/2)
                return "";
        }
        
        for (int i = 0; i < 26; ++i) {
            if (map[i])
                pq.push({map[i], i + 'a'});
        }
        
        string ans;
        while(!pq.empty()) {
            pair<int, char> p1, p2;
            p1 = pq.top(); pq.pop();
            ans = ans + p1.second;
            if (!pq.empty()) {
                p2 = pq.top(); pq.pop();
                ans = ans + p2.second;
                if (--p2.first)
                    pq.push(p2);
            }
            if (--p1.first)
                pq.push(p1);
        }
        return ans;
    }
};






// "We store frequency of characters from the String in a Hashmap. 
// Build a PriorityQueue(Max Heap), pq that stores characters and 
// their frequencies. We are maintaining a Priority Queue based on max frequency.
// We are storing a previous entry which tells which was our last character processed
// The previous entry is important since we don't want 2 consecutive characters to be the same.


// Pop an element from Priority Queue and add it to the final result. When we pop 
// an element from the queue, we have used 1 character, so we decrease the frequency 
// count of that Entry's Character. If the Character count of that Entry is >0 
// then we need to add that entry back to the Priority Queue for further processing.
// The reason why we are adding prev to the heap and not curr, is because we don't consecutive characters to be same. Because when we do maxHeap.poll(), then
// we are taking out an Entry(char and it's frequency), so next time we remove an entry from the PriorityQueue, we are going to get a different character entry for sure(which is the base condition: No consecutive chars should be same)
// If length of resultant string and original string is equal then return the resultant string, otherwise return an Empty String."
