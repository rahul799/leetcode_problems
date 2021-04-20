

Postfix Notation Evaluation




https://binarysearch.com/problems/Postfix-Notation-Evaluation






Postfix notation is a way to represent an expression where the operator comes after the operands.

For example, [2, 2, "+", 6, "*"] would be equal to 24, since we have (2 + 2) * 6 = 24.

Given a list of strings exp, representing a postfix notation consisting of integers and operators (+, -, *, /), evaluate the expression. / is integer division.


Example 1
Input
exp = ["9", "3", "+", "2", "/"]
Output
6
Explanation
(9 + 3) / 2 = 6

Example 2
Input
exp = ["3", "9", "-", "4", "/"]
Output
-1
Explanation
(3 - 9) / 4 = -1




long long int eval(long long int a, long long int b, string op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return a / b;
    return 0;
}

int solve(vector<string>& exp) {
    stack<string> st;
    set<string> s = {"+", "-", "*", "/"};
    for (auto str : exp) {
        if (s.find(str) != s.end()) {
            long long int valb = stol(st.top());
            st.pop();
            long long int vala = stol(st.top());
            st.pop();
            long long int res = eval(vala, valb, str);
            st.push(to_string(res));
            continue;
        }
        st.push(str);
    }
    return (int)stol(st.top());
}




