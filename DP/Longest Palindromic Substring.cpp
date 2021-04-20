5. Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"


class Solution
{
public:
    string longestPalindrome(string s)
	{
        int max_len = 1;
        int start = 0;
        
        for(int i = 1; i < s.size(); i++) 
		{
            checkPalindrome(s, i - 1, i, start, max_len);   /* Even */
            checkPalindrome(s, i - 1, i + 1, start, max_len);   /* Odd */
        }
        return s.substr(start, max_len);
    }
    
    void checkPalindrome( string& s, int low, int high, int& start, int& max_len)
	{
        while(low >= 0 && high < s.size() && s[low] == s[high])
		{
            if(high - low + 1 > max_len)
			{
                max_len = high - low + 1;
                start = low;
            }
            --low;
            ++high;
        }
    }
};




