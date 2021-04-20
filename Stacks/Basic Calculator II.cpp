Basic Calculator II

https://leetcode.com/problems/basic-calculator-ii/


227. Basic Calculator II
Medium

2062

331

Add to List

Share
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

 
 
 Approach 1: Using Stack
Intuition

We know that there could be 4 types of operations - addition (+), subtraction (-), multiplication (*) and division (/). Without parenthesis, we know that, multiplication (*) and (\) operations would always have higher precedence than addition (+) and subtraction (-) based on operator precedence rules.

img

If we look at the above examples, we can make the following observations -

If the current operation is addition (+) or subtraction (-), then the expression is evaluated based on the precedence of the
next operation.
In example 1, 4+3 is evaluated later because the next operation is multiplication (3*5) which has higher precedence. But, 
in example 2, 4+3 is evaluated first because the next operation is subtraction (3-5) which has equal precedence.

If the current operator is multiplication (*) or division (/), then the expression is evaluated irrespective of the next 
operation. This is because in the given set of operations (+,-,*,/), the * and / operations have the highest precedence and 
therefore must be evaluated first.
In the above example 2 and 3, 4*3 is always evaluated first irrespective of the next operation.

Using this intuition let's look at the algorithm to implement the problem.

Algorithm

Scan the input string s from left to right and evaluate the expressions based on the following rules

If the current character is a digit 0-9 ( operand ), add it to the number currentNumber.
Otherwise, the current character must be an operation (+,-,*, /). Evaluate the expression based on the type of operation.
Addition (+) or Subtraction (-): We must evaluate the expression later based on the next operation. So, we must store the
currentNumber to be used later. Let's push the currentNumber in the Stack.
Stack data structure follows Last In First Out (LIFO) principle. Hence, the last pushed number in the stack would be popped 
out first for evaluation. In addition, when we pop from the stack and evaluate this expression in the future, we need a way
to determine if the operation was Addition (+) or Subtraction (-). To simplify our evaluation, we can push -currentNumber 
in a stack if the current operation is subtraction (-) and assume that the operation for all the values in the stack is
addition (+). This works because (a - currentNumber) is equivalent to (a + (-currentNumber)).

Multiplication (*) or Division (/): Pop the top values from the stack and evaluate the current expression. Push the evaluated 
value back to the stack.




class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if (len == 0) return 0;
        stack<int> stack;
        int currentNumber = 0;
        char operation = '+';
        for (int i = 0; i < len; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1) {
                if (operation == '-') {
                    stack.push(-currentNumber);
                } else if (operation == '+') {
                    stack.push(currentNumber);
                } else if (operation == '*') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop * currentNumber);
                } else if (operation == '/') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop / currentNumber);
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        int result = 0;
        while (stack.size() != 0) {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};


Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.




class Solution {
public:
    int calculate(string s) {
        int length = s.length();
        if (length == 0) return 0;
        int currentNumber = 0, lastNumber = 0, result = 0;
        char sign = '+';
        for (int i = 0; i < length; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == length - 1) {
                if (sign == '+' || sign == '-') {
                    result += lastNumber;
                    lastNumber = (sign == '+') ? currentNumber : -currentNumber;
                } else if (sign == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else if (sign == '/') {
                    lastNumber = lastNumber / currentNumber;
                }
                sign = currentChar;
                currentNumber = 0;
            }
        }
        result += lastNumber;
        return result;  
    }
};




