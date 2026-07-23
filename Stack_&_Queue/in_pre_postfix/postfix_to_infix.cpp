// Convert postfix expression to infix expression using a stack
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <stdexcept>
using namespace std;

// Split the input into small pieces so we can process one token at a time.
vector<string> tokenize(const string& expression) {
    vector<string> tokens;

    // If the expression has spaces, split it by whitespace.
    if (expression.find_first_of(" \t\n\r") != string::npos) {
        stringstream ss(expression);
        string token;
        while (ss >> token) {
            tokens.push_back(token);
        }
        return tokens;
    }

    // If there are no spaces, treat each character as one token.
    for (char ch : expression) {
        if (!isspace(static_cast<unsigned char>(ch))) {
            tokens.push_back(string(1, ch));
        }
    }
    return tokens;
}

// Convert a postfix expression to infix.
// Example: a b + c *  ->  (a+(b*c))
string postfixToInfix(const string& expression) {
    stack<string> st;
    vector<string> tokens = tokenize(expression);

    for (const string& token : tokens) {
        // If the token is an operand, push it onto the stack.
        if (token.size() == 1 && isalnum(static_cast<unsigned char>(token[0])) &&
            token != "+" && token != "-" && token != "*" && token != "/" && token != "^") {
            st.push(token);
        }
        // If the token is an operator, combine the two latest operands.
        else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
            if (st.size() < 2) {
                throw invalid_argument("Invalid postfix expression");
            }

            string right = st.top();
            st.pop();
            string left = st.top();
            st.pop();

            st.push("(" + left + token + right + ")");
        } else {
            throw invalid_argument("Invalid token in expression");
        }
    }

    if (st.size() != 1) {
        throw invalid_argument("Invalid postfix expression");
    }

    return st.top();
}

int main() {
    string expression;
    cout << "Enter postfix expression (example: a b c + *): ";
    getline(cin, expression);

    if (expression.empty()) {
        expression = "a b c + *";
    }

    try {
        cout << "Infix: " << postfixToInfix(expression) << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
