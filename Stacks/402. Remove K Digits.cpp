402. Remove K Digits
Medium

2721

115

Add to List

Share
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.





class Solution {
public:
    string removeKdigits(string num, int k) {
    stack<char> stk; 
        int n = num.size();
        
        for( char c : num){
            while(!stk.empty() && stk.top() > c && k > 0 )
                stk.pop(), k--;
            
            if((!(stk.empty()) || c != '0')) stk.push(c);
        }
        
            while(!(stk.empty()) && k--) stk.pop();
        
        if(stk.empty()) return "0";
            
            while(!(stk.empty())){
                num[n-1] = stk.top();
                stk.pop();
                n--;
            }
        
        // here n is updated
        return num.substr(n);
        
        
            
                
        }
    
    
        
    
    
        
    
};
