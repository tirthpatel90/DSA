// Infix to Postfix Conversion using Stack
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

string infixToPostfix(string expression) {
    stack<char> st; // Stack to store operators
    string postfix = ""; // Resultant postfix expression

    auto precedence = [&](char op) -> int {
        switch (op) {
            case '+': case '-': return 1;
            case '*': case '/': return 2;
            case '^': return 3;
            default: return 0;
        }
    };

    for (char c : expression) {
        if (isspace(static_cast<unsigned char>(c))) {
            continue;
        }

        if (isalnum(c)) {
            // If the character is an operand, add it to the postfix expression
            postfix += c;
        } else if (c == '(') {
            // If the character is '(', push it onto the stack
            st.push(c);
        } else if (c == ')') {
            // If the character is ')', pop from the stack until '(' is found
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Pop the '(' from the stack
        } else {
            // If the character is an operator, pop from the stack based on precedence
            while (!st.empty() && st.top() != '(' &&
                   (precedence(st.top()) > precedence(c) ||
                    (precedence(st.top()) == precedence(c) && c != '^'))) {
                postfix += st.top();
                st.pop();
            }
            st.push(c); // Push the current operator onto the stack
        }
    }

    // Pop all remaining operators from the stack
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix; // Return the resultant postfix expression
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin >> ws, infixExpression); // Read the full infix expression, including spaces

    string postfixExpression = infixToPostfix(infixExpression); // Convert to postfix
    cout << "Postfix expression: " << postfixExpression << endl; // Output the postfix expression

    return 0;
}