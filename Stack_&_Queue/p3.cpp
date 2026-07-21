// Balanced Parentheses
#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s) {
    stack<char> st; // Create a stack to keep track of opening parentheses
    for (char c : s) { // Iterate through each character in the input string
        if (c == '(' || c == '[' || c == '{') { // If the character is an opening parenthesis, push it onto the stack
            st.push(c);
        } else {
            if (st.empty()) return false; // If the stack is empty and we encounter a closing parenthesis, return false
            char top = st.top(); // Get the top element of the stack, which is the last opening parenthesis
            if ((c == ')' && top == '(') || // Check if the closing parenthesis matches the opening parenthesis
                (c == ']' && top == '[') || // Check if the closing bracket matches the opening bracket
                (c == '}' && top == '{')) { // Check if the closing brace matches the opening brace
                st.pop(); // If they match, pop the opening parenthesis from the stack
            } else {
                return false; // If they don't match, return false
            }
        }
    }
    return st.empty(); // If the stack is empty at the end, all parentheses are balanced; otherwise, they are not
}

int main() {
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;
    if (isBalanced(s)) {
        cout << "The parentheses are balanced." << endl;
    } else {
        cout << "The parentheses are not balanced." << endl;
    }
    return 0;
}