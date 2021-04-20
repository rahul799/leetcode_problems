


https://www.youtube.com/watch?v=5XjJs5SBN8g&t=337s&ab_channel=CherryCoding%5BIIT-G%5D






1781. Sum of Beauty of All Substrings
Medium

128

58

Add to List

Share
The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

 

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
Example 2:

Input: s = "aabcbaa"
Output: 17
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters





class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            vector<int>track(26,0);
            for(int j=i; j<s.length(); j++){
                track[s[j]-'a']+=1;
                int minCount=INT_MAX, maxCount=INT_MIN;//We declare this min and max during every iteration of j and not outside j loop because at some point, for eg, we've aabcb, min might have become 2 but in last iteration of j it was 1, then if we don't reset min, min value won't change and we'll get a bigger answer.
                for(int n: track)if(n!=0){
                    minCount = min(minCount,n);
                    maxCount = max(maxCount,n);
                }
                ans = ans + maxCount - minCount;
            }
        }
        return ans;
    }
};







class Solution {
public:
    int beautySum(string s) {
		// Variable to store answer
        int ans = 0;
		// Size of the string
        int n = s.size();
		// Loop for left index of the substring
        for(int i=0; i<n; i++) {
			// Counter to store frequency of letters in substring
            int cnt[26] = {};
			// Initialise min and max frequency
            int max_f = INT_MIN;
            int min_f = INT_MAX;
			// Loop for right index of substring
            for(int j=i; j<n; j++) {
				// Get index of alphabet
                int ind = s[j] - 'a';
				// Increment frequency of that index
                cnt[ind]++;
				// The max frquency will be the maximum of the current max frquency and count of current index.
				// This is because that was the only value that was incremented in this run.
                max_f = max(max_f, cnt[ind]);
				// The maximum value of min frequency is the count of the current index
				// This is used for initialisation of min_f varaiable
                min_f = cnt[ind];
				// Loop across all alphabets to get the min frequency
                for(int k=0; k<26; k++) {
					// We want to consider the non-zero minimum, i.e. the letter should exist in the substring
                    if(cnt[k] >= 1)
                        min_f = min(min_f, cnt[k]);
                }
				// Increment answer by difference of max_f and min_f
                ans += (max_f - min_f);
            }
        }
        return ans;
    }
};




