1628. Design an Expression Tree With Evaluate Function




Add to List

Share
Given the postfix tokens of an arithmetic expression, build and return the binary expression tree that represents this expression.

Postfix notation is a notation for writing arithmetic expressions in which the operands (numbers) appear before their operators. For example, the postfix tokens 
of the expression 4*(5-(7+2)) are represented in the array postfix = ["4","5","7","2","+","-","*"].

The class Node is an interface you should use to implement the binary expression tree. The returned tree will be tested using the evaluate function, which is 
supposed to evaluate the tree's value. You should not remove the Node class; however, you can modify it as you wish, and you can define other classes to 
implement it if needed.

A binary expression tree is a kind of binary tree used to represent arithmetic expressions. Each node of a binary expression tree has either zero or two children. Leaf nodes (nodes with 0 children) correspond to operands (numbers), and internal nodes (nodes with two children) correspond to the operators '+' (addition), '-' (subtraction), '*' (multiplication), and '/' (division).

It's guaranteed that no subtree will yield a value that exceeds 109 in absolute value, and all the operations are valid (i.e., no division by zero).

Follow up: Could you design the expression tree such that it is more modular? For example, is your design able to support additional operators without
making changes to your existing evaluate implementation?

 
 
 
 
 Yet to read properly 

Example 1:



Input: s = ["3","4","+","2","*","7","/"]
Output: 2
Explanation: this expression evaluates to the above binary tree with expression ((3+4)*2)/7) = 14/7 = 2.
Example 2:



Input: s = ["4","5","7","2","+","-","*"]
Output: -16
Explanation: this expression evaluates to the above binary tree with expression 4*(5-(2+7)) = 4*(-4) = -16.
Example 3:

Input: s = ["4","2","+","3","5","1","-","*","+"]
Output: 18
Example 4:

Input: s = ["100","200","+","2","/","5","*","7","+"]
Output: 757
 

Constraints:

1 <= s.length < 100
s.length is odd.
s consists of numbers and the characters '+', '-', '*', and '/'.
If s[i] is a number, its integer representation is no more than 105.
It is guaranteed that s is a valid expression.
The absolute value of the result and intermediate values will not exceed 109.
It is guaranteed that no expression will include division by zero.








Build the tree:
As the definition of Postfix notation, it is a stack model:

Loop the array and allocate the memory for each node
Push into stack if it is a operand
Pop the right and left operand from the tree if it is a operator, and push the operator into stack
Return the top of stack as the root of expression tree

Evaluate the value
Complete the definition of Node class

Add the val, left, right, like a tree node.
Implement the constructor, which accept one string as input.
Complete the evaluate() function,

According to the comment, each node should call evaluate() function
Return the value if it is a number
Otherwise(operator), return the value from left and right.
Time complexity
All build and evaluate take O(n)

/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    Node(string s) : val(s), left(nullptr), right(nullptr) {};
    virtual ~Node () {};
    int evaluate(){
        if(val == "+"){
            return left->evaluate() + right->evaluate();
        } else if(val == "-"){
            return left->evaluate() - right->evaluate();
        } else if(val == "*"){
            return left->evaluate() * right->evaluate();
        } else if(val == "/"){
            return left->evaluate() / right->evaluate();
        }
        return stoi(val); 
    }
    string val;
    Node* left;
    Node* right;
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        vector<Node*> st;
        for(auto p : postfix){
            Node* node = new Node(p);
            if(p == "+" || p == "-" || p == "*" || p == "/"){
                node->right = st.back();
                st.pop_back();
                node->left = st.back();
                st.pop_back();
            }
            st.push_back(node);
        }
        return st.back();
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
