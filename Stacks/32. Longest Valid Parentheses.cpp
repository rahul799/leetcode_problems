Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"



1) Create an empty stack and push -1 to it. The first element
   of the stack is used to provide a base for the next valid string. 

2) Initialize result as 0.

3) If the character is '(' i.e. str[i] == '('), push index 
   'i' to the stack. 
   
2) Else (if the character is ')')
   a) Pop an item from the stack (Most of the time an opening bracket)
   b) If the stack is not empty, then find the length of current valid
      substring by taking the difference between the current index and
      top of the stack. If current length is more than the result,
      then update the result.
   c) If the stack is empty, push the current index as a base for the next
      valid substring.

3) Return result.





class Solution {
public:
    int longestValidParentheses(string s) {
        
        int res=0;
        stack<int> st;
        st.push(-1); // -1 here is added to provide base for already 
                     // balanced string, dry run the code to understand this
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(!st.empty()) res=max(res,i-st.top());
                else st.push(i);
            }
        }        
        return res;        
    }
};

