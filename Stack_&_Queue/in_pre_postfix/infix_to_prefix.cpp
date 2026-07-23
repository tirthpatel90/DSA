// Infix to Prefix Conversion using Stack
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int precedence(char op) { // Function to return the precedence of operators
    switch (op) { // Return precedence based on operator type
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

string infixToPrefix(string infix) { // Function to convert infix expression to prefix expression
    reverse(infix.begin(), infix.end()); // Reverse the infix expression to process it from right to left

    stack<char> s;
    string prefix = ""; // Resultant prefix expression

    for (char c : infix) { // Iterate through each character in the reversed infix expression
        if (isspace(static_cast<unsigned char>(c))) { // Skip whitespace characters
            continue;
        }

        if (isalnum(c)) { // If the character is an operand, add it to the prefix expression
            prefix += c;
        } else if (c == ')') { // If the character is ')', push it onto the stack
            s.push(c);
        } else if (c == '(') { // If the character is '(', pop from the stack until ')' is found
            while (!s.empty() && s.top() != ')') { // Pop operators from the stack and add them to the prefix expression
                prefix += s.top();
                s.pop();
            }
            if (!s.empty()) { // Pop the ')' from the stack
                s.pop();
            }
        } else { // If the character is an operator, pop from the stack based on precedence
            while (!s.empty() && s.top() != ')' && // Check operator precedence and associativity
                   (precedence(s.top()) > precedence(c) || // If the top operator has higher precedence or equal precedence and is not right associative
                    (precedence(s.top()) == precedence(c) && c != '^'))) { // Pop operators from the stack and add them to the prefix expression
                prefix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) { // Pop all remaining operators from the stack and add them to the prefix expression
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end()); // Reverse the prefix expression to get the final result
    return prefix;
}

int main() {
    string infix = "A+B*(C^D-E)";
    string prefix = infixToPrefix(infix);
    cout << "Infix: " << infix << endl;
    cout << "Prefix: " << prefix << endl;
    return 0;
}