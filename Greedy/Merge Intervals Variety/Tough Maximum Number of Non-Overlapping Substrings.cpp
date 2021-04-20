1520. Maximum Number of Non-Overlapping Substrings


https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/discuss/748453/C%2B%2B-easy-to-understand-greedy

305

42

Add to List

Share
Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:

The substrings do not overlap, that is for any two substrings s[i..j] and s[k..l], either j < k or i > l is true.
A substring that contains a certain character c must also contain all occurrences of c.
Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.

Notice that you can return the substrings in any order.

 

Example 1:

Input: s = "adefaddaccc"
Output: ["e","f","ccc"]
Explanation: The following are all the possible substrings that meet the conditions:
[
  "adefaddaccc"
  "adefadda",
  "ef",
  "e",
  "f",
  "ccc",
]
If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.
Example 2:

Input: s = "abbaccd"
Output: ["d","bb","cc"]
Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.






class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
    int n = s.size();
    vector<int> first(26, n);
    vector<int> last(26, -1);
    //get the first and last occurance for each character of s
    for(int i = 0; i < n; i++) {
        int idx = s[i] - 'a';
        first[idx] = min(first[idx], i);
        last[idx] = max(last[idx], i);
    }
    
    //update boundary to get valid substring
    //i.e. acabbbc, for 'a', first and last occurance is [0, 2], but "aca" is not a valid substring since we didn't include all 'c', 
	//so we iterate the substring of [first, last],  update left and right boundary 
    for(int i = 0; i < 26; i++) {  // here loop for 26 lower case character
        int l = first[i];
        int r = last[i];
        for(int j = l + 1; j < r; j++) { // here loop the substring of s in [last, first] interval
            int idx = s[j] - 'a';
            l = min(l, first[idx]); 
            r = max(r, last[idx]);
        }
        first[i] = l;
        last[i] = r;
    }

  
    vector<vector<int> > subs;
    for(int i = 0; i < n; i++) {
        int idx = s[i] - 'a';
        if(first[idx] == i) { // if first occurance is the current index, it is possible candidate 
            int r = last[idx];
            if(!subs.empty() && subs.back()[1] > r) {
                subs.pop_back(); // we found a inner interval, i.e. aea [0, 2], 'e' [1,1], is a shorter inner interval, it's better to take the shorter one so that we can get more
            }
            subs.push_back({i, r});
        }
    }
    // get all valid substrings
    vector<string> res;
    for(int i = 0; i < subs.size(); i++) {
        int l = subs[i][0];
        int r = subs[i][1];
        res.push_back(s.substr(l, r - l +1));
    }
    return res;
    }
};
