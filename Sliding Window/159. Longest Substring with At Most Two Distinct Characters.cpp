Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.




 // 0. using a idx_start to remember the current start
// 1. using a map<char, int> cand remember how many times char occurs
// 2. once the map has more than two elements.  
// 3. then move the idx_start and minus the count in map and then calculate the len



class Solution {
public:
   
 int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map <char, int> countMap;
        int left = 0, res=0;
        for(int  right =0; right < s.size(); right++) {
            countMap[s[right]]++;
            //the rule is no longer valid, balance the window
            if(countMap.size() > 2){
                countMap[s[left]]--;
                if(countMap[s[left]] == 0)
                    countMap.erase(s[left]);
                left++;
            }
            res = max(res, right - left + 1);
        }
        
        return res;
    }
};
