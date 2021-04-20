
Balanced Brackets Sequel
Given a string s containing round, curly, and square open and closing brackets, return whether the brackets are balanced.

Constraints

n ≤ 100,000 where n is the length of s
Example 1
Input
s = "[(])"
Output
false
Example 2
Input
s = "([])[]({})"
Output
true



bool solve(string s) {
        stack<char> st;
    
    for(int i = 0 ;i < s.length() ; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        if(s[i] ==')' || s[i] == ']' || s[i] =='}')
        {
            if(st.empty())
                return false;
            else if(s[i] ==')' && st.top() != '(')
                return false;
            else if(s[i] ==']' && st.top() != '[')
                return false;
            else if(s[i] =='}' && st.top() != '{')
                return false;
            else
                st.pop();
        }
    }
    
    if(!st.empty())
        return false;
    return true;
    
}
    
