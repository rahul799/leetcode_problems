234. Replace the Substring for Balanced String
Medium

427

89

Add to List

Share
You are given a string containing only 4 kinds of characters 'Q', 'W', 'E' and 'R'.

A string is said to be balanced if each of its characters appears n/4 times where n is the length of the string.

Return the minimum length of the substring that can be replaced with any other string of the same length to make the original string s balanced.

Return 0 if the string is already balanced.

 

Example 1:

Input: s = "QWER"
Output: 0
Explanation: s is already balanced.
Example 2:

Input: s = "QQWE"
Output: 1
Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.
Example 3:

Input: s = "QQQW"
Output: 2
Explanation: We can replace the first "QQ" to "ER". 
Example 4:

Input: s = "QQQQ"
Output: 3
Explanation: We can replace the last 3 'Q' to make s = "QWER".
 

Constraints:

1 <= s.length <= 10^5
s.length is a multiple of 4
s contains only 'Q', 'W', 'E' and 'R'



The question finds us to asks the minimum window substring which you can replace by any other substring so that the count of all the characters remain same.

Solution
Given that the only characters are Q, W, E, R, and all of them should have the same final count. So, count of each character should be len/4. So, we have to store the extra characters which we have to replace with some other characters.

For example, let's take the string QEWQRQEQ .

Count of Q - 4
Count of E - 2
Count of W - 1
Count of R - 1
Now it's kind of evident that you have to replace two Q's with a W and a R. So now you have to find the minimum window substring, which actually contains QQ. In the above example, that would be QRQ or QEQ.

So, I use an unordered_map to store the count of the characters. And then I create a string str which will contain all the characters I need to replace. If the string is empty, it implies that we do not have to do any change. Otherwise find the minimum window substring containing all characters of str.

Please refer to the Minimum Window Substring question for clearly understanding the afore-mentioned portion of the code.



class Solution {
public:
	// Minimum Window Substring
    int minwindowsubstr(string s, string text)
    {
        vector<int> ct(26,0);
        int n=text.length();
        for(int i=0;i<n;i++) ct[text[i]-'A']++;
        int r=0,l=0,mi=INT_MAX;
        while(r<s.length()){
            ct[s[r]-'A']--;
            if(ct[s[r]-'A']>=0) n--;
            r++;
            while(l<r && n==0){
                mi=min(mi,r-l);
                ct[s[l]-'A']++;
                if(ct[s[l]-'A']>0) n++;
                l++;
            }
        }
        return mi;
    }
    
    int balancedString(string s) {
        int n=s.length();
        unordered_map<char,int> m;
        for(int i=0;i<n;i++) m[s[i]]++;
        int len=n/4;
        //cout<<len<<endl;
        string str="";
        for(auto it:m){
            if(it.second>len) str+=string(it.second-len,it.first);
        }
        if(str.length()==0) return 0;
        return minwindowsubstr(s,str);
    }
};
