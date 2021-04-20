
https://leetcode.com/problems/basic-calculator-iii/


https://leetcode.com/problems/basic-calculator-iii/discuss/757809/C%2B%2B-Explained-Template-for-Basic-Calculator-I-II-III

772. Basic Calculator III
Hard

566

219

Add to List

Share
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, '+', '-', '*', '/' operators, and open '(' and closing parentheses ')'. The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

 

Example 1:

Input: s = "1+1"
Output: 2
Example 2:

Input: s = "6-4/2"
Output: 4
Example 3:

Input: s = "2*(5+5*2)/3+(6/2+8)"
Output: 21
Example 4:

Input: s = "(2+6*3+5-(3*14/7+2)*5)+3"
Output: -12
Example 5:

Input: s = "0"
Output: 0
 

Constraints:

1 <= s <= 104
s consists of digits, '+', '-', '*', '/', '(', and ')'.
s is a valid expression.

Approach:



Use sign to remember the lasted operator we have met
Use number for the number we are operating
Use stack to track the number we have meet

The basic idea to resolve this type of question involves the following 3 basic steps
Step 1. calculate the current number you meet. If there is parenthese, calculate the inner parenthesis values recursivley
Step 2. push the current number inside your stack based on the last sign you meet
Step 3. sum up all the numbers you have meet by poping elements from the stack





class Solution {
public:
    int calculate(string s) {
        if (s.size() == 0) {
            return 0;
        }
        
        stack<int> myStack;
        char sign = '+'; // sign only indicaite next element attribute
        long number = 0;
        
        for (int i = 0; i< s.size(); i++) {
		    // Step 1. calculate the current number you meet. have a recursive call the func encounter a parenthese
            if (isdigit(s[i])) {
                number = number*10 + long(s[i]-'0');
            } else if (s[i] == '(') {
                int j = i + 1; 
                int braces = 1;
                while (braces > 0) {
                    if (s[j] == '(')
                        braces++;
                    else if (s[j] ==')')
                        braces--;
                    j++;
                }
                
                int length = (j-1) -i ;
                number = calculate(s.substr(i + 1, length));
                i = j-1; // adjust cursor to the last calculated character
            }
            
			// Step 2.  push the current number inside your stack based on the **last sign** you meet
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == s.size() - 1) {
                switch (sign) {
                    case '+':
                        myStack.push(number);
                        break;
                    case '-':
                        myStack.push(-number);
                        break;
                    case '*': {
                        int top = myStack.top();
                        myStack.pop();
                        myStack.push(top*number);
                        break;                        
                    }
                    case '/': {
                        int top = myStack.top();
                        myStack.pop();
                        myStack.push(top/number);
                        break;                        
                    }
                }

                sign = s[i]; // assign new operator 
                number = 0; // reset the current number 
            }
        }
        
		// Step 3.  sum up all the numbers you have meet by poping elements from the stack
        int sum = 0;
        while(!myStack.empty()) {
            sum += myStack.top();
            myStack.pop();
        }
        return sum;
    }
};
