763. Partition Labels

Share
A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return 
a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.



class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n=S.length();
        vector<int> m(26,0), ans;

        for(int i=0; i<n; i++) m[S[i]-'a'] = i;
        
        int curr_max = -1, min_index=0;
        for(int i=0; i<n; i++) {
            curr_max = max(curr_max, m[S[i]-'a']);
            
            if(curr_max==i) {
                ans.push_back(curr_max-min_index + 1);
                min_index = i+1;
            }
        }
        
        return ans;
    }
};
