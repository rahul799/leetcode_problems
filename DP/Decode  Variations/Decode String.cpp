
394. Decode String
Medium

4306

212

Add to List

Share
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
Example 4:

Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"
 

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300]



class Solution {
public:

    string decodeString(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ']') {
                st.push(s[i]);
            }
            else{
                string curr_str = "";
                
                while(st.top() != '['){
                    curr_str = st.top() + curr_str ;
                    st.pop();
                }
                
                st.pop();   // for '['
                string number = "";
                
                // for calculating number
                
                while(!st.empty() && isdigit(st.top())){
                    number = st.top() + number;
                    st.pop();
                }
                int k_time = stoi(number);    // convert string to number
                
                while(k_time--){
                    for(int p = 0; p < curr_str.size() ; p++)
                        st.push(curr_str[p]);
                }
            }
        }
        
        s = "";
        while(!st.empty()){
            s = st.top() + s;
            st.pop();
        }
        return s;
        
    }
};







class Solution {
public:
    string findstr(string& s,int& i)
    {
        string res="";
        while(i<s.size())
        {
            if(s[i]==']') return res;
            if(isalpha(s[i])) res += s[i++];
            else
            {
                int n=0;
                while(i<s.size() and isdigit(s[i])) n = n*10+(s[i++]-'0');    //form the number, like in string "2456[ab]" this loop will get you 2456.
                i++;                        // just after number the next character is '[' so ignore this by incrementing the index.
                string str = findstr(s,i);  //now recursively call this function to get the inner string within the brackets.
                i++;                        //just after the inner string next character is ']' so ignore this by incrementing the index.
                while(n--) res += str;      //now you have the number 2456 and the inner string ab so add this to result.
            }
        }
        return res;
    }
    
    string decodeString(string s) {
        int i=0;
        return findstr(s,i);
    }
};
